#!/usr/bin/env python3
"""Recheck a bounded set of tracked VC6 near misses and route their evidence."""

from argparse import ArgumentParser
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor
from dataclasses import replace
import json
from pathlib import Path
import re
import struct
import subprocess
import tempfile

from capstone import CsError
from coff_cache import cache_environment, cache_identity, cache_path, hash_bytes, store_object
from compare_match_blocks import compare as compare_blocks
from match_decomp import (DEFAULT_VC6, GAME, ROOT, compiler_provenance, parse_coff, pe_image, resolve_auto_symbol,
                          section_relocations)
from verify_linked_image import CacheMissing, PINNED_SHA256, verify_recipe
from verify_replay_batch import plan


CONFIG = 'pc2.near_miss_pilot.v1'
FLAG_CONFIG = 'pc2.near_miss_flag_screen.v1'
MAX_DRAFTS = 10
MAX_VARIANTS = 12
MAX_FLAG_DRAFTS = 16
MAX_FLAG_ATTEMPTS = 60
SHAPE_NAME = re.compile(r'[a-z0-9][a-z0-9-]{0,47}')
FLAG_AXES = ({'/Od', '/O1', '/O2'}, {'/Oy', '/Oy-'}, {'/G5', '/G6'}, {'/Oi', '/Oi-'}, {'/Os', '/Ot'})
SCREEN_FLAGS = set().union(*FLAG_AXES)


def read_json(path):
    return json.loads(path.read_text())


def write_json(path, data):
    with path.open('x') as stream:
        json.dump(data, stream, indent=2)
        stream.write('\n')


def load_seeds(config, compiler):
    payload = read_json(config)
    schema = payload.get('schema')
    flag_screen = schema == FLAG_CONFIG
    limit = MAX_FLAG_DRAFTS if flag_screen else MAX_DRAFTS
    seeds = payload['recipes']
    if schema not in {CONFIG, FLAG_CONFIG} or not isinstance(seeds, list) or not 1 <= len(seeds) <= limit:
        raise ValueError(f'expected a supported near-miss recipe schema with one to {limit} drafts')
    tracked = set(subprocess.check_output(['git', 'ls-files', '-z', '--', 'reconstructed/match'],
                                          cwd=ROOT, text=True).split('\0'))
    records, edits = {}, {}
    for seed in seeds:
        receipt = (ROOT / seed['receipt']).resolve()
        if not receipt.is_relative_to(ROOT) or str(receipt.relative_to(ROOT)) not in tracked:
            raise ValueError(f'expected tracked near-miss receipt: {receipt}')
        row = read_json(receipt)
        address = int(row['address'], 0)
        if (address in records or row.get('strict_match') is not False or row['executable_sha256'] != PINNED_SHA256
                or row['compiler']['sha256'] != compiler or not row['source_sha256'] or not row['entry']):
            raise ValueError(f'expected unique near miss with pinned PE and compiler provenance: {receipt}')
        if flag_screen and (row.get('match') is not False or not row.get('difference_count') or row.get('blocked_sections')):
            raise ValueError(f'flag screen requires primary codegen differences without a secondary-section blocker: {receipt}')
        records[address] = {**row, 'receipt': str(receipt), 'source': seed.get('source', row['source'])}
        if flag_screen:
            focus = seed.get('focus')
            if not isinstance(focus, str) or not focus.strip():
                raise ValueError(f'flag screen requires a recorded codegen focus: {receipt}')
            records[address]['focus'] = focus
        shapes = seed.get('profiles' if flag_screen else 'variants', [])
        if not isinstance(shapes, list) or len(shapes) > 3 or (flag_screen and not shapes):
            raise ValueError(f'expected at most three alternatives per draft at {address:#x}')
        edits[address] = shapes
    alternatives = sum(map(len, edits.values()))
    if flag_screen and len(records) + alternatives > MAX_FLAG_ATTEMPTS:
        raise ValueError(f'at most {MAX_FLAG_ATTEMPTS} flag attempts per run')
    if not flag_screen and alternatives > MAX_VARIANTS:
        raise ValueError(f'at most {MAX_VARIANTS} shapes per run')
    return records, edits, flag_screen


