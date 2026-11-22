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
from match_decomp import function_length

if __package__:
    from .fixture_plan import HEADER as PLAN_HEADER, MAGIC as PLAN_MAGIC, SNAPSHOT as PLANNED_SNAPSHOT, normalize_plan
else:
    from fixture_plan import HEADER as PLAN_HEADER, MAGIC as PLAN_MAGIC, SNAPSHOT as PLANNED_SNAPSHOT, normalize_plan

SURFACE = 0x539F20
CLAMP = 0x52A3A0
NAMES = {SURFACE: "Surface_ResetFlags", CLAMP: "UI_SetClampedValue"}
SNAPSHOT = struct.Struct("<14I")
SCHEMA = "pc2.function_fixtures.v1"
PLANNED_SCHEMA = "pc2.function_fixtures.v2"
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


def planned_rows(payload, plan):
    targets = {int(target["address"], 16): target for target in plan["targets"]}
    if payload[:PLAN_HEADER.size] != PLAN_HEADER.pack(PLAN_MAGIC, len(targets)):
        raise ValueError("recorded snapshot header does not match the capture plan")
    for address, guest_object, *fields in PLANNED_SNAPSHOT.iter_unpack(payload[PLAN_HEADER.size:]):
        target = targets.get(address)
        if not target:
            raise ValueError(f"fixture snapshot target {address:#x} is outside its capture plan")
        offsets = [field["offset"] for field in target["fields"]]
        before = dict(zip(offsets, fields[4:12]))
        after = dict(zip(offsets, fields[12:20]))
        if target["return"] == "eax":
            after["EAX"] = fields[20]
        yield {"address": hex(address), "name": target["name"], "arguments": fields[:target["argument_words"]],
               "before": before, "after": after, "captured_ecx": hex(guest_object)}


def extract(directory, cache=None):
    run = read_json(directory / "run.json")
    report = read_json(directory / "report.json")
    if (run["guest_sha256"] != PE_HASH or report["run"] != run or not report["complete"]
            or report["format"] != "pc2.capture.v1"):
        raise ValueError("a complete capture of the pinned executable is required")
    payload = (directory / "function-fixtures.bin").read_bytes()
    snapshots = run["function_fixtures"]
    plan = None
    schema = SCHEMA
    format = snapshots["format"]
    if snapshots["sha256"] != sha256(payload) or format not in {"pc2.function_snapshots.v1", "pc2.function_snapshots.v2"}:
        raise ValueError("function snapshots do not match the recorded format or SHA-256")
    if format == "pc2.function_snapshots.v2":
        plan_bytes = (directory / "function-fixture-plan.json").read_bytes()
        if snapshots["plan_sha256"] != sha256(plan_bytes):
            raise ValueError("function fixture plan SHA-256 differs from capture metadata")
        plan = normalize_plan(json.loads(plan_bytes))
        schema = PLANNED_SCHEMA
    source = {"kind": "headless_capture", "scenario": report["scenario"],
              "directory": str(directory.resolve()), "snapshots_sha256": snapshots["sha256"]}
    if plan:
        source["plan_sha256"] = snapshots["plan_sha256"]
    key = sha256(json.dumps([schema, PE_HASH, source], sort_keys=True).encode())
    cached = cache / f"{key}.json" if cache is not None else None
    if cached is not None and cached.is_file():
        result = read_json(cached)
        if result["source"] != source or result["schema"] != schema or result["executable_sha256"] != PE_HASH:
            raise ValueError("cached function fixture has incorrect capture provenance")
        return result, True
    cases, skipped, seen = [], Counter(), set()
    if plan:
        candidates = planned_rows(payload, plan)
    else:
        candidates = legacy_rows(payload, skipped)
    for row in candidates:
        key = (row["address"], tuple(row["arguments"]), tuple(row["before"].items()),
               tuple(row["after"].items()), row.get("cpuid_edx"))
        if key not in seen:
            seen.add(key)
            cases.append(row)
    if not cases:
        raise ValueError(f"capture contains no supported completed function snapshots: {dict(skipped)}")
    result = {"schema": schema, "executable_sha256": PE_HASH, "source": source,
              "skipped": dict(skipped), "cases": cases}
    if plan:
        result["plan"] = plan
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


def legacy_rows(payload, skipped):
    for address, guest_object, arg0, arg1, *values in SNAPSHOT.iter_unpack(payload):
        args = () if address == SURFACE else (arg0, arg1)
        if address == CLAMP and values[3]:
            skipped["clamp text callback"] += 1
            continue
        row = make_case(address, args, values[:5], values[5:], guest_object)
        if address == SURFACE and values[2]:
            row["cpuid_edx"] = values[1]
        yield row


def reviewed_case(row, entry="pc2_candidate"):
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
    routine = Routine(address, NAMES[address], "tools/pcrecomp_pc2/function_fixtures.py", entry,
                      (case,), "void", "capture", stack_cleanup=4 * len(args),
                      observations=tuple((hex(offset), SCRATCH + offset, 4) for offset in offsets),
                      writable=((SCRATCH + offsets[0], 4),))
    return routine, case


