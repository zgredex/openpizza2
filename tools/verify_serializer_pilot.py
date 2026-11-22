#!/usr/bin/env python3
"""Generate and strictly check serializers with known VC6 stream ABI."""

import argparse
from concurrent.futures import ThreadPoolExecutor
from functools import lru_cache
import json
from pathlib import Path
import re
import struct
import subprocess

from decomp_fixtures import PE_HASH
import match_decomp as match
from x86_call_abi import decode_reachable


EXPORTS = match.ROOT / 'decompiled_fastfood2_named_v2/full_game_verification/functions'
TARGETS = (0x50f6b0, 0x50f750, 0x4dd4f0, 0x4dd590, 0x4d3a50, 0x4d3ba0, 0x4ec4f0, 0x47b9e0)
FLAGS = ['/O2', '/TP']
METHODS = {
    'CRT_Istream_Read': ('IStream', 'Read', 'void', ('void *', 'int'), 0x54cbc1),
    'CRT_Ostream_Write': ('OStream', 'Write', 'void', ('void *', 'int'), 0x54cc2b),
    'IDMap_Lookup': ('IDMap', 'Lookup', 'int', ('int', 'int *'), 0x4017f0),
    'Game_GetPlayerBySlot': ('GamePlayers', 'GetPlayerBySlot', 'int', ('int',), 0x488be0),
    'Game_FindCompanyIndex': ('CompanyIndex', 'FindCompanyIndex', 'int', ('int',), 0x4dde70),
    'Game_RemoveIDMapEntry': ('WorldIds', 'LookupSavedId', 'int', ('int',), 0x4eacb0),
    'StatsPeriodReport_Save': ('StatsPeriodReport', 'Save', 'void', ('void *',), 0x401200),
    'Array_FindIndexByPtr': ('PointerArray', 'FindIndexByPtr', 'int', ('int',), 0x4d7e90),
    'Map_LookupLinear': ('Map', 'LookupLinear', 'int', ('int',), 0x401930),
    'ConstructionOrder_Save': ('ConstructionOrder', 'Save', 'void', ('void *',), 0x4e5e30),
    'List_Add': ('List', 'Add', 'int', ('unsigned int',), 0x4014b0),
}
GLOBALS = {'DAT_0057dfbc': 'int', 'DAT_0057c668': 'int', 'DAT_0057c670': 'void *', 'DAT_0057c5cc': 'void *'}
TYPES = {'undefined1': 'unsigned char', 'undefined2': 'unsigned short', 'undefined4': 'unsigned int', 'uint': 'unsigned int'}
PARAMETER_TYPES = {'void', 'int', 'unsigned int', 'char', 'signed char', 'unsigned char', 'short', 'unsigned short'}
CALL = re.compile(r'\b(' + '|'.join(METHODS) + r')\s*\(')
EARLY_DEFAULT = re.compile(
    r'if \((DAT_[0-9a-f]{8}) < (0x[0-9a-f]+|[1-9][0-9]*)\) \{\s*'
    r'(DAT_[0-9a-f]{8} = [^;]+;)\s*return;\s*\}\s*'
    r'(CRT_Istream_Read\([^;]+;)\s*return;\s*$'
)
SAVE_STACK_TEMP = re.compile(
    r'(\bthis_00 = param_1;\s*)local_4 = this;\s*(CRT_Ostream_Write\()param_1,'
)


def read_arguments(text, start):
    args, depth, begin = [], 1, start
    for index in range(start, len(text)):
        char = text[index]
        if depth == 1 and char in ',)':
            args.append(' '.join(text[begin:index].split()))
            if char == ')':
                return args, index + 1
            begin = index + 1
        elif char == '(':
            depth += 1
        elif char == ')':
            depth -= 1
    raise ValueError('unterminated serializer call')


