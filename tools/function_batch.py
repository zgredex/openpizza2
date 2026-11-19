#!/usr/bin/env python3
"""Build a repeatable function-batch packet from the retained pseudocode.

For each requested address this records the function name, body, callers,
unresolved Ghidra placeholders, a bounded disassembly excerpt and, when
available, curated typed annotations. The Markdown packet is intended for
review; the JSON packet is keyed by executable SHA-256 and address for
machine consumption.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")
INDEX = os.path.join(BASE, "full_game_verification", "decompile-index.json")
FUNCTIONS = os.path.join(BASE, "full_game_verification", "functions")
EXE = os.path.join(ROOT, "game", "fastfood2.exe")
CALL_RE = re.compile(r"\b([A-Z][A-Za-z0-9_]+)\s*\(")
UNRESOLVED_RE = re.compile(
    r"\b(extraout_[A-Za-z0-9_]+|unaff_[A-Za-z0-9_]+|in_[A-Za-z0-9_]+)\b")


def sha256_file(path):
    digest = hashlib.sha256()
    with open(path, "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def load_index():
    with open(INDEX) as fh:
        return {item["address"].lower(): item for item in json.load(fh)["functions"]}


def function_path(address):
    return os.path.join(FUNCTIONS, f"0x{address[2:].lower()}.c")


def body(path):
    with open(path) as fh:
        return fh.read()


def callers(name, address, paths, index):
    hits = []
    for other_address, other_path in paths.items():
        if other_address == address:
            continue
        text = body(other_path)
        if name in text:
            other_name = index.get(other_address, {}).get("name", "<unnamed>")
            hits.append((other_address, other_name))
    return sorted(hits)


def callees(text, index, own_address):
    names = {}
    for name in CALL_RE.findall(text):
        for address, item in index.items():
            if item.get("name") == name and address != own_address:
                names[name] = address
                break
    return sorted(names.items())


def range_from_text(text):
    match = re.search(r"// range: (0x[0-9a-f]+)-(0x[0-9a-f]+)", text)
    if not match:
        return None
    return [match.group(1), match.group(2)]


def disassembly(start, end):
    proc = subprocess.run(
        ["objdump", "-d", "-M", "intel", f"--start-address={start}",
         f"--stop-address={end}", EXE],
        text=True, capture_output=True)
    return proc.stdout.strip() or "Disassembly unavailable."


def normalize(address):
    address = address.lower()
    if not address.startswith("0x"):
        address = "0x" + address
    return address


def base_record(address, index, paths):
    item = index.get(address)
    if item is None:
        return None
    name = item.get("name", "<unnamed>")
    path = paths.get(address)
    text = body(path) if path else ""
    ranges = range_from_text(text)
    return {
        "address": address,
        "name": name,
        "symbol": {
            "provider_name": name,
            "in_named_export": True,
            "source": "full_game_verification/decompile-index.json",
        },
        "body": {
            "available": item.get("body", {}).get("available", False),
            "pseudocode_path": os.path.relpath(path, ROOT) if path else None,
            "ranges": item.get("body", {}).get("ranges", []),
        },
        "callers": [
            {"address": caller_address, "name": caller_name}
            for caller_address, caller_name in callers(name, address, paths, index)
        ],
        "callees": [
            {"address": callee_address, "name": callee_name}
            for callee_name, callee_address in callees(text, index, address)
        ],
        "unresolved_placeholders": sorted(set(UNRESOLVED_RE.findall(text))),
        "disassembly": {
            "range": ranges,
            "text": disassembly(ranges[0], ranges[1]) if ranges else None,
        },
        "signature": None,
        "dispatch": [],
        "fields": [],
        "event_order": [],
        "unresolved_questions": [],
        "annotations": [],
    }


def merge_record(record, annotation):
    for key, value in annotation.items():
        if key == "fields" and value:
            record.setdefault("fields", []).extend(value)
        elif key == "dispatch" and value:
            record.setdefault("dispatch", []).extend(value)
        elif key == "event_order" and value:
            record.setdefault("event_order", []).extend(value)
        elif key == "unresolved_questions" and value:
            record.setdefault("unresolved_questions", []).extend(value)
        elif key == "annotations" and value:
            record.setdefault("annotations", []).extend(value)
        else:
            record[key] = value
    return record


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("addresses", nargs="+")
    parser.add_argument("--no-disassembly", action="store_true")
    parser.add_argument("--annotations")
    parser.add_argument("--json-out")
    parser.add_argument("--out")
    args = parser.parse_args()
    index = load_index()
    paths = {}
    for address in index:
        path = function_path(address)
        if os.path.isfile(path):
            paths[address] = path
    annotations = {"records": {}, "trace": [], "known_gaps": []}
    if args.annotations:
        with open(args.annotations) as fh:
            annotations.update(json.load(fh))
    records = {}
    ordered = []
    for raw in args.addresses:
        address = normalize(raw)
        if address in records:
            continue
        record = base_record(address, index, paths)
        if record is None:
            if address not in annotations.get("records", {}):
                ordered.append((address, None))
                continue
            record = {
                "address": address,
                "name": None,
                "symbol": {
                    "provider_name": None,
                    "in_named_export": False,
                    "source": "curated annotation (no named procedure)",
                },
                "body": {"available": False, "pseudocode_path": None, "ranges": None},
                "callers": [],
                "callees": [],
                "unresolved_placeholders": [],
                "disassembly": {"range": None, "text": None},
                "signature": None,
                "dispatch": [],
                "fields": [],
                "event_order": [],
                "unresolved_questions": [],
                "annotations": [],
            }
        merge_record(record, annotations.get("records", {}).get(address, {}))
        if args.no_disassembly:
            record["disassembly"] = {"range": None, "text": None}
        records[address] = record
        ordered.append((address, record))

    lines = ["# Function batch packet", ""]
    for address, record in ordered:
        if record is None:
            lines.append(f"## {address}\n\nAddress is not in the decompile index.\n")
            continue
        name = record.get("name") or "<unnamed>"
        lines.extend([
            f"## `{name}` — `{address}`",
            "",
            f"- Body: `{record['body'].get('pseudocode_path') or 'curated'}`",
            f"- Callers: {', '.join(f'`{item['name']}` ({item['address']})' for item in record['callers']) or 'none in the named export'}",
            f"- Callees: {', '.join(f'`{item['name']}` ({item['address']})' for item in record['callees']) or 'none resolved'}",
            "",
        ])
        if record.get("signature"):
            lines.append(f"- Signature: `{record['signature']}`")
        if record.get("dispatch"):
            lines.append(
                "- Dispatch: " + ", ".join(
                    f"`{item.get('kind')}` {item.get('from')} -> {item.get('targets')}"
                    for item in record["dispatch"]))
        unresolved = record.get("unresolved_questions") or []
        lines.append(
            "- Unresolved questions: " +
            ("; ".join(unresolved) if unresolved else "none"))
        lines.append("")
        if record.get("disassembly", {}).get("text"):
            lines.extend(["### Disassembly", "", "```asm",
                          record["disassembly"]["text"], "```", ""])
    output = "\n".join(lines) + "\n"
    if args.out:
        with open(args.out, "w") as fh:
            fh.write(output)
    else:
        sys.stdout.write(output)

    if args.json_out:
        target_sha256 = sha256_file(EXE)
        for address, record in records.items():
            record["packet_key"] = f"{target_sha256}:{address}"
        packet = {
            "schema": "pc2.function_batch.v1",
            "target": {
                "path": os.path.relpath(EXE, ROOT),
                "sha256": target_sha256,
            },
            "batch": annotations.get("batch"),
            "method": annotations.get("method"),
            "records": records,
            "trace": annotations.get("trace", []),
            "tables": annotations.get("tables", []),
            "fixtures": annotations.get("fixtures", []),
            "controls": annotations.get("controls", {}),
            "imports": annotations.get("imports", {}),
            "resolved_questions": annotations.get("resolved_questions", []),
            "known_gaps": annotations.get("known_gaps", []),
        }
        with open(args.json_out, "w") as fh:
            json.dump(packet, fh, indent=2, sort_keys=True)
            fh.write("\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
