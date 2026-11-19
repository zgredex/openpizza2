#!/usr/bin/env python3
"""Run bounded Unicorn probes for the free-play cash-multiplier path.

Covers three original byte ranges:

* Settings_InitDefaults 0x406B7F..0x406BA7 - the base-0x30 loop that fills the
  six multiplier slots at 0x57B97C with 100.
* FreePlaySetup_InitWindow 0x4CBEB2..0x4CBED8 - copies the three parallel
  setting arrays into six 0xC0-stride profiles at 0x57BCD8.
* Game_InitScenario 0x48203D..0x482063 - applies (multiplier * capital)/100 for
  the free-play player starting cash.
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
SOURCE = os.path.join(ROOT, "tools", "emulate_freeplay_profiles.c")
EXE = os.path.join(ROOT, "game", "fastfood2.exe")


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
    binary = os.path.join(directory, "emulate_freeplay_profiles")
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


def parse_output(text: str) -> dict:
    values = {}
    for line in text.splitlines():
        if "=" not in line:
            continue
        key, value = line.split("=", 1)
        values[key.strip()] = int(value.strip())
    return values


CASES = [
    {
        "id": "init_defaults",
        "args": ["init"],
        "expect": {
            "p0_multiplier": 100, "p1_multiplier": 100,
            "p2_multiplier": 100, "p3_multiplier": 100,
            "p4_multiplier": 100, "p5_multiplier": 100,
            "p0_second": 0, "p5_second": 0,
            "p0_active": 1, "p1_active": 1, "p2_active": 0,
            "p3_active": 0, "p4_active": 0, "p5_active": 0,
        },
    },
    {
        "id": "copy_profiles",
        "args": ["copy"],
        "expect": {
            "p0_multiplier": 100, "p1_multiplier": 101,
            "p2_multiplier": 102, "p3_multiplier": 103,
            "p4_multiplier": 104, "p5_multiplier": 105,
            "p0_second": 10, "p5_second": 15,
            "p0_active": 1, "p1_active": 0, "p2_active": 1,
            "p3_active": 0, "p4_active": 1, "p5_active": 0,
        },
    },
    {
        "id": "cash_default",
        "args": ["cash", "100", "50000"],
        "expect": {"starting_cash": 50000},
    },
    {
        "id": "cash_half",
        "args": ["cash", "50", "50000"],
        "expect": {"starting_cash": 25000},
    },
    {
        "id": "cash_one_and_half",
        "args": ["cash", "150", "50000"],
        "expect": {"starting_cash": 75000},
    },
    {
        "id": "cash_zero_multiplier",
        "args": ["cash", "0", "50000"],
        "expect": {"starting_cash": 0},
    },
    {
        "id": "cash_negative_multiplier",
        "args": ["cash", "-50", "50000"],
        "expect": {"starting_cash": -25000},
    },
    {
        "id": "cash_32bit_product_wrap",
        "args": ["cash", "65536", "65536"],
        "expect": {"starting_cash": 0},
    },
    {
        "id": "cash_large_wrap",
        "args": ["cash", "65536", "50000"],
        "expect": {"starting_cash": -10181672},
    },
]


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
                actual = parse_output(completed.stdout)
                match = all(actual.get(key) == value
                            for key, value in case["expect"].items())
                results.append({
                    "id": case["id"],
                    "args": case["args"],
                    "expected": case["expect"],
                    "actual": actual,
                    "match": match,
                })
                if not match and mismatch is None:
                    mismatch = {"case": case["id"], "actual": actual}
    except (RuntimeError, subprocess.TimeoutExpired) as error:
        print(f"fixture pending: {error}", file=sys.stderr)
        return 2

    output = {
        "fixture": "freeplay_cash_multiplier",
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