def parameter_type(argument, name, *, pointer=False):
    declaration = re.fullmatch(r'((?:signed |unsigned )?\w+)(?:\s*(\*))?\s*' + name, argument)
    if declaration:
        base = TYPES.get(declaration[1], declaration[1])
        if base in PARAMETER_TYPES and (declaration[2] or (base != 'void' and not pointer)):
            return base + ' *' if declaration[2] else base
    raise ValueError(f'unsupported serializer parameter {argument!r}')


def normalize_save_stack_temp(body):
    setup = SAVE_STACK_TEMP.search(body)
    if setup:
        # The prologue's push ecx reserves this slot. Save paths replace the
        # value before passing the address to the stream's write method.
        uses = list(re.finditer(r'\blocal_4\b', body[setup.end():]))
        if len(uses) == 2:
            follow = body[setup.end() + uses[0].start():]
            if (re.match(r'local_4 = [^;]+;\s*CRT_Ostream_Write\(this_00,&local_4,4\);', follow)
                    and len(re.findall(r'\blocal_4\b', follow)) == 2):
                return body[:setup.start()] + setup[1] + setup[2] + 'this_00,' + body[setup.end():]
    return body


def translate(pseudocode, expected_name):
    clean = re.sub(r'//[^\n]*|/\*.*?\*/', '', pseudocode, flags=re.S).strip()
    function = re.fullmatch(r'void\s+__thiscall\s+(\w+)\s*\((.*?)\)\s*\{(.*)\}', clean, re.S)
    if not function or function[1] != expected_name:
        raise ValueError('unsupported serializer signature or named export')
    parameters = [' '.join(arg.split()) for arg in function[2].split(',')]
    if len(parameters) not in (2, 3):
        raise ValueError('unsupported serializer parameter count')
    parameter_type(parameters[0], 'this', pointer=True)
    stream_arg = parameter_type(parameters[1], 'param_1', pointer=True)
    extra_arg = ''
    if len(parameters) == 3:
        typ = parameter_type(parameters[2], 'param_2')
        separator = '' if typ.endswith('*') else ' '
        extra_arg = f',{typ}{separator}param_2'
    body = re.sub(r'\b(?:undefined1|undefined2|undefined4|uint)\b', lambda found: TYPES[found[0]], function[3])
    body = normalize_save_stack_temp(body)
    if expected_name == 'GameCalendar_Load':
        # Its shipped conditional falls through into the new-version read.
        trailer = EARLY_DEFAULT.search(body)
        if trailer is None or not int(trailer[2], 0) > 0:
            raise ValueError('calendar version trailer differs from the typed recipe')
        version, minimum, default, read = trailer.groups()
        body = (body[:trailer.start()] + f'if ({version} > {int(minimum, 0) - 1}) {{\n'
                f'    {read}\n    return;\n  }}\n  {default}\n  return;\n')
    aliases = set(re.findall(r'\bDAT_[0-9a-f]{8}\b', body))
    if aliases - GLOBALS.keys():
        raise ValueError(f'unmodeled serializer globals: {sorted(aliases - GLOBALS.keys())}')
    # Ghidra can print addition on a void* global as a byte offset.
    body = re.sub(r'\(void \*\)\((DAT_[0-9a-f]{8})(\s*[+-]\s*(?:0x[0-9a-f]+|\d+))\)',
                  lambda term: (f'(void *)((int){term[1]}{term[2]})'
                                if GLOBALS[term[1]] == 'void *' else term[0]), body)
    used, calls, snippets, cursor = {}, [], [], 0
    while found := CALL.search(body, cursor):
        name = found[1]
        owner, method, result, parameter_types, target = METHODS[name]
        args, end = read_arguments(body, found.end())
        if len(args) != len(parameter_types) + 1:
            raise ValueError(f'wrong argument count for {name}')
        receiver, *values = args
        values = ', '.join(f'({typ})({value})' for value, typ in zip(values, parameter_types))
        snippets.extend((body[cursor:found.start()], f'(({owner} *)({receiver}))->{method}({values})'))
        used[name] = (owner, method, result, parameter_types, target)
        calls.append(target)
        cursor = end
    snippets.append(body[cursor:])
    streams = {method[0] for method in used.values() if method[0] in {'IStream', 'OStream'}}
    if len(streams) != 1:
        raise ValueError('expected exactly one stream ABI')
    stream = streams.pop()
    if stream_arg == 'void *' and not re.search(r'\bparam_1\s*=(?!=)', body):
        stream_arg = f'{stream} *'
    lines = [f'/* Generated from the named export of {expected_name}. */']
    for owner, method, result, parameters, _ in used.values():
        lines.append(f'struct {owner} {{ {result} {method}({", ".join(parameters)}); }};')
    lines.extend(f'extern "C" {GLOBALS[name]} {name};' for name in sorted(aliases))
    lines.extend((f'struct Record {{ void Run({stream_arg}param_1{extra_arg}); }};',
                  f'void Record::Run({stream_arg}param_1{extra_arg})\n{{' + ''.join(snippets) + '}'))
    return '\n'.join(lines) + '\n', calls, used, 8 if extra_arg else 4


