#!/usr/bin/env python3
"""Mine function families by vtable-like references, string references, and opcode shape.

Read-only discovery tool for OpenPizza2, not a matching verifier. Uses Python stdlib
and GNU objdump; outputs only compact derived evidence, not original game data.

Usage:
 python3 tools/mine_pc2_shape_families.py --exe game/fastfood2.exe \
   --symbols decompiled_fastfood2_named_v2/full_game_symbols.json \
   --json /tmp/pc2-shapes.json --report /tmp/pc2-shapes.md
"""
from __future__ import annotations

import argparse
import bisect
import collections
import hashlib
import json
import re
import statistics
import struct
import subprocess
from dataclasses import dataclass
from pathlib import Path

TARGET_SHA = '18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd'


@dataclass(frozen=True)
class Section:
    name: str
    va: int
    vs: int
    raw: int
    rawsz: int


class PE:
    def __init__(self, path: Path):
        self.data = path.read_bytes()
        self.hash = hashlib.sha256(self.data).hexdigest()
        if self.data[:2] != b'MZ':
            raise ValueError('Expected MZ executable')
        pe = struct.unpack_from('<I', self.data, 0x3c)[0]
        if self.data[pe:pe + 4] != b'PE\0\0':
            raise ValueError('Expected PE executable')
        nsects = struct.unpack_from('<H', self.data, pe + 6)[0]
        optsize = struct.unpack_from('<H', self.data, pe + 20)[0]
        opt = pe + 24
        if struct.unpack_from('<H', self.data, opt)[0] != 0x10b:
            raise ValueError('Only PE32 supported')
        self.imagebase = struct.unpack_from('<I', self.data, opt + 28)[0]
        sbase = opt + optsize
        self.sections = []
        for i in range(nsects):
            off = sbase + i * 40
            name = self.data[off:off + 8].split(b'\0')[0].decode('ascii', 'replace')
            vs, rva, rawsz, raw = struct.unpack_from('<IIII', self.data, off + 8)
            self.sections.append(Section(name, self.imagebase + rva, vs, raw, rawsz))
        self.imports = self.read_imports(struct.unpack_from('<II', self.data, opt + 96 + 8))

    def section(self, va: int):
        return next((s for s in self.sections if s.va <= va < s.va + min(s.rawsz, s.vs or s.rawsz)), None)

    def data_at(self, va: int, size: int):
        s = self.section(va)
        if not s or va + size > s.va + s.rawsz:
            return None
        start = s.raw + va - s.va
        return self.data[start:start + size]

    def u32(self, va: int):
        b = self.data_at(va, 4)
        return struct.unpack('<I', b)[0] if b is not None and len(b) == 4 else None

    def cstr(self, va: int, maxlen: int = 500):
        b = self.data_at(va, 1)
        if b is None:
            return None
        s = self.section(va)
        off = s.raw + va - s.va
        data = self.data[off:min(off + maxlen, s.raw + s.rawsz)]
        result = data.split(b'\0')[0]
        return result.decode('ascii', 'replace')

    def read_imports(self, directory):
        rva, size = directory
        if not rva or not size:
            return {}
        ptr = self.imagebase + rva
        result = {}
        for _ in range(100):
            desc = self.data_at(ptr, 20)
            if not desc:
                break
            oft, _, _, name_rva, ft = struct.unpack('<IIIII', desc)
            if not (oft or ft):
                break
            dll = self.cstr(self.imagebase + name_rva) or '?'
            thunk_rva = oft or ft
            for i in range(2048):
                entry = self.u32(self.imagebase + thunk_rva + i * 4)
                if entry in (None, 0):
                    break
                if entry & 0x80000000:
                    name = f'ordinal_{entry & 0xffff}'
                else:
                    name = self.cstr(self.imagebase + entry + 2) or '?'
                result[self.imagebase + ft + i * 4] = f'{dll}!{name}'
            ptr += 20
        return result


def objdump_instructions(exe: Path):
    output = subprocess.check_output(['objdump', '-d', '-Mintel', str(exe)], text=True)
    instructions = []
    for line in output.splitlines():
        # objdump generally emits address, bytes, instruction in 3 tab-separated columns.
        cols = line.split('\t')
        if len(cols) < 3 or not re.match(r'^\s*[0-9a-f]+:$', cols[0]):
            continue
        try:
            va = int(cols[0].strip()[:-1], 16)
        except ValueError:
            continue
        text = cols[2].strip()
        if not text:
            continue
        m = re.match(r'([a-z0-9_.]+)\s*(.*)', text)
        if m:
            instructions.append((va, m.group(1), m.group(2)))
    return instructions


def parse_symbols(path: Path):
    d = json.loads(path.read_text())
    if isinstance(d, dict):
        result = {int(k, 0): str(v) for k, v in d.items() if str(k).startswith('0x')}
    elif isinstance(d, list):
        result = {}
        for item in d:
            if isinstance(item, dict) and 'address' in item:
                result[int(str(item['address']), 0)] = item.get('name', '?')
    else:
        raise ValueError('Unsupported symbols schema')
    if not result:
        raise ValueError('No address->name records in symbols file')
    return result


