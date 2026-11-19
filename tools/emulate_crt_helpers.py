#!/usr/bin/env python3
"""Run bounded Unicorn checks for named MSVC CRT helpers.

The names in symbols.csv are semantic only if the behavior matches. These
cases exercise the mapped CRT block directly from the shipped PE.
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
SOURCE = os.path.join(ROOT, "tools", "emulate_crt_helpers.c")
EXE = os.path.join(ROOT, "game", "fastfood2.exe")

CASES = [
    {"id": "control_invalid_bit", "args": ["control", "1"], "expect": {"eax": 0x20010}},
    {"id": "control_inverse", "args": ["control_inv", "0x20010"], "expect": {"eax": 1}},
    {"id": "strcspn", "args": ["strcspn", "abc", "bx"], "expect": {"eax": 1}},
    {"id": "strpbrk", "args": ["strpbrk", "abc", "bx"], "expect": {"offset": 1}},
    {"id": "strnlen_short", "args": ["strnlen", "abc", "5"], "expect": {"eax": 3}},
    {"id": "strnlen_limit", "args": ["strnlen", "abc", "2"], "expect": {"eax": 2}},
    {"id": "addcarry_overflow", "args": ["addcarry", "0xffffffff", "1"], "expect": {"eax": 1, "sum": 0}},
    {"id": "addcarry_plain", "args": ["addcarry", "1", "2"], "expect": {"eax": 0, "sum": 3}},
]


def sha256_file(path: str) -> str:
    digest = hashlib.sha256()
    with open(path, "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def compile_harness(directory: str) -> str:
    compiler = shutil.which("gcc")
    if compiler is None:
        raise RuntimeError("gcc is not available")
    binary = os.path.join(directory, "emulate_crt_helpers")
    result = subprocess.run(
        [compiler, "-O2", "-Wall", "-Wextra", SOURCE, "-o", binary, "-lunicorn"],
        cwd=ROOT,
        text=True,
        capture_output=True,
    )
    if result.returncode != 0:
        raise RuntimeError(
            "cannot build Unicorn harness; is libunicorn installed? "
            + (result.stderr or result.stdout)[-600:]
        )
    return binary


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--exe", default=EXE)
    parser.add_argument("--json-out")
    args = parser.parse_args()
    try:
        with tempfile.TemporaryDirectory() as directory:
            harness = compile_harness(directory)
            results = []
            mismatch = None
            for case in CASES:
                completed = subprocess.run(
                    [harness, args.exe, *case["args"]],
                    cwd=ROOT,
                    text=True,
                    capture_output=True,
                    timeout=30,
                )
                if completed.returncode != 0:
                    print(
                        f"case {case['id']} failed: {completed.stderr.strip()}",
                        file=sys.stderr,
                    )
                    return 2
                actual = json.loads(completed.stdout)
                match = all(actual.get(key) == value for key, value in case["expect"].items())
                results.append(
                    {
                        "id": case["id"],
                        "args": case["args"],
                        "expected": case["expect"],
                        "actual": actual,
                        "match": match,
                    }
                )
                if not match and mismatch is None:
                    mismatch = {"case": case["id"], "actual": actual}
    except (RuntimeError, subprocess.TimeoutExpired) as error:
        print(f"fixture pending: {error}", file=sys.stderr)
        return 2

    output = {
        "fixture": "crt_helpers",
        "schema": "pc2.fixture_result.v1",
        "executable_sha256": sha256_file(args.exe),
        "case_count": len(results),
        "matches": sum(1 for item in results if item["match"]),
        "first_mismatch": mismatch,
        "cases": results,
    }
    text = json.dumps(output, separators=(",", ":"))
    if args.json_out:
        with open(args.json_out, "w", encoding="utf-8") as fh:
            fh.write(text + "\n")
    print(text)
    return 0 if mismatch is None else 1


if __name__ == "__main__":
    raise SystemExit(main())
