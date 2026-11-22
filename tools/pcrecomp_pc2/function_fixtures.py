#!/usr/bin/env python3
"""Extract reviewed function snapshots and recheck them without booting PC2."""

from __future__ import annotations

import argparse
from collections import Counter
import inspect
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from check_decomp import compile_candidate, load_original, parse_elf, run_case, run_command, sha256
from decomp_fixtures import Case, PE_HASH, ROOT, Routine, SCRATCH, words

SURFACE = 0x539F20
CLAMP = 0x52A3A0
NAMES = {SURFACE: "Surface_ResetFlags", CLAMP: "UI_SetClampedValue"}
SNAPSHOT = struct.Struct("<14I")
SCHEMA = "pc2.function_fixtures.v1"
REGRESSIONS = {SURFACE: ((0x539F2E, b"\x89\x61\x74"), (0x539F81, b"\x89\x61\x74")),
               CLAMP: ((0x52A3F7, b"\x90"),)}  # shift the destination four bytes


def read_json(path):
    return json.loads(path.read_text())


def output_json(output, result):
    with output.open("x") as stream:
        json.dump(result, stream, indent=2)
        stream.write("\n")


def watched_offsets(address, args):
    if address == SURFACE and not args:
        return (0x74,)
    if address == CLAMP and len(args) == 2 and 0 <= args[1] <= 3:
        return (0x8C + 4 * args[1], 0x9C, 0xA0, 0xB8, 0x388)
    raise ValueError(f"unsupported fixture ABI at {address:#x}")


def make_case(address, args, before, after, guest_object=None):
    row = {"address": hex(address), "name": NAMES[address], "arguments": list(args),
           "before": {hex(offset): value for offset, value in zip(watched_offsets(address, args), before)},
           "after": {hex(offset): value for offset, value in zip(watched_offsets(address, args), after)}}
    if guest_object is not None:
        row["captured_ecx"] = hex(guest_object)
    return row


def extract(directory, cache=None):
    run = read_json(directory / "run.json")
    report = read_json(directory / "report.json")
    if (run["guest_sha256"] != PE_HASH or report["run"] != run or not report["complete"]
            or report["format"] != "pc2.capture.v1"):
        raise ValueError("a complete capture of the pinned executable is required")
    payload = (directory / "function-fixtures.bin").read_bytes()
    snapshots = run["function_fixtures"]
    if snapshots != {"format": "pc2.function_snapshots.v1", "sha256": sha256(payload)}:
        raise ValueError("function snapshots do not match the recorded format or SHA-256")
    source = {"kind": "headless_capture", "scenario": report["scenario"],
              "directory": str(directory.resolve()), "snapshots_sha256": snapshots["sha256"]}
    key = sha256(json.dumps([SCHEMA, PE_HASH, source], sort_keys=True).encode())
    cached = cache / f"{key}.json" if cache is not None else None
    if cached is not None and cached.is_file():
        result = read_json(cached)
        if result["source"] != source or result["schema"] != SCHEMA or result["executable_sha256"] != PE_HASH:
            raise ValueError("cached function fixture has incorrect capture provenance")
        return result, True
    cases, skipped, seen = [], Counter(), set()
    for address, guest_object, arg0, arg1, *values in SNAPSHOT.iter_unpack(payload):
        args = () if address == SURFACE else (arg0, arg1)
        if address == CLAMP and values[3]:
            skipped["clamp text callback"] += 1
            continue
        row = make_case(address, args, values[:5], values[5:], guest_object)
        if address == SURFACE and values[2]:
            row["cpuid_edx"] = values[1]
        key = address, args, tuple(row["before"].values()), tuple(row["after"].values()), row.get("cpuid_edx")
        if key not in seen:
            seen.add(key)
            cases.append(row)
    if not cases:
        raise ValueError(f"capture contains no supported completed function snapshots: {dict(skipped)}")
    result = {"schema": SCHEMA, "executable_sha256": PE_HASH, "source": source,
              "skipped": dict(skipped), "cases": cases}
    if cached is not None:
        cache.mkdir(parents=True, exist_ok=True)
        with tempfile.NamedTemporaryFile(mode="w", dir=cache) as stream:
            json.dump(result, stream, indent=2)
            stream.write("\n")
            stream.flush()
            try:
                os.link(stream.name, cached)
            except FileExistsError:
                pass
    return result, False


