#!/usr/bin/env python3
"""Translate and strictly check a pilot of typed direct-call routines."""

import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import re
import struct
import subprocess

from decomp_fixtures import PE_HASH
from generate_ui_builder import EXPORTS, native_symbols
from match_decomp import (DEFAULT_VC6, GAME, compile_candidate, file_sha256, function_length,
                          match_object, match_provenance, parse_coff, pe_image, read_va,
                          resolve_auto_symbol)
from x86_call_abi import decode_reachable

PILOT = {
    "ui_update": (0x52fd00, 0x4cb3c0, 0x4922d0, 0x49e160, 0x49e830, 0x4aca80, 0x4949a0, 0x49ad30),
    "general": (0x54d85d, 0x48e0b0, 0x48c920, 0x4af620, 0x4dfcd0, 0x4c89b0, 0x51e650, 0x4f57f0),
}
# The parameters of a thiscall method exclude its ECX receiver. Callee RET
# immediates independently check all fixed stack arguments before compilation.
CALLS = {
    "IDMap_Lookup": (0x4017f0, "thiscall", "int", "int, int *"),
    "Debug_WarningMessageBox": (0x403510, "cdecl", "void", ""),
    "Game_GetPlayerBySlot": (0x488be0, "thiscall", "int", "int"),
    "Rating_UpdateBarByKey": (0x4a80e0, "cdecl", "void", "void *, int, int, int, int"),
    "UI_SetMultipleLabels": (0x4c70b0, "cdecl", "void", "void *, int *"),
    "Game_GetPlayerCity": (0x4ddcc0, "fastcall", "int", "int"),
    "Game_CountActiveStats": (0x50fe50, "fastcall", "int", "int"),
    "Language_CopyStringIds": (0x514690, "cdecl", "void", "undefined4 *, int, int"),
    "Gadget_SetTextf": (0x52f080, "cdecl", "void", "void *, int, const char *, ..."),
    "Window_GadgetNotify_Text_SetText": (0x52f9b0, "thiscall", "void", "int, const char *"),
    "Window_GadgetNotify": (0x52fdd0, "thiscall", "int", "int, int, int, int, int"),
    "UI_ShowChildByID": (0x5316b0, "thiscall", "void", "int"),
    "UI_SetChildVisibleByID": (0x5316f0, "thiscall", "void", "int, unsigned char"),
    "UI_RemoveObjectByKey": (0x531740, "thiscall", "void", "int"),
    "CS_Initialize": (0x54d346, "cdecl", "void", "void *"),
    "String_Format": (0x54dd83, "cdecl", "int", "void *, const char *, ..."),
}
# These address-based declarations follow byte-indexed pointer arithmetic
# and x87 single-precision memory operands in the reviewed exports/PE.
DATA_TYPES = {
    "DAT_0056b2dc": "char", "DAT_0056b2f0": "char", "DAT_0056b304": "char",
    "_DAT_00568998": "float", "DAT_005689b8": "char",
    "DAT_0057c228": "undefined4",
}
TYPES = """typedef unsigned char byte, uchar, undefined1;
typedef unsigned short ushort, undefined2;
typedef unsigned int uint, undefined4, undefined;
typedef unsigned long ulong;
typedef __int64 longlong;
typedef unsigned __int64 ulonglong, undefined8;
typedef void *LPCRITICAL_SECTION;
"""


def body_of(path):
    text = path.read_text().split("// pseudocode:", 1)[1].partition("\n")[2]
    return re.sub(r"/\*.*?\*/|//[^\n]*", "", text, flags=re.S).strip()


def fixed_arguments(text):
    """Split a C argument list at its outer commas and closing parenthesis."""
    quote = None
    escaped = False
    args, start, depth = [], 0, 0
    for i, char in enumerate(text):
        if quote:
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == quote:
                quote = None
            continue
        if char in "'\"":
            quote = char
        elif char in "([":
            depth += 1
        elif char == ")" and depth == 0:
            if text[start:i].strip():
                args.append(text[start:i].strip())
            return args, i + 1
        elif char in ")]":
            depth -= 1
        elif char == "," and depth == 0:
            args.append(text[start:i].strip())
            start = i + 1
    raise ValueError("unterminated call arguments")


