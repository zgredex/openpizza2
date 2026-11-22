#!/usr/bin/env python3
"""Exercise the batch routes without starting Wine or the game."""

from pathlib import Path
from types import SimpleNamespace
import sys
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools"))
import verify_replay_batch as batch


class ReplayBatchTest(unittest.TestCase):
    def test_strict_and_relocation_routes_do_not_run_emulation(self):
        with patch.object(batch, "verify") as verify:
            self.assertEqual(batch.route_result({"status": "strict"}, None, None, None, {}),
                             {"route": "verified"})
            blocker = {"symbol": "_Shared", "target": None, "target_section_index": None}
            local = {"symbol": "$L100", "target": None, "target_section_index": 2}
            result = {"status": "blocked", "relocations": [blocker, local, blocker]}
            self.assertEqual(batch.route_result(result, None, None, None, {}),
                             {"route": "resolve_symbols", "symbols": ["_Shared"]})
            verify.assert_not_called()

    def test_only_reproduced_fixture_routes_a_candidate(self):
        result = {"status": "mismatch", "relocations": [], "relocation_issues": []}
        fixture = {"cases": [object()]}
        recipe = SimpleNamespace(source=Path("candidate.c"))
        options = {"behavior_entry": "candidate"}
        divergence = {"field": "EAX", "expected": 1, "actual": 2}
        baseline = {"failures": []}
        with patch.object(batch, "verify", side_effect=[{"failures": [divergence]}]) as verify:
            self.assertEqual(batch.route_result(result, recipe, fixture, None, options),
                             {"route": "review_fixture", "first_divergence": divergence})
            verify.assert_called_once_with(fixture)
        with patch.object(batch, "verify", side_effect=[baseline, {"failures": [divergence]}]):
            self.assertEqual(batch.route_result(result, recipe, fixture, None, options),
                             {"route": "inspect_mismatch", "first_divergence": divergence})
        with patch.object(batch, "verify", side_effect=[baseline, baseline]):
            self.assertEqual(batch.route_result(result, recipe, fixture, None, options),
                             {"route": "compiler_tuning", "behavior": baseline})


if __name__ == "__main__":
    unittest.main()