def reviewed_case(row):
    address = int(row["address"], 16)
    args = tuple(row["arguments"])
    offsets = watched_offsets(address, args)
    keys = {hex(offset) for offset in offsets}
    if row["name"] != NAMES[address] or set(row["before"]) != keys or row["after"] and set(row["after"]) != keys:
        raise ValueError(f"invalid fixture offsets at {address:#x}")
    values = tuple((offset, row["before"][hex(offset)]) for offset in offsets)
    if address == CLAMP and dict(values)[0xB8]:
        raise ValueError("the UI text callback requires a separate fixture contract")
    case = Case(NAMES[address], args, ecx=SCRATCH, memory=tuple((SCRATCH + offset, words(value)) for offset, value in values))
    routine = Routine(address, NAMES[address], "tools/pcrecomp_pc2/function_fixtures.py", "pc2_candidate",
                      (case,), "void", "capture", stack_cleanup=4 * len(args),
                      observations=tuple((hex(offset), SCRATCH + offset, 4) for offset in offsets),
                      writable=((SCRATCH + offsets[0], 4),))
    return routine, case


def replay_case(pe, row, candidate=None, patch=()):
    routine, case = reviewed_case(row)
    result = run_case(pe, routine, case, candidate, patches=patch, cpuid_edx=row.get("cpuid_edx"))
    return {key: int.from_bytes(bytes.fromhex(value), "little") for key, value in result.items()}


def reference_cases():
    pe = load_original()
    rows = [make_case(SURFACE, (), (0xDEADBEEF,), ()),
            make_case(CLAMP, (150, 0), (7, 10, 100, 0, 1), ()),
            make_case(CLAMP, (150, 1), (7, 100, 10, 0, 1), ()),
            make_case(CLAMP, (150, 2), (7, 10, 100, 0, 0), ())]
    for row in rows:
        row["after"] = replay_case(pe, row)
    return {"schema": SCHEMA, "executable_sha256": PE_HASH,
            "source": {"kind": "isolated_original", "description": "Seeded inputs executed in the pinned PE"},
            "skipped": {}, "cases": rows}


def candidate_identity(source, contents, routine):
    nonhermetic = (b"#", b"%:", b"??", b"\\\n", b"\\\r", b"asm",
                   b"__DATE__", b"__TIME__", b"__TIMESTAMP__", b"_Pragma")
    if not contents.isascii() or any(marker in contents for marker in nonhermetic):
        return None, None
    env = {key: value for key, value in os.environ.items() if key in {"PATH", "HOME", "TMPDIR", "LANG"} or key.startswith("LC_")}
    paths = [shutil.which(name, path=env.get("PATH", os.defpath)) for name in ("gcc", "as", "ld")]
    if None in paths:
        return None, None
    cc1 = run_command([paths[0], "-print-prog-name=cc1"], env).strip()
    if not Path(cc1).is_file():
        return None, None
    tools = [(str(Path(path).resolve()), sha256(Path(path).read_bytes())) for path in [*paths, cc1]]
    key = sha256(json.dumps([str(source), sha256(contents), routine.address, routine.entry,
                             inspect.getsource(compile_candidate), tools, env], sort_keys=True).encode())
    return key, env


