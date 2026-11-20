#!/usr/bin/env python3
"""PC2 lift driver.

The pinned pcrecomp CLI discovers functions from the PE entry point, exports
and its own call/prologue scans, but has no --seed-functions option. These
confirmed PC2 targets are outside those scans, so seed them into the same
discovery call the CLI uses before generating the dispatch table.
"""

import os
import sys

PC2_SEEDS = (
    0x00504980,  # WorldObject_Delete (shipped vtable at 0x0055C668)
    0x00553C9D,  # CRT_LocalUnwind2
    0x00555F68,  # startup routine registering the unhandled-exception filter
)


def main():
    root = os.environ.get("PCRECOMP_ROOT")
    if root:
        sys.path.insert(0, root)

    from tools.lift import translator

    def discover_with_pc2_seed(pe_data, info, iat_map):
        # Keep the translator's own entry/export seeds, then add the PC2
        # vtable target that has no direct caller.
        from disasm32 import Disassembler

        disassembler = Disassembler(pe_data, info.image_base, info.sections)
        seeds = [info.image_base + info.entry_point_rva]
        seeds += [info.image_base + e.rva for e in getattr(info, "exports", []) if e.rva]
        seeds.extend(PC2_SEEDS)
        print("[*] PC2 seeds: " + ", ".join(f"0x{seed:08X}" for seed in PC2_SEEDS))
        return disassembler.find_functions(
            info.code_start, info.code_end, iat_map, seeds=seeds
        )

    translator.discover_functions = discover_with_pc2_seed
    translator.main()


if __name__ == "__main__":
    main()
