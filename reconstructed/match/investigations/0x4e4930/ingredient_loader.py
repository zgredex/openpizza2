#!/usr/bin/env python3
"""Generate the matching VC6 recipe for Ingredient_LoadMarketTable."""

import argparse
import collections
import json
from pathlib import Path
import re
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[4] / "tools"))
from decomp_fixtures import PE_HASH
import match_decomp as match
from x86_call_abi import decode_reachable

ADDRESS = 0x4e4930
ENTRY = "?LoadMarketTable@IngredientMarket@@QAEXXZ"
FLAGS = ["/O2", "/GX", "/TP"]
EXPORT = match.ROOT / "decompiled_fastfood2_named_v2/full_game_verification/functions/0x4e4930.c"
HANDLER_STUBS = (0x559526, 0x559e3d)
SYMBOLS = {
    "??0Ingredient@@QAE@H@Z": 0x4e4770,
    "??2@YAPAXI@Z": 0x54e221,
    "?Close@ResourceManager@@QAEXPAX@Z": 0x402990,
    "?Configure@Ingredient@@QAEXPADCHHHHNCCCCCC@Z": 0x4e4860,
    "?Open@ResourceManager@@QAEPAXPADH@Z": 0x402290,
    "?Read@ResourceManager@@QAEHPADHPAX@Z": 0x402750,
    "___CxxFrameHandler": 0x54e5f6,
}
PREAMBLE = '''// Ingredient_LoadMarketTable, reconstructed from the pinned named export.
void *operator new(unsigned int);
struct Ingredient {
    unsigned char header[8];
    unsigned short amounts[64];
    unsigned char details[0x50];
    Ingredient(int id);
    void Configure(char *, signed char, int, int, int, int, double,
                   signed char, signed char, signed char, signed char, signed char, signed char);
};
struct ResourceManager {
    void *Open(char *, int);
    int Read(char *, int, void *);
    void Close(void *);
};
extern "C" ResourceManager *DAT_0057c5d8;
extern "C" char STR_00570c50[];
struct IngredientMarket {
    unsigned char header[0xa8];
    Ingredient *entries[86];
    void LoadMarketTable();
};
'''
LOOP = '''void IngredientMarket::LoadMarketTable()
{
    void *file = DAT_0057c5d8->Open(STR_00570c50, 1);
    int index = 0;
    Ingredient **slot = entries;
    do {
        Ingredient *entry = new Ingredient(index + 1);
        int columns = 4;
        unsigned short *high = entry->amounts + 32;
        unsigned short low_amount;
        unsigned short high_amount;
        do {
            int rows = 8;
            do {
                DAT_0057c5d8->Read((char *)&low_amount, 2, file);
                DAT_0057c5d8->Read((char *)&high_amount, 2, file);
                high[-32] = low_amount;
                *high++ = high_amount;
            } while (--rows != 0);
        } while (--columns != 0);
        *slot = entry;
        ++index;
        ++slot;
    } while (index < 86);
    DAT_0057c5d8->Close(file);
    Ingredient *entry;
'''


def source_text():
    exported = EXPORT.read_text()
    tail = exported.split('Resource_Close(DAT_0057c5d8,(int)piVar3);', 1)[1].split('ExceptionList = local_14;', 1)[0]
    pattern = re.compile(r'pvVar2 = ([^;]+);\s*Game_SetBuildingDesc\s*\(pvVar2,(.*?)\)\s*;\s*([^;]+) = pvVar2;', re.S)
    groups = pattern.findall(tail)
    if len(groups) != 86 or pattern.sub('', tail).strip():
        raise ValueError(f'expected 86 configure rows, found {len(groups)}')
    names, calls = [], []
    for i, (load, args, store) in enumerate(groups):
        if i == 0:
            if load != '(void *)*puVar1' or store != '*puVar1':
                raise ValueError('first pointer load/store changed')
        else:
            operand = re.fullmatch(r'\*\(void \*\*\)\(param_1 \+ (\w+)\)', load)
            if not operand or int(operand[1], 0) != 0xa8 + i * 4 or load != store:
                raise ValueError(f'incompatible array slot {i}')
        name, *raw = (value.strip() for value in args.split(','))
        p = [int(value, 0) for value in raw]
        if len(p) != 13 or name != f'DAT_{0x583544+i*4:08x}':
            raise ValueError(f'bad configure row {i}')
        encoded = struct.pack('<II', *p[5:7])
        value, = struct.unpack('<d', encoded)
        price = repr(value)
        if struct.pack('<d', float(price)) != encoded:
            raise ValueError(f'double does not round trip at row {i}')
        flags = [v - 256 if v > 127 else v for v in p[7:]]
        names.append(f'extern "C" char *{name};')
        rendered = ', '.join(map(str, [name, *p[:5], price, *flags]))
        calls.extend([f'    entry = entries[{i}];', f'    entry->Configure({rendered});', f'    entries[{i}] = entry;'])
    return PREAMBLE + '\n'.join(names) + '\n\n' + LOOP + '\n'.join(calls) + '\n}\n'


