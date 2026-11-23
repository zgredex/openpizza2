#!/usr/bin/env python3
"""Generate the full typed Game_Construct candidate in a scratch directory."""

import argparse
from collections import Counter
import json
from pathlib import Path
import re
import struct
import subprocess

import animation_pilot as animation
from compare_vc6_unwind import Coff, compare as compare_unwind


match = animation.match
x86 = animation.x86
ENTRY = '??0Game@@QAE@PAX@Z'
HANDLER = 0x559e3d  # Independently bracketed by the neighboring constructor stubs.
KNOWN_CALLS = {0x4013a0: 1, 0x54dd83: 2, 0x54e221: 162, 0x53c7f0: 3, 0x532c40: 159,
               0x534ac0: 3, 0x534b30: 3, 0x5338c0: 11, 0x54f140: 1}
SYMBOL_PREFIXES = {
    '??0StartupList@@': 0x4013a0,
    '??1StartupList@@': 0x401480,
    '??0Sprite@@': 0x53c7f0,
    '??0Animation@@': 0x532c40,
    '??2@YAPAXI@Z': 0x54e221,
    '??3@YAXPAX@Z': 0x54dd78,
    '?GetRect@Animation@@': 0x534ac0,
    '?SetPointPairs@Animation@@': 0x534b30,
    '?FindFreeSlot@Animation@@': 0x5338c0,
    '_String_Format': 0x54dd83,
    '__ftol': 0x54f140,
    '___CxxFrameHandler': 0x54e5f6,
    '??_7Game@@6B@': 0x55c5d0,
}
FIELD_COPY = re.compile(r'\*\(undefined4 \*\)\(\(int\)this \+ (0x[0-9a-f]+)\) = '
                        r'(?:\*\(undefined4 \*\)\(\(int\)this \+ (0x[0-9a-f]+)\)|(0));')
STATE_RESET = r'local_c = \(uint\)local_c\._1_3_ << 8;'


DECLARATIONS = '''void *operator new(unsigned int);
extern "C" int __cdecl String_Format(char *, const char *, ...);
extern "C" char * __cdecl strcpy(char *, const char *);
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(strcpy, sqrt)

struct StartupList {
    unsigned int storage[7];
    StartupList(unsigned int);
    ~StartupList();
};
struct Sprite {
    virtual ~Sprite();
    unsigned char storage[0x4c];
    Sprite(void *, void *, const char *, int *, int, void *, int);
};
struct Animation {
    unsigned char storage[0x98];
    Animation(int, void *, const char *, int *, int);
    void GetRect(int, double *, double *, double *, double *);
    void SetPointPairs(int, double *, double *, double *, double *);
    int FindFreeSlot(int);
};
struct NameRecord {
    signed char marker;
    char text[51];
    unsigned int flags[5];
};

extern "C" void *DAT_0057c5c8;
extern "C" Sprite *DAT_005806ec[8];
extern "C" Sprite *DAT_0058070c[8];
extern "C" unsigned int DAT_0058072c;
extern "C" Sprite *DAT_00580730;
extern "C" unsigned int DAT_00580a48;
extern "C" const char STR_00579aec[];
extern "C" const char STR_005718b8[];
extern "C" const char STR_005718a8[];
extern "C" const char STR_00571898[];

struct Game {
    virtual ~Game();
    unsigned char beforeList[0x2c3f8 - 4];
    StartupList list;
    unsigned char afterList[0x2f890 - 0x2c414];
    Game(void *);

    __forceinline unsigned char *Offset(unsigned offset) {
        return reinterpret_cast<unsigned char *>(this) + offset;
    }
    __forceinline unsigned int &Dword(unsigned offset) { return *reinterpret_cast<unsigned int *>(Offset(offset)); }
    __forceinline int &Integer(unsigned offset) { return *reinterpret_cast<int *>(Offset(offset)); }
    __forceinline unsigned short &Word(unsigned offset) { return *reinterpret_cast<unsigned short *>(Offset(offset)); }
    __forceinline unsigned char &Byte(unsigned offset) { return *Offset(offset); }
    __forceinline NameRecord &Name(unsigned offset) { return *reinterpret_cast<NameRecord *>(Offset(offset)); }
    __forceinline void *&Pointer(unsigned offset) { return *reinterpret_cast<void **>(Offset(offset)); }
    __forceinline Animation *&Slot(unsigned offset) { return *reinterpret_cast<Animation **>(Offset(offset)); }
    __forceinline void *Archive() { return Pointer(0x2bf44); }
};
'''

