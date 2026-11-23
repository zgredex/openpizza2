"""Tests for tools/generate_port_batch.py."""
import importlib.util
import pathlib
import sys
import tempfile
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[1]
MODULE = ROOT / "tools" / "generate_port_batch.py"
spec = importlib.util.spec_from_file_location("port_batch", MODULE)
mod = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = mod
spec.loader.exec_module(mod)


class PortBatchTests(unittest.TestCase):
    def test_clean_code_retypes_and_renames(self):
        code = mod.clean_code(
            "// pseudocode: provider\n"
            "void __thiscall F(void *this, int param_1)\n"
            "{\n"
            "  int iVar1 = *(undefined4 *)((int)this + param_1);\n"
            "  return;\n"
            "}\n"
        )
        self.assertIn("void *self", code)
        self.assertIn("value1", code)
        self.assertIn("uint32_t", code)
        self.assertIn("intptr_t", code)

    def test_translate_accepts_standalone_function(self):
        with tempfile.TemporaryDirectory() as td:
            path = pathlib.Path(td) / "0x401000.c"
            path.write_text(
                "// name: Alpha\n// address: 0x401000\n// body: available\n"
                "// pseudocode: provider\nint Alpha(int x) { return x + 1; }\n"
            )
            item, reason = mod.translate(path)
            self.assertIsNone(reason)
            self.assertEqual(item["address"], "0x401000")
            self.assertEqual(item["name"], "Alpha")

    def test_translate_rejects_external_references(self):
        with tempfile.TemporaryDirectory() as td:
            path = pathlib.Path(td) / "0x401000.c"
            path.write_text(
                "// name: Beta\n// address: 0x401000\n// body: available\n"
                "// pseudocode: provider\nvoid Beta(void) { FUN_00401000(); }\n"
            )
            item, reason = mod.translate(path)
            self.assertIsNone(item)
            self.assertIn("external", reason)

    def test_render_has_original_marker(self):
        text = mod.render({"address": "0x401000", "name": "Alpha", "code": "int Alpha(void) {}\n"})
        self.assertIn("// original: 0x401000", text)
        self.assertIn('#include "pc2_port.h"', text)


if __name__ == "__main__":
    unittest.main()
