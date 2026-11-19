#!/usr/bin/env python3
"""Recover direct, base-relative and indexed references to a target global.

The scanner walks the shipped executable with objdump, tracks 32-bit register
constants inside each function, and resolves operands such as

    mov eax, 0x57b9ac
    mov DWORD PTR [eax-0x30], 0x64

to the absolute address 0x57B97C.  It also records symbolic indexed operands
like [eax+0x57bcd8] so array accesses are not lost when the index is dynamic.

Output is raw evidence, not a finished annotation: conditions and field
meanings still need review.  Use it to build a typed packet.
"""

from __future__ import annotations

import argparse
import bisect
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")
EXE = os.path.join(ROOT, "game", "fastfood2.exe")
FUNCTIONS = os.path.join(BASE, "functions_readable")

LINE_RE = re.compile(
    r"\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} )+)\s*([a-z][a-z0-9.]*)\s*(.*)$")
MEM_RE = re.compile(r"\[([^\]]+)\]")
IMM_RE = re.compile(r"^(?:ds:)?(0x[0-9a-f]+)$")
REG_IMM_RE = re.compile(r"^(e?[abcd]x|e?[sd]i|e?[sb]p|r\d+),\s*(0x[0-9a-f]+)$")
LEA_RE = re.compile(r"^(e?[abcd]x|e?[sd]i|e?[sb]p),\s*\[([^\]]+)\]$")
REG_RE = re.compile(r"\b(e?[abcd]x|e?[sd]i|e?[sb]p)\b")
CALLER_SAVED = {"eax", "ecx", "edx"}


def load_function_ranges() -> list[tuple[int, int, str]]:
    ranges = []
    index = os.path.join(BASE, "full_game_verification", "decompile-index.json")
    if os.path.exists(index):
        payload = json.load(open(index, encoding="utf-8"))
        for function in payload.get("functions", []):
            for span in function.get("body", {}).get("ranges", []):
                ranges.append((int(span["start"], 16), int(span["end"], 16),
                               function.get("name", "UNKNOWN")))
    ranges.sort()
    return ranges


def function_for(address: int, ranges: list[tuple[int, int, str]],
                 starts: list[int]) -> tuple[str, int | None]:
    position = bisect.bisect_right(starts, address) - 1
    while position >= 0:
        start, end, name = ranges[position]
        if start <= address <= end:
            return name, start
        if end < address and position == bisect.bisect_right(starts, address) - 1:
            # The address is in an unnamed gap; do not attribute it to the
            # previous function.
            return "UNNAMED", None
        position -= 1
    return "UNNAMED", None


def parse_instructions() -> list[tuple[int, str, str, str]]:
    proc = subprocess.run(
        ["objdump", "-d", "-M", "intel", EXE],
        cwd=ROOT, text=True, capture_output=True, check=True)
    instructions = []
    for line in proc.stdout.splitlines():
        match = LINE_RE.match(line)
        if match:
            instructions.append((
                int(match.group(1), 16),
                match.group(2).strip(),
                match.group(3),
                match.group(4).strip()))
    return instructions


def width_of(text: str) -> int | None:
    for keyword, width in (("QWORD PTR", 8), ("DWORD PTR", 4),
                           ("WORD PTR", 2), ("BYTE PTR", 1)):
        if re.search(r"\b" + keyword + r"\b", text):
            return width
    return None


def access_of(mnemonic: str, operands: str) -> str:
    if MEM_RE.search(operands) is None:
        return "none"
    if mnemonic in ("cmp", "test", "push", "call", "jmp", "lea"):
        return "read"
    first = operands.split(",", 1)[0]
    if MEM_RE.search(first) is None:
        return "read"
    if mnemonic in ("add", "sub", "or", "and", "xor", "inc", "dec"):
        return "read-write"
    return "write"


def register_value(regs: dict[str, int | None], token: str) -> int | None:
    token = token.strip().lower()
    return regs.get(token)


def parse_memory(expression: str,
                 regs: dict[str, int | None]) -> tuple[int | None, bool]:
    """Return (resolved absolute address or None, indexed flag)."""
    expression = expression.replace(" ", "").lower()
    total = 0
    resolved = True
    indexed = False
    for match in re.finditer(r"([+-]?)([^+-]+)", expression):
        sign = -1 if match.group(1) == "-" else 1
        term = match.group(2)
        if "*" in term:
            indexed = True
            resolved = False
            continue
        immediate = IMM_RE.match(term)
        if immediate:
            total += sign * int(immediate.group(1), 16)
            continue
        if term in regs:
            value = regs[term]
            if value is None:
                resolved = False
            else:
                total += sign * value
            continue
        resolved = False
    return (total if resolved else None, indexed)


