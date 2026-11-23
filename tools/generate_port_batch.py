#!/usr/bin/env python3
"""Bulk-port simple Ghidra pseudocode functions into readable C++.

This is a *source port* tool, not a byte matcher. It selects the cheapest
dependency-free functions from tools/port_work_queue.py's queue, applies
mechanical readability cleanups, and writes one file per function with an
`// original: 0x...` marker. The output is expected to be compiled; compilation
proves structural integration, not behavioral equivalence.

Only functions with no DAT_/FUN_/LAB_/goto/indirect-call/concat references are
selected by default, so the first batch needs no globals or stubs.
"""
from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_QUEUE = ROOT / "source_port/work_queue/queue.json"
DEFAULT_OUT = ROOT / "source_port/src"

TYPES = {
    "undefined8": "uint64_t",
    "undefined4": "uint32_t",
    "undefined2": "uint16_t",
    "undefined1": "uint8_t",
    "undefined": "uint8_t",
    "ushort": "uint16_t",
    "uchar": "uint8_t",
    "ulong": "uint32_t",
    "uint": "uint32_t",
    "sbyte": "int8_t",
    "byte": "uint8_t",
    "float10": "double",
    "code": "void",
    "longlong": "int64_t",
    "ulonglong": "uint64_t",
    "qword": "uint64_t",
    "dword": "uint32_t",
    "word": "uint16_t",
    "__int64": "int64_t",
    "__int32": "int32_t",
    "__int16": "int16_t",
    "__int8": "int8_t",
}
TYPE_RX = re.compile(r"\b(" + "|".join(TYPES) + r")\b")
LOCAL_RENAMES = (
    (re.compile(r"\biVar(\d+)\b"), r"value\1"),
    (re.compile(r"\buVar(\d+)\b"), r"uvalue\1"),
    (re.compile(r"\blVar(\d+)\b"), r"lvalue\1"),
    (re.compile(r"\bpiVar(\d+)\b"), r"ptr\1"),
    (re.compile(r"\bpfVar(\d+)\b"), r"fptr\1"),
    (re.compile(r"\bpbVar(\d+)\b"), r"bptr\1"),
    (re.compile(r"\bpcVar(\d+)\b"), r"cptr\1"),
    (re.compile(r"\bppuVar(\d+)\b"), r"pptr\1"),
    (re.compile(r"\bpuVar(\d+)\b"), r"uptr\1"),
    (re.compile(r"\bbVar(\d+)\b"), r"flag\1"),
    (re.compile(r"\bsVar(\d+)\b"), r"svalue\1"),
    (re.compile(r"\bparam_(\d+)\b"), r"arg\1"),
)
SKIP_RX = re.compile(
    r"\b(?:DAT_[0-9a-fA-F]+|FUN_[0-9a-fA-F]+|LAB_[0-9a-fA-F]+|switchD_[0-9a-fA-F]+|"
    r"CONCAT\d+\d+|SUB\d+\d+|ZEXT\d+\d+|SEXT\d+\d+|extraout_\w+|in_\w+|"
    r"__try|__except|__finally|ExceptionList|RtlUnwind|__CxxFrameHandler|"
    r"_alloca|__chkstk|__asm|Interlocked|uint3)\b"
)
INDIRECT_RX = re.compile(r"\(\s*\*\s*\*")
PSEUDO_MARKER = re.compile(r"(?m)^//\s*pseudocode:.*$")
META_NAME = re.compile(r"(?m)^//\s*name:\s*(.*?)\s*$")
META_ADDR = re.compile(r"(?m)^//\s*address:\s*(0x[0-9a-f]+)", re.I)


def clean_code(text: str) -> str:
    match = PSEUDO_MARKER.search(text)
    code = text[match.end():] if match else text
    # Drop Ghidra's leading blank lines and block comments that describe the
    # export itself. Keep ordinary implementation comments.
    lines = []
    for line in code.splitlines():
        if line.startswith("// ") and ("Ghidra" in line or "provider" in line):
            continue
        lines.append(line)
    code = "\n".join(lines).strip()
    code = re.sub(r"\bthis\b", "self", code)
    code = TYPE_RX.sub(lambda m: TYPES[m.group(1)], code)
    for rx, replacement in LOCAL_RENAMES:
        code = rx.sub(replacement, code)
    code = code.replace("(int)", "(intptr_t)")
    code = re.sub(r"\b__noreturn\b\s*", "", code)
    return code.strip() + "\n"


def translate(path: Path):
    text = path.read_text(encoding="utf-8", errors="replace")
    name = META_NAME.search(text)
    address = META_ADDR.search(text)
    code = clean_code(text)
    if not name or not address:
        return None, "missing metadata"
    if SKIP_RX.search(code):
        return None, "external or unresolved reference"
    if INDIRECT_RX.search(code):
        return None, "indirect call"
    if "goto " in code:
        return None, "goto"
    if "{" not in code or "}" not in code:
        return None, "no function body"
    return {
        "address": address.group(1).lower(),
        "name": name.group(1).strip(),
        "code": code,
    }, None


def render(item):
    return (
        f"// {item['name']}: ported from Pizza Connection 2 at {item['address']}.\n"
        f"// Readable source-port phase; this is not a byte-verified match.\n"
        f"// original: {item['address']}\n"
        f'#include "pc2_port.h"\n\n'
        f"{item['code']}"
    )


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--queue", type=Path, default=DEFAULT_QUEUE)
    parser.add_argument("--out", type=Path, default=DEFAULT_OUT)
    parser.add_argument("--limit", type=int, default=300)
    parser.add_argument("--manifest", type=Path, default=ROOT / "source_port/work_queue/port_manifest.json")
    args = parser.parse_args()
    payload = json.loads(args.queue.read_text(encoding="utf-8"))
    records = {row["address"]: row for row in payload["records"]}
    selected = []
    skipped = {}
    for address in payload["queue"]:
        if len(selected) >= args.limit:
            break
        row = records[address]
        item, reason = translate(ROOT / row["path"])
        if item is None:
            skipped[reason] = skipped.get(reason, 0) + 1
            continue
        target = args.out / f"{item['address']}.cpp"
        if target.exists():
            skipped["already present"] = skipped.get("already present", 0) + 1
            continue
        selected.append((item, target, row))
    args.out.mkdir(parents=True, exist_ok=True)
    for item, target, row in selected:
        target.write_text(render(item), encoding="utf-8")
    manifest = {
        "schema": "pc2.readable_port_batch.v1",
        "selected": len(selected),
        "skipped": skipped,
        "functions": [
            {"address": item["address"], "name": item["name"], "source": str(target.relative_to(ROOT)),
             "pseudocode": row["path"], "score": row["score"], "source_lines": row["source_lines"]}
            for item, target, row in selected
        ],
    }
    args.manifest.parent.mkdir(parents=True, exist_ok=True)
    args.manifest.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(f"ported {len(selected)} functions; skipped {sum(skipped.values())} ({skipped})")


if __name__ == "__main__":
    raise SystemExit(main())
