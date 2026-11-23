#!/usr/bin/env python3
"""Look up known VC6 compiler/source-shape fingerprints.

Read-only retrieval over reconstructed/match/compiler-fingerprints/fingerprints.json.
Search by free text, tag, or target address before starting a new compile-and-
compare investigation.

Examples:
    python3 tools/lookup_fingerprint.py --query state-release
    python3 tools/lookup_fingerprint.py --tag eh --tag destructor
    python3 tools/lookup_fingerprint.py --address 0x53fcc0
    python3 tools/lookup_fingerprint.py --list
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_INDEX = ROOT / "reconstructed/match/compiler-fingerprints/fingerprints.json"
FIELDS = ("id", "title", "symptom", "cause", "source_pattern", "counter_pattern")


def load_from_payload(payload):
    if payload.get("schema") != "pc2.compiler_fingerprints.v1":
        raise ValueError("expected pc2.compiler_fingerprints.v1")
    entries = payload.get("entries")
    if not isinstance(entries, list):
        raise ValueError("fingerprints entries must be a list")
    return payload, entries


def load(path):
    return load_from_payload(json.loads(Path(path).read_text(encoding="utf-8")))


def text_of(entry):
    parts = [str(entry.get(field, "")) for field in FIELDS]
    parts.extend(str(tag) for tag in entry.get("tags", []))
    return "\n".join(parts).lower()


def evidence_addresses(entry):
    result = set()
    for item in entry.get("evidence", []):
        try:
            result.add(int(str(item.get("address", "")), 0))
        except (TypeError, ValueError):
            continue
    return result


def search(entries, queries=(), tags=(), address=None):
    words = [query.lower() for query in queries if query]
    wanted = {tag.lower() for tag in tags}
    hits = []
    for entry in entries:
        if words and not all(word in text_of(entry) for word in words):
            continue
        entry_tags = {str(tag).lower() for tag in entry.get("tags", [])}
        if wanted and not wanted.issubset(entry_tags):
            continue
        if address is not None and address not in evidence_addresses(entry):
            continue
        hits.append(entry)
    return hits


def render(entry):
    lines = [f"## {entry.get('id', '?')} — {entry.get('title', '')}", ""]
    for field, label in (("symptom", "Symptom"), ("cause", "Cause"),
                         ("source_pattern", "Use"), ("counter_pattern", "Avoid")):
        if entry.get(field):
            lines += [f"**{label}.** {entry[field]}", ""]
    if entry.get("tags"):
        lines.append("Tags: " + ", ".join(entry["tags"]))
    for item in entry.get("evidence", []):
        lines.append(f"- {item.get('address', '?')}  {item.get('file', '')}"
                     f"  ({item.get('locator', '')})")
    return "\n".join(lines).rstrip() + "\n"


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--index", type=Path, default=DEFAULT_INDEX)
    parser.add_argument("--query", action="append", default=[],
                        help="case-insensitive text; repeat for AND")
    parser.add_argument("--tag", action="append", default=[],
                        help="required tag; repeat for AND")
    parser.add_argument("--address", help="match an evidence address, e.g. 0x53fcc0")
    parser.add_argument("--list", action="store_true", help="list every fingerprint id")
    parser.add_argument("--json", action="store_true", help="emit matching entries as JSON")
    args = parser.parse_args()
    try:
        payload, entries = load(args.index)
        if args.list:
            for entry in entries:
                print(f"{entry.get('id', '?'):42} {entry.get('title', '')}")
            return 0
        address = int(args.address, 0) if args.address else None
        hits = search(entries, args.query, args.tag, address)
        if args.json:
            print(json.dumps({"schema": payload["schema"], "entries": hits}, indent=2))
        else:
            if not hits:
                print("no matching fingerprint")
                return 0
            print(f"{len(hits)} matching fingerprint(s)\n")
            print("\n".join(render(entry) for entry in hits))
        return 0
    except (OSError, ValueError, TypeError, KeyError, json.JSONDecodeError) as error:
        parser.exit(2, f"fingerprint lookup: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
