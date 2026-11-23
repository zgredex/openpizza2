#!/usr/bin/env python3
"""Mine call-target families across the indexed PC2 functions.

A family is a group of functions that call the same relatively rare target.
The report ranks groups by total indexed bytes so large, coherent families
surface before one-off register walls.
"""

import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path

from capstone import CS_ARCH_X86, CS_MODE_32, Cs, x86_const as x86

import match_decomp as match


def load_names():
    return json.loads(match.SYMBOL_INDEX.read_text())


def load_imports():
    return {address: name for name, address in match.pe_imports().items()}


def calls(address, length, image, names, imports):
    data = match.read_va(image, address, length)
    disasm = Cs(CS_ARCH_X86, CS_MODE_32)
    disasm.detail = True
    result = []
    for insn in disasm.disasm(data, address):
        if insn.id == x86.X86_INS_CALL:
            operands = insn.operands
            if not operands:
                continue
            op = operands[0]
            if op.type == x86.X86_OP_IMM:
                target = op.imm & 0xffffffff
            elif op.type == x86.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
                target = op.mem.disp & 0xffffffff
            else:
                continue
            if target in imports:
                label = f"imp:{imports[target]}"
            elif target in names:
                label = names[target]
            else:
                label = f"0x{target:08x}"
            result.append((target, label))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", required=True, type=Path)
    parser.add_argument("--report", type=Path)
    parser.add_argument("--min-functions", type=int, default=3)
    parser.add_argument("--min-bytes", type=int, default=500)
    parser.add_argument("--top", type=int, default=40)
    args = parser.parse_args()
    try:
        if match.file_sha256(match.GAME) != "18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd":
            raise ValueError("original PE does not match the pinned hash")
        image = match.pe_image(match.GAME)
        names = load_names()
        imports = load_imports()
        lengths = match.function_lengths()
        calls_by_function = {}
        for address, length in sorted(lengths.items()):
            calls_by_function[address] = calls(address, length, image, names, imports)
        frequency = Counter(label for rows in calls_by_function.values() for _, label in rows)
        groups = defaultdict(list)
        for address, rows in calls_by_function.items():
            labels = {label for _, label in rows if frequency[label] >= 2}
            if not labels:
                continue
            # The rarest target is the most distinctive family key.
            key = min(labels, key=lambda label: (frequency[label], label))
            groups[key].append(address)
        families = []
        for key, addresses in groups.items():
            total = sum(lengths.get(address, 0) for address in addresses)
            if len(addresses) < args.min_functions or total < args.min_bytes:
                continue
            families.append({
                "key": key,
                "callee_frequency": frequency[key],
                "functions": len(addresses),
                "indexed_bytes": total,
                "members": [{"address": hex(address), "name": names.get(hex(address)), "length": lengths[address]}
                            for address in sorted(addresses, key=lambda value: lengths[value], reverse=True)],
            })
        families.sort(key=lambda row: (-row["indexed_bytes"], -row["functions"], row["key"]))
        report = {"schema": "pc2.feature_families.v1", "families": families[: args.top]}
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps(report, indent=2) + "\n")
        if args.report:
            lines = ["# Call-target families", "", "| key | fns | bytes | members (largest) |", "|---|---:|---:|---|"]
            for family in report["families"]:
                members = ", ".join(f"{row['name'] or row['address']} ({row['length']})" for row in family["members"][:6])
                lines.append(f"| {family['key']} | {family['functions']} | {family['indexed_bytes']:,} | {members} |")
            args.report.write_text("\n".join(lines) + "\n")
        print(f"{len(families)} feature families; top {len(report['families'])} written")
        for family in report["families"][:20]:
            print(f"  {family['indexed_bytes']:8,d} B  {family['functions']:3d} fns  {family['key']}")
    except (OSError, ValueError, json.JSONDecodeError) as error:
        parser.exit(1, f"feature families: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
