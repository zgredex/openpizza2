#!/usr/bin/env python3
"""Run match_decomp.py over a batch part manifest."""

from __future__ import annotations

import argparse
import json
import os
import tempfile
from pathlib import Path

from match_decomp import DEFAULT_VC6, match, match_provenance, write_function_audit


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
    parser.add_argument("--strict", action="store_true",
                        help="require exact extent and relocation checks")
    parser.add_argument("--auto-symbols", action="store_true",
                        help="resolve external symbols from the shipped symbol map")
    args = parser.parse_args()
    strict = args.strict or os.environ.get("PC2_STRICT") == "1"
    auto_symbols = args.auto_symbols or os.environ.get("PC2_AUTO_SYMBOLS") == "1"
    records = json.loads(args.manifest.read_text())
    symbols = ({name: int(value, 0) if isinstance(value, str) else value
                for name, value in json.loads(args.symbols.read_text()).items()}
               if args.symbols else {})
    flags = args.flags.split()
    results = []
    required = "strict_match" if strict else "match"
    with tempfile.TemporaryDirectory(prefix="pc2-match-batch-") as directory:
        for index, record in enumerate(records):
            address = int(record["address"], 0)
            source = args.directory / f"{record['address']}.c"
            error = None
            if not source.is_file():
                error = f"missing {source}"
            elif not args.allow_asm:
                text = source.read_text(errors="replace")
                if "__asm" in text or "asm {" in text:
                    error = "inline assembly is not decompiled C"
            if error:
                result = {"address": f"{address:#08x}", "match": False, "strict_match": False,
                          "error": error, "entry": record.get("entry"), "length": record.get("length")}
                result.update(match_provenance(source, args.vc6, flags, symbols, strict, auto_symbols))
                write_function_audit(result)
            else:
                result = match(address, source, Path(directory) / f"{index}.obj",
                               args.vc6, flags, symbols, record.get("length"), record.get("entry"),
                               strict=strict, auto_symbols=auto_symbols)
            results.append(result)
            print(f"{record['address']} {record['name']}: "
                  f"{'MATCH' if result.get(required) else 'unmatched'}")
    matched = sum(1 for result in results if result.get("match"))
    strict_matched = sum(1 for result in results if result.get("strict_match"))
    report = {"matched": matched, "strict_matched": strict_matched,
              "total": len(results), "results": results}
    text = json.dumps(report, indent=2)
    if args.json_out:
        args.json_out.write_text(text + "\n")
    print(f"matched {matched}/{len(results)}; strict {strict_matched}/{len(results)}")
    return 0 if all(result.get(required) for result in results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
