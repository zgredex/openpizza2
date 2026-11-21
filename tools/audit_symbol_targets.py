#!/usr/bin/env python3
"""Trace exact symbol, placed section, and source dependencies in a strict audit."""

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


def registry_changes(path, executable_sha256):
    before = json.loads(path.read_text())
    if (before["schema"] != "pc2.symbol_registry.v1"
            or before["executable_sha256"] != executable_sha256):
        raise ValueError("registry snapshot schema or executable SHA-256 differs")
    previous = {row["symbol"]: row for row in before["entries"]}
    if len(previous) != len(before["entries"]):
        raise ValueError("registry snapshot contains duplicate symbols")
    current = load_registry(executable_sha256)
    return {name for name in previous.keys() | current.keys() if previous.get(name) != current.get(name)}


def reverse_dependencies(directory, symbols, sections, sources, changed_symbols, unverified_only, executable_sha256):
    records = []

    def source_match(path):
        return path and (ROOT / path).resolve() in sources

    for path in sorted(directory.glob("*.json")):
        row = json.loads(path.read_text())
        if row["executable_sha256"] != executable_sha256:
            raise ValueError(f"{path.name}: audit target differs from game/fastfood2.exe")
        strict = row.get("strict_match") is True
        overrides = row.get("symbol_overrides", {})
        matches = set()

        def add(kind, value, consumed):
            if consumed is False or not unverified_only:
                matches.add((kind, str(value), "consumed" if consumed else "blocked"))

        if source_match(row.get("source")):
            add("source", (ROOT / row["source"]).resolve(), strict)

        for fixup in row.get("relocations", []):
            name = fixup["symbol"]
            origin = fixup.get("origin")
            verified = fixup["verified"] is True
            if name in symbols:
                add("symbol", name, verified)
            if name in changed_symbols and name not in overrides and origin not in {"explicit_symbol", "candidate_entry"}:
                add("registry_symbol", name, verified)
            for evidence in fixup.get("evidence", []):
                if source_match(evidence.get("path")):
                    add("evidence_source", (ROOT / evidence["path"]).resolve(), verified)

        for placed in [*row.get("linked_sections", []), *row.get("linked_spans", [])]:
            address = int(placed.get("address", placed.get("start")), 16)
            if address in sections:
                add("section_address", hex(address), True)
            for anchor in placed.get("anchors", []):
                name = anchor["symbol"]
                if name in symbols:
                    add("symbol", name, True)
                if name in changed_symbols and name not in overrides:
                    add("registry_symbol", name, True)
                for evidence in anchor.get("evidence", []):
                    if source_match(evidence.get("path")):
                        add("evidence_source", (ROOT / evidence["path"]).resolve(), True)

        for blocked in row.get("blocked_sections", []):
            for name in blocked["symbols"]:
                if name in symbols:
                    add("symbol", name, False)
                if name in changed_symbols and name not in overrides:
                    add("registry_symbol", name, False)
            for value in blocked.get("expected_addresses", []):
                address = int(value, 16)
                if address in sections:
                    add("section_address", hex(address), False)

        if matches:
            records.append({"address": hex(int(row["address"], 16)), "record": path.name,
                            "strict_match": strict, "references": [
                                {"kind": kind, "value": value, "status": status}
                                for kind, value, status in sorted(matches)]})

    def addresses(rows):
        return sorted({row["address"] for row in rows}, key=lambda value: int(value, 16))

    return {"schema": "pc2.audit_reverse_dependencies.v1", "executable_sha256": executable_sha256,
            "changed_registry_symbols": sorted(changed_symbols), "addresses": addresses(records),
            "strict_addresses": addresses(row for row in records if row["strict_match"]),
            "blocked_addresses": addresses(row for row in records if any(r["status"] == "blocked"
                                                                          for r in row["references"])),
            "records": records}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("audit", type=Path, help="output directory from tools/audit_matches.py")
    parser.add_argument("--symbol", action="append", help="exact COFF spelling (default: all registry entries)")
    parser.add_argument("--reverse", action="store_true", help="emit consumed and blocked dependency records")
    parser.add_argument("--section-address", action="append", type=lambda value: int(value, 0),
                        help="select recorded section placements at this VA (repeatable)")
    parser.add_argument("--source", action="append", type=Path,
                        help="select recorded source or evidence path (repeatable)")
    parser.add_argument("--registry-before", type=Path,
                        help="select consumers of exact facts changed from this registry snapshot")
    parser.add_argument("--unverified-only", action="store_true", help="select only unverified fixups")
    parser.add_argument("--json-out", type=Path)
    args = parser.parse_args()
    try:
        executable_sha256 = file_sha256(GAME)
        symbols = set(args.symbol or load_registry(executable_sha256))
        directory = args.audit / "functions"
        if not directory.is_dir():
            raise ValueError(f"audit records directory is missing: {directory}")
        if args.reverse or args.section_address or args.source or args.registry_before:
            changed_symbols = registry_changes(args.registry_before, executable_sha256) if args.registry_before else set()
            reverse_symbols = symbols if args.reverse and not (args.registry_before or args.source or args.section_address) else set(args.symbol or ())
            payload = reverse_dependencies(directory, reverse_symbols, set(args.section_address or ()),
                                           {path.resolve() for path in args.source or ()}, changed_symbols,
                                           args.unverified_only, executable_sha256)
            summary = f"selected {len(payload['addresses'])} distinct dependent VAs"
        else:
            targets = select_records(directory, symbols, args.unverified_only, executable_sha256)
            if not targets:
                raise ValueError("no audited fixups match the selection")
            payload = {"executable_sha256": executable_sha256, "targets": targets}
            summary = f"selected {sum(len(target['variants']) for target in targets)} attempts across {len(targets)} targets"
        result = json.dumps(payload, indent=2) + "\n"
        if args.json_out:
            args.json_out.write_text(result)
            print(summary)
        else:
            print(result, end="")
    except (OSError, KeyError, ValueError) as error:
        parser.error(str(error))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
