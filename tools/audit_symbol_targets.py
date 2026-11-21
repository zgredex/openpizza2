#!/usr/bin/env python3
"""Select exact-symbol users from a strict audit for bounded compiler replay."""

from __future__ import annotations

import argparse
import json
from pathlib import Path

from match_decomp import GAME, ROOT, file_sha256
from symbol_registry import load_registry


def select_records(directory, symbols, unverified_only, executable_sha256):
    targets = {}
    for path in sorted(directory.glob("*.json")):
        record = json.loads(path.read_text())
        affected = {fixup["symbol"] for fixup in record.get("relocations", [])
                    if fixup["symbol"] in symbols and (not unverified_only or not fixup["verified"])}
        if not affected:
            continue
        if record["executable_sha256"] != executable_sha256:
            raise ValueError(f"{path.name}: audit target differs from game/fastfood2.exe")
        source = (ROOT / record["source"]).resolve()
        if file_sha256(source) != record["source_sha256"] or not source.is_file():
            raise ValueError(f"{path.name}: audited source is missing or changed ({source})")
        key = record["address"], record["length"], record["entry"]
        target = targets.setdefault(key, {"address": key[0], "length": key[1], "entry": key[2],
                                          "variants": []})
        target["variants"].append({"name": path.stem, "source": str(source.relative_to(ROOT)),
                                   "flags": " ".join(record["flags"]), "symbols": record["symbol_overrides"],
                                   "affected_symbols": sorted(affected)})
    return list(targets.values())


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("audit", type=Path, help="output directory from tools/audit_matches.py")
    parser.add_argument("--symbol", action="append", help="exact COFF spelling (default: all registry entries)")
    parser.add_argument("--unverified-only", action="store_true", help="select only unverified fixups")
    parser.add_argument("--json-out", type=Path)
    args = parser.parse_args()
    try:
        executable_sha256 = file_sha256(GAME)
        symbols = set(args.symbol or load_registry(executable_sha256))
        directory = args.audit / "functions"
        if not directory.is_dir():
            raise ValueError(f"audit records directory is missing: {directory}")
        targets = select_records(directory, symbols, args.unverified_only, executable_sha256)
        if not targets:
            raise ValueError("no audited fixups match the selection")
        result = json.dumps({"executable_sha256": executable_sha256, "targets": targets}, indent=2) + "\n"
        if args.json_out:
            args.json_out.write_text(result)
            print(f"selected {sum(len(target['variants']) for target in targets)} attempts across {len(targets)} targets")
        else:
            print(result, end="")
    except (OSError, KeyError, ValueError) as error:
        parser.error(str(error))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