def edited_source(original, edits):
    if not isinstance(edits, list) or not 1 <= len(edits) <= 3:
        raise ValueError('a shape needs one to three exact source edits')
    updated = original
    for edit in edits:
        before, after = edit['before'].encode('ascii'), edit['after'].encode('ascii')
        if not before or max(len(before), len(after)) > 1024 or updated.count(before) != 1:
            raise ValueError('a shape edit needs a unique exact source fragment of at most 1,024 bytes')
        updated = updated.replace(before, after, 1)
    if updated == original or re.search(rb'\b(?:__asm__|__asm|_asm)\b|\basm\s*[{(]', updated):
        raise ValueError('shape requires a changed C/C++ source without assembly')
    return updated


def flag_profile(original, profile):
    flags = profile['flags']
    if not isinstance(flags, list) or len(flags) != len(set(flags)) or not flags:
        raise ValueError('a flag profile needs a complete list of distinct flags')
    selected = set(flags)
    if selected - SCREEN_FLAGS != set(original) - SCREEN_FLAGS:
        raise ValueError('a flag profile must preserve the baseline language, EH, and non-screened flags')
    if not selected & FLAG_AXES[0] or any(len(selected & group) > 1 for group in FLAG_AXES):
        raise ValueError('a flag profile needs one optimization level and no conflicting switches')
    return tuple(flags)


def attempts(recipes, variants, cache, identity, flag_screen=False):
    source_directory = cache / 'sources'
    coff = cache / 'coff'
    ordered = []
    for recipe in recipes:
        baseline = recipe.source.read_bytes()
        trials = [('baseline', recipe, baseline)]
        used_names = {'baseline'}
        used_inputs = {frozenset(recipe.flags) if flag_screen else recipe.source_sha256}
        for variant in variants[recipe.address]:
            name = variant['name']
            if name in used_names or not SHAPE_NAME.fullmatch(name):
                raise ValueError(f'invalid or repeated shape {name!r} at {recipe.address:#x}')
            if flag_screen:
                flags = flag_profile(recipe.flags, variant)
                trial = (name, replace(recipe, flags=flags), baseline)
                identity_key = frozenset(flags)
            else:
                contents = edited_source(baseline, variant['edits'])
                digest = hash_bytes(contents)
                path = source_directory / f'{recipe.address:08x}-{digest}{recipe.source.suffix}'
                trial = (name, replace(recipe, source=path, source_sha256=digest), contents)
                identity_key = digest
            if identity_key in used_inputs:
                raise ValueError(f'non-distinct alternative {name!r} at {recipe.address:#x}')
            used_names.add(name)
            used_inputs.add(identity_key)
            trials.append(trial)
        for name, candidate, contents in trials:
            if cache_path(coff, identity, candidate.source, contents, list(candidate.flags)) is None:
                raise ValueError(f'{recipe.address:#x}/{name} is outside the existing COFF cache contract')
            ordered.append((name, candidate, contents))
    return ordered


def save_variant_source(path, contents):
    if not path.is_symlink():
        store_object(path, contents)
        if not path.is_symlink() and path.read_bytes() == contents:
            return
    raise ValueError(f'variant source already exists with different contents or is a symlink: {path}')


def route(result, diagnostics, diagnostic_error):
    status = result['status']
    if status in {'strict', 'cache_missing', 'error', 'unsupported'}:
        return {'name': {'strict': 'verified', 'unsupported': 'review_link_plan'}.get(status, status)}
    symbols = sorted({r['symbol'] for r in result['relocations']
                      if r['target'] is None and r['target_section_index'] is None})
    if symbols:
        return {'name': 'resolve_symbols', 'symbols': symbols}
    if result['blocked_sections']:
        return {'name': 'review_secondary_sections'}
    if any('extent' in issue for issue in result['strict_issues']):
        return {'name': 'review_extent'}
    if status == 'blocked' and result['relocation_issues']:
        return {'name': 'review_relocations'}
    if status == 'blocked':
        return {'name': 'review_strict_evidence'}
    if diagnostic_error:
        return {'name': 'review_block_diagnostics', 'error': diagnostic_error}
    return {'name': 'inspect_codegen', 'difference_kinds': (diagnostics or {}).get('difference_kinds', {})}


