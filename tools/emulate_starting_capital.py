#!/usr/bin/env python3
"""Run the bounded Unicorn fixture for Game_GetStartingCapital.

The C harness maps the PE image at its preferred base, writes the difficulty
dword at 0x57bb24, and stops at the first RET. This wrapper compiles the
harness, runs every fixture case, compares EAX and emits one compact JSON
result to stdout. Diagnostics go to stderr.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULT_FIXTURE = os.path.join(
    ROOT, "decompiled_fastfood2_named_v2", "typed_packets", "fixtures",
    "game_get_starting_capital.fixture.json")
SOURCE = os.path.join(ROOT, "tools", "emulate_starting_capital.c")


def sha256_file(path):
    digest = hashlib.sha256()
    with open(path, "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def compile_harness(directory):
    compiler = shutil.which("gcc")
    if compiler is None:
        raise RuntimeError("gcc is not available")
    binary = os.path.join(directory, "emulate_starting_capital")
    result = subprocess.run(
        [compiler, "-O2", "-Wall", "-Wextra", SOURCE, "-o", binary, "-lunicorn"],
        cwd=ROOT, text=True, capture_output=True)
    if result.returncode != 0:
        raise RuntimeError(
            "cannot build Unicorn harness; is libunicorn installed? "
            + (result.stderr or result.stdout)[-600:])
    return binary


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--fixture", default=DEFAULT_FIXTURE)
    parser.add_argument("--exe", required=False)
    parser.add_argument("--json-out")
    args = parser.parse_args()
    fixture = json.load(open(args.fixture))
    exe = args.exe or os.path.join(ROOT, fixture["executable"]["path"])
    if sha256_file(exe) != fixture["executable"]["sha256"]:
        print("fixture executable sha256 mismatch", file=sys.stderr)
        return 2
    try:
        with tempfile.TemporaryDirectory() as directory:
            harness = compile_harness(directory)
            cases = []
            first_mismatch = None
            for case in fixture["cases"]:
                difficulty = case["memory"]["0x57bb24"]
                completed = subprocess.run(
                    [harness, exe, str(difficulty)],
                    cwd=ROOT, text=True, capture_output=True,
                    timeout=fixture["limits"]["wall_ms"] / 1000.0 * 4)
                if completed.returncode != 0:
                    print(
                        f"case {case['id']} failed: {completed.stderr.strip()}",
                        file=sys.stderr)
                    return 2
                result = json.loads(completed.stdout)
                actual = result["eax"]
                expected = case["expected_eax"]
                match = actual == expected
                cases.append({
                    "id": case["id"],
                    "difficulty": difficulty,
                    "expected_eax": expected,
                    "actual_eax": actual,
                    "match": match,
                    "instructions": result["instructions"],
                    "stop_address": result["stop_address"],
                    "stop_reason": result["stop_reason"],
                    "evidence": "emulated",
                })
                if not match and first_mismatch is None:
                    first_mismatch = {
                        "case": case["id"],
                        "field": "EAX",
                        "expected": expected,
                        "actual": actual,
                    }
    except (RuntimeError, subprocess.TimeoutExpired) as error:
        print(f"fixture pending: {error}", file=sys.stderr)
        return 2
    output = {
        "fixture": fixture["id"],
        "schema": "pc2.fixture_result.v1",
        "executable_sha256": fixture["executable"]["sha256"],
        "entry": fixture["entry"],
        "case_count": len(cases),
        "matches": sum(1 for case in cases if case["match"]),
        "first_mismatch": first_mismatch,
        "cases": cases,
    }
    text = json.dumps(output, separators=(",", ":"))
    if args.json_out:
        with open(args.json_out, "w") as fh:
            fh.write(text + "\n")
    print(text)
    return 0 if first_mismatch is None else 1


if __name__ == "__main__":
    raise SystemExit(main())