PREFIX = '''Game::Game(void *archive) : list(0)
{
    int coordinates[8];
    char spriteName[256];
    int status;
    double x, y, p, q;

    coordinates[1] = 0xab;
    coordinates[3] = 0xab;
    coordinates[7] = 0xab;
    Pointer(0x2bf44) = archive;
    Byte(0x2bf48) = 0xff;
    Dword(0x2f87c) = 0;
    Dword(0x2f880) = 0;
    Dword(0x2f884) = 0;
    Dword(0x2f88c) = 0;
    Dword(0x2f888) = 0;
    DAT_0058072c = 0;
    DAT_00580a48 = 0;
    Dword(0x1c) = 0;
    coordinates[0] = 0x6c;
    coordinates[2] = 0x56;
    coordinates[4] = 0x6b;
    coordinates[5] = 0xaa;
    coordinates[6] = 0x56;
    Dword(0x20) = 0;
    int i = 0;
    do {
        String_Format(spriteName, STR_005718b8, i);
        DAT_005806ec[i] = new Sprite(DAT_0057c5c8, Archive(), spriteName, 0, 0, 0, 0);
        String_Format(spriteName, STR_005718a8, i);
        DAT_0058070c[i] = new Sprite(DAT_0057c5c8, Archive(), spriteName, 0, 0, 0, 0);
        ++i;
    } while (i < 8);
    DAT_00580730 = new Sprite(DAT_0057c5c8, Archive(), STR_00571898, &status, 0, 0, 0);
    if (status) {
        delete DAT_00580730;
        DAT_00580730 = 0;
    }

    unsigned short *indexWord = &Word(0x2e4f4);
    NameRecord *record = &Name(0x24);
    i = 0;
    do {
        *indexWord = static_cast<unsigned short>(i);
        record->marker = -1;
        strcpy(record->text, STR_00579aec);
        record->flags[0] = 0;
        record->flags[1] = 0;
        record->flags[2] = 0;
        record->flags[3] = 0;
        record->flags[4] = 0;
        ++indexWord;
        ++i;
        ++record;
    } while (i < 2500);

    Dword(0xc) = 0;
    Dword(0x14) = 0;
    Dword(0x10) = 0;
    Dword(0x18) = 0;
    unsigned int *bank = &Dword(0x2c00c);
    i = 0x30;
    do {
        bank[-0x30] = 0;
        bank[0] = 0;
        bank[0x8a] = 0;
        bank[0xba] = 0;
        ++bank;
    } while (--i);
    bank = &Dword(0x2c180);
    i = 0x2d;
    do {
        bank[-0x2d] = 0;
        bank[0] = 0;
        ++bank;
    } while (--i);
    Dword(0x2c3b4) = 0;
    Dword(0x2c3b8) = 0;
    Dword(0x2c3bc) = 0;
    Dword(0x2c3c0) = 0;
    Dword(0x2c3c8) = 0;
    Dword(0x2c3c4) = 0;
    Dword(0x2c3cc) = 0;
    Dword(0x2c3d0) = 0;
    Dword(0x2c3d4) = 0;
    bank = &Dword(0x2c3e8);
    i = 6;
    do {
        bank[-4] = 0;
        bank[0] = 0;
        ++bank;
    } while (--i);
'''

SUFFIX = '''    int *xy = coordinates + 1;
    Animation **pair = &Slot(0x2c3e8);
    i = 4;
    do {
        pair[-4]->GetRect(0, &x, &y, &p, &q);
        const double dx = xy[-1];
        x -= dx;
        const double dy = xy[0];
        y -= dy;
        pair[-4]->SetPointPairs(0, &x, &y, &p, &q);
        pair[0]->GetRect(0, &x, &y, &p, &q);
        x -= dx;
        y -= dy;
        pair[0]->SetPointPairs(0, &x, &y, &p, &q);
        ++pair;
        xy += 2;
    } while (--i);

    Integer(0x2c414) = Slot(0x2c3b8)->FindFreeSlot(-1);
    Integer(0x2c418) = Slot(0x2c3b4)->FindFreeSlot(-1);
    int *right = &Integer(0x2c498);
    int *left = &Integer(0x2c41c);
    i = 6;
    do {
        *left = Slot(0x2c3d4)->FindFreeSlot(-1);
        right[-1] = Slot(0x2c3e8)->FindFreeSlot(-1);
        right[0] = Slot(0x2c3ec)->FindFreeSlot(-1);
        right[1] = Slot(0x2c3f0)->FindFreeSlot(-1);
        right[2] = Slot(0x2c3f4)->FindFreeSlot(-1);
        right[-0x19] = Slot(0x2c3d8)->FindFreeSlot(-1);
        right[-0x18] = Slot(0x2c3dc)->FindFreeSlot(-1);
        right[-0x17] = Slot(0x2c3e0)->FindFreeSlot(-1);
        right[-0x16] = Slot(0x2c3e4)->FindFreeSlot(-1);
        ++left;
        right += 4;
    } while (--i);

    i = 0;
    int *table = &Integer(0x2c4f4);
    do {
        *table = static_cast<int>(2.0 * sqrt(static_cast<double>(0x400000 - i * i)));
        ++i;
        ++table;
    } while (i < 0x800);
}
'''