def planned_case(row, target, entry):
    address = int(row["address"], 16)
    args = tuple(row["arguments"])
    if row["name"] != target["name"] or len(args) != target["argument_words"] or any(
            type(arg) is not int or not 0 <= arg <= 0xffffffff for arg in args):
        raise ValueError(f"fixture arguments differ from plan at {address:#x}")
    fields = {field["offset"]: field for field in target["fields"]}
    expected = set(fields) | ({"EAX"} if target["return"] == "eax" else set())
    if set(row["before"]) != fields.keys() or set(row["after"]) != expected:
        raise ValueError(f"fixture object and return fields differ from plan at {address:#x}")
    memory, observed, written = [], [], []
    for offset, field in fields.items():
        size = field["size"]
        va = SCRATCH + int(offset, 16)
        for state in ("before", "after"):
            value = row[state][offset]
            if type(value) is not int or not 0 <= value < 1 << (size * 8):
                raise ValueError(f"fixture value does not fit field {offset}")
        memory.append((va, row["before"][offset].to_bytes(size, "little")))
        observed.append((offset, va, size))
        if field["writable"]:
            written.append((va, size))
    case = Case(target["name"], args, ecx=SCRATCH, memory=tuple(memory))
    routine = Routine(address, target["name"], "tools/pcrecomp_pc2/function_fixtures.py", entry,
                      (case,), target["return"], "capture", stack_cleanup=4 * len(args),
                      observations=tuple(observed), writable=tuple(written))
    return routine, case


def replay_case(pe, row, candidate=None, patch=(), target=None, entry="pc2_candidate"):
    routine, case = planned_case(row, target, entry) if target else reviewed_case(row, entry)
    bounds = {"read_ranges": [(va, len(data)) for va, data in case.memory],
              "original_extent": function_length(routine.address)} if target else {}
    result = run_case(pe, routine, case, candidate, patches=patch, cpuid_edx=row.get("cpuid_edx"), **bounds)
    return {key: int(value, 16) if key == "EAX" else int.from_bytes(bytes.fromhex(value), "little")
            for key, value in result.items()}


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


def candidate_identity(source, contents, routine, language="c"):
    nonhermetic = (b"#", b"%:", b"??", b"\\\n", b"\\\r", b"asm",
                   b"__DATE__", b"__TIME__", b"__TIMESTAMP__", b"_Pragma")
    if not contents.isascii() or any(marker in contents for marker in nonhermetic):
        return None, None
    env = {key: value for key, value in os.environ.items() if key in {"PATH", "HOME", "TMPDIR", "LANG"} or key.startswith("LC_")}
    compiler, frontend = ("g++", "cc1plus") if language == "c++" else ("gcc", "cc1")
    paths = [shutil.which(name, path=env.get("PATH", os.defpath)) for name in (compiler, "as", "ld")]
    if None in paths:
        return None, None
    cc1 = run_command([paths[0], f"-print-prog-name={frontend}"], env).strip()
    if not Path(cc1).is_file():
        return None, None
    tools = [(str(Path(path).resolve()), sha256(Path(path).read_bytes())) for path in [*paths, cc1]]
    key = sha256(json.dumps([str(source), sha256(contents), routine.address, routine.entry, language,
                             inspect.getsource(compile_candidate), tools, env], sort_keys=True).encode())
    return key, env


def compiled_candidate(routine, source, cache, language="c"):
    source = source.resolve(strict=True)
    contents = source.read_bytes()
    key, environment = candidate_identity(source, contents, routine, language) if cache is not None else (None, None)
    cached = cache / f"{key}.elf" if key is not None else None
    if cached is not None and cached.is_symlink():
        raise ValueError("compiled fixture cache entry is a symlink")
    if cached is not None and cached.exists():
        data = cached.read_bytes()
        return parse_elf(data), {"cache": "hit", "sha256": sha256(data)}
    with tempfile.TemporaryDirectory(prefix="pc2-function-fixture-") as directory:
        compiler = "g++" if language == "c++" else "gcc"
        data = compile_candidate(routine, source, Path(directory), compiler, "ld", environment=environment, language=language)
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


def verify(fixture, source=None, regression=False, repeat=1, cache=None, *, entry=None, language="c"):
    rows = fixture["cases"]
    schema = fixture["schema"]
    if schema not in {SCHEMA, PLANNED_SCHEMA} or fixture["executable_sha256"] != PE_HASH or not rows:
        raise ValueError("fixture does not match the pinned executable")
    targets = {}
    if schema == PLANNED_SCHEMA:
        targets = {target["address"]: target for target in normalize_plan(fixture["plan"])["targets"]}
        if any(row["address"] not in targets for row in rows):
            raise ValueError("fixture includes a case outside its capture plan")
        if regression:
            raise ValueError("planned regressions require an intentionally changed candidate source")
    entry = entry or "pc2_candidate"
    if source and len({row["address"] for row in rows}) != 1:
        raise ValueError("select one function before checking a compiled candidate")
    if language not in {"c", "c++"}:
        raise ValueError(f"unsupported candidate language: {language}")
    pe = load_original()
    candidate = artifact = None
    if source:
        target = targets.get(rows[0]["address"])
        routine, _ = planned_case(rows[0], target, entry) if target else reviewed_case(rows[0], entry)
        candidate, artifact = compiled_candidate(routine, source, cache, language)
    failures, passed = [], Counter()
    for row in rows:
        if not row["after"]:
            raise ValueError("fixture is missing its observed return snapshot")
        for attempt in range(1, repeat + 1):
            try:
                actual = replay_case(pe, row, candidate, REGRESSIONS[int(row["address"], 16)] if regression else (),
                                     targets.get(row["address"]), entry)
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
    run.add_argument("--entry", help="alternate ELF candidate entry (defaults to pc2_candidate)")
    run.add_argument("--language", choices=("c", "c++"), default="c", help="compiled candidate language")
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
        report = verify(fixture, args.source, args.regression, args.repeat, args.cache, entry=args.entry,
                        language=args.language)
        print(json.dumps(report, indent=2))
        return int(bool(report["failures"]))
    except (OSError, ValueError, KeyError, ImportError, struct.error, subprocess.TimeoutExpired) as error:
        parser.exit(2, f"function fixtures: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