def original_evidence(image):
    from capstone.x86_const import X86_INS_CALL, X86_OP_IMM
    length = match.function_length(ADDRESS)
    instructions = decode_reachable(match.read_va(image, ADDRESS, length), ADDRESS)[0]
    counts = collections.Counter(i.operands[0].imm for i in instructions
                                if i.id == X86_INS_CALL and i.operands[0].type == X86_OP_IMM)
    if counts != {0x402290: 1, 0x54e221: 1, 0x4e4770: 1, 0x402750: 2, 0x402990: 1, 0x4e4860: 86}:
        raise ValueError('unexpected shipped direct-call counts')
    return length, {hex(a): n for a, n in counts.items()}


def handler_anchor(image):
    # Scan the interval between the corroborated stubs of 0x4e3c00 and
    # 0x4e64c0 without consulting the loader's EH relocation field.
    lo, hi = HANDLER_STUBS
    lo += 10
    raw = match.read_va(image, lo, hi - lo)
    targets = [lo + off for off in range(len(raw) - 9) if raw[off] == 0xb8 and raw[off + 5] == 0xe9
               and lo + off + 10 + struct.unpack_from('<i', raw, off + 6)[0] == SYMBOLS['___CxxFrameHandler']]
    if len(targets) != 1:
        raise ValueError('expected exactly one independently bracketed loader EH handler')
    return targets[0]


def compare_tail(image, obj, result):
    _, sections, symbols = match.parse_coff(obj)
    entry = next(symbol for symbol in symbols if symbol and symbol['name'] == ENTRY)
    section = sections[entry['section'] - 1]
    relocations = [r for r in result['relocations'] if r['section_index'] == section['index']]
    close_call = [int(r['site'], 16) + 4 for r in relocations
                  if r['kind'] == 'REL32' and r['target'] == '0x402990']
    start = ADDRESS + 0x11b
    if close_call != [start] or result['candidate_length'] != result['length']:
        return {'equal': False, 'issue': 'loader tail placement or extent differs'}
    length = result['length'] - (start - ADDRESS)
    offset = entry['value'] + start - ADDRESS
    linked = bytearray(section['raw'][offset:offset + length])
    for relocation in relocations:
        site = int(relocation['site'], 16)
        if site >= start:
            if site + 4 > start + length or relocation['expected'] is None:
                return {'equal': False, 'issue': 'unsupported relocation in loader tail'}
            struct.pack_into('<I', linked, site - start, int(relocation['expected'], 16))
    original = match.read_va(image, start, length)
    return {'equal': linked == original, 'start': hex(start), 'length': length}


def verify_object(image, source, obj, vc6, length):
    overrides = {**SYMBOLS, '$L403': handler_anchor(image)}
    result = match.match_object(ADDRESS, obj, overrides, length, ENTRY, True, True, True)
    result.update(match.match_provenance(source, vc6, FLAGS, overrides, True, True, True))
    result['pseudocode_sha256'] = match.file_sha256(EXPORT)
    result['relocated_tail'] = compare_tail(image, obj, result)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', required=True, type=Path, help='fresh scratch directory')
    parser.add_argument('--verify', action='store_true', help='compile once and retain the strict matcher receipt')
    parser.add_argument('--vc6', type=Path, default=match.DEFAULT_VC6)
    args = parser.parse_args()
    try:
        if match.file_sha256(match.GAME) != PE_HASH:
            raise ValueError('expected pinned game image')
        image = match.pe_image(match.GAME)
        length, calls = original_evidence(image)
        output = args.out.resolve()
        output.mkdir(parents=True)
        source = output / 'ingredient.cpp'
        source.write_text(source_text())
        print(f'{source}: {length} original bytes, {calls}', flush=True)
        if not args.verify:
            return 0
        obj = source.with_suffix('.obj')
        vc6 = args.vc6.resolve()
        match.compile_candidate(source, vc6, obj, FLAGS)
        result = verify_object(image, source, obj, vc6, length)
        (output / 'result.json').write_text(json.dumps(result, indent=2) + '\n')
        print(f"strict={result['strict_match']}, differences={result['difference_count']}, "
              f"tail={result['relocated_tail']}: {output / 'result.json'}")
        return int(not result['strict_match'])
    except (OSError, ValueError, struct.error) as error:
        parser.exit(1, f'ingredient loader: {error}\n')


if __name__ == '__main__':
    raise SystemExit(main())
