#!/usr/bin/env python3
"""Regression tests for the blocked-symbol proposal joins."""
from __future__ import annotations

import json
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "tools"))

import propose_symbol_mappings as proposals  # noqa: E402
from match_decomp import GAME, file_sha256  # noqa: E402


def relocation(symbol, target, site, kind="REL32", verified=False):
    original = target if kind == "DIR32" else (target - site - 4) & 0xFFFFFFFF
    return {
        "section": ".text",
        "offset": hex(site & 0xFFF),
        "site": hex(site),
        "symbol": symbol,
        "kind": kind,
        "addend": 0,
        "original": hex(original),
        "target": hex(target) if verified else None,
        "verified": verified,
    }


def audit_row(address, length, entry, relocations, strict=False, registry_sha=None):
    return {
        "address": hex(address),
        "length": length,
        "entry": entry,
        "match": True,
        "strict_match": strict,
        "strict_issues": [] if strict else [f"unresolved symbol {r['symbol']}" for r in relocations
                                            if not r["verified"]],
        "relocation_issues": [],
        "link_plan_issues": [],
        "blocked_sections": [],
        "relocations": relocations,
        "source": f"candidate/{address:x}.c",
        "source_sha256": "0" * 64,
        "executable_sha256": file_sha256(GAME),
        "compiler": {"sha256": {}},
        "flags": ["/O2"],
        "symbol_registry_sha256": registry_sha,
        "symbol_overrides": {},
    }


def test_observed_target():
    assert proposals.observed_target({
        "kind": "DIR32", "original": "0x54e221", "site": "0x401000", "addend": 0,
    }) == 0x54E221
    target = 0x54E221
    site = 0x401000
    original = (target - site - 4) & 0xFFFFFFFF
    assert proposals.observed_target({
        "kind": "REL32", "original": hex(original), "site": hex(site), "addend": 0,
    }) == target


def test_merge_prefers_verified_address():
    registry = file_sha256(ROOT / "reconstructed/match/symbol_registry.json")
    old = audit_row(0x401000, 16, "?A@@YAXXZ", [], strict=False, registry_sha=None)
    new = audit_row(0x401000, 16, "?A@@YAXXZ", [], strict=True, registry_sha=registry)
    merged, verified = proposals.merge_rows([old, new], registry)
    assert 0x401000 in verified
    assert len(merged) == 1


def test_end_to_end_ready_group():
    registry = file_sha256(ROOT / "reconstructed/match/symbol_registry.json")
    synthetic = "?SyntheticBlocked@@YAXXZ"
    strict = audit_row(
        0x401000, 16, "?PushFront@List@@QAEXPAX@Z",
        [relocation(synthetic, 0x54E221, 0x401010, verified=True)],
        strict=True, registry_sha=registry,
    )
    blocked = audit_row(
        0x402000, 32, "?Blocked@@YAXXZ",
        [relocation(synthetic, 0x54E221, 0x402010),
         relocation("?g_game@@3PAUGame@@A", 0x57C670, 0x402020, kind="DIR32")],
        strict=False, registry_sha=registry,
    )
    with tempfile.TemporaryDirectory() as temporary:
        audit = Path(temporary) / "audit"
        (audit / "functions").mkdir(parents=True)
        (audit / "functions" / "strict.json").write_text(json.dumps(strict))
        (audit / "functions" / "blocked.json").write_text(json.dumps(blocked))
        output = Path(temporary) / "proposals.json"
        report = Path(temporary) / "proposals.md"
        result = subprocess.run(
            [sys.executable, str(ROOT / "tools/propose_symbol_mappings.py"),
             str(audit), "--json-out", str(output), "--report-out", str(report),
             "--top-groups", "10"],
            cwd=ROOT, text=True, capture_output=True, check=True,
        )
        payload = json.loads(output.read_text())
        report_text = report.read_text()
    assert payload["summary"]["body_only_addresses"] == 1
    assert payload["summary"]["ready_facts"] >= 1
    facts = {fact["symbol"]: fact for fact in payload["facts"]}
    assert facts[synthetic]["status"] == "ready"
    assert facts[synthetic]["chosen_address"] == "0x54e221"
    assert facts["?g_game@@3PAUGame@@A"]["status"] == "ready"
    assert any("0x402000" in group["covered_ready"]
               for group in payload["ready_groups"])
    assert "Blocked symbol reuse proposals" in report_text


if __name__ == "__main__":
    test_observed_target()
    test_merge_prefers_verified_address()
    test_end_to_end_ready_group()
    print("symbol proposal joins: ok")
