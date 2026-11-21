import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools"))
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


if __name__ == "__main__":
    unittest.main()
