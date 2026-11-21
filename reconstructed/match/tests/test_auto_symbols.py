#!/usr/bin/env python3
"""Regression: strict matching without explicit symbol maps.

Covers PE import IAT slots, data globals resolved from data_symbols.csv,
C++ EH funclets (.text$x/.xdata$x), and anchored vtable COMDATs.
"""
from __future__ import annotations

import json
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
MATCHER = ROOT / "tools" / "match_decomp.py"

CASES = [
    # dllimport RegCloseKey: resolved from the PE import directory.
    ("0x4032e0", "reconstructed/match/batch03/part1/0x4032e0.c",
     24, "@RegistryKey_Close@4", "/O2"),
    # C++ EH funclet, .xdata$x, and a vtable COMDAT.
    ("0x401a20", "reconstructed/match/batch01/part1/0x401a20.c",
     204, "??1ResourceManager@@UAE@XZ", "/O2 /GX /TP"),
    # Data globals g_game/g_gfx plus .text$x verification.
    ("0x477190", "reconstructed/match/batch01/part4/0x477190.c",
     456, "?SpawnWalkInCustomer@Branch@@QAEXXZ", "/O2 /GX /TP"),
]


def main() -> int:
    for address, source, length, entry, flags in CASES:
        with tempfile.NamedTemporaryFile(suffix=".json") as report:
            command = [
                sys.executable, str(MATCHER), address,
                str(ROOT / source), "--length", str(length),
                "--entry", entry, "--flags", flags,
                "--strict", "--auto-symbols", "--json-out", report.name,
            ]
            result = subprocess.run(command, cwd=ROOT, text=True,
                                    capture_output=True, check=True)
            data = json.loads(Path(report.name).read_text())
        assert data["strict_match"], (address, data)
        assert not data["strict_issues"], (address, data["strict_issues"])
        assert not data["relocation_issues"], (address, data["relocation_issues"])
        assert data["difference_count"] == 0, (address, data)
        print(f"auto symbol/unwind {address}: strict match")
    print("auto symbol/unwind regression: ok")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