def vtable_candidates(pe: PE):
    text = next(s for s in pe.sections if s.name == '.text')
    tables = {}
    for section in pe.sections:
        if section.name not in ('.rdata', '.data'):
            continue
        start = section.va
        end = start + section.rawsz - 4
        prev_good = False
        for va in range(start, end + 1, 4):
            p = pe.u32(va)
            good = p is not None and text.va <= p < text.va + text.vs
            if good and not prev_good:
                ptrs = []
                for i in range(128):
                    p2 = pe.u32(va + i * 4)
                    if p2 is None or not (text.va <= p2 < text.va + text.vs):
                        break
                    ptrs.append(p2)
                if len(ptrs) >= 3:
                    tables[va] = ptrs
            prev_good = good
    return tables


def vtable_like_at(pe: PE, address: int):
    """Very conservative potential pointer-table classifier, never proof of RTTI."""
    sec = pe.section(address)
    if not sec or sec.name not in ('.rdata', '.data') or address % 4:
        return False
    text = next(s for s in pe.sections if s.name == '.text')
    slots = [pe.u32(address + i * 4) for i in range(8)]
    valid = sum(x is not None and text.va <= x < text.va + text.vs for x in slots)
    # Constructors often point to a table with leading gaps/NULL and function slots.
    return valid >= 3 and any(x is not None and text.va <= x < text.va + text.vs for x in slots[:2])


IMM_RE = re.compile(r'(?<![\w])0x[0-9a-fA-F]{5,8}(?![\w])')
OFFSET_RE = re.compile(r'([+-])0x[0-9a-fA-F]+')


def refs_in_instruction(operand: str):
    for found in IMM_RE.findall(operand):
        yield int(found, 16)


def shape_instruction(op, operands):
    # Architectural shape, not a machine-code equivalence relation.
    operands = operands.lower()
    operands = re.sub(r'0x[0-9a-f]+', '#', operands)
    operands = re.sub(r'(?<!\w)-?\b\d+\b', '#', operands)
    return op + ' ' + operands


def short_ascii(pe: PE, va: int):
    s = pe.section(va)
    if not s or s.name not in ('.rdata', '.data'):
        return None
    raw = pe.cstr(va, 110)
    if not raw or len(raw) < 5 or not all(32 <= ord(c) < 127 for c in raw):
        return None
    # A string inside a table of pointers or a code address is unlikely to pass.
    return raw[:65]


def family_record(kind, key, members, info, limit=15):
    member_list = sorted(members)
    return {
        'kind': kind, 'key': key, 'members': [f'0x{x:08x}' for x in member_list],
        'count': len(member_list), 'sample': [f'0x{x:08x}' for x in member_list[:limit]],
        'info': info,
    }


