#!/usr/bin/env python3
"""Run the bounded Unicorn fixture for Game_WindowProc command dispatch."""

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
    "game_window_command_dispatch.fixture.json")
SOURCE = os.path.join(ROOT, "tools", "emulate_clock_command.c")


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
    binary = os.path.join(directory, "emulate_clock_command")
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
    parser.add_argument("--exe")
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
                command = case["command"]
                completed = subprocess.run(
                    [harness, exe, command],
                    cwd=ROOT, text=True, capture_output=True,
                    timeout=fixture["limits"]["wall_ms"] / 1000.0 * 4)
                if completed.returncode != 0:
                    print(
                        f"case {case['id']} failed: {completed.stderr.strip()}",
                        file=sys.stderr)
                    return 2
                result = json.loads(completed.stdout)
                actual = {
                    "target": result["target"],
                    "eax": result["eax"],
                    "ecx": result["ecx"],
                }
                expected = {
                    "target": case["expected_target"],
                    "eax": case["expected_eax"],
                    "ecx": case["expected_ecx"],
                }
                match = actual == expected
                cases.append({
                    "id": case["id"],
                    "command": command,
                    "expected": expected,
                    "actual": actual,
                    "match": match,
                    "instructions": result["instructions"],
                    "evidence": "emulated",
                })
                if not match and first_mismatch is None:
                    field = next(key for key in expected
                                 if expected[key] != actual[key])
                    first_mismatch = {
                        "case": case["id"],
                        "field": field,
                        "expected": expected[field],
                        "actual": actual[field],
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