def translate(pseudocode):
    original_header, separator, body = pseudocode.partition("{")
    if not separator or not body.rstrip().endswith("}"):
        raise ValueError("missing function definition")
    header = re.fullmatch(r"([\w *]+?)\s*\b(?:(__cdecl|__thiscall|__fastcall)\s+)?(\w+)\s*\((.*?)\)\s*",
                          original_header, re.S)
    if not header:
        raise ValueError("unsupported function declaration")
    result_type, convention, name, params = header.groups()
    result_type = result_type.strip()
    bindings, calls = {}, []
    pattern = re.compile(r"\b(" + "|".join(CALLS) + r"|SUB84)\s*\(")

    def rewrite(expression):
        parts = []
        cursor = 0
        while found := pattern.search(expression, cursor):
            parts.append(expression[cursor:found.start()])
            callee = found[1]
            args, length = fixed_arguments(expression[found.end():])
            cursor = found.end() + length
            if callee == "SUB84":
                if len(args) != 2 or args[1] != "0" or "double" not in args[0]:
                    raise ValueError("unsupported Ghidra double argument")
                parts.append("(" + args[0] + ")")
                continue
            address, cc, result, parameters = CALLS[callee]
            recv = f"((PC2Calls *)({rewrite(args.pop(0))}))->" if cc == "thiscall" else ""
            types = parameters.split(", ") if parameters else []
            variadic = bool(types and types[-1] == "...")
            if variadic:
                types.pop()
            if len(args) < len(types) or not variadic and len(args) != len(types):
                raise ValueError(f"{callee}: inconsistent argument count")
            rendered = [rewrite(arg) for arg in args]
            for i, kind in enumerate(types):
                if "*" in kind:
                    rendered[i] = f"({kind})({rendered[i]})"
            calls.append(address)
            bindings[callee] = (address, cc, result, parameters)
            parts.append(f"{recv}{callee}({', '.join(rendered)})")
        parts.append(expression[cursor:])
        return "".join(parts)

    body = rewrite(re.sub(r"\bthis\b", "self", body))
    body = re.sub(r"\b(_?DAT_[0-9a-f]{8})\._([0-9]+)_([124])_\b",
                  r"(*(undefined\3 *)((char *) &\1 + \2))", body)
    body = re.sub(r"&(?=(?:PTR_[A-Za-z0-9_]*_)[0-9a-f]{8}\b)", "(undefined4)&", body)
    data_names = set(re.findall(r"\b((?:_?DAT_|PTR_[A-Za-z0-9_]*_|s_[A-Za-z0-9_]*_)[0-9a-f]{8})\b", body))
    declarations = [TYPES, "struct PC2Calls {"]
    declarations.extend(f"    {result} {callee}({params});"
                        for callee, (_, cc, result, params) in bindings.items() if cc == "thiscall")
    declarations.append("};")
    if "SBORROW4(" in body:
        declarations.append("""static __forceinline bool SBORROW4(unsigned a, unsigned b)
{
    return ((a ^ b) & (a ^ (a - b))) >> 31 != 0;
}""")
    declarations.extend(f'extern "C" {result} __{cc} {callee}({params});'
                        for callee, (_, cc, result, params) in bindings.items() if cc != "thiscall")
    addresses = {}
    for symbol in sorted(data_names):
        if symbol.startswith("s_"):
            declaration = f"char {symbol}[]"
        else:
            declaration = f"{DATA_TYPES.get(symbol, 'int')} {symbol}"
        declarations.append(f'extern "C" {declaration};')
        addresses["_" + symbol] = int(symbol[-8:], 16)
    if convention == "__thiscall":
        receiver, separator, rest = params.partition(",")
        if not receiver.strip().endswith("this"):
            raise ValueError("missing explicit receiver in thiscall export")
        declarations.append(f"struct PC2Subject {{ {result_type} {name}({rest.strip() if separator else ''}); }};")
        declarations.append(f"{result_type} PC2Subject::{name}({rest.strip()}) {{\n    void *self = this;")
    else:
        declarations.append(f'extern "C" {result_type} {convention or "__cdecl"} {name}({params}) {{')
    return name, "\n".join(declarations) + body + "\n", calls, bindings, addresses


def checked_calls(image, address, length, expected, bindings):
    from capstone import CS_GRP_CALL
    from capstone.x86_const import X86_OP_IMM, X86_INS_RET

    instructions, _, undecodable, indirect = decode_reachable(read_va(image, address, length), address)
    calls = [ins for ins in instructions if ins.group(CS_GRP_CALL)]
    if undecodable or indirect or any(ins.operands[0].type != X86_OP_IMM for ins in calls):
        raise ValueError("indirect or undecodable control flow")
    if Counter(ins.operands[0].imm for ins in calls) != Counter(expected):
        raise ValueError("translated direct calls differ from original call-site counts")
    for target, cc, _, params in bindings.values():
        fn, _, _, _ = decode_reachable(read_va(image, target, function_length(target)), target)
        pops = {ins.operands[0].imm if ins.operands else 0 for ins in fn if ins.id == X86_INS_RET}
        expected_pop = 4 * len(params.split(", ")) if cc == "thiscall" and params else 0
        if pops and pops != {expected_pop}:
            raise ValueError(f"{target:#x} has stack cleanup {pops}, expected {expected_pop}")