@lru_cache(maxsize=None)
def return_width(address):
    from capstone.x86_const import X86_INS_RET

    image = match.pe_image(match.GAME)
    original = match.read_va(image, address, match.function_length(address))
    instructions, _, _, _ = decode_reachable(original, address)
    return {i.operands[0].imm if i.operands else 0 for i in instructions if i.id == X86_INS_RET}


def list_add_witness(image):
    from capstone.x86_const import X86_INS_CALL, X86_INS_MOV, X86_INS_PUSH, X86_OP_IMM, X86_OP_REG, X86_REG_ECX

    start, call = 0x47b5cb, 0x47b5d6
    instructions, _, undecodable, _ = decode_reachable(match.read_va(image, start, call + 5 - start), start)
    pushes = [i for i in instructions if i.id == X86_INS_PUSH]
    receiver = any(i.id == X86_INS_MOV and i.operands[0].type == X86_OP_REG and i.operands[0].reg == X86_REG_ECX
                   for i in instructions)
    last = instructions[-1] if instructions else None
    if (undecodable or len(pushes) != 1 or not receiver or last is None or last.address != call
            or last.id != X86_INS_CALL or last.operands[0].type != X86_OP_IMM
            or last.operands[0].imm != METHODS['List_Add'][-1]):
        raise ValueError('List_Add caller witness no longer confirms the ECX receiver and one stack argument')
    return {'call_site': hex(call), 'stack_argument_bytes': 4, 'receiver': 'ecx'}


def gen_candidate(address, image, names):
    from capstone import CS_GRP_CALL
    from capstone.x86_const import X86_INS_CALL, X86_INS_RET, X86_OP_IMM

    export = EXPORTS / f'{address:#x}.c'
    export_name = names.get(hex(address))
    if not export_name:
        raise ValueError('serializer address is absent from the original symbol index')
    source, calls, methods, cleanup = translate(export.read_text(), export_name)
    length = match.function_length(address)
    instructions, _, undecodable, indirect_jump = decode_reachable(match.read_va(image, address, length), address)
    direct = [i.operands[0].imm for i in instructions if i.id == X86_INS_CALL and i.operands[0].type == X86_OP_IMM]
    returns = {i.operands[0].imm if i.operands else 0 for i in instructions if i.id == X86_INS_RET}
    modeled = set(calls)
    unmodeled = dict.fromkeys(target for target in direct if target not in modeled)
    if unmodeled:
        labels = ', '.join(f'{names.get(hex(target), "unnamed")} ({target:#x})' for target in unmodeled)
        raise ValueError(f'unmodeled serializer callees: {labels}')
    if undecodable or indirect_jump or direct != calls or sum(i.group(CS_GRP_CALL) for i in instructions) != len(calls):
        raise ValueError('export does not preserve the shipped ordered direct calls')
    if returns != {cleanup}:
        raise ValueError(f'original cleanup {returns} differs from declared {cleanup}')
    for name, (_, _, _, parameters, callee) in methods.items():
        if names.get(hex(callee)) != name or return_width(callee) != {len(parameters) * 4}:
            raise ValueError(f'named callee or stack width differs for {name} at {callee:#x}')
    evidence = {'address': hex(address), 'name': export_name, 'length': length,
                'direct_calls': len(calls), 'pseudocode_sha256': match.file_sha256(export)}
    if 'List_Add' in methods:
        evidence['abi_witnesses'] = {'List_Add': list_add_witness(image)}
    return source, methods, evidence


