import hashlib
import json
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools"))
import match_crt_archive as matcher
from match_crt_archive import (DIR32, REL32, LibraryFunction, Relocation, Symbol,
                               archive_members, coff_functions, match_functions)


def function(name, code, relocs=(), archive="LIBC", member="one.obj", section=1, member_offset=8):
    symbol = Symbol(name, 0, section, True, 2, len(code))
    return LibraryFunction(archive, member, member_offset, symbol, code, relocs)


def archive_record(name, body):
    header = f"{name:<16}{0:<12}{0:<6}{0:<6}{0:<8}{len(body):<10}`\n".encode()
    return header + body + (b"\n" if len(body) % 2 else b"")


def object_with_functions(code, entries):
    symbols = bytearray()
    for name, offset, size in entries:
        symbols += struct.pack("<8sIhHBB", name, offset, 1, 0x20, 2, bool(size))
        if size:
            symbols += struct.pack("<II10x", 0, size)
    header = struct.pack("<HHIIIHH", 0x14C, 1, 0, 60 + len(code), len(symbols) // 18, 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(code), 60, 0, 0, 0, 0, 0x20)
    return header + section + code + symbols + struct.pack("<I", 4)


class CrtArchiveTests(unittest.TestCase):
    def test_long_archive_name_and_alignment(self):
        data = b"!<arch>\n" + archive_record("//", b"dir\\long-member.obj\0")
        data += archive_record("/0", b"abc")
        self.assertEqual([(name, body) for _, name, body in archive_members(data)],
                         [("dir\\long-member.obj", b"abc")])
        with self.assertRaisesRegex(ValueError, "alignment"):
            list(archive_members(data[:-1]))

    def test_shared_code_needs_authoritative_extents(self):
        code = b"\x90\xc3\x31\xc0\xc3"
        unbounded = object_with_functions(code, [(b"_one", 0, 0), (b"_two", 2, 0)])
        self.assertEqual(list(coff_functions("LIBC", "two.obj", 8, unbounded)), [])
        bounded = object_with_functions(code, [(b"_one", 0, 2), (b"_two", 2, 3)])
        found = list(coff_functions("LIBC", "two.obj", 8, bounded))
        self.assertEqual([item.code for item in found], [code[:2], code[2:]])
        overlap = object_with_functions(code, [(b"_one", 0, 3), (b"_two", 2, 3)])
        found = list(coff_functions("LIBC", "two.obj", 8, overlap))
        self.assertEqual([item.symbol.name for item in found], ["_two"])

    def test_variants_group_by_location_and_ambiguities_are_explicit(self):
        code = b"\xc3"
        variants = [function("_one", code), function("_one", code, archive="LIBCMT")]
        game = {0x401000: ("first", code)}
        exact, matches, unresolved = match_functions(variants, game, {})
        self.assertEqual((exact, len(matches), len(unresolved)), (1, 1, 0))
        self.assertEqual(len(matches[0]["variants"]), 2)
        self.assertEqual(matches[0]["ambiguity"], [])
        game[0x401100] = ("second", code)
        variants.append(function("_other", code, member="two.obj"))
        _, matches, _ = match_functions(variants, game, {})
        self.assertEqual([record["ambiguity"] for record in matches],
                         [["multiple_archive_identities", "same_identity_at_multiple_game_addresses"]] * 2)

    def test_fixups_check_addends_and_reject_wrong_target(self):
        code = b"\xe8" + struct.pack("<i", -4) + b"\xa1" + struct.pack("<i", 8) + b"\xc3"
        rel = Symbol("_call", 0, 0, True, 2, 0)
        absolute = Symbol("_data", 0, 0, False, 2, 0)
        source = function("_entry", code, (Relocation(1, rel, REL32, -4),
                                           Relocation(6, absolute, DIR32, 8)))
        linked = (b"\xe8" + struct.pack("<i", 0x401200 - 4 - 0x401005)
                  + b"\xa1" + struct.pack("<I", 0x403008) + b"\xc3")
        game = {0x401000: ("entry", linked)}
        _, matches, candidates = match_functions([source], game, {"_call": 0x401200})
        self.assertEqual(matches, [])
        self.assertEqual(candidates[0]["variants"][0]["unresolved_symbols"], ["_data"])
        _, matches, candidates = match_functions([source], game, {"_call": 0x401204, "_data": 0x403000})
        self.assertEqual((matches, candidates), ([], []))
        _, matches, candidates = match_functions([source], game, {"_call": 0x401200, "_data": 0x403000})
        self.assertEqual(matches[0]["variants"][0]["method"], "relocated")
        self.assertEqual(candidates, [])

    def test_local_symbol_requires_a_same_member_anchor(self):
        helper = b"\x31\xc0\xc3"
        target = Symbol("_helper", 0, 2, True, 3, len(helper))
        source = function("_entry", b"\xe8\0\0\0\0\xc3", (Relocation(1, target, REL32, 0),))
        game = {0x401000: ("entry", b"\xe8" + struct.pack("<i", 0x401100 - 0x401005) + b"\xc3"),
                0x401100: ("helper", helper)}
        external = function("_helper", helper, member="other.obj", section=2, member_offset=140)
        _, matches, candidates = match_functions([source, external], game, {})
        self.assertEqual([match["address"] for match in matches], ["0x401100"])
        self.assertEqual(candidates[0]["variants"][0]["unresolved_symbols"], ["_helper"])
        local = LibraryFunction(source.archive, source.member, source.member_offset, target, helper, ())
        _, matches, candidates = match_functions([source, local], game, {})
        self.assertEqual(matches[0]["variants"][0]["relocations"][0]["basis"], "exact_member_symbol")
        self.assertEqual(candidates, [])

    def test_same_section_target_uses_object_offset(self):
        target = Symbol(".text", 0, 1, False, 3, 0)
        source = function("_entry", b"\xa1\x02\0\0\0\xc3", (Relocation(1, target, DIR32, 2),))
        linked = b"\xa1" + struct.pack("<I", 0x401002) + b"\xc3"
        _, matches, candidates = match_functions([source], {0x401000: ("entry", linked)}, {})
        self.assertEqual(matches[0]["variants"][0]["relocations"][0]["basis"], "same_section")
        self.assertEqual(candidates, [])

    def test_stock_propagates_a_chain_and_keeps_an_unseeded_cycle_unresolved(self):
        base = 0x401000

        def candidate(name, target, suffix):
            symbol = Symbol(target, 0, 0, True, 2, 0)
            return function(name, b"\xe8\0\0\0\0" + suffix, (Relocation(1, symbol, REL32, 0),),
                            member=name + ".obj", member_offset=100 + suffix[0])

        def linked(source, address, target):
            return b"\xe8" + struct.pack("<i", target - address - 5) + source.code[5:]

        root = function("_root", b"\x31\xc0\xc3")
        second = candidate("_second", "_root", b"\x90\xc3")
        third = candidate("_third", "_second", b"\x91\xc3")
        cycle_a = candidate("_cycle_a", "_cycle_b", b"\x92\xc3")
        cycle_b = candidate("_cycle_b", "_cycle_a", b"\x93\xc3")
        game = {base: ("root", root.code), base + 0x10: ("second", linked(second, base + 0x10, base)),
                base + 0x20: ("third", linked(third, base + 0x20, base + 0x10)),
                base + 0x30: ("cycle_a", linked(cycle_a, base + 0x30, base + 0x40)),
                base + 0x40: ("cycle_b", linked(cycle_b, base + 0x40, base + 0x30))}
        _, matches, pending, public, _, _, _, _ = matcher.stock_matches([root, second, third, cycle_a, cycle_b], game, {})
        self.assertEqual({name: proof["round"] for name, proof in public.items()}, {"_root": 1, "_second": 2, "_third": 3})
        self.assertEqual(set(matches), {base, base + 0x10, base + 0x20})
        self.assertEqual(set(pending), {base + 0x30, base + 0x40})

    def test_stock_revokes_a_seed_that_would_enable_an_ambiguous_identity(self):
        address = 0x401000
        root = function("_root", b"\xe8\xfb\xff\xff\xff\xc3")
        target = Symbol("_root", 0, 0, True, 2, 0)
        conflict = function("_conflict", b"\xe8\0\0\0\0\xc3", (Relocation(1, target, REL32, 0),),
                            member="conflict.obj", member_offset=200)
        image = (root.code, address, [(".text", 0, len(root.code), 0, len(root.code))])
        with patch.object(matcher, "image_imports", return_value={}):
            _, matches, _, plan = matcher.stock_plan(image, {address: ("root", root.code)}, [root, conflict], [], {})
        self.assertEqual(plan["revoked"]["public"], ["_root"])
        self.assertEqual(plan["symbols"], {})
        self.assertEqual(plan["functions"], [])
        self.assertEqual(matches[0]["ambiguity"], ["revoked_stock_identity"])

    def test_import_spelling_requires_one_unique_iat_slot(self):
        name = "__imp__Call@4"
        symbol = Symbol(name, 0, 0, True, 2, 0)
        imported = function("_f", b"\xff\x15" + bytes(4) + b"\xc3", (Relocation(2, symbol, DIR32, 0),))
        self.assertEqual(matcher.stock_imports([imported], {"Call": {0x402000}}), {name: (0x402000, "pe_iat")})
        self.assertEqual(matcher.stock_imports([imported], {"Call": {0x402000, 0x403000}, "_Call": {0x402000}}), {})

    def test_stock_plan_rebuilds_original_bytes_and_rejects_changed_inputs(self):
        base, code = 0x401000, b"\xc3"
        image = (code, base, [(".text", 0, 1, 0, 1)])
        archive_bytes = b"!<arch>\n" + archive_record("a.obj", object_with_functions(code, [(b"_f", 0, 0)]))
        with tempfile.TemporaryDirectory() as scratch:
            directory = Path(scratch)
            archive, index_path, plan_path = (directory / name for name in ("a.lib", "index.json", "plan.json"))
            archive.write_bytes(archive_bytes)
            index_path.write_text(json.dumps({"target_sha256": hashlib.sha256(code).hexdigest(), "functions": [
                {"address": hex(base), "body": {"ranges": [{"start": hex(base), "end": hex(base)}]}, "name": "example"}]}))
            pinned = {"a.lib": hashlib.sha256(archive_bytes).hexdigest()}
            with (patch.object(matcher, "STOCK_LIBS", pinned), patch.object(matcher, "image_imports", return_value={}),
                  patch.object(matcher, "function_lengths", return_value={base: 1})):
                game, index = matcher.read_game(image, index_path)
                functions, archives = matcher.read_archives([archive], stock=True)
                _, _, _, plan = matcher.stock_plan(image, game, functions, archives, index)
                plan_path.write_text(json.dumps(plan))
                self.assertEqual(matcher.load_stock_plan(plan_path, image), plan)
                plan["functions"][0]["linked_spans"][0]["hex_bytes"] = "90"
                plan_path.write_text(json.dumps(plan))
                with self.assertRaisesRegex(ValueError, "does not reproduce"):
                    matcher.load_stock_plan(plan_path, image)
                archive.write_bytes(archive_bytes + b"bad")
                with self.assertRaisesRegex(ValueError, "archive SHA-256 changed"):
                    matcher.load_stock_plan(plan_path, image)


if __name__ == "__main__":
    unittest.main()
