#!/usr/bin/env python3
"""Validate the reconstructed .piz character/player records with the existing parser."""

from __future__ import annotations

import json
import os
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

from piz_payload import PizSave  # noqa: E402


def main() -> int:
    binary = os.path.join(ROOT, "reconstructed", "build", "test_piz_container")
    if not os.path.isfile(binary):
        subprocess.run(["make", "-C", os.path.join(ROOT, "reconstructed"),
                        "build/test_piz_container"], cwd=ROOT, check=True,
                       capture_output=True, text=True)
    with tempfile.TemporaryDirectory() as directory:
        path = os.path.join(directory, "records.piz")
        subprocess.run([binary, path], cwd=ROOT, check=True,
                       capture_output=True, text=True)
        save = PizSave(path)
        characters = save.parse_characters()
        players = save.parse_players()
        companies = save.parse_companies()
    result = {
        "fixture": "piz_records",
        "character_count": characters["count"],
        "character_record_size": characters["record_size"],
        "character_errors": characters["errors"],
        "player_errors": players["errors"],
        "player_slots": len(players["slots"]),
        "player_slot0_present": players["slots"][0]["present"] if players["slots"] else 0,
        "company_count": companies["count"],
        "company_record_size": companies["record_size"],
        "company_nested_size": companies["nested_size"],
        "company_errors": companies["errors"],
        "company_slot0_name": (companies["slots"][0].get("name")
                               if companies["slots"] else None),
        "company_slot0_cash": (companies["slots"][0].get("cash")
                               if companies["slots"] else None),
    }
    ok = (not characters["errors"] and not players["errors"]
          and not companies["errors"]
          and characters["count"] == 1 and characters["record_size"] == 2086
          and result["player_slot0_present"] == 1
          and companies["count"] == 1 and companies["record_size"] == 270
          and result["company_slot0_name"] == "Ada Pizza"
          and result["company_slot0_cash"] == 494270.0)
    result["ok"] = ok
    print(json.dumps(result, separators=(",", ":")))
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
