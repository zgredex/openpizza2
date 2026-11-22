#!/usr/bin/env python3
"""Extract Game_Construct animation rows and compile a contiguous VC6 slice."""

import argparse
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[4] / 'tools'))
from capstone import x86_const as x86
from decomp_fixtures import PE_HASH
import match_decomp as match
from x86_call_abi import decode_reachable


ADDRESS = 0x4e64c0
ALLOC = 0x54e221
CONSTRUCT = 0x532c40
GRAPHICS = 0x57c5c8
ARCHIVE = 0x2bf44
SLICE_COUNT = 16
FLAGS = ['/O2', '/GX', '/TP']
EXPORT = match.ROOT / 'decompiled_fastfood2_named_v2/full_game_verification/functions/0x4e64c0.c'
ALLOCATION = re.compile(r'pvVar2 = operator_new\(0x98\);\s*local_c\._0_1_ = (\w+);')
LOAD = re.compile(r'Anim_Load\(pvVar2,\(int\)DAT_0057c5c8,\*\(void \*\*\)\(\(int\)this \+ 0x2bf44\),'
                  r'\s*s_(\w+)_([0-9a-f]{8}),&local_174,(\w+)\);')
STORE = re.compile(r'\*\(undefined4 \*{1,2}\)\(\(int\)this \+ (\w+)\) = puVar3;')


def extract_export(image):
    pseudocode = EXPORT.read_text()
    allocations = list(ALLOCATION.finditer(pseudocode))
    if len(allocations) != 159:
        raise ValueError(f'expected 159 exported allocation sites, got {len(allocations)}')
    rows = []
    for i, allocation in enumerate(allocations):
        end = allocations[i + 1].start() if i + 1 < len(allocations) else len(pseudocode)
        block = pseudocode[allocation.end():end]
        calls = list(LOAD.finditer(block))
        store = STORE.search(block)
        if len(calls) != 1 or store is None or store.start() < calls[0].end():
            raise ValueError(f'unmodeled exported constructor/store in row {i}')
        call = calls[0]
        state, asset, mode, destination = (int(allocation[1], 0), int(call[2], 16), int(call[3], 0), int(store[1], 0))
        asset_name = match.read_va(image, asset, 100).split(b'\0', 1)[0].decode('ascii')
        slug = re.sub(r'[^a-zA-Z0-9]', '_', asset_name)
        if state != i + 4 or slug != call[1] or not asset_name.lower().endswith('.ani'):
            raise ValueError(f'exported animation state/name differs in row {i}')
        remainder = re.sub(r'local_c = \(uint\)local_c\._1_3_ << 8;', '', block[store.end():]).strip()
        rows.append({'asset_address': asset, 'asset_name': asset_name, 'mode': mode,
                     'destination_offset': destination, 'eh_state': state,
                     'following_startup_code': i < len(allocations) - 1 and bool(remainder)})
    return rows


def operand_value(instruction, operand, resolve):
    if operand.type == x86.X86_OP_IMM:
        return resolve(instruction, instruction.imm_offset, operand.imm)
    if operand.type == x86.X86_OP_MEM and not (operand.mem.base or operand.mem.index):
        return resolve(instruction, instruction.disp_offset, operand.mem.disp)
    return None


def memory_role(instruction, operand, resolve):
    if operand_value(instruction, operand, resolve) == GRAPHICS:
        return 'graphics', GRAPHICS
    if operand.mem.disp == ARCHIVE and operand.mem.base and not operand.mem.index:
        return 'archive', operand.mem.base
    return None


def destination_offset(instructions, index, receiver):
    insn = instructions[index]
    if insn.id != x86.X86_INS_MOV or insn.operands[0].type != x86.X86_OP_MEM:
        return None
    dest, source = insn.operands[:2]
    base = dest.mem.base
    if source.type != x86.X86_OP_REG or source.reg != x86.X86_REG_EAX or dest.mem.index:
        return None
    if base == receiver:
        return dest.mem.disp
    if not base or base in (x86.X86_REG_ESP, x86.X86_REG_EBP):
        return None
    setup = next((previous for previous in reversed(instructions[:index]) if base in previous.regs_access()[1]), None)
    if setup and setup.id == x86.X86_INS_LEA and setup.operands[1].mem.base == receiver and not setup.operands[1].mem.index:
        return dest.mem.disp + setup.operands[1].mem.disp
    return None