def emitted_identity(obj, entry):
    data, sections, symbols = parse_coff(obj)
    entries = [(s['section'], s['value']) for s in symbols if s and s['name'] == entry and s['section'] > 0]
    if len(entries) != 1:
        raise ValueError('expected a unique emitted entry for code/relocation grouping')
    identity = []
    for section in sections:
        if section['name'].startswith('.debug') or section['name'] == '.drectve':
            continue
        relocations = []
        for offset, index, kind in sorted(section_relocations(data, section)):
            symbol = symbols[index]
            relocations.append((offset, kind, symbol['name'], symbol['section'], symbol['value']))
        identity.append((section['name'], hash_bytes(section['raw']), relocations))
    return hash_bytes(json.dumps([entry, entries[0], identity], separators=(',', ':')).encode())


def assess(item, vc6, scratch, image, cache, identity, environment, cache_only, output):
    name, recipe, _ = item
    label = f'{recipe.address:08x}-{name}'
    local = scratch / label
    local.mkdir()
    obj = local / f'{recipe.address:08x}.obj'
    diagnostics = diagnostic_error = None
    try:
        _, result = verify_recipe(recipe, vc6, local, image[0], cache / 'coff', identity,
                                  environment, cache_only=cache_only, assess=True)
        if result['cache'] not in {'hit', 'miss'} or (cache_only and result['cache'] != 'hit'):
            raise ValueError('unexpected cache bypass')
    except (ValueError, OSError, struct.error, subprocess.TimeoutExpired) as error:
        result = {'address': hex(recipe.address), 'status': 'cache_missing' if isinstance(error, CacheMissing) else 'error',
                  'error': str(error)}
    receipt = {**result, 'entry': recipe.entry, 'length': recipe.length, 'executable_sha256': PINNED_SHA256}
    if obj.is_file() and 'object' in result:
        receipt['object_sha256'] = result['object']['sha256']
        try:
            diagnostics = compare_blocks(obj, receipt)
        except (ValueError, OSError, KeyError, struct.error, CsError) as error:
            diagnostic_error = receipt['block_diagnostic_error'] = str(error)
    receipt_file = f'{label}.receipt.json'
    write_json(output / receipt_file, receipt)
    if diagnostics is not None:
        write_json(output / f'{label}.blocks.json', diagnostics)
    exact = [row['original'] for row in (diagnostics or {}).get('blocks', []) if row['first_difference'] is None]
    verdict = route(result, diagnostics, diagnostic_error)
    return {'address': hex(recipe.address), 'shape': name, 'length': recipe.length, 'source_sha256': recipe.source_sha256,
            'seed_receipt': recipe.audit_record, 'receipt': receipt_file, 'route': verdict,
            'flags': list(recipe.flags),
            'exact_original_blocks': exact, 'paired_blocks': (diagnostics or {}).get('paired_blocks'),
            'strict_issue_count': len(result.get('strict_issues', [])),
            'relocation_issue_count': len(result.get('relocation_issues', [])),
            'emitted_code_relocations_sha256': emitted_identity(obj, recipe.entry) if 'object' in result else None,
            **({'block_diagnostic_error': diagnostic_error} if diagnostic_error else {}),
            **{key: result[key] for key in ('status', 'cache', 'cache_key', 'object', 'strict_match', 'first_difference',
                                           'difference_count', 'error') if key in result}}


def deltas(rows):
    baselines = {row['address']: row for row in rows if row['shape'] == 'baseline'}
    for row in rows:
        if row['shape'] == 'baseline':
            continue
        baseline = baselines[row['address']]
        old, new = set(baseline['exact_original_blocks']), set(row['exact_original_blocks'])
        comparable = baseline['paired_blocks'] is not None and row['paired_blocks'] is not None
        before, after = baseline.get('difference_count'), row.get('difference_count')
        row['delta'] = {'exact_blocks_gained': sorted(new - old) if comparable else None,
                        'exact_blocks_lost': sorted(old - new) if comparable else None,
                        'diagnostic_byte_differences_before': before, 'diagnostic_byte_differences_after': after,
                        'strict_promotion': row['status'] == 'strict' and baseline['status'] != 'strict'}


def rank_profiles(rows):
    targets = defaultdict(dict)
    for row in rows:
        key = row['emitted_code_relocations_sha256'] or row['shape']
        targets[row['address']].setdefault(key, []).append(row)
    rankings = {}
    for address, groups in targets.items():
        def rank(group):
            first = group[0]
            return (first['status'] in {'error', 'cache_missing'}, first['status'] != 'strict',
                    first['paired_blocks'] is None, -len(first['exact_original_blocks']),
                    first['strict_issue_count'], first['relocation_issue_count'],
                    first.get('difference_count', float('inf')))
        rankings[address] = [{'representative': group[0]['shape'], 'same_emitted_code_and_relocations': [r['shape'] for r in group],
                              'exact_original_blocks': len(group[0]['exact_original_blocks']),
                              'difference_count': group[0].get('difference_count'), 'status': group[0]['status']}
                             for group in sorted(groups.values(), key=rank)]
    return rankings