def render_animation_steps(rows):
    pseudocode = animation.EXPORT.read_text()
    allocations = list(animation.ALLOCATION.finditer(pseudocode))
    instructions = []
    gap_count = 0
    for index, (allocation, row) in enumerate(zip(allocations, rows)):
        destination = row['destination_offset']
        constructor = animation.render_rows([{**row, 'following_startup_code': False}]).strip()
        constructor = constructor.replace('DAT_0057c5c8, archive,', 'reinterpret_cast<int>(DAT_0057c5c8), Archive(),')
        instructions.append('    ' + constructor)
        if not row['following_startup_code']:
            continue
        block = pseudocode[allocation.end():allocations[index + 1].start()]
        store = animation.STORE.search(block)
        gap = re.sub(STATE_RESET, '', block[store.end():]).strip()
        field_copy = FIELD_COPY.fullmatch(gap)
        if field_copy:
            offset, source, _ = field_copy.groups()
            value = f'Dword({source})' if source else '0'
            instructions.append(f'    Dword({offset}) = {value};')
        elif (destination == 0x2c3cc and gap.startswith('Record_GetRect98(puVar3,0,')
              and gap.count('Animation_SetPointPairs') == 1):
            instructions.extend((
                '    Slot(0x2c3cc)->GetRect(0, &x, &y, &p, &q);',
                '    x += 18.0;', '    y -= 14.0;',
                '    Slot(0x2c3cc)->SetPointPairs(0, &x, &y, &p, &q);',
            ))
        else:
            raise ValueError(f'unmodeled startup statements after animation row {index}')
        gap_count += 1
    return '\n'.join(instructions) + '\n', gap_count


def original_rows(image):
    length = match.function_length(animation.ADDRESS)
    code = match.read_va(image, animation.ADDRESS, length)
    decoded, _, undecodable, _ = animation.decode_reachable(code, animation.ADDRESS)
    calls = Counter(insn.operands[0].imm for insn in decoded if insn.id == x86.X86_INS_CALL
                    and insn.operands[0].type == x86.X86_OP_IMM)
    if undecodable or calls != KNOWN_CALLS:
        raise ValueError('shipped constructor direct-call census differs')
    rows = animation.extract_export(image)
    animation.compare_rows(rows, animation.machine_rows(decoded))
    return length, rows


def source_text(rows):
    assets = ''.join(f'extern "C" const char STR_{asset:08x}[];\n'
                     for asset in dict.fromkeys(row['asset_address'] for row in rows))
    body, gaps = render_animation_steps(rows)
    return DECLARATIONS + assets + '\n' + PREFIX + body + SUFFIX, gaps


def compiler_evidence(obj, image, length, rows, output):
    _, _, symbols = match.parse_coff(obj)
    names = {symbol['name'] for symbol in symbols if symbol and symbol['storage'] == 2}
    overrides = {name: target for name in sorted(names) for prefix, target in SYMBOL_PREFIXES.items()
                 if name.startswith(prefix)}
    coff = Coff(obj, overrides)
    entry = coff.symbols.get(ENTRY)
    if not entry or entry['section'] <= 0:
        raise ValueError(f'could not find emitted entry {ENTRY}')
    section = coff.sections[entry['section'] - 1]
    start = entry['section'], entry['value']
    code = section['raw'][start[1]:]
    emitted, _, undecodable, _ = animation.decode_reachable(code, 0)
    if undecodable:
        raise ValueError('emitted constructor has undecodable instructions')

    def resolve(insn, offset, raw):
        relocation = coff.relocations.get((start[0], start[1] + insn.address + offset))
        return coff.resolve(start, insn.address + offset, relocation[1]) if relocation else raw

    original, _, _, _ = animation.decode_reachable(match.read_va(image, animation.ADDRESS, length),
                                                     animation.ADDRESS)
    original_calls = direct_calls(original)
    emitted_calls = direct_calls(emitted, resolve)
    animation.compare_rows(rows, animation.machine_rows(emitted, resolve))

    unwind = compare_unwind(animation.ADDRESS, obj, ENTRY, overrides)
    if unwind['original']['handler'] != HANDLER:
        raise ValueError('original EH prologue disagrees with the independently bracketed handler')
    handler_section, handler_offset = unwind['candidate']['handler']
    handler_names = {name for name, symbol in coff.symbols.items()
                     if symbol['section'] == handler_section and symbol['value'] == handler_offset}
    strict = match.match_object(animation.ADDRESS, obj, {**overrides, **dict.fromkeys(handler_names, HANDLER)},
                                length, ENTRY, strict_symbols=True, strict=True, auto_symbols=True)
    unwind['linked_sections'] = compare_eh_sections(image, coff, unwind)
    for name, report in [('unwind', unwind), ('strict', strict)]:
        (output / f'{name}.json').write_text(json.dumps(report, indent=2) + '\n')
    return {
        'object_sha256': match.file_sha256(obj),
        'candidate_primary_bytes': len(code),
        'verified_animation_sites': len(rows),
        'ordered_direct_calls_match': original_calls == emitted_calls,
        'original_direct_call_count': len(original_calls),
        'candidate_direct_call_count': len(emitted_calls),
        'original_unwind_states': len(unwind['original']['states']),
        'candidate_unwind_states': len(unwind['candidate']['states']),
        'unwind_difference_counts': unwind['difference_counts'],
        'unwind_linked_sections': unwind['linked_sections'],
        'strict_symbol_overrides': {name: hex(address) for name, address in
                                    sorted({**overrides, **dict.fromkeys(handler_names, HANDLER)}.items())},
        'strict_match': strict['strict_match'],
        'first_strict_difference': strict['first_difference'],
    }