def machine_rows(instructions, resolve=lambda instruction, offset, raw: raw):
    calls = [(index, operand_value(insn, insn.operands[0], resolve))
             for index, insn in enumerate(instructions) if insn.id == x86.X86_INS_CALL]
    rows = []
    for call_index, (index, target) in enumerate(calls):
        if target != CONSTRUCT:
            continue
        first, allocator = calls[call_index - 1]
        alloc_push = next((insn for insn in reversed(instructions[max(0, first - 5):first])
                           if insn.id == x86.X86_INS_PUSH), None)
        if allocator != ALLOC or alloc_push is None or operand_value(alloc_push, alloc_push.operands[0], resolve) != 0x98:
            raise ValueError(f'constructor at {instructions[index].address:#x} lacks a 0x98 allocation')
        registers = {x86.X86_REG_EAX: ('allocation', 0)}
        pushes = []
        for insn in instructions[first + 1:index]:
            operands = insn.operands
            if insn.id in (x86.X86_INS_MOV, x86.X86_INS_LEA) and operands[0].type == x86.X86_OP_REG:
                source = operands[1]
                value = None
                if source.type == x86.X86_OP_REG:
                    value = registers.get(source.reg)
                elif source.type == x86.X86_OP_MEM:
                    if insn.id == x86.X86_INS_MOV:
                        value = memory_role(insn, source, resolve)
                    if insn.id == x86.X86_INS_LEA and source.mem.base in (x86.X86_REG_ESP, x86.X86_REG_EBP):
                        value = ('status', source.mem.disp)
                registers[operands[0].reg] = value
            if insn.id == x86.X86_INS_PUSH:
                src = operands[0]
                value = registers.get(src.reg) if src.type == x86.X86_OP_REG else None
                if src.type == x86.X86_OP_MEM:
                    value = memory_role(insn, src, resolve)
                pushes.append(value or ('immediate', operand_value(insn, src, resolve)))
        kinds = [role for role, _ in pushes]
        if kinds != ['immediate', 'status', 'immediate', 'archive', 'graphics'] or registers.get(x86.X86_REG_ECX) != ('allocation', 0):
            raise ValueError(f'constructor argument staging differs at {instructions[index].address:#x}: {pushes}')
        last = calls[call_index + 1][0] if call_index + 1 < len(calls) else len(instructions)
        stores = ((j, destination_offset(instructions, j, pushes[3][1])) for j in range(index + 1, last))
        store = next(((j, offset) for j, offset in stores if offset is not None), None)
        if store is None:
            raise ValueError(f'constructor result store differs at {instructions[index].address:#x}')
        destination = instructions[store[0]]
        rows.append({'asset_address': pushes[2][1], 'mode': pushes[0][1],
                     'destination_offset': store[1],
                     'allocation_start': alloc_push.address, 'constructor_call': instructions[index].address,
                     'destination_end': destination.address + destination.size})
    return rows


def compare_rows(expected, actual):
    if len(expected) != len(actual):
        raise ValueError(f'animation row count differs: {len(actual)} vs {len(expected)}')
    for i, (want, got) in enumerate(zip(expected, actual)):
        for key in ('asset_address', 'mode', 'destination_offset'):
            if want[key] != got[key]:
                raise ValueError(f'animation row {i} {key} differs: {got[key]} vs {want[key]}')


def render_rows(rows):
    text = []
    for row in rows:
        text.append(f'    Slot({row["destination_offset"]:#x}) = new Animation(DAT_0057c5c8, '
                    f'archive, STR_{row["asset_address"]:08x}, &status, {row["mode"]});')
        if row['following_startup_code']:
            text.append('    // Other Game_Construct code intervenes here.')
    return '\n'.join(text) + '\n'


def render_slice(rows):
    end = max(row['destination_offset'] for row in rows) + 4
    declarations = [f'extern "C" const char STR_{asset:08x}[];'
                    for asset in dict.fromkeys(row['asset_address'] for row in rows)]
    return '''void *operator new(unsigned int);
struct Animation {
    unsigned char payload[0x98];
    Animation(int, void *, const char *, int *, int);
};
extern "C" int DAT_0057c5c8;
''' + '\n'.join(declarations) + f'''
struct GameAnimationSlice {{
    unsigned char prefix[{ARCHIVE:#x}];
    void *archive;
    unsigned char remaining[{end - ARCHIVE - 4:#x}];
    __forceinline Animation *&Slot(unsigned offset) {{
        return *reinterpret_cast<Animation **>(reinterpret_cast<unsigned char *>(this) + offset);
    }}
    void Load();
}};
void GameAnimationSlice::Load()
{{
    int status;
''' + render_rows(rows) + '}\n'


