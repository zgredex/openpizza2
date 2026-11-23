#!/usr/bin/env python3
"""Create a cheap, deterministic queue from OpenPizza2's named Ghidra pseudocode.

Read-only: never generates or claims executable source from pseudocode.
Requires Python 3.9+. Designed for the repository's existing exported .c files.
"""
from __future__ import annotations
import argparse
import collections
import csv
import json
import re
from pathlib import Path

PSEUDO = Path('decompiled_fastfood2_named_v2/full_game_verification/functions')
TOKENS = re.compile(r'\b[A-Za-z_][A-Za-z_0-9]*\s*\(')
CONTROL = {'if','while','switch','for','sizeof','return','do','else','cast','__builtin_unreachable'}
BAD = {
    'undefined': re.compile(r'\bundefined(?:1|2|4|8)?\b'),
    'indirect_call': re.compile(r'\(\s*\*\s*\*'),
    'goto': re.compile(r'\bgoto\b'),
    'concat': re.compile(r'\b(?:CONCAT\d+\d+|SUB\d+\d+|ZEXT\d+\d+|SEXT\d+\d+)\s*\('),
    'address_data': re.compile(r'\bDAT_00[0-9a-f]{6}\b', re.I),
    'address_code': re.compile(r'\b(?:FUN|LAB)_00[0-9a-f]{6}\b', re.I),
    'stacklocal': re.compile(r'\blocal_[0-9a-f]+\b', re.I),
    'cxx': re.compile(r'\b(?:__thiscall|operator new|operator delete|\bthis\b|try\s*\{|catch\s*\()'),
}
META_NAME = re.compile(r'(?m)^//\s*name:\s*(.*?)\s*$')
META_ADDR = re.compile(r'(?m)^//\s*address:\s*(0x[0-9a-f]+)', re.I)
META_BODY = re.compile(r'(?m)^//\s*body:\s*(.*?)\s*$')
# This is deliberately heuristic; generic name tokens are only used for ranking.
NAME_REF = re.compile(r'\b([A-Za-z_][A-Za-z_0-9]*)\s*\(')
MARKER = re.compile(r'(?im)^\s*//\s*(?:original(?:_address)?|pc2_address|function_address)\s*:\s*(0x[0-9a-f]+)\b')
ADDRESS_FILENAME = re.compile(r'^0x([0-9a-f]{6,8})\.(?:cpp|c|cc)$', re.I)


def scan_one(path: Path):
    text = path.read_text(encoding='utf-8', errors='replace')
    m = META_ADDR.search(text)
    a = (m.group(1).lower() if m else path.stem.lower())
    if not re.fullmatch(r'0x[0-9a-f]+', a):
        return None
    n = META_NAME.search(text)
    body = META_BODY.search(text)
    code_start = text.find('// pseudocode:')
    code = text[code_start:] if code_start >= 0 else text
    calls = set(NAME_REF.findall(code)) - CONTROL
    # First token is likely a function declaration; remove it via known name below.
    name = (n.group(1).strip() if n else a)
    calls.discard(name)
    flags = {key: len(rx.findall(code)) for key, rx in BAD.items()}
    # Preserve complexity signals; penalize huge functions and unresolved global addresses.
    nonblank = sum(bool(line.strip()) for line in code.splitlines())
    score = (len(code) / 350.0 + 10*flags['indirect_call'] + 8*flags['concat'] +
             5*flags['goto'] + 2*flags['address_code'] +
             .6*flags['address_data'] + .8*flags['undefined'] +
             .35*len(calls))
    return {
        'address': a, 'name': name, 'path': str(path),
        'body_available': body is None or body.group(1).strip().lower() == 'available',
        'source_lines': nonblank, 'score': round(score, 2),
        'signals': flags, 'call_tokens': sorted(calls),
    }


def mapped_port_status(root: Path, port_src: Path):
    # Files with the same original address or an explicit marker count as submitted,
    # NOT as compiled or recovered, until a real build proves them.
    covered, stubs = set(), set()
    if not port_src.exists():
        return covered, stubs
    for p in port_src.rglob('*'):
        if not p.is_file() or p.suffix.lower() not in {'.c','.cc','.cpp'}:
            continue
        text = p.read_text(encoding='utf-8', errors='replace')
        addresses = {m.group(1).lower() for m in MARKER.finditer(text)}
        m = ADDRESS_FILENAME.match(p.name)
        if m:
            addresses.add('0x'+m.group(1).lower())
        if re.search(r'(?im)^\s*//\s*PORT_STATUS:\s*STUB\b', text):
            stubs.update(addresses)
        else:
            covered.update(addresses)
    return covered - stubs, stubs


