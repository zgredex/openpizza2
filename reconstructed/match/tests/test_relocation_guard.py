#!/usr/bin/env python3
"""Strict mode must reject a wrong call target even when code bytes match."""

import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
SOURCE = ROOT / "reconstructed/match/batch02/part4/0x532510.c"


def run(symbol_address: str):
    command = [
        sys.executable, str(ROOT / "tools/match_decomp.py"),
        "0x532510", str(SOURCE), "--length", "8",
        "--entry", "?DestroyMemberList@UI_Group@@QAEXXZ",
        "--flags", "/O2 /TP", "--strict",
        "--symbol", f"?Destroy@Array@@QAEXXZ={symbol_address}",
    ]
    result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True)
    return json.loads(result.stdout)


wrong = run("0x522f28")
correct = run("0x522f20")
assert wrong["match"] is True, wrong
assert wrong["strict_match"] is False, wrong
assert any("relocation" in issue for issue in wrong["strict_issues"]), wrong
assert correct["match"] is True, correct
assert correct["strict_match"] is True, correct
print("relocation guard: wrong target rejected, correct target accepted")