def check_object(obj, expected):
    data, sections, symbols = match.parse_coff(obj)
    entry = next((symbol for symbol in symbols if symbol and symbol['name'] == '?Load@GameAnimationSlice@@QAEXXZ'), None)
    if entry is None:
        raise ValueError('emitted animation slice entry is absent')
    section = sections[entry['section'] - 1]
    raw = section['raw'][entry['value']:]
    addresses = {'??2@YAPAXI@Z': (ALLOC, 0x14), '??0Animation@@QAE@HPAXPBDPAHH@Z': (CONSTRUCT, 0x14),
                 '_DAT_0057c5c8': (GRAPHICS, 0x06)}
    addresses.update({f'_STR_{row["asset_address"]:08x}': (row['asset_address'], 0x06) for row in expected})
    relocations = {}
    for pos, symbol_index, kind in match.section_relocations(data, section):
        symbol = symbols[symbol_index]['name']
        if symbol in addresses:
            target, wanted_kind = addresses[symbol]
            if kind != wanted_kind:
                raise ValueError(f'wrong COFF relocation kind for {symbol}')
            addend, = struct.unpack_from('<i', section['raw'], pos)
            relocations[pos - entry['value']] = target + addend
    instructions, _, undecodable, indirect = decode_reachable(raw, 0)
    if undecodable or indirect:
        raise ValueError('emitted slice has undecoded or indirect branches')
    actual = machine_rows(instructions, lambda insn, offset, value: relocations.get(insn.address + offset, value))
    compare_rows(expected, actual)
    return {'row_count': len(actual), 'object_sha256': match.file_sha256(obj),
            'reachable_code_bytes': max(insn.address + insn.size for insn in instructions),
            'sections': [{'name': sec['name'], 'size': len(sec['raw'])} for sec in sections if sec['raw']]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True, help='fresh scratch directory')
    parser.add_argument('--compile', action='store_true', help='compile and validate the representative slice')
    args = parser.parse_args()
    try:
        if match.file_sha256(match.GAME) != PE_HASH:
            raise ValueError('expected pinned executable')
        image = match.pe_image(match.GAME)
        extent = match.function_length(ADDRESS)
        instructions = decode_reachable(match.read_va(image, ADDRESS, extent), ADDRESS)[0]
        rows = extract_export(image)
        actual = machine_rows(instructions)
        compare_rows(rows, actual)
        constructor = decode_reachable(match.read_va(image, CONSTRUCT, match.function_length(CONSTRUCT)), CONSTRUCT)[0]
        exits = {insn.operands[0].imm if insn.operands else 0 for insn in constructor if insn.id == x86.X86_INS_RET}
        if exits != {20}:
            raise ValueError(f'Anim_Load ABI cleanup differs: {exits}')
        slice_rows = rows[:SLICE_COUNT]
        if any(row['following_startup_code'] for row in slice_rows[:-1]):
            raise ValueError('selected slice crosses unrelated startup code')
        output = args.out.resolve()
        output.mkdir(parents=True)
        source = output / 'animation_slice.cpp'
        source.write_text(render_slice(slice_rows))
        (output / 'animation_rows.inc').write_text(render_rows(rows))
        report = {'executable_sha256': PE_HASH, 'pseudocode_sha256': match.file_sha256(EXPORT),
                  'function_byte_extent': extent, 'animation_row_count': len(actual),
                  'constructor_callee_cleanup_bytes': 20,
                  'interleaved_startup_gaps': sum(row['following_startup_code'] for row in rows),
                  'animation_rows': [{**row, **machine} for row, machine in zip(rows, actual)],
                  'slice_reference_bytes': actual[SLICE_COUNT - 1]['destination_end'] - actual[0]['allocation_start'],
                  'slice_source_sha256': match.file_sha256(source), 'strict_match': False}
        if args.compile:
            obj = source.with_suffix('.obj')
            match.compile_candidate(source, match.DEFAULT_VC6.resolve(), obj, FLAGS)
            report.update(compiled_slice=check_object(obj, slice_rows), flags=FLAGS,
                          compiler=match.compiler_provenance(match.DEFAULT_VC6))
        (output / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
        print(f'{len(rows)} original rows validated, {SLICE_COUNT}-row slice: {output / "report.json"}')
        return 0
    except (ValueError, OSError, struct.error, subprocess.TimeoutExpired) as error:
        parser.exit(1, f'animation pilot: {error}\n')


if __name__ == '__main__':
    raise SystemExit(main())