def verify_one(address, group, length, candidate, source, image, vc6):
    name, rendered, calls, bindings, overrides = candidate
    checked_calls(image, address, length, calls, bindings)
    _, base, sections = image
    for va in overrides.values():
        if not any(base + start <= va < base + start + max(virtual, raw)
                   for _, start, virtual, _, raw in sections):
            raise ValueError(f"data label outside PE virtual sections at {va:#x}")
    source.write_text(rendered)
    obj = source.with_suffix(".obj")
    flags = ["/O2", "/TP"]
    compile_candidate(source, vc6, obj, flags)
    _, _, symbols = parse_coff(obj)
    entry = None
    for symbol in symbols:
        if symbol is None:
            continue
        spelling = symbol["name"]
        short = re.match(r"(?:\?|@|_)([A-Za-z_][A-Za-z0-9_]*)(?:@|$)", spelling)
        if not short:
            continue
        key = short[1]
        if key == name and symbol["section"] > 0 and symbol["type"] == 0x20:
            if entry:
                raise ValueError("multiple COFF entries for the emitted function")
            entry = spelling
        elif key in bindings and symbol["section"] == 0:
            overrides[spelling] = bindings[key][0]
    if not entry:
        raise ValueError("missing COFF entry for the emitted function")
    match = match_object(address, obj, overrides, length, entry, strict=True, auto_symbols=True)
    match.update(match_provenance(source, vc6, flags, overrides, True, True))
    receipt = source.with_suffix(".match.json")
    receipt.write_text(json.dumps(match, indent=2) + "\n")
    return {"address": hex(address), "group": group, "length": length, "receipt": receipt.name,
            "status": "strict" if match["strict_match"] else "mismatch",
            "first_difference": match["first_difference"], "difference_count": match["difference_count"],
            "strict_issues": match["strict_issues"], "relocation_issues": match["relocation_issues"]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", required=True, type=Path)
    parser.add_argument("--jobs", type=int, choices=range(1, 9), default=4)
    parser.add_argument("--address", action="append", type=lambda value: int(value, 0), default=[])
    parser.add_argument("--vc6", type=Path, default=DEFAULT_VC6)
    args = parser.parse_args()
    if file_sha256(GAME) != PE_HASH:
        parser.error("original PE hash differs")
    selected = [(group, va) for group, addresses in PILOT.items() for va in addresses
                if not args.address or va in args.address]
    if not selected or set(args.address) - {va for _, va in selected}:
        parser.error("select addresses from the pilot")
    out = args.out.resolve()
    out.mkdir(parents=True)
    image = pe_image(GAME)
    names = native_symbols()
    for name, (va, *_) in CALLS.items():
        if names.get(hex(va)) != name:
            parser.error(f"named PE call binding differs at {va:#x}")
    resolve_auto_symbol("__except_list")

    def run(item):
        group, address = item
        length = function_length(address)
        export = EXPORTS / f"{address:#x}.c"
        try:
            candidate = translate(body_of(export))
            return verify_one(address, group, length, candidate, out / f"{address:#x}.cpp", image, args.vc6.resolve())
        except (ValueError, OSError, KeyError, struct.error, subprocess.TimeoutExpired) as error:
            return {"address": hex(address), "group": group, "length": length,
                    "status": "blocked", "error": str(error)[:1600]}

    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        rows = list(pool.map(run, selected))
    summary = {"schema": "pc2.direct_call_pilot.v1", "executable_sha256": PE_HASH,
               "cases": len(rows), "statuses": dict(Counter(row["status"] for row in rows)),
               "candidate_bytes": sum(row["length"] for row in rows),
               "strict_bytes": sum(row["length"] for row in rows if row["status"] == "strict"),
               "functions": rows}
    (out / "report.json").write_text(json.dumps(summary, indent=2) + "\n")
    print(f"{summary['statuses']}, {summary['strict_bytes']}/{summary['candidate_bytes']} bytes")


if __name__ == "__main__":
    main()