def scan(addresses: set[int], span: int) -> list[dict]:
    targets = {address: address + span for address in addresses}
    ranges = load_function_ranges()
    starts = [start for start, _, _ in ranges]
    instructions = parse_instructions()
    sites = []
    current = None
    regs: dict[str, int | None] = {}
    for address, raw, mnemonic, operands in instructions:
        name, start = function_for(address, ranges, starts)
        if name != current:
            current = name
            regs = {reg: None for reg in
                    ("eax", "ebx", "ecx", "edx", "esi", "edi", "ebp")}
        memory = MEM_RE.search(operands)
        if memory is not None:
            expression = memory.group(1).strip().lower()
            width = width_of(operands)
            resolved, indexed = parse_memory(expression, regs)
            candidates: list[int] = []
            if resolved is not None:
                candidates.append(resolved)
            # Indexed operands still expose the absolute displacement/base.
            for term in expression.replace("-", "+").split("+"):
                immediate = IMM_RE.match(term.strip())
                if immediate:
                    candidates.append(int(immediate.group(1), 16))
            for candidate in candidates:
                for target, end in targets.items():
                    if target <= candidate < end:
                        sites.append({
                            "address": f"0x{address:x}",
                            "function": name,
                            "function_start": f"0x{start:x}" if start else None,
                            "instruction": f"{mnemonic} {operands}".strip(),
                            "bytes": raw,
                            "access": access_of(mnemonic, operands),
                            "width": width,
                            "resolved_address": f"0x{candidate:x}",
                            "expression": expression,
                            "indexed": indexed or resolved is None,
                        })
                        break
        # Register state updates after the memory operand was classified.
        if mnemonic == "call":
            for reg in CALLER_SAVED:
                regs[reg] = None
            continue
        if mnemonic in ("ret", "jmp"):
            for reg in list(regs):
                regs[reg] = None
            continue
        match = REG_IMM_RE.match(operands)
        if mnemonic == "mov" and match:
            regs[match.group(1).lower()] = int(match.group(2), 16)
            continue
        match = LEA_RE.match(operands)
        if mnemonic == "lea" and match:
            value, _ = parse_memory(match.group(2), regs)
            regs[match.group(1).lower()] = value
            continue
        match = re.match(r"^(e?[abcd]x|e?[sd]i|e?[sb]p),\s*(e?[abcd]x|e?[sd]i|e?[sb]p)$",
                         operands)
        if mnemonic == "mov" and match:
            regs[match.group(1).lower()] = regs.get(match.group(2).lower())
            continue
        if mnemonic == "xor" and operands.lower().split(",")[0].strip() == \
                operands.lower().split(",")[-1].strip():
            reg = operands.split(",")[0].strip().lower()
            if reg in regs:
                regs[reg] = 0
    return sites


def render_markdown(addresses: list[int], span: int, sites: list[dict]) -> str:
    lines = ["# Global dependency scan", ""]
    lines.append("Targets:")
    for address in addresses:
        lines.append(f"- `0x{address:X}` (scan span `0x{span:X}`)")
    lines.append("")
    lines.append("| Site | Function | Access | Width | Resolved | Instruction |")
    lines.append("|---|---|---|---:|---|---|")
    for site in sites:
        lines.append(
            f"| `{site['address']}` | `{site['function']}` | {site['access']} | "
            f"{site['width'] or '?'} | `{site['resolved_address']}` | "
            f"`{site['instruction']}` |")
    lines.append("")
    return "\n".join(lines)


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("addresses", nargs="+",
                        help="target global addresses, e.g. 0x57B97C")
    parser.add_argument("--span", type=lambda value: int(value, 0), default=4,
                        help="bytes after each target included in the range")
    parser.add_argument("--json", action="store_true")
    args = parser.parse_args(argv)
    addresses = [int(value, 0) for value in args.addresses]
    sites = scan(set(addresses), args.span)
    if args.json:
        print(json.dumps({"targets": [f"0x{value:X}" for value in addresses],
                          "span": args.span, "sites": sites}, indent=2))
    else:
        print(render_markdown(addresses, args.span, sites))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