def compare_eh_sections(image, coff, unwind):
    bases = {}
    for name in ('handler', 'func_info'):
        index, offset = unwind['candidate'][name]
        address = unwind['original'][name] - offset
        if index in bases and bases[index][0] != address:
            return []
        bases[index] = address, name
    reports = []
    for index, (address, _) in bases.items():
        section = coff.sections[index - 1]
        code = bytearray(section['raw'])
        for (reloc_section, offset), (symbol, kind) in coff.relocations.items():
            if reloc_section != index:
                continue
            target, _ = match.relocation_target(symbol, bases, coff.overrides, True)
            if target is None:
                raise ValueError(f'unresolved EH relocation {symbol["name"]}')
            addend, = struct.unpack_from('<i', code, offset)
            struct.pack_into('<I', code, offset, match.relocation_value(target, addend, address + offset, kind))
        shipped = match.read_va(image, address, len(code))
        differences = [offset for offset, (a, b) in enumerate(zip(shipped, code)) if a != b]
        reports.append({'section': section['name'], 'address': hex(address), 'bytes': len(code),
                        'different_bytes': len(differences),
                        'first_difference_address': hex(address + differences[0]) if differences else None})
    return reports


def direct_calls(instructions, resolve=lambda _insn, _offset, raw: raw):
    return [animation.operand_value(insn, insn.operands[0], resolve)
            for insn in instructions if insn.id == x86.X86_INS_CALL
            and insn.operands[0].type == x86.X86_OP_IMM]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', required=True, type=Path)
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument('--compile', action='store_true', help='compile with the pinned VC6 toolchain and verify')
    mode.add_argument('--object', type=Path, help='verify a previously compiled COFF without launching Wine')
    args = parser.parse_args()
    try:
        if match.file_sha256(match.GAME) != animation.PE_HASH:
            raise ValueError('expected pinned executable')
        image = match.pe_image(match.GAME)
        length, rows = original_rows(image)
        text, gaps = source_text(rows)
        output = args.out.resolve()
        output.mkdir(parents=True)
        source = output / 'game_construct.cpp'
        source.write_text(text)
        report = {'address': hex(animation.ADDRESS), 'length': length, 'entry': ENTRY,
                  'animation_sites': len(rows), 'interleaved_updates': gaps, 'flags': animation.FLAGS,
                  'source_sha256': match.file_sha256(source), 'executable_sha256': animation.PE_HASH,
                  'pseudocode_sha256': match.file_sha256(animation.EXPORT)}
        (output / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
        if args.compile:
            obj = source.with_suffix('.obj')
            vc6 = match.DEFAULT_VC6.resolve()
            match.compile_candidate(source, vc6, obj, animation.FLAGS)
            report['compiler'] = match.compiler_provenance(vc6)
        else:
            obj = args.object
        if obj is not None:
            report.update(compiler_evidence(obj, image, length, rows, output))
            (output / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
        print(f'{len(rows)} animation sites, {gaps} interleaved updates: {output / "report.json"}')
        return 0
    except (OSError, ValueError, struct.error, subprocess.TimeoutExpired) as error:
        parser.exit(1, f'Game_Construct: {error}\n')


if __name__ == '__main__':
    raise SystemExit(main())
