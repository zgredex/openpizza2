"""Exercise the call summarizer on invented i386 instruction sequences."""

import importlib.util
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools"))
from x86_call_abi import summarize


@unittest.skipUnless(importlib.util.find_spec("capstone"), "requires Capstone")
class CallABITests(unittest.TestCase):
    def test_reachable_calls_use_local_staging_and_coff_names(self):
        # Jump past an unreachable call. The next block pushes one argument,
        # clears ECX, calls a COFF symbol and adjusts the stack.
        code = bytes.fromhex("eb05 e800000000 6a02 33c9 e800000000 83c404 c3")
        result = summarize(code, 0x1000, relocations={0x100c: "?Synthetic@@QAEXH@Z"})
        self.assertEqual(result["calls"], {"direct": 1})
        self.assertEqual(result["decoded_instructions"], 6)
        self.assertEqual(result["top_callees"][0]["name"], "?Synthetic@@QAEXH@Z")
        self.assertEqual(result["staging"]["local_push_count"], {"1": 1})
        self.assertEqual(result["staging"]["ecx_last_write"], {"zero": 1})
        self.assertEqual(result["staging"]["following_stack_add"], {"4": 1})

    def test_branch_boundary_stops_staging_and_tail_padding_stays_unreachable(self):
        code = bytes.fromhex("6a02 7400 ff10 c3 90 90")
        result = summarize(code, 0x1000)
        self.assertEqual(result["calls"], {"indirect": 1})
        self.assertEqual(result["staging"]["local_push_count"], {"0": 1})
        self.assertEqual(result["reachable_span_bytes"], 7)
        self.assertEqual(result["extent_bytes"], 9)

    def test_loop_target_is_visited_separately_from_fallthrough(self):
        code = bytes.fromhex("e201 c3 e800000000 c3")
        result = summarize(code, 0x1000)
        self.assertEqual(result["calls"], {"direct": 1})
        self.assertEqual(result["decoded_instructions"], 4)


if __name__ == "__main__":
    unittest.main()