def run(args):
    root = Path(args.root).resolve()
    pseudo = root / args.pseudocode_dir
    if not pseudo.is_dir():
        raise SystemExit(f'Missing Ghidra export: {pseudo}')
    out = Path(args.out)
    if not out.is_absolute():
        out = root / out
    out = out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    records = [record for p in sorted(pseudo.glob('0x*.c')) if (record := scan_one(p))]
    by_name = collections.defaultdict(list)
    for r in records:
        by_name[r['name']].append(r['address'])
    for r in records:
        r['known_calls'] = sorted({a for name in r.pop('call_tokens') if name != r['name'] for a in by_name.get(name, [])})
        r['known_dependencies'] = len(r['known_calls'])
        r['score'] = round(r['score']+2*r['known_dependencies'],2)
    submitted, stubbed = mapped_port_status(root, root / args.port_src)
    for r in records:
        r['status'] = ('stub' if r['address'] in stubbed else
                       'submitted_unverified' if r['address'] in submitted else
                       'pseudocode')
        if not r['body_available']:
            r['status'] = 'missing_body'
    available = [r for r in records if r['status'] == 'pseudocode']
    available.sort(key=lambda r: (r['score'], r['known_dependencies'], r['source_lines'], r['address']))
    # Files for handoff. No prompt data is sent to a model here.
    (out/'queue.json').write_text(json.dumps({'records': records, 'queue': [r['address'] for r in available], 'summary': {
        'exported':len(records), 'queued':len(available), 'submitted_not_verified':sum(r['status']=='submitted_unverified' for r in records),
        'stubs_not_counted':sum(r['status']=='stub' for r in records), 'missing_body':sum(r['status']=='missing_body' for r in records),
    }},indent=2)+'\n',encoding='utf-8')
    with (out/'queue.csv').open('w', encoding='utf-8', newline='') as f:
        w=csv.writer(f); w.writerow(['address','name','score','lines','dependencies','path'])
        for r in available: w.writerow([r['address'],r['name'],r['score'],r['source_lines'],r['known_dependencies'],Path(r['path']).relative_to(root)])
    lines=[
        '# OpenPizza2 source-port queue (heuristic; NOT proof of correctness)', '',
        f'Exported pseudocode bodies: {len(records)}',
        f'Available for porting: {len(available)}',
        f'Submitted source (not build verified): {sum(r["status"]=="submitted_unverified" for r in records)}',
        f'Explicit stubs excluded from recovery: {sum(r["status"]=="stub" for r in records)}', '',
        '## First candidates (lowest estimated complexity)', '',
        '| Address | Name | Cost | Lines | Direct named dependencies |',
        '|---|---|---:|---:|---:|',
    ]
    for r in available[:args.limit]:
        safe_name=r['name'].replace('|','/')
        lines.append(f'| `{r["address"]}` | `{safe_name}` | {r["score"]:.1f} | {r["source_lines"]} | {r["known_dependencies"]} |')
    lines += ['', 'Cost is only a text-based triage heuristic, not a measurement of effort, recoverability or runnable coverage.',
              'After each batch: re-run this script; mark real compiled functions using your build manifest, not file existence.',
              'For running the game, additionally prioritize the actual entrypoint call graph and critical startup APIs.', '']
    (out/'queue.md').write_text('\n'.join(lines),encoding='utf-8')
    print(f'Wrote {out}/queue.csv, queue.json, queue.md | {len(available)} queued')


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--root',default='.',help='OpenPizza2 checkout')
    p.add_argument('--pseudocode-dir',default=str(PSEUDO))
    p.add_argument('--port-src',default='source_port/src',help='Local source tree with // original: 0x... markers')
    p.add_argument('--out',default='source_port/work_queue')
    p.add_argument('--limit',type=int,default=120)
    run(p.parse_args())
if __name__=='__main__': main()
