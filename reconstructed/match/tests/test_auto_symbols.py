#!/usr/bin/env python3
"""Verify independent IAT/data targets and fail closed on unresolved C++ EH."""
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
     24, "@RegistryKey_Close@4", "/O2", "pe_iat", None),
    # Typed DAT_ address label and the independent IDMap_Lookup symbol.
    ("0x4d3910", "reconstructed/match/batch03/part1/0x4d3910.c",
     23, "?Game_GetRecordByField814@@YIXPAD@Z", "/O2 /TP", "address_label", None),
    # The constructor anchors the vtable, while this EH body still has an
    # unknown local C++ destructor and must fail closed.
    ("0x401a20", "reconstructed/match/batch01/part1/0x401a20.c",
     204, "??1ResourceManager@@UAE@XZ", "/O2 /GX /TP", "registry_section_anchor",
     "??1Lock@@QAE@XZ"),
    # Explicit global addresses would be needed for these source-specific names.
    ("0x477190", "reconstructed/match/batch01/part4/0x477190.c",
     456, "?SpawnWalkInCustomer@Branch@@QAEXXZ", "/O2 /GX /TP", "decorated_alias",
     "?g_game@@3PAUGame@@A"),
]


def main() -> int:
    for address, source, length, entry, flags, origin, unresolved in CASES:
        with tempfile.NamedTemporaryFile(suffix=".json") as report:
            command = [
                sys.executable, str(MATCHER), address,
                str(ROOT / source), "--length", str(length),
                "--entry", entry, "--flags", flags,
                "--strict", "--auto-symbols", "--json-out", report.name,
            ]
            result = subprocess.run(command, cwd=ROOT, text=True,
                                    capture_output=True)
            data = json.loads(Path(report.name).read_text())
        assert not data.get("error"), (address, data)
        assert not data["relocation_issues"], (address, data["relocation_issues"])
        assert data["difference_count"] == 0, (address, data)
        assert any(fixup["origin"] == origin and fixup["verified"]
                   for fixup in data["relocations"]), (address, data)
        if unresolved:
            assert result.returncode == 1 and not data["strict_match"], (address, data)
            assert any(issue.endswith(f"unresolved symbol {unresolved}")
                       for issue in data["strict_issues"]), (address, data)
            print(f"auto symbol/unwind {address}: unresolved {unresolved} rejected")
        else:
            assert result.returncode == 0 and data["strict_match"], (address, data)
            assert not data["strict_issues"], (address, data["strict_issues"])
            print(f"auto symbol/unwind {address}: strict match")
    print("auto symbol/unwind regression: ok")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
