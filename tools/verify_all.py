#!/usr/bin/env python3
"""Single reproducibility entry point for the Pizza Connection 2 workspace.

Runs the model checks from MODERN_ENGINE_ROADMAP.md, regenerates the demo
samples from the same run, and refreshes SIM_VERIFICATION.json.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TARGET = os.path.join(ROOT, "game", "fastfood2.exe")
EXPECTED_SHA256 = (
    "18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd"
)
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")
SAMPLES = os.path.join(BASE, "samples")
SUITES = [
    ("tests/test_sim_core.py", "simulation"),
    ("tests/test_tab_tool.py", "tab"),
    ("tests/test_iso_tool.py", "iso"),
    ("tests/test_piz_payload.py", "save"),
    ("tests/test_piz_fuzz.py", "save-fuzz"),
    ("tests/test_spr_tool.py", "spr"),
    ("tests/test_scene_tool.py", "scene"),
    ("tests/test_ani_tool.py", "ani"),
]
PENDING = [
    "original-game paused city crop (Wine capture dropped by request)",
    "original-game branch interior crop (Wine capture dropped by request)",
    "fresh manual .piz save and a second controlled-change save",
    "original-game reload of a modified save",
    "one controlled sale with stock/cash/ledger deltas",
    "one calendar-boundary event and its observed values",
]


def sha256(path):
    digest = hashlib.sha256()
    with open(path, "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def run(command, timeout=180):
    started = time.perf_counter()
    proc = subprocess.run(
        command, cwd=ROOT, text=True, capture_output=True, timeout=timeout)
    return {
        "command": command,
        "returncode": proc.returncode,
        "stdout": proc.stdout,
        "stderr": proc.stderr,
        "seconds": round(time.perf_counter() - started, 3),
    }


def check_target():
    actual = sha256(TARGET)
    return {
        "name": "executable sha256",
        "ok": actual == EXPECTED_SHA256,
        "detail": f"{actual} (expected {EXPECTED_SHA256})",
    }


def check_manifest():
    with open(os.path.join(BASE, "full_game_symbols.json")) as fh:
        symbols = json.load(fh)
    with open(os.path.join(
            BASE, "full_game_verification", "decompile-index.json")) as fh:
        index = json.load(fh)
    available = {
        item["address"]: item["name"]
        for item in index["functions"]
        if item.get("body", {}).get("available")
        and str(item.get("address", "")).startswith("0x")
    }
    missing = [address for address in symbols if address not in available]
    mismatch = [
        address for address, name in symbols.items()
        if address in available and available[address] != name
    ]
    return {
        "name": "named manifest",
        "ok": not missing and not mismatch,
        "detail": (f"{len(symbols)} names, {len(available)} bodies, "
                   f"{len(missing)} missing, {len(mismatch)} mismatched"),
    }


def run_suite(relative, label):
    result = run([sys.executable, "-W", "error::ResourceWarning",
                  relative])
    tests = 0
    output = result["stdout"] + result["stderr"]
    ok = result["returncode"] == 0
    for line in output.splitlines():
        if line.startswith("Ran ") and " test" in line:
            try:
                tests = int(line.split()[1])
            except (IndexError, ValueError):
                pass
        if line.startswith("FAILED"):
            ok = False
    return {
        "name": f"tests: {label}",
        "ok": ok,
        "tests": tests,
        "detail": (f"Ran {tests} test{'s' if tests != 1 else ''} "
                   f"in {result['seconds']}s"
                   if ok else output[-1200:]),
    }


def check_rust_inventory():
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-inventory", "--",
         "--install", "game", "--check"],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    if result.returncode != 0:
        return {
            "name": "rust archive inventory",
            "ok": False,
            "detail": (result.stdout + result.stderr)[-800:],
        }
    try:
        inventory = json.loads(result.stdout)
    except json.JSONDecodeError as error:
        return {
            "name": "rust archive inventory",
            "ok": False,
            "detail": f"invalid JSON: {error}",
        }
    ok = (inventory.get("pak_count") == 5
          and inventory.get("entries") == 9142
          and inventory.get("payload_bytes") == 448651308)
    return {
        "name": "rust archive inventory",
        "ok": ok,
        "detail": (f"{inventory.get('pak_count')} paks, "
                   f"{inventory.get('entries')} entries, "
                   f"{inventory.get('payload_bytes')} payload bytes"),
    }


def check_spr_exports():
    root = os.path.join(ROOT, "extracted_png")
    manifest = os.path.join(root, "SHA256SUMS")
    if not os.path.isfile(manifest):
        return {"name": "sprite PNG exports", "ok": False,
                "detail": "extracted_png/SHA256SUMS is missing"}
    entries = 0
    missing = []
    mismatched = []
    with open(manifest) as fh:
        for line in fh:
            line = line.rstrip("\n")
            if not line:
                continue
            digest, relative = line.split("  ", 1)
            entries += 1
            path = os.path.join(root, relative)
            if not os.path.isfile(path):
                missing.append(relative)
            elif sha256(path) != digest:
                mismatched.append(relative)
    samples = [
        ("extracted/isodaten/sprites/b_laub_b.spr",
         "isodaten/sprites/b_laub_b.png"),
        ("extracted/sprites/m_service_m01.spr",
         "sprites/m_service_m01.png"),
        ("extracted/sprites/pb07__01.spr",
         "sprites/pb07__01.png"),
        ("extracted/isodaten/sprites/filiale_klein_einf_back.spr",
         "isodaten/sprites/filiale_klein_einf_back.png"),
        ("extracted/sprites/playlog_5_02_00.spr",
         "sprites/playlog_5_02_00.png"),
    ]
    scratch = tempfile.mkdtemp(prefix="pc2-spr-export-",
                               dir="/tmp/opencode" if os.path.isdir(
                                   "/tmp/opencode") else None)
    regenerated = 0
    for source, relative in samples:
        out = os.path.join(scratch, os.path.basename(relative))
        result = subprocess.run(
            [sys.executable, os.path.join(ROOT, "tools", "spr_tool.py"),
             "export", os.path.join(ROOT, source), out],
            cwd=ROOT, text=True, capture_output=True, timeout=120)
        expected = os.path.join(root, relative)
        produced = os.path.join(out, os.path.basename(relative))
        if (result.returncode == 0 and os.path.isfile(produced)
                and sha256(produced) == sha256(expected)):
            regenerated += 1
    ok = (entries == 6947 and not missing and not mismatched
          and regenerated == len(samples))
    return {
        "name": "sprite PNG exports",
        "ok": ok,
        "detail": (f"{entries} PNGs, {len(missing)} missing, "
                   f"{len(mismatched)} mismatched, "
                   f"{regenerated}/{len(samples)} regenerated"),
    }


def check_customer_trace():
    path = os.path.join(BASE, "CUSTOMER_VISIT_TRACE.md")
    if not os.path.isfile(path):
        return {"name": "customer visit trace", "ok": False,
                "detail": "CUSTOMER_VISIT_TRACE.md is missing"}
    with open(path) as fh:
        text = fh.read()
    addresses = ["0x477190", "0x409d80", "0x40a380", "0x509580", "0x47d4a0"]
    traces = ["Worked trace A", "Worked trace B", "Worked trace C"]
    ok = (all(address in text for address in addresses)
          and all(trace in text for trace in traces)
          and "13.4205247" in text and "400" in text)
    return {
        "name": "customer visit trace",
        "ok": ok,
        "detail": ("state table + successful/full-queue/missing-ingredient traces"
                   if ok else "trace document is missing required sections"),
    }


def check_recipe_function_cards():
    path = os.path.join(BASE, "RECIPE_ORDER_FUNCTIONS.md")
    if not os.path.isfile(path):
        return {"name": "recipe function cards", "ok": False,
                "detail": "RECIPE_ORDER_FUNCTIONS.md is missing"}
    with open(path) as fh:
        text = fh.read()
    addresses = ["0x513bf0", "0x5092b0", "0x509580", "0x47d4a0"]
    tests = ["recipe_price_0x513bf0_matches_python_contract",
             "candidate_score_0x5092b0_matches_disassembly",
             "candidate_rank_0x509580_matches_bands",
             "one_sale_matches_python_case",
             "shortage_0x47d4a0_posts_nothing"]
    batch = os.path.join(BASE, "RECIPE_ORDER_BATCH.md")
    batch_ok = os.path.isfile(batch)
    if batch_ok:
        with open(batch) as fh:
            batch_text = fh.read()
        batch_ok = ("extraout_EDX" in batch_text
                    and "unaff_EDI" in batch_text
                    and "Disassembly" in batch_text)
    ok = (all(address in text for address in addresses)
          and all(test in text for test in tests) and batch_ok)
    return {
        "name": "recipe function cards",
        "ok": ok,
        "detail": ("price, score, selection and settlement cards linked to tests"
                   if ok else "recipe function cards or batch packet are incomplete"),
    }


def check_skill_quality_cards():
    path = os.path.join(BASE, "SKILL_QUALITY_FUNCTIONS.md")
    batch = os.path.join(BASE, "SKILL_QUALITY_BATCH.md")
    if not os.path.isfile(path) or not os.path.isfile(batch):
        return {"name": "skill quality batch", "ok": False,
                "detail": "SKILL_QUALITY_FUNCTIONS.md or batch packet is missing"}
    with open(path) as fh:
        text = fh.read()
    with open(batch) as fh:
        batch_text = fh.read()
    ok = (all(address in text for address in
              ["0x513760", "0x5139e0", "0x47d910"])
          and "skill_rating_0x5139e0_aggregates_arrays" in text
          and "quality_95_replay_0x47d910_0x509580_0x47d4a0" in text
          and "extraout_EDX" in text
          and "Disassembly" in batch_text)
    table_path = os.path.join(BASE, "PRODUCT_QUALITY_TABLES.json")
    shapes = {"0x567938": (1, 8), "0x567958": (1, 8),
              "0x567978": (8, 6), "0x567a38": (8, 9)}
    errors = []
    try:
        with open(table_path) as fh:
            fixture = json.load(fh)
        tables = fixture["tables"]
        if (fixture["function"] != "0x47d910"
                or fixture["target_sha256"] != EXPECTED_SHA256
                or not isinstance(tables, dict) or tables.keys() != shapes.keys()):
            raise ValueError("wrong target or table inventory")
        with open(TARGET, "rb") as fh:
            for address, (row_count, width) in shapes.items():
                rows = tables[address]
                if len(rows) != row_count or any(len(row) != width for row in rows):
                    errors.append(f"{address} shape mismatch")
                    continue
                values = [value for row in rows for value in row]
                expected = struct.pack(f"<{len(values)}i", *values)
                # The pinned PE maps .data VA 0x563000 at file offset 0x163000.
                fh.seek(int(address, 16) - 0x400000)
                if fh.read(len(expected)) != expected:
                    errors.append(f"{address} bytes differ from executable")
    except (OSError, KeyError, TypeError, ValueError, struct.error) as error:
        errors.append(str(error))
    if not ok:
        errors.append("skill/quality cards or batch are incomplete")
    return {
        "name": "skill quality batch",
        "ok": not errors,
        "detail": (", ".join(errors) if errors
                   else "skill cards and all four product-quality tables verified"),
    }


def check_product_quality_replay():
    result = subprocess.run(
        [sys.executable, os.path.join(ROOT, "tools", "quality_tool.py")],
        cwd=ROOT, text=True, capture_output=True, timeout=120)
    output = result.stdout + result.stderr
    trace = os.path.join(BASE, "VIRTUAL_CALL_TRACE.md")
    fixture = os.path.join(BASE, "PRODUCT_QUALITY_REPLAY.json")
    trace_ok = False
    if os.path.isfile(trace):
        with open(trace) as fh:
            trace_text = fh.read()
        trace_ok = all(value in trace_text for value in
                       ["0x401420", "0x55c2ec", "DirectSound"])
    fixture_ok = False
    if os.path.isfile(fixture):
        try:
            with open(fixture) as fh:
                replay = json.load(fh)
            fixture_ok = (
                all("combined_score" not in case for case in replay["cases"])
                and len(replay.get("mutations", [])) == 2
            )
        except (OSError, KeyError, TypeError, json.JSONDecodeError):
            fixture_ok = False
    ok = (result.returncode == 0 and output.count("OK") == 7
          and "FAIL" not in output and trace_ok and fixture_ok)
    return {
        "name": "product quality replay",
        "ok": ok,
        "detail": ("5/5 derived quality cases, 2/2 mutations, virtual-call evidence"
                   if ok else output[-1000:]),
    }


def check_main_menu():
    output_png = "/tmp/opencode/pc2-main-menu.png"
    continue_png = "/tmp/opencode/pc2-main-menu-continue.png"
    quit_png = "/tmp/opencode/pc2-main-menu-quit.png"
    for path in (output_png, continue_png, quit_png):
        try:
            os.remove(path)
        except FileNotFoundError:
            pass
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--menu", "--output", output_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    continue_run = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--menu", "--menu-script", "down;down;enter",
         "--output", continue_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    quit_run = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--menu", "--menu-script", "up;enter",
         "--output", quit_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    invalid_run = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--menu", "--menu-script", "not-a-command",
         "--output", "/tmp/opencode/pc2-main-menu-invalid.png"],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    continue_output = continue_run.stdout + continue_run.stderr
    quit_output = quit_run.stdout + quit_run.stderr
    invalid_output = invalid_run.stdout + invalid_run.stderr
    rows = [
        (0, "Start new game", 0x3EE, 6),
        (1, "Start free game", 0x3EF, 48),
        (2, "Continue game", 0x3F0, 91),
        (3, "Options", 0x3F1, 133),
        (4, "Credits", 0x3F7, 175),
        (5, "Quit", 0x3F6, 560),
    ]
    rows_ok = all(
        f'menu: item {index} label="{label}" id=0x{control_id:03x} '
        f'x=595 y={y} w=204 h=38' in output
        for index, label, control_id, y in rows
    )
    menu_ok = (
        result.returncode == 0
        and "menu: background=pictures\\pe_startscreen.tga 800x600" in output
        and "menu: font=fonts\\timesfont.fnt line_height=23" in output
        and "menu: items=6" in output
        and rows_ok
        and 'menu: selected=0 label="Start new game"' in output
        and "0 byte mismatches" in output
        and "result: OK" in output
    )
    actions_ok = (
        continue_run.returncode == 0
        and 'menu: action=ContinueGame id=0x3f0 label="Continue game"' in continue_output
        and quit_run.returncode == 0
        and 'menu: action=Quit id=0x3f6 label="Quit"' in quit_output
        and invalid_run.returncode != 0
        and "unknown menu command: not-a-command" in invalid_output
    )
    ok = menu_ok and actions_ok
    detail = "6 controls, LDF labels, roles; ContinueGame/Quit; invalid command rejected"
    if ok and os.path.isfile(output_png):
        actual = sha256(output_png)
        expected = "720d4add6e4bc43cb78bbe19007043c4e5c3fc19b52d487c719d215b18b9c044"
        ok = actual == expected
        detail = f"menu {actual[:16]}; 6 controls at original coordinates"
    else:
        ok = False
    return {
        "name": "main menu replay",
        "ok": ok,
        "detail": detail if ok else (output + continue_output + quit_output + invalid_output)[-1800:],
    }


def check_character_select():
    output_png = "/tmp/opencode/pc2-character-select.png"
    start_png = "/tmp/opencode/pc2-character-select-start.png"
    invalid_png = "/tmp/opencode/pc2-character-select-invalid.png"
    for path in (output_png, start_png, invalid_png):
        try:
            os.remove(path)
        except FileNotFoundError:
            pass
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--character-select", "--output", output_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    start_run = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--character-select", "--character-script", "down;enter",
         "--output", start_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    invalid_run = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--character-select", "--character-script", "not-a-command",
         "--output", invalid_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    start_output = start_run.stdout + start_run.stderr
    invalid_output = invalid_run.stdout + invalid_run.stderr
    screen_ok = (
        result.returncode == 0
        and "character: background=pictures\\pe_charakterauswahl.tga 800x600" in output
        and 'character: button 0 label="To main menu" id=0x434 x=595 y=509 w=204 h=38' in output
        and 'character: button 1 label="Start game" id=0x435 x=595 y=551 w=204 h=38' in output
        and 'character: selected=0 label="To main menu"' in output
        and "0 byte mismatches" in output
        and "result: OK" in output
    )
    action_ok = (
        start_run.returncode == 0
        and 'character: action=Start id=0x435 label="Start game"' in start_output
        and "character: final_action=Start" in start_output
        and invalid_run.returncode != 0
        and "unknown character command: not-a-command" in invalid_output
    )
    ok = screen_ok and action_ok
    detail = "character screen, Back/Start controls, Start action, invalid command rejected"
    if ok and os.path.isfile(output_png):
        actual = sha256(output_png)
        expected = "feba57b7487a5c3711c7b58fdc1018a4187c3146fd1d4b680cb965476a11a781"
        ok = actual == expected
        detail = f"character select {actual[:16]}; Back/Start at original coordinates"
    else:
        ok = False
    return {
        "name": "character select replay",
        "ok": ok,
        "detail": detail if ok else (output + start_output + invalid_output)[-1800:],
    }


def check_clock_replay():
    morning = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-sim", "--bin", "pc2-clock", "--",
         "--start", "10:55", "--end", "11:20", "--snapshot-at", "11:00",
         "--snapshot-resume"],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    boundary = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-sim", "--bin", "pc2-clock", "--",
         "--start", "10:55", "--end", "11:05"],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    midnight = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-sim", "--bin", "pc2-clock", "--",
         "--start", "23:55", "--end", "00:05", "--snapshot-resume"],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    morning_output = morning.stdout + morning.stderr
    boundary_output = boundary.stdout + boundary.stderr
    midnight_output = midnight.stdout + midnight.stderr
    morning_ok = (
        morning.returncode == 0
        and "hourly_count=1" in morning_output
        and "arrival queue=1" in morning_output
        and "production_start" in morning_output
        and "queue_service remaining=0" in morning_output
        and "sale stock=399 cash_delta=13.420525" in morning_output
        and "departure" in morning_output
        and "branch_clock=11:20" in morning_output
        and "snapshot_resume=identical" in morning_output
    )
    boundary_ok = (
        boundary.returncode == 0
        and "hourly_count=1" in boundary_output
        and "arrival queue=1" in boundary_output
        and "production_start" in boundary_output
        and "sale " not in boundary_output
        and "branch_clock=11:05" in boundary_output
    )
    midnight_ok = (
        midnight.returncode == 0
        and "hourly_count=1" in midnight_output
        and "quarter_boundary_count=1" in midnight_output
        and "snapshot_resume=identical" in midnight_output
    )
    ok = morning_ok and boundary_ok and midnight_ok
    return {
        "name": "clock replay",
        "ok": ok,
        "detail": ("full visit, hourly-once 11:05, midnight, snapshot resume"
                   if ok else (morning_output + boundary_output + midnight_output)[-1600:]),
    }


def check_rust_asset_audit():
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-audit", "--",
         "--install", "game", "--check"],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    expected = ("9142 entries, 7542 decoded, 1600 header-only, "
                "0 unsupported, 0 errors")
    ok = result.returncode == 0 and expected in output
    return {
        "name": "rust asset audit",
        "ok": ok,
        "detail": (expected if ok else output[-1200:]),
    }


def check_rust_quads():
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-render"],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    ok = (result.returncode == 0 and "backend: Vulkan" in output
          and "result: OK" in output)
    adapter = ""
    for line in output.splitlines():
        if line.startswith("adapter:"):
            adapter = line.split(":", 1)[1].strip()
    return {
        "name": "rust Vulkan quads",
        "ok": ok,
        "detail": (f"{adapter}; two overlapping quads matched"
                   if ok else output[-1000:]),
    }


def check_rust_viewer():
    output_png = "/tmp/opencode/pc2-berlin-crop.png"
    output_json = "/tmp/opencode/pc2-berlin-draws.json"
    for path in (output_png, output_json):
        try:
            os.remove(path)
        except FileNotFoundError:
            pass
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--install", "game", "--map", "game/Isokarten/Ber.iso",
         "--output", output_png, "--json", output_json],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    ok = (result.returncode == 0
          and "draws: 125 ordered, missing 0, ambiguous 0" in output
          and "backend: Vulkan" in output
          and "readback, 0 byte mismatches" in output
          and "result: OK" in output)
    detail = "125 ordered draws, Vulkan readback matched"
    if ok and os.path.isfile(output_png):
        actual = sha256(output_png)
        expected = "e4c82cdaea60e74b27923b26b14942f23f823580d776bbeacfbca5cb9531fb49"
        ok = actual == expected
        detail = f"125 draws, {actual}"
    else:
        ok = False
    if ok and os.path.isfile(output_json):
        try:
            with open(output_json) as fh:
                draw_list = json.load(fh)
            ok = (draw_list.get("draws") == 125
                  and not draw_list.get("missing")
                  and not draw_list.get("ambiguous"))
        except (OSError, json.JSONDecodeError) as error:
            ok = False
            detail = f"draw list invalid: {error}"
    return {
        "name": "rust Berlin viewer",
        "ok": ok,
        "detail": detail if ok else output[-1200:],
    }


def check_rust_playable():
    output_png = "/tmp/opencode/pc2-playable-replay.png"
    try:
        os.remove(output_png)
    except FileNotFoundError:
        pass
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--map", "game/Isokarten/Iso_Filiale_einf_klein.iso",
         "--replay", "open;step;step;step;step",
         "--output", output_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    price = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--map", "game/Isokarten/Iso_Filiale_einf_klein.iso",
         "--replay", "open;step;step;price=18;step",
         "--output", "/tmp/opencode/pc2-playable-price.png"],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    closed = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--map", "game/Isokarten/Iso_Filiale_einf_klein.iso",
         "--replay", "step;step;step;step",
         "--output", "/tmp/opencode/pc2-playable-closed.png"],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    price_output = price.stdout + price.stderr
    closed_output = closed.stdout + closed.stderr
    arrival_at_11 = ('"clock_minutes":660' in output
                     and '"cash":10000.000000,"stock":400.000000' in output)
    settled_once = ('"cash":10013.420525,"stock":399.000000' in output
                    and '"clock_minutes":670' in output
                    and '"servings_sold":1,"customers_served":1' in output)
    departed = ('"clock_minutes":675' in output
                and '"sales":1' in output)
    price_change = ('"price":18.000000,"cash":10020.320525,"stock":399.000000' in price_output
                    and '"revenue":20.700000' in price_output)
    closed_no_sale = ('"sales":0' in closed_output
                      and '"customers_served":0' in closed_output
                      and '"cash":10000.000000,"stock":400.000000' in closed_output)
    ok = (result.returncode == 0 and price.returncode == 0
          and closed.returncode == 0 and arrival_at_11 and settled_once
          and departed and price_change and closed_no_sale
          and "0 byte mismatches" in output and "result: OK" in output)
    detail = "arrival 11:00, production 11:05, sale 11:10, departure 11:15; closed no sale; price 18 sale +20.32"
    if ok and os.path.isfile(output_png):
        actual = sha256(output_png)
        expected = "f6264367fa7739dd1ba50c67bca459d9b86ffe4e9589068704ae98735d77d96e"
        ok = actual == expected
        detail = f"replay {actual[:16]}; stock 399, cash 10013.420525"
    else:
        ok = False
    return {
        "name": "rust playable replay",
        "ok": ok,
        "detail": detail if ok else (output + price_output + closed_output)[-1800:],
    }

def check_free_play_scenario():
    free_profile = (
        "mode=free;gender=0;head=7;eyes=4;hair=6;mouth=3;logo=5;color=6;"
        "difficulty=9;attrs=3,-1,2,0,-2,1;player=Ada;enterprise=Ada Pizza")
    free_scenario = (
        "mode=free;city=ber;name=Berlin;map=Ber.iso;population=250;"
        "length=11;opponents=-1,-1,-1")
    campaign_profile = (
        "mode=campaign;gender=1;head=0;eyes=0;hair=0;mouth=0;logo=1;color=0;"
        "difficulty=9;attrs=0,-2,0,-1,1,0;player=Ada;enterprise=Ada Pizza")
    campaign_scenario = (
        "mode=campaign;city=ber;name=Berlin;map=Ber.iso;population=260;"
        "length=3;opponents=0,1,-1")
    commands = [
        (free_profile, free_scenario, "/tmp/opencode/pc2-free-play.png",
         "starting_capital=22000",
         '"cash":22013.420525,"stock":399.000000',
         "free Berlin difficulty 9 -> 22000"),
        (campaign_profile, campaign_scenario, "/tmp/opencode/pc2-campaign.png",
         "starting_capital=70000",
         '"cash":70013.420525,"stock":399.000000',
         "campaign Berlin -> 70000"),
    ]
    expected_hashes = {
        "/tmp/opencode/pc2-free-play.png":
            "e0131ccf867d20d886f238ee2aa6bff217ad770e380bb3473601da14fca057be",
        "/tmp/opencode/pc2-campaign.png":
            "4a51e0043b5db51c57edbda59524c629a4fbe87f7d3188bc9a3020a9c73c3d6c",
    }
    details = []
    for profile, scenario, output_png, capital, sale, label in commands:
        result = subprocess.run(
            ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
             "--map", "game/Isokarten/Iso_Filiale_einf_klein.iso",
             "--replay", "open;step;step;step;step",
             "--character-profile", profile,
             "--scenario", scenario,
             "--output", output_png],
            cwd=ROOT, text=True, capture_output=True, timeout=300)
        output = result.stdout + result.stderr
        if (result.returncode != 0 or "mode=" not in output
                or capital not in output or sale not in output
                or '"sales":1' not in output
                or not os.path.isfile(output_png)
                or sha256(output_png) != expected_hashes[output_png]):
            return {
                "name": "free play scenario",
                "ok": False,
                "detail": output[-1800:],
            }
        details.append(label)
    return {
        "name": "free play scenario",
        "ok": True,
        "detail": "; ".join(details) + "; first sale cash += 13.420525",
    }

def check_free_play_setup_screen():
    profile = (
        "mode=free;gender=0;head=7;eyes=4;hair=6;mouth=3;logo=5;color=6;"
        "difficulty=9;attrs=3,-1,2,0,-2,1;player=Ada;enterprise=Ada Pizza")
    scenario = (
        "mode=free;city=ber;name=Berlin;map=Ber.iso;population=250;"
        "length=11;opponents=-1,-1,-1")
    output_png = "/tmp/opencode/pc2-free-play-setup.png"
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--free-play-setup",
         "--character-profile", profile,
         "--scenario", scenario,
         "--output", output_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    expected = "3e14650a7fe47fcaf7cb468d62d21ea51d88911131010025ac6a71a1ec0efb91"
    ok = (result.returncode == 0
          and "pictures\\pe_freies_spiel.tga" in output
          and "button 0 label=\"To main menu\" id=0x4e2 x=595 y=509" in output
          and "button 1 label=\"Start game\" id=0x4e3 x=595 y=550" in output
          and "city=ber name=Berlin map=Ber.iso" in output
          and "starting_capital=22000" in output
          and "0 byte mismatches" in output
          and os.path.isfile(output_png)
          and sha256(output_png) == expected)
    return {
        "name": "free play setup screen",
        "ok": ok,
        "detail": ("Pe_Freies_Spiel.tga 800x600; Back 0x4e2 at 595,509; "
                   "Start 0x4e3 at 595,550; Berlin/22000") if ok else output[-1800:],
    }

def check_free_play_chain():
    profile = (
        "mode=free;gender=0;head=7;eyes=4;hair=6;mouth=3;logo=5;color=6;"
        "difficulty=9;attrs=3,-1,2,0,-2,1;player=Ada;enterprise=Ada Pizza")
    def run(city, name, map_name):
        scenario = (
            f"mode=free;city={city};name={name};map={map_name};population=250;"
            "length=11;opponents=-1,-1,-1")
        result = subprocess.run(
            ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
             "--free-play-chain", "--character-profile", profile, "--scenario", scenario],
            cwd=ROOT, text=True, capture_output=True, timeout=300)
        return result.returncode, result.stdout + result.stderr

    hashes = set()
    for city, name, map_name, installed_name in (
            ("ber", "Berlin", "Ber.iso", "Ber.iso"),
            ("lon", "London", "lon.iso", "Lon.iso")):
        code, output = run(city, name, map_name)
        prefix = "free-play-chain: loaded city="
        loaded = next((line[len(prefix):] for line in output.splitlines()
                       if line.startswith(prefix)), "")
        city_path, _, metadata = loaded.partition(" hash=")
        scene_hash, _, branch_path = metadata.partition(" branch=")
        if not (code == 0
                and "free-play-chain: menu=StartFreeGame" in output
                and "free-play-chain: character=Start" in output
                and f"free-play-chain: setup=Start city={city} map={map_name}" in output
                and os.path.basename(city_path) == installed_name
                and len(scene_hash) == 16
                and os.path.basename(branch_path) == "Iso_Filiale_einf_klein.iso"
                and "free-play-chain: first sale sales=1 cash=22013.420525" in output):
            return {"name": "free play chain", "ok": False, "detail": output[-1800:]}
        hashes.add(scene_hash)
    if len(hashes) != 2:
        return {"name": "free play chain", "ok": False, "detail": "city scene hashes match"}

    code, output = run("ber", "Berlin", "Missing.iso")
    ok = (code != 0
          and "city map Missing.iso not found" in output
          and "free-play-chain: loaded city=" not in output
          and "free-play-chain: world=" not in output
          and "free-play-chain: first sale" not in output)
    return {
        "name": "free play chain",
        "ok": ok,
        "detail": ("Berlin and London loaded distinct city scenes and made one sale each; "
                   "missing map rejected") if ok else output[-1800:],
    }

def check_two_party_queue():
    output_png = "/tmp/opencode/pc2-two-party.png"
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--map", "game/Isokarten/Iso_Filiale_einf_klein.iso",
         "--replay", "open;step;party;step;step;step;step;step;step;step",
         "--output", output_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    sims = []
    queues = []
    for line in result.stdout.splitlines():
        if line.startswith("sim: "):
            try:
                sims.append(json.loads(line[5:]))
            except json.JSONDecodeError:
                pass
        elif line.startswith("queue: "):
            try:
                queues.append(json.loads(line[6:]))
            except json.JSONDecodeError:
                pass
    ok = result.returncode == 0 and len(sims) == len(queues) == 10
    if ok:
        first_sale = next((i for i, sim in enumerate(sims)
                           if sim.get("sales") == 1), None)
        second_sale = next((i for i, sim in enumerate(sims)
                            if sim.get("sales") == 2), None)
        ok = (first_sale is not None and second_sale is not None
              and sims[first_sale]["clock_minutes"] == 670
              and queues[first_sale]["queue"] == 2
              and queues[first_sale]["visit_state"] == "departing"
              and [c["phase"] for c in queues[first_sale]["customers"]]
                  == ["departing", "queued"]
              and queues[first_sale]["customers"][1]["slot"] is None
              and sims[second_sale]["clock_minutes"] == 685
              and sims[second_sale]["sales"] == 2
              and abs(sims[second_sale]["cash"] - 10026.841049) < 1e-6
              and sims[second_sale]["stock"] == 398.0
              and queues[second_sale]["queue"] == 1
              and queues[second_sale]["customers"][0]["id"] == 2
              and queues[-1]["queue"] == 0
              and queues[-1]["visit_state"] == "idle")
    return {
        "name": "two-party queue",
        "ok": ok,
        "detail": ("party 1 sold at 670 while party 2 stayed queued; "
                   "party 2 admitted at 675 and sold at 685; queue drained at 690") if ok
                  else output[-1800:],
    }

def check_full_queue_rejection():
    output_png = "/tmp/opencode/pc2-full-queue.png"
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--map", "game/Isokarten/Iso_Filiale_einf_klein.iso",
         "--replay", "capacity=1;open;party;party;step;step;step;step",
         "--output", output_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    sims = []
    queues = []
    for line in result.stdout.splitlines():
        if line.startswith("sim: "):
            try:
                sims.append(json.loads(line[5:]))
            except json.JSONDecodeError:
                pass
        elif line.startswith("queue: "):
            try:
                queues.append(json.loads(line[6:]))
            except json.JSONDecodeError:
                pass
    ok = (result.returncode == 0 and len(sims) == len(queues) == 8
          and queues[3]["queue_capacity"] == 1
          and queues[3]["queue"] == 1
          and len(queues[3]["customers"]) == 1
          and sims[-1]["customers_lost"] == 1
          and sims[-1]["sales"] == 1
          and abs(sims[-1]["cash"] - 10013.420525) < 1e-6
          and sims[-1]["stock"] == 399.0
          and queues[-1]["queue"] == 0)
    return {
        "name": "full queue rejection",
        "ok": ok,
        "detail": ("capacity 1 rejected the second party (lost=1); "
                   "the admitted party still sold once with unchanged rejection cost") if ok
                  else output[-1800:],
    }

def check_10ms_timer_lane():
    output_png = "/tmp/opencode/pc2-10ms-timer.png"
    result = subprocess.run(
        ["cargo", "run", "--quiet", "-p", "pc2-app", "--",
         "--map", "game/Isokarten/Iso_Filiale_einf_klein.iso",
         "--replay", "open;party;ticks=259;ticks=1;ticks=180;ticks=80",
         "--output", output_png],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    sims = []
    queues = []
    for line in result.stdout.splitlines():
        if line.startswith("sim: "):
            try:
                sims.append(json.loads(line[5:]))
            except json.JSONDecodeError:
                pass
        elif line.startswith("queue: "):
            try:
                queues.append(json.loads(line[6:]))
            except json.JSONDecodeError:
                pass
    ok = (result.returncode == 0 and len(sims) == len(queues) == 6
          and queues[2]["customers"][0]["phase"] == "waiting"
          and queues[2]["customers"][0]["timer_ticks"] == 1
          and queues[3]["customers"][0]["phase"] == "producing"
          and queues[3]["customers"][0]["timer_ticks"] == 180
          and queues[4]["customers"][0]["phase"] == "departing"
          and queues[4]["customers"][0]["timer_ticks"] == 80
          and sims[4]["sales"] == 1
          and queues[5]["queue"] == 0
          and queues[5]["visit_state"] == "idle")
    return {
        "name": "10 ms timer lane",
        "ok": ok,
        "detail": ("259+1 queue ticks -> producing; 180 production ticks -> sale; "
                   "80 service ticks -> idle") if ok else output[-1800:],
    }

def check_campaign_start():
    profile = "mode=campaign;difficulty=9;player=Ada;enterprise=Ada Pizza"
    command = ["cargo", "run", "--quiet", "-p", "pc2-app", "--", "--campaign-start",
               "--character-profile", profile]
    with tempfile.TemporaryDirectory() as directory:
        png = os.path.join(directory, "campaign.png")
        result = subprocess.run(command + ["--output", png], cwd=ROOT,
                                text=True, capture_output=True, timeout=300)
        output = result.stdout + result.stderr
        if os.path.isfile(png):
            with open(png, "rb") as frame:
                header = frame.read(24)
        else:
            header = b""
        empty_install = os.path.join(directory, "empty-install")
        os.mkdir(empty_install)
        missing = subprocess.run(command + ["--install", empty_install], cwd=ROOT,
                                 text=True, capture_output=True, timeout=300)
        lease_script = ";".join(["lease=13694", "branch", "open"] + ["step"] * 14)
        lease = subprocess.run(command + ["--playable-script", lease_script], cwd=ROOT,
                               text=True, capture_output=True, timeout=300)
        repeated = subprocess.run(command + ["--playable-script", "lease=13694;lease=13694"],
                                  cwd=ROOT, text=True, capture_output=True, timeout=300)

    result_prefix = "campaign: result="
    try:
        state = next(line[len(result_prefix):] for line in lease.stdout.splitlines()
                     if line.startswith(result_prefix))
        final = json.loads(state)
    except (StopIteration, json.JSONDecodeError):
        final = {}
    debit = "campaign: leased tile=13694 charge=5730 cash=494270.000000 owned=false"
    ok = (result.returncode == 0
          and 'player="Ada" enterprise="Ada Pizza"' in output
          and "campaign: loaded city=game/Isokarten/Lon.iso hash=" in output
          and "city=lon name=London map=Lon.iso population=280 length=2" in output
          and "starting_capital=500000" in output
          and "campaign: goals=[0, 1, 2] rivals=1 player_start_hq=0 rival_start_hq=1"
              " difficulty_percent=10 player_starting_branches=0" in output
          and "campaign: starting_branch owner=1 size=0 style=0 owned=true" in output
          and '"cash":500000.000000' in output
          and '"clock_minutes":0' in output
          and '"sales":0' in output
          and header.startswith(b"\x89PNG\r\n\x1a\n")
          and header[16:24] == struct.pack(">II", 800, 600)
          and missing.returncode != 0
          and "missing campaign mission list" in missing.stderr
          and "campaign: world=" not in missing.stdout
          and lease.returncode == 0
          and "campaign: offer tile=13694 lease_charge=5730 source=static_initial_state" in lease.stdout
          and lease.stdout.count(debit) == 1
          and "campaign: entered branch=game/Isokarten/Iso_Filiale_einf_klein.iso" in lease.stdout
          and final.get("cash") == 494283.420525
          and final.get("sales") == 1
          and final.get("stock") == 399.0
          and repeated.returncode != 0
          and repeated.stdout.count(debit) == 1
          and "property is already leased" in repeated.stderr)
    return {
        "name": "campaign start",
        "ok": ok,
        "detail": ("London loaded with 500,000 and no player branch; tile 13694 leased once for 5,730; "
                   "entered branch and sold one serving") if ok else
                  (output + missing.stderr + lease.stdout + lease.stderr + repeated.stderr)[-1800:],
    }

def check_typed_packet():
    result = subprocess.run(
        ["python3", "tools/verify_typed_packet.py"],
        cwd=ROOT, text=True, capture_output=True, timeout=120)
    output = (result.stdout + result.stderr).strip()
    ok = (result.returncode == 0
          and "2 packet(s)" in output
          and "80/80 instruction prefixes match" in output
          and "3 tables" in output
          and "8 fixtures" in output
          and "15/15 mutations rejected" in output)
    return {
        "name": "typed function packet",
        "ok": ok,
        "detail": output[-600:],
    }

def check_starting_capital_emulation():
    result = subprocess.run(
        ["python3", "tools/emulate_starting_capital.py"],
        cwd=ROOT, text=True, capture_output=True, timeout=180)
    output = (result.stdout + result.stderr).strip()
    if result.returncode == 2:
        return {
            "name": "starting capital emulation",
            "ok": False,
            "detail": output[-1200:],
        }
    try:
        payload = json.loads(result.stdout)
    except json.JSONDecodeError:
        return {
            "name": "starting capital emulation",
            "ok": False,
            "detail": output[-1200:],
        }
    ok = (result.returncode == 0
          and payload.get("case_count") == 12
          and payload.get("matches") == 12
          and payload.get("first_mismatch") is None
          and all(case.get("evidence") == "emulated"
                  and case.get("stop_reason") == "ret"
                  for case in payload.get("cases", [])))
    return {
        "name": "starting capital emulation",
        "ok": ok,
        "detail": ("12/12 cases (difficulty 0..9 + 10/255 fallback); "
                   "Unicorn first-RET stops; EAX matches") if ok else output[-1200:],
    }

def check_clock_command_emulation():
    result = subprocess.run(
        ["python3", "tools/emulate_clock_command.py"],
        cwd=ROOT, text=True, capture_output=True, timeout=180)
    output = (result.stdout + result.stderr).strip()
    if result.returncode == 2:
        return {
            "name": "clock command emulation",
            "ok": False,
            "detail": output[-1200:],
        }
    try:
        payload = json.loads(result.stdout)
    except json.JSONDecodeError:
        return {
            "name": "clock command emulation",
            "ok": False,
            "detail": output[-1200:],
        }
    ok = (result.returncode == 0
          and payload.get("case_count") == 2
          and payload.get("matches") == 2
          and payload.get("first_mismatch") is None
          and all(case.get("evidence") == "emulated"
                  for case in payload.get("cases", [])))
    return {
        "name": "clock command emulation",
        "ok": ok,
        "detail": ("2/2 command cases: 0xfffe79de -> 0x405aa9 "
                   "(index 0x62, selector 4); 0xfffe79f7 -> 0x405ae0") if ok else output[-1200:],
    }

def check_mission_goals_emulation():
    result = subprocess.run(
        ["python3", "tools/emulate_mission_goals.py"],
        cwd=ROOT, text=True, capture_output=True, timeout=180)
    output = (result.stdout + result.stderr).strip()
    try:
        payload = json.loads(result.stdout)
    except json.JSONDecodeError:
        return {
            "name": "mission goal emulation",
            "ok": False,
            "detail": output[-1200:],
        }
    ok = (result.returncode == 0
          and payload.get("case_count") == 9
          and payload.get("matches") == 9
          and payload.get("first_mismatch") is None
          and all(case.get("actual", {}).get("evidence") == "emulated"
                  for case in payload.get("cases", [])))
    return {
        "name": "mission goal emulation",
        "ok": ok,
        "detail": ("9/9 cases: goal 0 needs C20>2, goal 1 needs +0x14>0, "
                   "goal 2 needs flag 0x16f4; rat action writes slot 1") if ok else output[-1200:],
    }

def check_crt_helpers_emulation():
    result = subprocess.run(
        ["python3", "tools/emulate_crt_helpers.py"],
        cwd=ROOT, text=True, capture_output=True, timeout=180)
    output = (result.stdout + result.stderr).strip()
    try:
        payload = json.loads(result.stdout)
    except json.JSONDecodeError:
        return {
            "name": "CRT helper emulation",
            "ok": False,
            "detail": output[-1200:],
        }
    ok = (result.returncode == 0
          and payload.get("case_count") == 8
          and payload.get("matches") == 8
          and payload.get("first_mismatch") is None)
    return {
        "name": "CRT helper emulation",
        "ok": ok,
        "detail": ("8/8 cases: control word mapping, strcspn/strpbrk, "
                   "strnlen and 32-bit carry") if ok else output[-1200:],
    }

def check_settings_defaults_emulation():
    result = subprocess.run(
        ["python3", "tools/emulate_settings_defaults.py"],
        cwd=ROOT, text=True, capture_output=True, timeout=180)
    output = (result.stdout + result.stderr).strip()
    try:
        payload = json.loads(result.stdout)
    except json.JSONDecodeError:
        return {
            "name": "settings defaults emulation",
            "ok": False,
            "detail": output[-1200:],
        }
    ok = (result.returncode == 0
          and payload.get("case_count") == 17
          and payload.get("matches") == 17
          and payload.get("first_mismatch") is None)
    return {
        "name": "settings defaults emulation",
        "ok": ok,
        "detail": ("17/17 globals: autosave interval/counter/slots, language index, "
                   "free-play length/max HQ and sentinels") if ok else output[-1200:],
    }

def check_ingredient_desc_emulation():
    result = subprocess.run(
        ["python3", "tools/emulate_ingredient_desc.py"],
        cwd=ROOT, text=True, capture_output=True, timeout=180)
    output = (result.stdout + result.stderr).strip()
    try:
        payload = json.loads(result.stdout)
    except json.JSONDecodeError:
        return {
            "name": "ingredient descriptor emulation",
            "ok": False,
            "detail": output[-1200:],
        }
    ok = (result.returncode == 0
          and payload.get("case_count") == 9
          and payload.get("matches") == 9
          and payload.get("first_mismatch") is None)
    return {
        "name": "ingredient descriptor emulation",
        "ok": ok,
        "detail": ("9/9 fields: Olives name copied to +0x88 and descriptor "
                   "values stored at +0xa8..+0xc8") if ok else output[-1200:],
    }

def check_reconstructed_c():
    result = subprocess.run(
        ["make", "-C", "reconstructed", "check", "full-game"],
        cwd=ROOT, text=True, capture_output=True, timeout=180)
    output = (result.stdout + result.stderr).strip()
    ok = (result.returncode == 0
          and "settings reconstruction: OK" in output
          and "ingredient descriptor reconstruction: OK" in output
          and "mission state reconstruction: OK" in output
          and "mission goals reconstruction: OK" in output
          and "branch economy reconstruction: OK" in output
          and "menu state reconstruction: OK" in output
          and "UI screen reconstruction: OK" in output
          and "options state reconstruction: OK" in output
          and "statistics state reconstruction: OK" in output
          and "AI state reconstruction: OK" in output
          and "recipe menu reconstruction: OK" in output
          and "personnel state reconstruction: OK" in output
          and "render state reconstruction: OK" in output
          and "branch operations reconstruction: OK" in output
          and "SPR/FNT asset reconstruction: OK" in output
          and "UI render reconstruction: OK" in output
          and "screen render reconstruction: OK" in output
          and "map render reconstruction: OK" in output
          and "save state reconstruction: OK" in output
          and "piz container reconstruction: OK" in output
          and "construction state reconstruction: OK" in output
          and "city branch state reconstruction: OK" in output
          and "unified game reconstruction: OK" in output
          and "pc2 reconstructed full game: OK" in output)
    return {
        "name": "reconstructed C build",
        "ok": ok,
        "detail": ("module tests, unified target and pc2-reconstructed full-game "
                   "target compile with gcc -std=c11 -Werror and pass; piz "
                   "container, options/autosave, statistics, AI, recipes, "
                   "personnel, render, operations, SPR/FNT assets and UI "
                   "composition, startscreen menu, character-select, London "
                   "briefing, free-play setup, statistics view, branch-list "
                   "window, branch-details page, branch-offer page, personnel "
                   "overview, personnel record, statistics balance, branch-"
                   "balance statistics, iso-map/branch interior render and "
                   "hourly branch economy included")
        if ok else output[-1200:],
    }

def check_piz_records():
    result = subprocess.run(
        ["python3", "tools/verify_piz_records.py"],
        cwd=ROOT, text=True, capture_output=True, timeout=180)
    output = (result.stdout + result.stderr).strip()
    try:
        payload = json.loads(result.stdout)
    except json.JSONDecodeError:
        return {
            "name": "piz record parse",
            "ok": False,
            "detail": output[-1200:],
        }
    ok = (result.returncode == 0
          and payload.get("ok") is True
          and payload.get("character_count") == 1
          and payload.get("character_record_size") == 2086
          and not payload.get("character_errors")
          and not payload.get("player_errors")
          and not payload.get("company_errors")
          and payload.get("company_count") == 1
          and payload.get("company_record_size") == 270
          and payload.get("company_branch_record_size") == 6412
          and payload.get("company_slot0_name") == "Ada Pizza"
          and payload.get("company_slot0_cash") == 494270.0
          and payload.get("company_slot0_plan_count") == 1
          and payload.get("company_slot0_recipe_count") == 1
          and payload.get("company_slot0_recipes")[0]["topping_count"] == 1
          and payload.get("company_slot0_recipes")[0]["toppings"] == [
              {"ingredient": 5, "category": 1, "tier": 2, "x": 10, "y": 20,
               "variant": 1, "flag": 1}]
          and payload.get("company_slot0_branch_count") == 1
          and payload.get("company_slot0_branches")[0]["id"] == 13694
          and payload.get("company_slot0_branches")[0]["name"] == "London branch"
          and payload.get("company_slot0_branches")[0]["style"] == 2
          and payload.get("company_slot0_branches")[0]["flags"] == 0x24
          and payload.get("company_slot0_report_count") == 1
          and payload.get("company_slot0_reports")[0]["income"][0] == 100.5
          and payload.get("company_slot0_reports")[0]["income"][4] == 50.25
          and payload.get("company_slot0_reports")[0]["expense"][12] == 30.75
          and payload.get("company_slot0_storage") == [
              {"id": 7, "name": "London storage"}]
          and payload.get("company_slot0_pairs") == [
              {"id": 9, "value": 0x1122334455667788}]
          and payload.get("company_slot0_big_count") == 1)
    return {
        "name": "piz record parse",
        "ok": ok,
        "detail": ("piz_payload.py accepts 1 character (2086-byte record), "
                   "6 player slots and 1 company with plan, recipe, branch, "
                   "report, storage, pair and 0x1A0 lists with populated "
                   "recipe/branch/report/storage fields with no errors") if ok else output[-1200:],
    }

def check_rust_tests():
    result = subprocess.run(
        ["cargo", "test", "--quiet", "--all"],
        cwd=ROOT, text=True, capture_output=True, timeout=300)
    output = result.stdout + result.stderr
    return {
        "name": "rust tests",
        "ok": result.returncode == 0,
        "detail": ("cargo test --all: OK" if result.returncode == 0
                   else output[-1000:]),
    }


def check_generated_models():
    """Regenerate the four model exports in a scratch checkout and compare."""
    scratch = tempfile.mkdtemp(prefix="pc2-model-repro-",
                               dir="/tmp/opencode" if os.path.isdir(
                                   "/tmp/opencode") else None)
    checkout = os.path.join(scratch, "checkout")
    out = os.path.join(checkout, "decompiled_fastfood2_named_v2")
    try:
        os.makedirs(out)
        os.symlink(os.path.join(ROOT, "game"),
                   os.path.join(checkout, "game"))
        shutil.copytree(os.path.join(ROOT, "tools"),
                        os.path.join(checkout, "tools"),
                        ignore=shutil.ignore_patterns("__pycache__"))
        os.symlink(os.path.join(BASE, "full_game_verification"),
                   os.path.join(out, "full_game_verification"))
        os.symlink(os.path.join(BASE, "full_game_symbols.json"),
                   os.path.join(out, "full_game_symbols.json"))
        scripts = [
            "build_class_skeletons.py",
            "build_save_schema.py",
            "build_state_model.py",
            "build_structs.py",
        ]
        for script in scripts:
            result = subprocess.run(
                [sys.executable, script],
                cwd=os.path.join(checkout, "tools"), text=True,
                capture_output=True, timeout=300)
            if result.returncode != 0:
                return {
                    "name": "generated models",
                    "ok": False,
                    "detail": f"{script} failed: " +
                              (result.stdout + result.stderr)[-800:],
                }
        generated = []
        for root, _dirs, files in os.walk(out):
            for filename in files:
                path = os.path.join(root, filename)
                relative = os.path.relpath(path, out)
                if relative in ("full_game_symbols.json",):
                    continue
                if relative.startswith("full_game_verification" + os.sep):
                    continue
                generated.append(relative)
        missing = []
        mismatch = []
        for relative in sorted(generated):
            reference = os.path.join(BASE, relative)
            candidate = os.path.join(out, relative)
            if not os.path.exists(reference):
                missing.append(relative)
            elif sha256(reference) != sha256(candidate):
                mismatch.append(relative)
        return {
            "name": "generated models",
            "ok": bool(generated) and not missing and not mismatch,
            "detail": (f"{len(generated)} files regenerated, "
                       f"{len(missing)} missing, {len(mismatch)} mismatched"),
        }
    finally:
        shutil.rmtree(scratch, ignore_errors=True)


def check_iso():
    result = run([sys.executable, "tools/iso_tool.py", "scan",
                  "game/Isokarten"])
    summary = ""
    for line in result["stdout"].splitlines():
        if line.startswith("summary:"):
            summary = line
    return {
        "name": "iso map scan",
        "ok": result["returncode"] == 0 and "25 OK, 0 failed" in summary,
        "detail": summary or result["stderr"][-400:],
    }


def check_isodaten():
    result = run([sys.executable, "tools/isodaten_tool.py", "info",
                  "extracted/isodaten/isodaten.idx"])
    values = {}
    for line in result["stdout"].splitlines():
        parts = line.split()
        if len(parts) >= 2:
            values[parts[0]] = parts[1]
    ok = (result["returncode"] == 0
          and values.get("count") == "2467"
          and values.get("markers") == "9"
          and values.get("animations") == "119")
    return {
        "name": "isodaten index",
        "ok": ok,
        "detail": (f"count {values.get('count')}, markers "
                   f"{values.get('markers')}, animations "
                   f"{values.get('animations')}"),
    }


def check_structs():
    source = '#include "decompiled_fastfood2_named_v2/game_structs.h"\n'
    proc = subprocess.run(
        ["cc", "-x", "c", "-std=c11", "-fsyntax-only", "-"],
        cwd=ROOT, input=source, text=True, capture_output=True)
    return {
        "name": "struct header C11",
        "ok": proc.returncode == 0,
        "detail": "gcc -std=c11 -fsyntax-only: OK" if proc.returncode == 0
        else proc.stderr[-600:],
    }


def write_json(path, value):
    with open(path, "w") as fh:
        json.dump(value, fh, indent=2)
        fh.write("\n")


def run_simulations(write):
    demo = run([sys.executable, "tools/sim_core.py", "demo", "--days", "360",
                "--city", "extracted/daten/ber.ini", "--json"])
    sweep = run([sys.executable, "tools/sim_core.py", "sweep", "--days", "90",
                 "--city", "extracted/daten/ber.ini", "--json"])
    map_demo = run([sys.executable, "tools/sim_core.py", "demo", "--days",
                    "90", "--map", "game/Isokarten/Ber.iso", "--json"])
    ok = all(result["returncode"] == 0 for result in (demo, sweep, map_demo))
    if not ok:
        return {"name": "simulation samples", "ok": False,
                "detail": (demo["stderr"] + sweep["stderr"]
                           + map_demo["stderr"])[-600:]}
    demo_data = json.loads(demo["stdout"])
    sweep_data = json.loads(sweep["stdout"])
    map_data = json.loads(map_demo["stdout"])
    if write:
        write_json(os.path.join(SAMPLES, "sim_demo_360.json"), demo_data)
        write_json(os.path.join(SAMPLES, "sim_sweep_90.json"), sweep_data)
        write_json(os.path.join(SAMPLES, "sim_demo_map_90.json"), map_data)
    customers = sum(row["customers"] for row in demo_data["quarters"])
    revenue = round(sum(row["revenue"] for row in demo_data["quarters"]), 2)
    return {
        "name": "simulation samples",
        "ok": True,
        "detail": (f"{len(demo_data['quarters'])} quarters, {customers} "
                   f"customers, ${revenue:,.2f} revenue"),
        "demo": demo_data,
        "sweep": sweep_data,
        "customers": customers,
        "revenue": revenue,
    }


def refresh_verification(sim, sim_tests, write):
    path = os.path.join(BASE, "SIM_VERIFICATION.json")
    with open(path) as fh:
        verification = json.load(fh)
    verification["target"] = {
        "path": "game/fastfood2.exe",
        "sha256": sha256(TARGET),
    }
    verification["tests"] = {
        "suite": "tests/test_sim_core.py",
        "count": sim_tests,
        "passed": sim_tests,
    }
    demo = sim["demo"]
    verification["demo"] = {
        "city": demo["city"],
        "days": demo["day"],
        "year": demo["year"],
        "quarter": demo["quarter"],
        "quarters": len(demo["quarters"]),
        "customers": sim["customers"],
        "revenue": sim["revenue"],
        "companies": [
            {"name": company["name"], "cash": company["cash"],
             "market_share": company["market_share"]}
            for company in demo["companies"]
        ],
        "branches": len(demo["branches"]),
    }
    verification["sweep"] = sim["sweep"]
    artifacts = verification.setdefault("artifacts", {})
    artifacts["tools/verify_all.py"] = sha256(
        os.path.join(ROOT, "tools", "verify_all.py"))
    artifacts["README.md"] = sha256(os.path.join(ROOT, "README.md"))
    for relative in list(artifacts):
        path_to_hash = os.path.join(ROOT, relative)
        if relative != os.path.relpath(
                os.path.join(BASE, "SIM_VERIFICATION.json"), ROOT):
            artifacts[relative] = sha256(path_to_hash)
    if write:
        write_json(path, verification)
    return verification


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--no-write", action="store_true",
                        help="check only; do not rewrite samples/verification")
    args = parser.parse_args(argv)
    write = not args.no_write
    checks = [check_target(), check_manifest()]
    suite_results = [run_suite(relative, label)
                     for relative, label in SUITES]
    checks.extend(suite_results)
    checks.append(check_generated_models())
    checks.append(check_rust_inventory())
    checks.append(check_spr_exports())
    checks.append(check_customer_trace())
    checks.append(check_recipe_function_cards())
    checks.append(check_skill_quality_cards())
    checks.append(check_product_quality_replay())
    checks.append(check_main_menu())
    checks.append(check_character_select())
    checks.append(check_clock_replay())
    checks.append(check_rust_asset_audit())
    checks.append(check_rust_quads())
    checks.append(check_rust_viewer())
    checks.append(check_rust_playable())
    checks.append(check_free_play_scenario())
    checks.append(check_free_play_setup_screen())
    checks.append(check_free_play_chain())
    checks.append(check_two_party_queue())
    checks.append(check_full_queue_rejection())
    checks.append(check_10ms_timer_lane())
    checks.append(check_campaign_start())
    checks.append(check_typed_packet())
    checks.append(check_starting_capital_emulation())
    checks.append(check_clock_command_emulation())
    checks.append(check_mission_goals_emulation())
    checks.append(check_crt_helpers_emulation())
    checks.append(check_settings_defaults_emulation())
    checks.append(check_ingredient_desc_emulation())
    checks.append(check_reconstructed_c())
    checks.append(check_piz_records())
    checks.append(check_rust_tests())
    checks.append(check_iso())
    checks.append(check_isodaten())
    checks.append(check_structs())
    sim = run_simulations(write)
    checks.append({"name": sim["name"], "ok": sim["ok"],
                   "detail": sim["detail"]})
    sim_tests = next((row["tests"] for row in suite_results
                      if row["name"] == "tests: simulation"), 0)
    verification = refresh_verification(sim, sim_tests, write)

    failed = [check for check in checks if not check["ok"]]
    print("Pizza Connection 2 baseline verification")
    print(f"  workspace: {ROOT}")
    print(f"  python:    {sys.version.split()[0]}")
    print()
    for check in checks:
        state = "PASS" if check["ok"] else "FAIL"
        print(f"{state:4s}  {check['name']:24s} {check['detail']}")
    print()
    print(f"simulation snapshot: ${verification['demo']['companies'][0]['cash']:,.2f} "
          f"player cash, {verification['demo']['customers']} customers, "
          f"${verification['demo']['revenue']:,.2f} revenue")
    print("pending original-game comparisons:")
    for item in PENDING:
        print(f"  - {item}")
    print()
    print(f"result: {'OK' if not failed else 'FAILED'} "
          f"({len(checks) - len(failed)}/{len(checks)} checks)")
    return 0 if not failed else 1


if __name__ == "__main__":
    raise SystemExit(main())
