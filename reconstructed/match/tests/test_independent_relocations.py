"""Strict COFF matching regressions that require neither Wine nor VC6."""

import shutil
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools"))
import match_decomp as matcher


def coff_object(sections, symbols):
    headers = bytearray()
    payload = bytearray()
    for name, code, relocations in sections:
        raw = 20 + len(sections) * 40 + len(payload)
        reloc = raw + len(code)
        headers += struct.pack("<8sIIIIIIHHI", name, 0, 0, len(code), raw, reloc, 0,
                               len(relocations), 0, 0x20)
        payload += code
        for record in relocations:
            payload += struct.pack("<IIH", *record)
    symbol_ptr = 20 + len(headers) + len(payload)
    header = struct.pack("<HHIIIHH", 0x14C, len(sections), 0, symbol_ptr, len(symbols), 0, 0)
    table = bytearray()
    strings = bytearray()
    for name, *values in symbols:
        if len(name) > 8:
            offset = 4 + len(strings)
            strings += name + b"\0"
            name = struct.pack("<II", 0, offset)
        table += struct.pack("<8sIhHBB", name, *values)
    return header + headers + payload + table + struct.pack("<I", 4 + len(strings)) + strings


class IndependentRelocationTests(unittest.TestCase):
    def compare(self, address, body, symbols, **options):
        with tempfile.TemporaryDirectory() as directory:
            obj = Path(directory) / "fixture.obj"
            obj.write_bytes(body)
            return matcher.match_object(address, obj, symbols, strict=True,
                                        auto_symbols=True, **options)

    def test_unknown_external_cannot_borrow_original_call_target(self):
        body = coff_object([(b".text", b"\x83\xc1\x04\xe9\0\0\0\0", [(4, 1, 0x14)])],
                           [(b"_entry", 0, 1, 0x20, 2, 0), (b"_Bogus", 0, 0, 0x20, 2, 0)])
        unknown = self.compare(0x532510, body, {}, entry="_entry")
        self.assertFalse(unknown["strict_match"])
        self.assertEqual(unknown["difference_count"], 0)
        self.assertIn("unresolved symbol _Bogus", unknown["strict_issues"][0])
        self.assertFalse(unknown["relocations"][0]["verified"])
        wrong = self.compare(0x532510, body, {"_Bogus": 0x522F28}, length=8, entry="_entry")
        self.assertFalse(wrong["strict_match"])
        self.assertTrue(wrong["relocation_issues"])
        right = self.compare(0x532510, body, {"_Bogus": 0x522F20}, length=8, entry="_entry")
        self.assertTrue(right["strict_match"])
        self.assertEqual(right["relocations"][0]["origin"], "explicit_symbol")

    def test_secondary_code_relocation_must_also_resolve(self):
        base, secondary, target = 0x401000, 0x401020, 0x401050
        before_fixup = b"\x90\x55\x8b\xec\x90\x31\xc0\x90\xe9"
        linked = before_fixup + struct.pack("<i", target - secondary - 13)
        image_data = b"\xc3" + b"\0" * 31 + linked
        image = (image_data, base, [(".text", 0, len(image_data), 0, len(image_data))])
        body = coff_object([(b".text", b"\xc3", []),
                            (b".text$x", before_fixup + b"\0" * 4, [(9, 2, 0x14)])],
                           [(b"_entry", 0, 1, 0x20, 2, 0),
                            (b"_funclet", 0, 2, 0x20, 3, 0), (b"_Bogus", 0, 0, 0x20, 2, 0)])
        with patch.object(matcher, "pe_image", return_value=image):
            unknown = self.compare(base, body, {}, length=1, entry="_entry")
            self.assertFalse(unknown["strict_match"])
            self.assertIn("unresolved symbol _Bogus", unknown["strict_issues"][0])
            self.assertEqual(unknown["linked_sections"][1]["origin"], "unique_section_signature")
            right = self.compare(base, body, {"_Bogus": target}, length=1, entry="_entry")
            self.assertTrue(right["strict_match"])

    def test_duplicate_section_signature_needs_independent_anchor(self):
        body = b"\x90\x55\x8b\xec\x90\x31\xc0\xc3"
        data = body + b"\0" * 4 + body
        image = (data, 0x401000, [(".text", 0, len(data), 0, len(data))])
        section = {"raw": body, "index": 2}
        self.assertIsNone(matcher.locate_linked_section(image, section, [], [], {}, {}, False))
        anchored = matcher.locate_linked_section(image, section, [], [], {}, {}, False,
                                                 anchors=[(0, 0x40100C)])
        self.assertEqual(anchored, (0x40100C, "explicit_section_anchor"))

    @unittest.skipUnless(shutil.which("llvm-undname"), "MSVC demangler required")
    def test_msvc_decorations_use_independent_identifiers(self):
        resolve = matcher.resolve_auto_symbol
        self.assertEqual(resolve("?DAT_0057c670@@3HA"), (0x57C670, "address_label"))
        self.assertEqual(resolve("?STR_00583ABC@@3PADA"), (0x583ABC, "address_label"))
        self.assertEqual(resolve("?Mem_Free@@YAXPAX@Z"), (0x54DD78, "decorated_alias"))
        self.assertEqual(resolve("?DAT_0057c670@@3junk"), (None, None))
        self.assertEqual(resolve("?DAT_0057c670@Foo@@3HA"), (None, None))
        self.assertEqual(resolve("?Bogus@@YAXPAX@Z"), (None, None))

    def test_exact_registered_symbol_supplies_relocation_evidence(self):
        base, target = 0x401000, 0x531330
        raw = b"\xe8" + struct.pack("<i", target - base - 5) + b"\xc3"
        image = (raw, base, [(".text", 0, len(raw), 0, len(raw))])
        candidate = b"\xe8\0\0\0\0\xc3"
        symbol = b"?BinarySearch8@Array@@QAEHHH@Z"
        body = coff_object([(b".text", candidate, [(1, 1, 0x14)])],
                           [(b"_entry", 0, 1, 0x20, 2, 0), (symbol, 0, 0, 0x20, 2, 0)])
        with patch.object(matcher, "pe_image", return_value=image):
            match = self.compare(base, body, {}, length=len(raw), entry="_entry")
            self.assertTrue(match["strict_match"], match)
            self.assertEqual(match["relocations"][0]["origin"], "symbol_registry")
            self.assertTrue(match["relocations"][0]["evidence"])
            wrong = self.compare(base, body, {symbol.decode(): target + 1}, length=len(raw), entry="_entry")
            self.assertFalse(wrong["strict_match"])
            self.assertEqual(wrong["relocations"][0]["origin"], "explicit_symbol")
        self.assertEqual(matcher.load_registry("0" * 64), {})

    def test_defined_vtable_uses_registry_anchor_and_checks_slot_fixup(self):
        base, vtable, destructor = 0x401000, 0x55c2f0, 0x401a00
        raw = b"\xa1" + struct.pack("<I", vtable) + b"\xc3"
        image = (raw + struct.pack("<I", destructor), base,
                 [(".text", 0, len(raw), 0, len(raw)), (".rdata", vtable - base, 4, len(raw), 4)])
        body = coff_object([(b".text", b"\xa1\0\0\0\0\xc3", [(1, 1, 0x06)]),
                            (b".rdata", bytes(4), [(0, 2, 0x06)])],
                           [(b"_entry", 0, 1, 0x20, 2, 0), (b"??_7ResourceManager@@6B@", 0, 2, 0, 2, 0),
                            (b"_dtor", 0, 0, 0x20, 2, 0)])
        with patch.object(matcher, "pe_image", return_value=image):
            match = self.compare(base, body, {"_dtor": destructor}, length=len(raw), entry="_entry")
            self.assertTrue(match["strict_match"], match)
            anchor = match["linked_sections"][1]
            self.assertEqual(anchor["origin"], "registry_section_anchor")
            self.assertEqual(anchor["anchors"][0]["symbol"], "??_7ResourceManager@@6B@")
            self.assertEqual(match["linked_spans"][1]["hex_bytes"], struct.pack("<I", destructor).hex())
            self.assertEqual(match["linked_spans"][1]["placement"], "registry_section_anchor")
            wrong = self.compare(base, body, {"_dtor": destructor + 1}, length=len(raw), entry="_entry")
            self.assertFalse(wrong["strict_match"])
            self.assertEqual(wrong["linked_spans"], [])
            self.assertIn("unverified .rdata", wrong["strict_issues"][0])


if __name__ == "__main__":
    unittest.main()