def main():
    parser = ArgumentParser(description=__doc__)
    parser.add_argument('--recipes', required=True, type=Path)
    parser.add_argument('--cache', required=True, type=Path)
    parser.add_argument('--out', required=True, type=Path, help='fresh scratch directory')
    parser.add_argument('--cache-only', action='store_true', help='fail on a missing object without invoking VC6')
    parser.add_argument('--jobs', choices=range(1, 9), default=1, type=int)
    args = parser.parse_args()
    try:
        image = pe_image(GAME)
        if hash_bytes(image[0]) != PINNED_SHA256:
            raise ValueError('expected pinned PE')
        vc6 = DEFAULT_VC6.resolve()
        compiler = compiler_provenance(vc6)['sha256']
        environment = cache_environment()
        identity = cache_identity(vc6, ROOT, environment)
        if identity is None:
            raise ValueError('VC6/Wine environment is outside the existing COFF cache contract')
        records, variants, flag_screen = load_seeds(args.recipes, compiler)
        recipes, missing = plan(records, records, image)
        if missing:
            raise ValueError('draft planning failed: ' + '; '.join(f'{va:#x} {why}' for va, why in missing.items()))
        cache, output = args.cache.resolve(), args.out.resolve()
        if cache == output:
            raise ValueError('cache and results require separate directories')
        planned = attempts(recipes, variants, cache, identity, flag_screen)
        output.mkdir(parents=True)
        (cache / 'coff').mkdir(parents=True, exist_ok=True)
        (cache / 'sources').mkdir(exist_ok=True)
        for name, recipe, contents in planned:
            if name != 'baseline' and not flag_screen:
                save_variant_source(recipe.source, contents)
        resolve_auto_symbol('__except_list')
        with tempfile.TemporaryDirectory(prefix='objects-', dir=output) as scratch:
            with ThreadPoolExecutor(max_workers=args.jobs) as pool:
                rows = list(pool.map(lambda item: assess(item, vc6, Path(scratch), image, cache, identity,
                                                         environment, args.cache_only, output), planned))
        deltas(rows)
        cache_counts = Counter(row['cache'] for row in rows if 'cache' in row)
        status_counts = Counter(row['status'] for row in rows)
        blocked = defaultdict(set)
        for row in rows:
            for symbol in row['route'].get('symbols', []):
                blocked[symbol].add(row['address'])
        summary = {'schema': 'pc2.near_miss_pilot_report.v1', 'executable_sha256': PINNED_SHA256,
                   'mode': 'flags' if flag_screen else 'source_shapes',
                   'cache_only': args.cache_only,
                   'compiler_invocations': (cache_counts['miss'] if args.cache_only or 'error' not in status_counts else None),
                   'compiled_cache_misses': cache_counts['miss'],
                   'recipes_sha256': hash_bytes(args.recipes.read_bytes()), 'drafts': len(recipes),
                   'attempts': len(rows), 'cache': dict(cache_counts), 'statuses': dict(status_counts),
                   'routes': dict(Counter(row['route']['name'] for row in rows)),
                   'shared_symbol_blockers': {symbol: sorted(addresses) for symbol, addresses in sorted(blocked.items())},
                   'candidates': rows}
        if flag_screen:
            summary['flag_focus'] = {hex(address): record['focus'] for address, record in records.items()}
            summary['ranked_profiles'] = rank_profiles(rows)
            summary['distinct_emitted_code_profiles'] = len({(row['address'], row['emitted_code_relocations_sha256'])
                                                          for row in rows if row['emitted_code_relocations_sha256']})
        write_json(output / 'summary.json', summary)
        print(f"{len(recipes)} drafts, {len(rows)} attempts, cache={dict(cache_counts)}, statuses={dict(status_counts)}")
        return int(any(status in status_counts for status in ('error', 'cache_missing')))
    except (ValueError, KeyError, TypeError, OSError, struct.error, subprocess.SubprocessError) as error:
        parser.exit(2, f'near-miss pilot: {error}\n')


if __name__ == '__main__':
    raise SystemExit(main())
