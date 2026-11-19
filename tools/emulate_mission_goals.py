#!/usr/bin/env python3
"""Run bounded Unicorn probes for London mission-goal evaluation.

This wraps tools/emulate_mission_goals.c.  The C harness maps the shipped PE,
places a synthetic player-mission state, patches the two external goal probes,
and calls the original Mission_EvaluateGoals (0x4f5fd0).  The expected values
come from the REA pseudocode:

* goal 0 (HQ level) completes when Game_GetPlayerFieldC20 > 2;
* goal 1 (rat) completes when mission-state +0x14 > 0;
* goal 2 (owned branch) completes when Game_CountRecordsWithFlag16F4 != 0.
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
SOURCE = os.path.join(ROOT, "tools", "emulate_mission_goals.c")
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
    binary = os.path.join(directory, "emulate_mission_goals")
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


CASES = [
    {
        "id": "rat_delivery_writes_slot_1",
        "args": ["array", "0"],
        "expect": {"mode": "array", "slot_14": 1},
    },
    {
        "id": "no_goals_complete",
        "args": ["evaluate", "0", "1", "2", "0", "0", "0"],
        "expect": {"completed": [0, 0, 0]},
    },
    {
        "id": "goal0_needs_more_than_2",
        "args": ["evaluate", "0", "1", "2", "0", "2", "0"],
        "expect": {"completed": [0, 0, 0]},
    },
    {
        "id": "goal0_level3",
        "args": ["evaluate", "0", "1", "2", "0", "3", "0"],
        "expect": {"completed": [1, 0, 0]},
    },
    {
        "id": "goal1_needs_progress",
        "args": ["evaluate", "0", "1", "2", "0", "0", "0"],
        "expect": {"completed": [0, 0, 0]},
    },
    {
        "id": "goal1_progress",
        "args": ["evaluate", "0", "1", "2", "1", "0", "0"],
        "expect": {"completed": [0, 1, 0]},
    },
    {
        "id": "goal2_needs_flagged_record",
        "args": ["evaluate", "0", "1", "2", "0", "0", "0"],
        "expect": {"completed": [0, 0, 0]},
    },
    {
        "id": "goal2_flagged_record",
        "args": ["evaluate", "0", "1", "2", "0", "0", "1"],
        "expect": {"completed": [0, 0, 1]},
    },
    {
        "id": "all_goals_complete",
        "args": ["evaluate", "0", "1", "2", "1", "3", "1"],
        "expect": {"completed": [1, 1, 1]},
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
        "fixture": "mission_goal_evaluation",
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
