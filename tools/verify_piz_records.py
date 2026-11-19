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
        "company_branch_record_size": companies["branch_record_size"],
        "company_errors": companies["errors"],
        "company_slot0_name": (companies["slots"][0].get("name")
                               if companies["slots"] else None),
        "company_slot0_cash": (companies["slots"][0].get("cash")
                               if companies["slots"] else None),
        "company_slot0_plan_count": (companies["slots"][0].get("plan_count")
                                     if companies["slots"] else None),
        "company_slot0_recipe_count": (companies["slots"][0].get("recipe_count")
                                       if companies["slots"] else None),
        "company_slot0_recipes": (companies["slots"][0].get("recipes")
                                  if companies["slots"] else None),
        "company_slot0_reports": (companies["slots"][0].get("reports")
                                  if companies["slots"] else None),
        "company_slot0_branch_count": (companies["slots"][0].get("branch_count")
                                       if companies["slots"] else None),
        "company_slot0_branches": (companies["slots"][0].get("branches")
                                   if companies["slots"] else None),
        "company_slot0_report_count": (companies["slots"][0].get("report_count")
                                       if companies["slots"] else None),
        "company_slot0_storage": (companies["slots"][0].get("storage")
                                  if companies["slots"] else None),
        "company_slot0_pairs": (companies["slots"][0].get("pairs")
                                if companies["slots"] else None),
        "company_slot0_big_count": (companies["slots"][0].get("big_count")
                                    if companies["slots"] else None),
    }
    ok = (not characters["errors"] and not players["errors"]
          and not companies["errors"]
          and characters["count"] == 1 and characters["record_size"] == 2086
          and result["player_slot0_present"] == 1
          and companies["count"] == 1 and companies["record_size"] == 270
          and result["company_slot0_name"] == "Ada Pizza"
          and result["company_slot0_cash"] == 494270.0
          and result["company_slot0_plan_count"] == 1
          and result["company_slot0_recipe_count"] == 1
          and result["company_slot0_recipes"][0]["topping_count"] == 1
          and result["company_slot0_recipes"][0]["toppings"] == [
              {"ingredient": 5, "category": 1, "tier": 2, "x": 10, "y": 20,
               "variant": 1, "flag": 1}]
          and result["company_slot0_branch_count"] == 1
          and result["company_slot0_branches"][0]["id"] == 13694
          and result["company_slot0_branches"][0]["name"] == "London branch"
          and result["company_slot0_branches"][0]["style"] == 2
          and result["company_slot0_branches"][0]["flags"] == 0x24
          and result["company_slot0_report_count"] == 1
          and result["company_slot0_reports"][0]["income"][0] == 100.5
          and result["company_slot0_reports"][0]["income"][4] == 50.25
          and result["company_slot0_reports"][0]["expense"][12] == 30.75
          and result["company_slot0_storage"] == [
              {"id": 7, "name": "London storage"}]
          and result["company_slot0_pairs"] == [
              {"id": 9, "value": 0x1122334455667788}]
          and result["company_slot0_big_count"] == 1)
    result["ok"] = ok
    print(json.dumps(result, separators=(",", ":")))
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
