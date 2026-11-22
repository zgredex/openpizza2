#!/usr/bin/env python3
"""Recheck drafts from a replay worklist with the strict and isolated verifiers."""

from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import re
import struct
import subprocess
import tempfile

from coff_cache import cache_environment, cache_identity, hash_bytes
from match_decomp import DEFAULT_VC6, GAME, ROOT, compiler_provenance, function_lengths, pe_image
from pcrecomp_pc2.fixture_plan import normalize_plan
from pcrecomp_pc2.function_fixtures import verify
from replay_worklist import read_json
from verify_linked_image import (PINNED_SHA256, Recipe, assemble_image, file_offset,
                                 merged_spans, verify_batch, write_outputs)


def queue_addresses(worklist):
    if worklist["schema"] != "pc2.replay_worklist.v1" or worklist["executable_sha256"] != PINNED_SHA256:
        raise ValueError("worklist must target the pinned PC2 executable")
    addresses = list(dict.fromkeys(int(va, 0) for group in worklist["groups"] for va in group["addresses"]))
    if set(addresses) != {int(va, 0) for va in worklist["uncovered"]}:
        raise ValueError("ranked groups differ from the uncovered address set")
    return addresses


def audit_recipes(directories, selected, compiler):
    records = {}
    for directory in directories:
        directory = directory / "functions" if (directory / "functions").is_dir() else directory
        paths = sorted(directory.glob("*.json"), key=lambda path: (path.stat().st_mtime_ns, path.name))
        if not paths:
            raise ValueError(f"no recipe receipts in {directory}")
        for path in paths:
            row = read_json(path)
            if row["executable_sha256"] != PINNED_SHA256:
                raise ValueError(f"receipt targets another executable: {path}")
            address = int(row["address"], 0)
            if address not in selected or not row.get("entry") or not row.get("source"):
                continue
            source = ROOT / row["source"]
            if (row["compiler"]["sha256"] != compiler or not source.is_file()
                    or hash_bytes(source.read_bytes()) != row["source_sha256"]):
                continue
            records[address] = {**row, "receipt": str(path)}
    return records


def plan(addresses, records, image):
    tracked = set(subprocess.check_output(["git", "ls-files", "-z", "--", "reconstructed/match"],
                                          cwd=ROOT, text=True).split("\0"))
    lengths = function_lengths()
    recipes, missing = [], {}
    for address in addresses:
        row = records.get(address)
        if row is None:
            missing[address] = "no current recorded recipe"
            continue
        source = (ROOT / row["source"]).resolve()
        if (not source.is_relative_to(ROOT) or str(source.relative_to(ROOT)) not in tracked
                or "asm" in source.relative_to(ROOT).parts):
            missing[address] = "recipe source is outside the tracked C/C++ drafts"
            continue
        if source.suffix.lower() not in {".c", ".cc", ".cpp", ".cxx"}:
            missing[address] = "recipe source is outside the tracked C/C++ drafts"
            continue
        contents = source.read_bytes()
        source_sha256 = hash_bytes(contents)
        if row.get("source_sha256", source_sha256) != source_sha256:
            missing[address] = "source has changed since the recipe was recorded"
            continue
        if re.search(rb"\b(?:__asm__|__asm|_asm)\b|\basm\s*[{(]", contents):
            missing[address] = "recipe uses inline assembly"
            continue
        length = row["length"]
        if not length or length != lengths.get(address):
            missing[address] = "recipe does not cover the contiguous indexed extent"
            continue
        recipes.append(Recipe(address, length, file_offset(image, address, length), source,
                              source_sha256, row["entry"], tuple(row["flags"]),
                              {name: int(va, 0) for name, va in row.get("symbol_overrides", {}).items()},
                              row.get("receipt")))
    return recipes, missing


def route_result(result, recipe, fixture, cache, behavior_recipe):
    status = result["status"]
    if status in {"strict", "unsupported", "error", "cache_missing"}:
        return {"route": {"strict": "verified", "unsupported": "link_review"}.get(status, status)}
    symbols = sorted({row["symbol"] for row in result["relocations"]
                      if row["target"] is None and row["target_section_index"] is None})
    if symbols:
        return {"route": "resolve_symbols", "symbols": symbols}
    if status == "blocked" or result["relocation_issues"]:
        return {"route": "review_strict_evidence"}
    if not fixture or not behavior_recipe.get("behavior_entry"):
        return {"route": "needs_fixture" if not fixture else "needs_behavior_entry"}
    try:
        baseline = verify(fixture)
        if baseline["failures"]:
            return {"route": "review_fixture", "first_divergence": baseline["failures"][0]}
        behavior = verify(fixture, source=recipe.source, cache=cache,
                          entry=behavior_recipe["behavior_entry"],
                          language=behavior_recipe.get("behavior_language", "c"))
    except (OSError, ValueError, KeyError, ImportError, struct.error, subprocess.TimeoutExpired) as error:
        return {"route": "behavior_error", "error": str(error)}
    if behavior["failures"]:
        return {"route": "inspect_mismatch", "first_divergence": behavior["failures"][0]}
    return {"route": "compiler_tuning", "behavior": behavior}


