#!/usr/bin/env python3
"""Bulk-port Ghidra pseudocode functions into readable, compilable C.

The permissive mode keeps DAT_/PTR_/FUN_/LAB_/indirect-call references and
emits shared declarations for data symbols. Unresolved function symbols are
left to the linker's temporary /force:unresolved scaffold; the smoke harness
never calls those paths. Compilation proves structural integration, not
behavioural equivalence.
"""
from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_QUEUE = ROOT / "source_port/work_queue/queue.json"
DEFAULT_OUT = ROOT / "source_port/src"
INCLUDE = ROOT / "source_port/include"

TYPES = {
    "undefined8": "uint64_t",
    "undefined4": "uint32_t",
    "undefined3": "uint32_t",
    "undefined2": "uint16_t",
    "undefined1": "uint8_t",
    "undefined": "uint8_t",
    "ushort": "uint16_t",
    "uchar": "uint8_t",
    "ulong": "uint32_t",
    "uint": "uint32_t",
    "sbyte": "int8_t",
    "byte": "uint8_t",
    "longlong": "int64_t",
    "ulonglong": "uint64_t",
    "qword": "uint64_t",
    "dword": "uint32_t",
    "word": "uint16_t",
    "__int64": "int64_t",
    "__int32": "int32_t",
    "__int16": "int16_t",
    "__int8": "int8_t",
    "float10": "double",
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
GLOBAL_RX = re.compile(r"\b(_?(?:DAT|PTR|UNK)_[A-Za-z0-9_]+|s_[A-Za-z0-9_]+|register[0-9a-fx]+|_param_\d+|local_[0-9a-fx]+|LAB_[0-9a-fA-F]+|\w*Var\d+|lp[A-Z]\w+|\w+_exref|extraout_\w+|in_\w+)\b")
PSEUDO_MARKER = re.compile(r"(?m)^//\s*pseudocode:.*$")
META_NAME = re.compile(r"(?m)^//\s*name:\s*(.*?)\s*$")
META_ADDR = re.compile(r"(?m)^//\s*address:\s*(0x[0-9a-f]+)", re.I)
DECL_RX = re.compile(r"\b(?:int|uint|long|short|char|float|double|void|bool)\s+([A-Za-z_]\w*)\s*[;=,)]")


BITFIELD_RX = re.compile(r"\b([A-Za-z_]\w*)\._(\d+)_(\d+)_\b")


BITFIELD_ASSIGN_RX = re.compile(
    r"\b([A-Za-z_]\w*)\._(\d+)_(\d+)_\s*=\s*([^;]+);")


def translate_bitfield_assignments(code: str) -> str:
    """Turn Ghidra x._N_M_ = value into a masked read-modify-write."""
    def replacement(match):
        name, width, offset, value = match.group(1), int(match.group(2)), int(match.group(3)), match.group(4)
        bits = min(width, 8) * 8
        shift = offset * 8
        mask = (1 << bits) - 1
        mask_text = "0xffffffffu" if bits == 32 else f"0x{mask:x}u"
        return (f"{name} = ({name} & ~({mask_text} << {shift})) | "
                f"((({value}) & {mask_text}) << {shift});")
    return BITFIELD_ASSIGN_RX.sub(replacement, code)

def translate_bitfields(code: str) -> str:
    """Translate Ghidra x._N_M_ byte/word extraction into shifts and casts."""
    def replacement(match):
        name, width, offset = match.group(1), int(match.group(2)), int(match.group(3))
        bits = min(width, 8) * 8
        kind = {8: "uint8_t", 16: "uint16_t", 32: "uint32_t"}.get(bits, "uint64_t")
        return f"(({kind})(({name}) >> {offset * 8}))"
    return BITFIELD_RX.sub(replacement, code)

def clean_code(text: str) -> str:
    match = PSEUDO_MARKER.search(text)
    code = text[match.end():] if match else text
    code = re.sub(r"\bthis\b", "self", code)
    code = TYPE_RX.sub(lambda m: TYPES[m.group(1)], code)
    code = translate_bitfield_assignments(code)
    code = translate_bitfields(code)
    for rx, replacement in LOCAL_RENAMES:
        code = rx.sub(replacement, code)
    code = code.replace("(int)", "(intptr_t)")
    code = re.sub(r"\(float\)\s*([A-Za-z_]\w*)\b", r"(float)(intptr_t)(\1)", code)
    code = re.sub(r"\(([A-Za-z_][A-Za-z0-9_ ]*\*)\)\s*(fVar\d+)\b", r"(\1)pc2_bits(\2)", code)
    code = re.sub(r"\b__noreturn\b\s*", "", code)
    return code.strip() + "\n"



TYPE_WORDS = (r"(?:undefined\d*|uint\d*_t|int\d*_t|intptr_t|uintptr_t|"
              r"uint|int|ushort|uchar|byte|sbyte|char|void|long|short|"
              r"float|double|bool|code)")


def retype_arrow_users(code: str, address: str) -> str:
    """Make variables used with -> pointers to a generated field struct."""
    users = {}
    for name in set(re.findall(r"\b([A-Za-z_]\w*)\s*->", code)):
        fields = sorted(set(re.findall(
            r"\b" + re.escape(name) + r"\s*->\s*([A-Za-z_]\w*)", code)))
        if fields:
            users[name] = fields
    if not users:
        return code
    structs = []
    for name, fields in users.items():
        struct = f"pc2_obj_{address}_{name}"
        members = " ".join(f"intptr_t {field};" for field in fields)
        structs.append(f"struct {struct} {{ {members} }};")
        pattern = re.compile(r"\b" + TYPE_WORDS + r"\b\s*\*?\s*" + re.escape(name) + r"\b")
        replacement = f"struct {struct} *{name}"
        if pattern.search(code):
            code = pattern.sub(replacement, code, count=1)
        else:
            brace = code.find("{")
            if brace >= 0:
                code = code[:brace + 1] + f"\n  struct {struct} *{name};" + code[brace + 1:]
    return "\n".join(structs) + "\n" + code

def collect_globals(code: str):
    signature = code.split("{", 1)[0]
    declared = set(re.findall(r"\b([A-Za-z_]\w*)\b", signature))
    declared.update(DECL_RX.findall(code))
    result = {}
    for name in set(GLOBAL_RX.findall(code)):
        if name in declared:
            continue
        escaped = re.escape(name)
        fields = set(re.findall(r"\b" + escaped + r"\s*->\s*([A-Za-z_]\w*)", code))
        subscript = re.search(r"\b" + escaped + r"\s*\[", code)
        assigned = re.search(r"\b" + escaped + r"\s*=(?!=)", code)
        indirect = re.search(r"\*\s*" + escaped + r"\b", code)
        if fields:
            kind = "struct_ptr"
        elif (subscript or indirect) and assigned:
            kind = "ptr"
        elif subscript:
            kind = "array"
        elif indirect:
            kind = "ptr"
        else:
            kind = "scalar"
        if name.endswith("_exref"):
            kind = "funcptr"
        result[name] = {"kind": kind, "fields": sorted(fields)}
    return result


def translate(path: Path):
    text = path.read_text(encoding="utf-8", errors="replace")
    name = META_NAME.search(text)
    address = META_ADDR.search(text)
    code = clean_code(text)
    if not name or not address:
        return None, "missing metadata"
    code = retype_arrow_users(code, address.group(1).lower())
    if "{" not in code or "}" not in code:
        return None, "no function body"
    return {
        "address": address.group(1).lower(),
        "name": name.group(1).strip(),
        "code": code,
        "globals": collect_globals(code),
    }, None


def render(item):
    return (
        f"// {item['name']}: ported from Pizza Connection 2 at {item['address']}.\n"
        f"// Readable source-port phase; this is not a byte-verified match.\n"
        f"// original: {item['address']}\n"
        f'#include "pc2_port.h"\n\n'
        f"{item['code']}"
    )


def refresh_symbols(out: Path, include: Path):
    """Rebuild shared data declarations from every generated source."""
    symbols = {}
    for path in sorted(out.glob("0x*.c*")):
        text = path.read_text(encoding="utf-8", errors="replace")
        if not re.search(r"// original:\s*0x[0-9a-f]+", text, re.I):
            continue
        start = text.find("#include")
        code = text[start:] if start >= 0 else text
        for name, info in collect_globals(code).items():
            current = symbols.setdefault(name, {"kind": "scalar", "fields": []})
            priority = {"scalar": 0, "array": 1, "ptr": 2, "struct_ptr": 3, "funcptr": 4}
            if priority[info["kind"]] > priority[current["kind"]]:
                current["kind"] = info["kind"]
            for field in info["fields"]:
                if field not in current["fields"]:
                    current["fields"].append(field)
    header = ["/* Generated by tools/generate_port_batch.py. */",
              "#ifndef PC2_GENERATED_SYMBOLS_H", "#define PC2_GENERATED_SYMBOLS_H"]
    definitions = ["// PORT_STATUS: STUB", "// Shared data placeholders for the",
                   "// readable port. These are not recovered data structures.",
                   '#include "pc2_port.h"']
    for name in sorted(symbols):
        info = symbols[name]
        kind = info["kind"]
        fields = info["fields"]
        if kind == "funcptr":
            header.append(f"extern code {name};")
            definitions.append(f"code {name};")
        elif kind == "struct_ptr":
            struct = "pc2_obj_" + name
            members = " ".join(f"intptr_t {field};" for field in fields)
            header.append(f"struct {struct} {{ {members} }};")
            header.append(f"extern struct {struct} *{name};")
            definitions.append(f"struct {struct} *{name};")
        elif kind == "ptr":
            header.append(f"extern intptr_t *{name};")
            definitions.append(f"intptr_t *{name};")
        elif kind == "array":
            header.append(f"extern intptr_t *{name};")
            definitions.append(f"intptr_t *{name};")
        else:
            header.append(f"extern intptr_t {name};")
            definitions.append(f"intptr_t {name};")
    header.append("#endif")
    (include / "pc2_generated_symbols.h").write_text("\n".join(header) + "\n", encoding="utf-8")
    stub = ROOT / "source_port/stubs/generated_data.c"
    stub.parent.mkdir(parents=True, exist_ok=True)
    stub.write_text("\n".join(definitions) + "\n", encoding="utf-8")
    return len(symbols)


def translate_payload(text: str):
    name = META_NAME.search(text)
    address = META_ADDR.search(text)
    code = clean_code(text)
    if not name or not address:
        return None, "missing metadata"
    return {"address": address.group(1).lower(), "name": name.group(1).strip(),
            "code": code, "globals": collect_globals(code)}, None


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--queue", type=Path, default=DEFAULT_QUEUE)
    parser.add_argument("--out", type=Path, default=DEFAULT_OUT)
    parser.add_argument("--limit", type=int, default=500)
    parser.add_argument("--manifest", type=Path, default=ROOT / "source_port/work_queue/port_manifest.json")
    args = parser.parse_args()
    payload = json.loads(args.queue.read_text(encoding="utf-8"))
    records = {row["address"]: row for row in payload["records"]}
    selected, skipped = [], {}
    for address in payload["queue"]:
        if len(selected) >= args.limit:
            break
        row = records[address]
        item, reason = translate(ROOT / row["path"])
        if item is None:
            skipped[reason] = skipped.get(reason, 0) + 1
            continue
        target = args.out / f"{item['address']}.c"
        if target.exists():
            skipped["already present"] = skipped.get("already present", 0) + 1
            continue
        selected.append((item, target, row))
    args.out.mkdir(parents=True, exist_ok=True)
    for item, target, row in selected:
        target.write_text(render(item), encoding="utf-8")
    symbols = refresh_symbols(args.out, INCLUDE)
    manifest = {
        "schema": "pc2.readable_port_batch.v1",
        "selected": len(selected),
        "shared_data_symbols": symbols,
        "skipped": skipped,
        "functions": [
            {"address": item["address"], "name": item["name"], "source": str(target.relative_to(ROOT)),
             "pseudocode": row["path"], "score": row["score"], "source_lines": row["source_lines"]}
            for item, target, row in selected
        ],
    }
    args.manifest.parent.mkdir(parents=True, exist_ok=True)
    args.manifest.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(f"ported {len(selected)} functions; shared data symbols {symbols}; skipped {sum(skipped.values())} ({skipped})")


if __name__ == "__main__":
    raise SystemExit(main())