def check_object(address, obj, methods, source, vc6, length):
    _, _, symbols = match.parse_coff(obj)
    entries = [symbol['name'] for symbol in symbols if symbol and symbol['section'] > 0
               and symbol['name'].startswith('?Run@Record@@')]
    if len(entries) != 1:
        raise ValueError('expected one compiler entry symbol')
    targets = {f'?{method}@{owner}@@': target for owner, method, _, _, target in methods.values()}
    overrides = {}
    for symbol in symbols:
        if symbol and symbol['section'] == 0:
            for prefix, target in targets.items():
                if symbol['name'].startswith(prefix):
                    overrides[symbol['name']] = target
    if set(overrides.values()) != set(targets.values()):
        raise ValueError('COFF did not emit the expected typed call symbols')
    result = match.match_object(address, obj, overrides, length, entries[0], True, True, True)
    result.update(match.match_provenance(source, vc6, FLAGS, overrides, True, True, True))
    return result


def build(address, out, image, names, vc6, verify):
    row = {'address': hex(address), 'name': names.get(hex(address)), 'length': None}
    try:
        row['length'] = match.function_length(address)
        text, methods, row = gen_candidate(address, image, names)
        source = out / f'{address:#x}.cpp'
        source.write_text(text)
        row.update(status='generated', source_sha256=match.file_sha256(source))
        if verify:
            obj = source.with_suffix('.obj')
            match.compile_candidate(source, vc6, obj, FLAGS)
            result = check_object(address, obj, methods, source, vc6, row['length'])
            receipt = source.with_suffix('.match.json')
            receipt.write_text(json.dumps(result, indent=2) + '\n')
            row.update(status='strict' if result['strict_match'] else 'miss', receipt=receipt.name,
                       **{key: result.get(key) for key in ('first_difference', 'difference_count', 'candidate_length',
                                                           'strict_issues', 'relocation_issues')})
    except (ValueError, OSError, struct.error, subprocess.TimeoutExpired) as error:
        row.update(status='error', error=str(error))
    return row


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--verify', action='store_true')
    parser.add_argument('--jobs', type=int, choices=range(1, 5), default=1)
    parser.add_argument('--address', type=lambda value: int(value, 0), action='append', help='named indexed serializer')
    args = parser.parse_args()
    if match.file_sha256(match.GAME) != PE_HASH:
        parser.exit(1, 'serializer pilot requires the pinned PE\n')
    targets = dict.fromkeys(args.address or TARGETS)
    if len(targets) > len(TARGETS):
        parser.error(f'at most {len(TARGETS)} serializers per invocation')
    output = args.out.resolve()
    output.mkdir(parents=True)
    names = json.loads(match.SYMBOL_INDEX.read_text())
    image = match.pe_image(match.GAME)
    vc6 = match.DEFAULT_VC6.resolve()
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        rows = list(pool.map(lambda address: build(address, output, image, names, vc6, args.verify), targets))
    for row in rows:
        print(f"{row['address']} {row['name']} {row['status']} {row['length']} bytes {row.get('error', '').splitlines()[:1]}")
    report = {'executable_sha256': PE_HASH, 'flags': FLAGS, 'functions': rows,
              'strict_bytes': sum(row['length'] for row in rows if row['status'] == 'strict')}
    (output / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    return int(any(row['status'] == 'error' for row in rows))


if __name__ == '__main__':
    raise SystemExit(main())