def linked_outputs(path, checked, original):
    functions = [row for spans, row in checked if spans]
    if not functions:
        raise ValueError("no strict linked spans to publish")
    spans = merged_spans([(row["address"], spans) for spans, row in checked if spans])
    image = assemble_image(original, [(int(row["file_offset"], 16), bytes.fromhex(row["hex_bytes"]))
                                      for row in spans])
    manifest = {"schema": "pc2.verified_linked_image_batch.v1", "functions": functions,
                "original": {"path": str(GAME), "sha256": PINNED_SHA256},
                "input": {"path": str(GAME), "sha256": PINNED_SHA256},
                "output": {"path": str(path.resolve()), "sha256": PINNED_SHA256}}
    return [(path, image), (path.with_name(path.name + ".manifest.json"),
                            (json.dumps(manifest, indent=2) + "\n").encode())]


def compiler_target(recipe):
    variants = []
    for option, alternatives in (("/O1", {"/Od", "/O1", "/O2"}), ("/O2", {"/Od", "/O1", "/O2"}),
                                 ("/Oy-", {"/Oy", "/Oy-"}), ("/G6", {"/G3", "/G4", "/G5", "/G6"})):
        if option in recipe.flags:
            continue
        flags = [flag for flag in recipe.flags if flag not in alternatives]
        variants.append({"name": option[1:], "source": str(recipe.source.relative_to(ROOT)),
                         "flags": " ".join([*flags, option])})
    return {"address": hex(recipe.address), "length": recipe.length, "entry": recipe.entry,
            "symbols": {name: hex(va) for name, va in recipe.symbols.items()}, "variants": variants}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--worklist", type=Path)
    parser.add_argument("--audit", type=Path, action="append", default=[])
    parser.add_argument("--recipes", type=Path, help="JSON list of reviewed recipes for a pilot or overrides")
    parser.add_argument("--fixture", type=Path, action="append", default=[], help="extracted offline fixtures")
    parser.add_argument("--fixture-profiles", type=Path, help="reviewed scalar-thiscall fixture plan template")
    parser.add_argument("--plan-out", type=Path, help="write a capture plan for queued addresses with reviewed profiles")
    parser.add_argument("--matrix-out", type=Path, help="write a bounded compiler retry matrix for behavior passes")
    parser.add_argument("--linked-out", type=Path, help="also publish a byte-identical scratch PE and its manifest")
    parser.add_argument("--only-address", action="append", default=[], type=lambda text: int(text, 0))
    parser.add_argument("--cache", required=True, type=Path)
    parser.add_argument("--cache-only", action="store_true", help="reuse retained COFF objects without starting Wine")
    parser.add_argument("--jobs", type=int, choices=range(1, 17), default=1, metavar="N")
    parser.add_argument("--out", required=True, type=Path, help="new batch report JSON")
    args = parser.parse_args()
    if not (args.worklist or args.recipes):
        parser.error("provide --worklist or --recipes")
    if bool(args.fixture_profiles) != bool(args.plan_out):
        parser.error("--fixture-profiles and --plan-out must be used together")
    try:
        paths = [path for path in (args.out, args.plan_out, args.matrix_out, args.linked_out) if path]
        if args.linked_out:
            paths.append(args.linked_out.with_name(args.linked_out.name + ".manifest.json"))
        if len({path.resolve() for path in paths}) != len(paths):
            raise ValueError("outputs require distinct paths")
        for path in paths:
            if path.exists() or path.is_symlink() or not path.parent.is_dir():
                raise ValueError(f"output must be a new file in an existing directory: {path}")
        image = pe_image(GAME)
        if hash_bytes(image[0]) != PINNED_SHA256:
            raise ValueError("canonical executable differs from the pinned image")
        worklist = read_json(args.worklist) if args.worklist else None
        rows = read_json(args.recipes) if args.recipes else []
        explicit = {int(row["address"], 0): row for row in rows}
        if len(explicit) != len(rows):
            raise ValueError("explicit recipes repeat an address")
        addresses = queue_addresses(worklist) if worklist is not None else list(explicit)
        if args.only_address:
            unknown = set(args.only_address) - set(addresses)
            if unknown:
                raise ValueError(f"selected addresses are outside the queue: {', '.join(map(hex, sorted(unknown)))}")
            addresses = [va for va in addresses if va in args.only_address]
        vc6 = DEFAULT_VC6.resolve()
        compiler = compiler_provenance(vc6)["sha256"]
        if any(value is None for value in compiler.values()):
            raise ValueError("VC6 compiler files are missing. See reconstructed/match/VC6_TOOLCHAIN.md")
        audits = args.audit or [Path(path) for path in (worklist or {}).get("audits", [])]
        records = audit_recipes(audits, set(addresses), compiler)
        records.update(explicit)
        recipes, missing = plan(addresses, records, image)
        fixtures = {}
        for path in args.fixture:
            fixture = read_json(path)
            if fixture["executable_sha256"] != PINNED_SHA256:
                raise ValueError(f"fixture targets another executable: {path}")
            by_address = defaultdict(list)
            for row in fixture["cases"]:
                by_address[int(row["address"], 0)].append(row)
            for address, cases in by_address.items():
                if address in fixtures:
                    raise ValueError(f"provide one fixture collection per address: {address:#x}")
                fixtures[address] = {**fixture, "cases": cases}
        coff = args.cache.resolve() / "coff"
        coff.mkdir(parents=True, exist_ok=True)
        environment = cache_environment()
        with tempfile.TemporaryDirectory(prefix="pc2-replay-batch-") as scratch:
            checked = verify_batch(recipes, args.jobs, vc6, Path(scratch), image[0], coff,
                                   cache_identity(vc6, ROOT, environment), environment, args.cache_only, assess=True)
        blockers = defaultdict(list)
        results = {address: {"address": hex(address), "route": "needs_recipe", "reason": reason}
                   for address, reason in missing.items()}
        for (_, result), recipe in zip(checked, recipes):
            address = recipe.address
            route = route_result(result, recipe, fixtures.get(address), args.cache.resolve() / "behavior",
                                 records[address])
            results[address] = {**result, **route}
            for symbol in route.get("symbols", []):
                blockers[symbol].append(hex(address))
        result = {"schema": "pc2.replay_batch_verification.v1", "executable_sha256": PINNED_SHA256,
                  "summary": dict(Counter(row["route"] for row in results.values())),
                  "cache": dict(Counter(row["cache"] for row in results.values() if "cache" in row)),
                  "shared_symbol_blockers": dict(sorted(blockers.items(), key=lambda item: (-len(item[1]), item[0]))),
                  "verified_addresses": [hex(va) for va in addresses if results[va]["route"] == "verified"],
                  "candidates": [results[va] for va in addresses]}
        extra = []
        if args.linked_out:
            if result["verified_addresses"]:
                extra = linked_outputs(args.linked_out, checked, image[0])
                result["linked_manifest"] = str(extra[-1][0].resolve())
            else:
                result["linked_manifest"] = None
        if args.plan_out:
            profiles = normalize_plan(read_json(args.fixture_profiles))
            queue = {va for va in addresses if results[va]["route"] in {"needs_fixture", "needs_recipe"}}
            targets = [row for row in profiles["targets"] if int(row["address"], 0) in queue]
            result["capture_plan"] = {"path": str(args.plan_out.resolve()) if targets else None,
                                      "targets": len(targets)}
            if targets:
                extra.append((args.plan_out, (json.dumps({**profiles, "targets": targets}, indent=2) + "\n").encode()))
        if args.matrix_out:
            targets = [compiler_target(recipe) for recipe in recipes
                       if results[recipe.address]["route"] == "compiler_tuning"]
            result["compiler_matrix"] = {"path": str(args.matrix_out.resolve()) if targets else None,
                                         "targets": len(targets)}
            if targets:
                extra.append((args.matrix_out, (json.dumps({"targets": targets}, indent=2) + "\n").encode()))
        write_outputs([*extra, (args.out, (json.dumps(result, indent=2) + "\n").encode())])
        print(f"{len(recipes)} checked, routes={result['summary']}, COFF cache={result['cache']}")
        return int(any(name in result["summary"] for name in ("error", "cache_missing", "behavior_error")))
    except (OSError, ValueError, KeyError, TypeError, subprocess.SubprocessError) as error:
        parser.exit(2, f"replay batch: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
