#!/usr/bin/env python3
"""Inventory original PC2 functions by the cleanup targets in their VC6 unwind maps."""

import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import struct

from compare_vc6_unwind import handler_field_offset, original_operand, read_unwind
from decomp_fixtures import PE_HASH
import match_decomp as match


def inventory():
    if match.file_sha256(match.GAME) != PE_HASH:
        raise ValueError("cleanup inventory requires the pinned executable")
    image = match.pe_image(match.GAME)
    names = json.loads(match.SYMBOL_INDEX.read_text())
    groups = defaultdict(list)
    unsupported = []
    decoded = 0

    def read(address, size):
        return match.read_va(image, address, size)

    def resolve(address, offset, kind):
        return original_operand(read, address, offset, kind)

    for address, length in sorted(match.function_lengths().items()):
        try:
            offset = handler_field_offset(read(address, min(length, 32)))
            handler = resolve(address, offset, 0x06)
        except (ValueError, struct.error):
            continue
        try:
            unwind = read_unwind(read, resolve, handler)
        except (ValueError, struct.error) as error:
            unsupported.append({"address": hex(address), "error": str(error)})
            continue
        decoded += 1
        actions = defaultdict(list)
        for index, row in enumerate(unwind["states"]):
            cleanup = row["cleanup"]
            if cleanup is None:
                continue
            for transfer in cleanup["transfers"]:
                actions[transfer["target"]].append({
                    "state": index, "previous": row["previous"], "transfer": transfer["instruction"],
                    "frame_offsets": cleanup["frame_offsets"],
                })
        for target, occurrences in actions.items():
            groups[target].append({
                "address": hex(address), "name": names.get(hex(address)), "length": length,
                "handler": hex(handler), "func_info": hex(unwind["func_info"]),
                "state_count": len(unwind["states"]), "actions": occurrences,
            })
    families = []
    for target, members in groups.items():
        state_counts = Counter(member["state_count"] for member in members)
        families.append({
            "cleanup_target": hex(target), "cleanup_name": names.get(hex(target)),
            "functions": len(members), "indexed_bytes": sum(member["length"] for member in members),
            "unwind_state_counts": dict(sorted(state_counts.items())), "members": members,
        })
    families.sort(key=lambda family: (-family["indexed_bytes"], int(family["cleanup_target"], 16)))
    return {
        "schema": "pc2.vc6_cleanup_families.v1", "executable_sha256": PE_HASH,
        "decoded_unwind_maps": decoded, "unsupported_unwind_maps": unsupported, "families": families,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cleanup", action="append", type=lambda text: int(text, 0), default=[])
    parser.add_argument("--top", type=int, default=8)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    try:
        report = inventory()
        if args.cleanup:
            selected = {hex(address) for address in args.cleanup}
            report["families"] = [family for family in report["families"] if family["cleanup_target"] in selected]
            missing = selected - {family["cleanup_target"] for family in report["families"]}
            if missing:
                raise ValueError("no supported unwind references to " + ", ".join(sorted(missing)))
        with args.out.open("x") as stream:
            json.dump(report, stream, indent=2)
            stream.write("\n")
    except (OSError, ValueError) as error:
        parser.exit(1, f"VC6 cleanup inventory: {error}\n")
    print(f"{report['decoded_unwind_maps']} unwind maps decoded")
    for family in report["families"][:args.top]:
        print(f"{family['cleanup_target']} {family['cleanup_name'] or '(unnamed)'}: "
              f"{family['functions']} functions, {family['indexed_bytes']} indexed bytes")


if __name__ == "__main__":
    main()