def mine(pe: PE, symbols, instructions, minmembers=3, maxlen=6000):
    starts = sorted(addr for addr in symbols if pe.section(addr) and pe.section(addr).name == '.text')
    grouped = collections.defaultdict(list)
    vtables = vtable_candidates(pe)
    table_start = sorted(vtables)
    imp = collections.defaultdict(set)
    indirect_vtables = {}
    vref = collections.defaultdict(set)
    sref = collections.defaultdict(set)
    shapes = collections.defaultdict(set)
    function_details = {}
    for va, op, operands in instructions:
        i = bisect.bisect_right(starts, va) - 1
        if i < 0:
            continue
        start = starts[i]
        stop = starts[i + 1] if i + 1 < len(starts) else next(s for s in pe.sections if s.name == '.text').va + next(s for s in pe.sections if s.name == '.text').vs
        if va >= min(stop, start + maxlen):
            continue
        grouped[start].append((va, op, operands))

    for start in starts:
        ins = grouped.get(start, [])
        if not ins:
            continue
        # A few lines of bytes as direct source-binary evidence, not recompilation.
        referenced_tables = set()
        referenced_strings = set()
        referenced_imports = set()
        for _, op, operands in ins:
            for ref in refs_in_instruction(operands):
                if op in ('call', 'jmp', 'mov') and ref in pe.imports:
                    referenced_imports.add(pe.imports[ref])
                if op in ('push', 'mov', 'lea') and (ref in vtables or vtable_like_at(pe, ref)):
                    referenced_tables.add(ref)
                    if ref not in vtables:
                        indirect_vtables[ref] = [pe.u32(ref + i * 4) for i in range(8)]
                if op in ('push', 'mov', 'lea') and ref not in vtables and ref not in indirect_vtables:
                    txt = short_ascii(pe, ref)
                    if txt:
                        referenced_strings.add((ref, txt))
        for vt in referenced_tables:
            vref[vt].add(start)
        for va, txt in referenced_strings:
            sref[(va, txt)].add(start)
        for name in referenced_imports:
            imp[name].add(start)
        # Remove only the canonical MSVC6 C++ EH prologue to keep useful body shape.
        body = list(ins)
        if (len(body) >= 5 and body[0][1] == 'push' and body[0][2].strip() == '0xffffffff'
                and body[2][1] == 'mov' and 'fs:0x0' in body[2][2]):
            body = body[5:]
        if len(body) >= 5:
            signature = '|'.join(shape_instruction(op, operands) for _, op, operands in body[:7])
            shapes[signature].add(start)
        end = min(starts[bisect.bisect_right(starts, start)] if bisect.bisect_right(starts, start) < len(starts) else start + maxlen, start + maxlen)
        function_details[f'0x{start:08x}'] = {
            'name': symbols[start], 'span_upper_bound': end - start,
            'disassembled_instructions': len(ins),
            'vtables': [f'0x{x:08x}' for x in sorted(referenced_tables)],
            'strings': [{'address': f'0x{va:08x}', 'preview': s} for va, s in sorted(referenced_strings)][:12],
            'imports_direct': sorted(referenced_imports),
        }

    families = []
    for addr, members in vref.items():
        if len(members) >= minmembers:
            # Four code pointers act as a fingerprint; vtable-like is NOT a proven vtable.
            funcs = vtables.get(addr, indirect_vtables.get(addr, []))
            families.append(family_record('shared_vtable_like_ref', f'0x{addr:08x}', members,
                                          {'first_slots': [f'0x{x:08x}' for x in funcs[:6] if x is not None], 'slots': len(funcs)}))
    for (addr, label), members in sref.items():
        if len(members) >= minmembers:
            families.append(family_record('shared_string_ref', f'0x{addr:08x}', members, {'ascii': label}))
    for signature, members in shapes.items():
        if len(members) >= minmembers:
            families.append(family_record('normalized_opcode_prefix', hashlib.sha256(signature.encode()).hexdigest()[:16], members,
                                          {'pattern': signature[:260]}))
    # Include imports as annotation/reference lens; already handled by repo's feature-family miner.
    for name, members in imp.items():
        if len(members) >= minmembers:
            families.append(family_record('import_reference', name, members, {'existing_feature_family_lens': True}))
    families.sort(key=lambda f: (f['kind'] in ('import_reference',), -f['count'], f['kind'], f['key']))
    return {
        'target_sha256': pe.hash, 'symbol_count': len(starts),
        'vtable_like_addresses': len(vtables), 'import_slots': len(pe.imports),
        'note': 'Discovery only; exact function extents, vtable ownership, and strict status must be independently verified.',
        'families': families,
        'functions': function_details,
    }


def report(result, maxfamilies):
    out = [
        '# PE structural-family mining (unverified candidates)', '',
        f"Executable SHA-256: `{result['target_sha256']}`",
        f"Symbols in executable text: {result['symbol_count']}; vtable-like address starts: {result['vtable_like_addresses']}; import slots: {result['import_slots']}.",
        '', '**Important:** Discovery families are NOT byte-matched functions. A shared immediate may be a function-pointer table rather than a C++ vtable. Source and strict matcher are required.', '',
    ]
    families = result['families']
    by_kind = collections.Counter(f['kind'] for f in families)
    out.append('Family counts (minimum member threshold applied): ' + ', '.join(f'{k}: {v}' for k, v in sorted(by_kind.items())) + '.')
    out.extend(['', '| Lens | Key | Count | Example addresses |', '|---|---|---:|---|'])
    for f in families[:maxfamilies]:
        out.append(f"| {f['kind']} | `{f['key']}` | {f['count']} | " + ', '.join('`' + a + '`' for a in f['sample'][:5]) + ' |')
    out.extend(['', '## Recommended local verification', '',
        'Cross-reference each family with the tracked registry, remove existing strict/generated matches, pick simple/typical/held-out siblings, and run `tools/match_decomp.py --strict --auto-symbols` using exact manifest lengths and entry symbols.'])
    return '\n'.join(out) + '\n'


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--exe', type=Path, default=Path('game/fastfood2.exe'))
    ap.add_argument('--symbols', type=Path, default=Path('decompiled_fastfood2_named_v2/full_game_symbols.json'))
    ap.add_argument('--json', type=Path, default=Path('/tmp/pc2-shape-families.json'))
    ap.add_argument('--report', type=Path, default=Path('/tmp/pc2-shape-families.md'))
    ap.add_argument('--min-members', type=int, default=3)
    ap.add_argument('--max-family-report', type=int, default=100)
    ap.add_argument('--allow-other-exe', action='store_true')
    args = ap.parse_args()
    pe = PE(args.exe)
    if not args.allow_other_exe and pe.hash != TARGET_SHA:
        ap.error('Executable SHA mismatch. Refusing to mine non-target executable.')
    result = mine(pe, parse_symbols(args.symbols), objdump_instructions(args.exe), args.min_members)
    args.json.parent.mkdir(parents=True, exist_ok=True)
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.json.write_text(json.dumps(result, indent=2, sort_keys=True) + '\n')
    args.report.write_text(report(result, args.max_family_report))
    print(f"Functions: {result['symbol_count']}; family candidates: {len(result['families'])}")
    print(f"JSON: {args.json}\nReport: {args.report}")


if __name__ == '__main__':
    main()
