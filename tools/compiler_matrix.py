#!/usr/bin/env python3
"""Run a small matrix of C/C++ variants against one original function."""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from match_decomp import DEFAULT_VC6, GAME, match  # noqa: E402


def sha256(path: Path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def first_instruction(address: int, length: int, offset: int):
    result = subprocess.run(
        ["objdump", "-d", "-M", "intel",
         f"--start-address={address:#x}", f"--stop-address={address + length:#x}",
         str(GAME)], text=True, capture_output=True, check=True)
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


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("config", type=Path)
    parser.add_argument("--json-out", type=Path)
    parser.add_argument("--vc6", type=Path, default=DEFAULT_VC6)
    args = parser.parse_args()
    config = json.loads(args.config.read_text())
    cl = args.vc6 / "BIN" / "CL.EXE"
    c2 = args.vc6 / "BIN" / "C2.DLL"
    link = args.vc6 / "BIN" / "LINK.EXE"
    compiler = {str(path.name): sha256(path) for path in (cl, c2, link)}
    results = []
    for target in config["targets"]:
        address = int(target["address"], 16)
        length = target["length"]
        entry = target.get("entry")
        for variant in target["variants"]:
            source = Path(variant["source"])
            flags = variant.get("flags", "/O2")
            with tempfile.TemporaryDirectory(prefix="pc2-matrix-") as directory:
                obj = Path(directory) / "candidate.obj"
                try:
                    result = match(address, source, obj, args.vc6, flags.split(),
                                   {}, length, entry, False, False)
                    first = result.get("first_difference")
                    if first:
                        instruction = first_instruction(address, length, first["offset"])
                    else:
                        instruction = None
                    result.update({
                        "variant": variant["name"], "flags": flags,
                        "compiler": compiler,
                        "first_instruction": instruction,
                    })
                except Exception as error:
                    result = {"variant": variant["name"], "flags": flags,
                              "compiler": compiler, "match": False,
                              "error": str(error)}
            results.append(result)
            print(f"{target['address']} {variant['name']:20} "
                  f"{'MATCH' if result.get('match') else 'diff=' + str(result.get('difference_count'))}")
    report = {"compiler": compiler, "results": results}
    text = json.dumps(report, indent=2)
    if args.json_out:
        args.json_out.write_text(text + "\n")
    print(json.dumps(report, indent=2)[:4000])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
