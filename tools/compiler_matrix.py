#!/usr/bin/env python3
"""Run a bounded matrix of C/C++ variants through the strict match gate."""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from match_decomp import DEFAULT_VC6, GAME, ROOT, match, parse_symbols  # noqa: E402


def positive_count(text):
    count = int(text)
    if count < 1:
        raise argparse.ArgumentTypeError("expected a positive count")
    return count


def address_value(value):
    return int(value, 0) if isinstance(value, str) else int(value)


def symbol_map(config):
    return {name: address_value(address) for name, address in config.get("symbols", {}).items()}


def first_instruction(address: int, length: int, offset: int):
    try:
        result = subprocess.run(
            ["objdump", "-d", "-M", "intel",
             f"--start-address={address:#x}", f"--stop-address={address + length:#x}",
             str(GAME)], text=True, capture_output=True, check=True, timeout=10)
    except (OSError, subprocess.SubprocessError):
        return None
    current = None
    for line in result.stdout.splitlines():
        match = re.match(r"\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} )+)\s*(.*)", line)
        if not match:
            continue
        instruction_address = int(match.group(1), 16)
        if instruction_address - address <= offset:
            current = (instruction_address - address, match.group(2).strip(),
                       match.group(3).strip())
        else:
            break
    return current


def issues(result):
    return result.get("relocation_issues", []) + result.get("strict_issues", [])


def rank(result):
    return (not result.get("strict_match"), bool(result.get("error")), len(issues(result)),
            abs(result.get("candidate_length", 0) - result["length"]),
            result.get("difference_count", 0), result["address"], result["variant"])


def status(result):
    if result.get("error"):
        return result["error"].splitlines()[0]
    if result.get("strict_match"):
        return "STRICT PASS"
    blockers = issues(result)
    first = result.get("first_difference")
    detail = f" first={first['offset']:#x}" if first else ""
    if blockers:
        detail += f" issues={len(blockers)} ({blockers[0]})"
    return (f"bytes={result['difference_count']} extent={result['candidate_length']}/"
            f"{result['length']}{detail}")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("config", type=Path)
    parser.add_argument("--json-out", type=Path)
    parser.add_argument("--vc6", type=Path, default=DEFAULT_VC6)
    parser.add_argument("--target", action="append", default=[], type=address_value,
                        help="limit to configured target VA (repeatable)")
    parser.add_argument("--symbol", action="append", default=[], metavar="NAME=0xADDR",
                        help="override an independently known target (repeatable)")
    parser.add_argument("--max-attempts", type=positive_count, default=8)
    parser.add_argument("--top", type=positive_count, default=5,
                        help="print this many best results (default: 5)")
    parser.add_argument("--require-match", action="store_true",
                        help="return nonzero if no attempt passes strict verification")
    args = parser.parse_args()
    try:
        config = json.loads(args.config.read_text())
        overrides = parse_symbols(args.symbol)
        base_symbols = symbol_map(config)
        attempts = []
        selected = set()
        for target in config["targets"]:
            address = address_value(target["address"])
            if args.target and address not in args.target:
                continue
            selected.add(address)
            length = positive_count(target["length"])
            entry = target.get("entry")
            target_symbols = symbol_map(target)
            for variant in target["variants"]:
                symbols = {**base_symbols, **target_symbols, **symbol_map(variant), **overrides}
                attempts.append((address, length, entry, variant["name"],
                                 ROOT / variant["source"], variant.get("flags", "/O2").split(), symbols))
        if set(args.target) - selected:
            raise ValueError("--target must name a target from the config")
        if not attempts:
            raise ValueError("no variants selected")
    except (OSError, KeyError, TypeError, ValueError, AttributeError, argparse.ArgumentTypeError) as error:
        parser.error(str(error))

    results = []
    for address, length, entry, name, source, flags, symbols in attempts[:args.max_attempts]:
        with tempfile.TemporaryDirectory(prefix="pc2-matrix-") as directory:
            result = match(address, source, Path(directory) / "candidate.obj", args.vc6, flags,
                           symbols, length, entry, strict=True, auto_symbols=True)
        first = result.get("first_difference")
        result.update(variant=name, first_instruction=(
            first_instruction(address, length, first["offset"]) if first else None))
        results.append(result)

    results.sort(key=rank)
    omitted = len(attempts) - len(results)
    passes = sum(result["strict_match"] for result in results)
    failures = sum("error" in result for result in results)
    report = {"attempts": len(results), "omitted": omitted, "strict_passes": passes,
              "errors": failures, "results": results}
    if args.json_out:
        args.json_out.write_text(json.dumps(report, indent=2) + "\n")
    print(f"attempts={len(results)} strict={passes} errors={failures} omitted={omitted}")
    for result in results[:args.top]:
        print(f"{result['address']} {result['variant']} {status(result)}")
    return int(failures > 0 or (args.require_match and not passes))


if __name__ == "__main__":
    raise SystemExit(main())
