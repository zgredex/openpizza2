#!/usr/bin/env python3
"""Run the bounded Unicorn probe for an ingredient descriptor."""

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
SOURCE = os.path.join(ROOT, "tools", "emulate_ingredient_desc.c")
EXE = os.path.join(ROOT, "game", "fastfood2.exe")
EXPECTED = {
    "name": "Olives",
    "field_a8": 1,
    "field_ac": 7,
    "field_b0": 4,
    "field_b4": 2,
    "field_b8": 1,
    "field_c0": 0,
    "field_c4": 0x402E0000,
    "field_c8": 1,
}


def sha256_file(path: str) -> str:
    digest = hashlib.sha256()
    with open(path, "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--exe", default=EXE)
    parser.add_argument("--json-out")
    args = parser.parse_args()
    compiler = shutil.which("gcc")
    if compiler is None:
        print("gcc is not available", file=sys.stderr)
        return 2
    try:
        with tempfile.TemporaryDirectory() as directory:
            binary = os.path.join(directory, "emulate_ingredient_desc")
            build = subprocess.run(
                [compiler, "-O2", "-Wall", "-Wextra", SOURCE, "-o", binary, "-lunicorn"],
                cwd=ROOT,
                text=True,
                capture_output=True,
            )
            if build.returncode != 0:
                print(build.stderr[-1200:], file=sys.stderr)
                return 2
            completed = subprocess.run(
                [binary, args.exe], cwd=ROOT, text=True, capture_output=True, timeout=30
            )
            if completed.returncode != 0:
                print(completed.stderr[-1200:], file=sys.stderr)
                return 2
            payload = json.loads(completed.stdout)
    except (subprocess.TimeoutExpired, json.JSONDecodeError) as error:
        print(f"fixture pending: {error}", file=sys.stderr)
        return 2
    mismatch = {
        key: {"expected": expected, "actual": payload.get(key)}
        for key, expected in EXPECTED.items()
        if payload.get(key) != expected
    }
    output = {
        "fixture": "ingredient_descriptor",
        "schema": "pc2.fixture_result.v1",
        "executable_sha256": sha256_file(args.exe),
        "case_count": len(EXPECTED),
        "matches": len(EXPECTED) - len(mismatch),
        "first_mismatch": next(iter(mismatch.items()), None),
        "payload": payload,
    }
    text = json.dumps(output, separators=(",", ":"))
    if args.json_out:
        with open(args.json_out, "w", encoding="utf-8") as fh:
            fh.write(text + "\n")
    print(text)
    return 0 if not mismatch else 1


if __name__ == "__main__":
    raise SystemExit(main())