def compiled_candidate(routine, source, cache):
    source = source.resolve(strict=True)
    contents = source.read_bytes()
    key, environment = candidate_identity(source, contents, routine) if cache is not None else (None, None)
    cached = cache / f"{key}.elf" if key is not None else None
    if cached is not None and cached.is_symlink():
        raise ValueError("compiled fixture cache entry is a symlink")
    if cached is not None and cached.exists():
        data = cached.read_bytes()
        return parse_elf(data), {"cache": "hit", "sha256": sha256(data)}
    with tempfile.TemporaryDirectory(prefix="pc2-function-fixture-") as directory:
        data = compile_candidate(routine, source, Path(directory), "gcc", "ld", environment=environment)
    if source.read_bytes() != contents:
        raise ValueError("candidate source changed during compilation")
    candidate = parse_elf(data)
    if cached is not None:
        cache.mkdir(parents=True, exist_ok=True)
        with tempfile.NamedTemporaryFile(dir=cache) as stream:
            stream.write(data)
            stream.flush()
            try:
                os.link(stream.name, cached)
            except FileExistsError:
                pass
    return candidate, {"cache": "miss" if cached is not None else "bypass", "sha256": sha256(data)}


def verify(fixture, source=None, regression=False, repeat=1, cache=None):
    rows = fixture["cases"]
    if fixture["schema"] != SCHEMA or fixture["executable_sha256"] != PE_HASH or not rows:
        raise ValueError("fixture does not match the pinned executable")
    if source and len({row["address"] for row in rows}) != 1:
        raise ValueError("select one function before checking a compiled candidate")
    pe = load_original()
    candidate = artifact = None
    if source:
        routine, _ = reviewed_case(rows[0])
        candidate, artifact = compiled_candidate(routine, source, cache)
    failures, passed = [], Counter()
    for row in rows:
        if not row["after"]:
            raise ValueError("fixture is missing its observed return snapshot")
        for attempt in range(1, repeat + 1):
            try:
                actual = replay_case(pe, row, candidate, REGRESSIONS[int(row["address"], 16)] if regression else ())
            except ValueError as error:
                failures.append({"function": row["name"], "attempt": attempt, "error": str(error)})
                break
            if actual != row["after"]:
                failures.append({"function": row["name"], "attempt": attempt, "fields": {
                    key: {"expected": expected, "actual": actual.get(key)}
                    for key, expected in row["after"].items() if actual.get(key) != expected}})
                break
            passed[row["name"]] += 1
    route = "inspect_mismatch" if failures else "strict_match" if candidate else "candidate_check"
    return {"source": fixture["source"], "candidate": artifact, "passed": dict(passed), "failures": failures,
            "repeat": repeat, "route": route}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    exp = sub.add_parser("extract")
    exp.add_argument("directory", type=Path)
    exp.add_argument("--out", type=Path, required=True)
    exp.add_argument("--cache", type=Path, help="optionally reuse an extraction keyed by capture provenance")
    ref = sub.add_parser("reference", help="generate separate bootless original-function smoke cases")
    ref.add_argument("--out", type=Path, required=True)
    run = sub.add_parser("verify")
    run.add_argument("fixture", type=Path)
    run.add_argument("--address", type=lambda value: int(value, 0))
    run.add_argument("--source", type=Path, help="C candidate exposing pc2_candidate with the original i386 ABI")
    run.add_argument("--cache", type=Path, help="reuse compiled self-contained C candidate objects")
    run.add_argument("--regression", action="store_true", help="verify deliberately modified original code")
    run.add_argument("--repeat", type=int, default=1)
    args = parser.parse_args()
    try:
        if args.command in {"extract", "reference"}:
            if args.command == "extract":
                result, hit = extract(args.directory, args.cache)
            else:
                result, hit = reference_cases(), False
            output_json(args.out, result)
            print(json.dumps({"cases": dict(Counter(row["name"] for row in result["cases"])), "cache_hit": hit}))
            return 0
        if not 1 <= args.repeat <= 100 or args.source and args.regression:
            raise ValueError("repeat must be 1–100 and source and regression are mutually exclusive")
        fixture = read_json(args.fixture)
        if args.address is not None:
            fixture["cases"] = [row for row in fixture["cases"] if int(row["address"], 16) == args.address]
        if args.cache and not args.source:
            raise ValueError("verification cache requires --source")
        report = verify(fixture, args.source, args.regression, args.repeat, args.cache)
        print(json.dumps(report, indent=2))
        return int(bool(report["failures"]))
    except (OSError, ValueError, KeyError, ImportError, struct.error, subprocess.TimeoutExpired) as error:
        parser.exit(2, f"function fixtures: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
