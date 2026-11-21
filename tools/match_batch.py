#!/usr/bin/env python3
"""Run match_decomp.py over a batch part manifest."""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from match_decomp import DEFAULT_VC6, GAME, match  # noqa: E402


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("manifest", type=Path)
    parser.add_argument("directory", type=Path)
    parser.add_argument("--symbols", type=Path,
                        help="JSON object mapping external symbol names to addresses")
    parser.add_argument("--flags", default="/O2")
    parser.add_argument("--json-out", type=Path)
    parser.add_argument("--vc6", type=Path, default=DEFAULT_VC6)
    parser.add_argument("--allow-asm", action="store_true",
                        help="count naked inline-assembly transcriptions as matches")
    args = parser.parse_args()
    records = json.loads(args.manifest.read_text())
    symbols = json.loads(args.symbols.read_text()) if args.symbols else {}
    results = []
    for record in records:
        address = int(record["address"], 0)
        source = args.directory / f"{record['address']}.c"
        if not source.is_file():
            results.append({"address": record["address"], "match": False,
                            "error": f"missing {source}"})
            continue
        text = source.read_text(errors="replace")
        if not args.allow_asm and ("__asm" in text or "asm {" in text):
            results.append({"address": record["address"], "match": False,
                            "error": "inline assembly is not decompiled C",
                            "source": str(source)})
            continue
        try:
            result = match(address, source, args.directory / f"{record['address']}.obj",
                           args.vc6, args.flags.split(), symbols,
                           record.get("length"), None, False)
        except Exception as error:  # keep the batch report
            result = {"address": record["address"], "match": False,
                      "error": str(error)}
        results.append(result)
        print(f"{record['address']} {record['name']}: "
              f"{'MATCH' if result.get('match') else 'unmatched'}")
    matched = sum(1 for result in results if result.get("match"))
    report = {"matched": matched, "total": len(results), "results": results}
    text = json.dumps(report, indent=2)
    if args.json_out:
        args.json_out.write_text(text + "\n")
    print(f"matched {matched}/{len(results)}")
    return 0 if matched == len(results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
