"""Check the narrow builder translator without Wine or an installed game."""

import importlib.util
from pathlib import Path
import sys
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools"))
from generate_ui_builder import METHODS, extract, verify_calls


METHOD_NAME = "Window_GadgetNotify_Text_SetLayout"
METHODS_FOR_TEST = {METHOD_NAME: (METHOD_NAME, *METHODS[METHOD_NAME])}
EXPORT = """
void * __cdecl Example(int *param_1)
{
  int iVar1;
  void *this;
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  Window_GadgetNotify_Text_SetLayout(this,0x401,0,
                                     0x80,0xffff,0);
  return this;
}
"""


class BuilderExtractionTests(unittest.TestCase):
    def test_render_layout_word_and_keep_ordered_targets(self):
        candidate = extract(0x1000, EXPORT, METHODS_FOR_TEST)
        self.assertEqual(candidate["calls"], [0x52f9d0])
        self.assertIn("(0x401, 0, 0x80, -1, 0);", candidate["source"])
        self.assertIn("(int, int, short, short, int);", candidate["source"])

    def test_null_return_only_uses_window_under_its_null_guard(self):
        export = EXPORT.replace("if (this == (void *)0x0)", "if (iVar1 != 0)")
        candidate = extract(0x1000, export, METHODS_FOR_TEST)
        self.assertIn("if (iVar1 != 0) {\n        return 0;", candidate["source"])

    def test_reject_unmodeled_call(self):
        export = EXPORT.replace(METHOD_NAME, "Unknown")
        with self.assertRaisesRegex(ValueError, "unsupported UI builder statement"):
            extract(0x1000, export, METHODS_FOR_TEST)

    def test_button_layout_accepts_spacing_and_preserves_signed_word_sentinel(self):
        method = "Gadget_SetButtonTextLayout"
        source = EXPORT.replace(METHOD_NAME + "(this,0x401,0,", method + " (this,0x401,0,", 1)
        source = source.replace("0x80,0xffff,0);", "0x80,0xfffe,0,0);")
        candidate = extract(0x1000, source, {method: (method, *METHODS[method])})
        self.assertEqual(candidate["calls"], [0x52f7a0])
        self.assertIn(f"{method}(0x401, 0, 0x80, -2, 0, 0);", candidate["source"])

    def test_input_field_preserves_dword_width_and_color_arguments(self):
        add = "UI_AddInputField"
        color = "Window_GadgetNotify_Input_SetFocusColor"
        source = EXPORT.replace(
            f"  {METHOD_NAME}(this,0x401,0,\n                                     0x80,0xffff,0);",
            f"  iVar1 = {add}(this,0x401,0,0,s_font_00501000,s_input_00502000,0xffff);\n"
            f"  if (iVar1 != 0) {{\n    {color}(this,0x401,0xffff);\n  }}",
        )
        candidate = extract(0x1000, source, {name: (name, *METHODS[name]) for name in (add, color)})
        self.assertEqual(candidate["calls"], [0x52fa40, 0x52fb80])
        self.assertIn("AddInputField(int, int, int, char *, char *, int);", candidate["source"])
        self.assertIn(f"{color}(int, unsigned int);", candidate["source"])
        self.assertIn("AddInputField(0x401, 0, 0, STR_00501000, STR_00502000, 0xffff);", candidate["source"])
        self.assertIn(f"{color}(0x401, 0xffff);", candidate["source"])

    @unittest.skipUnless(importlib.util.find_spec("capstone"), "requires Capstone")
    def test_named_callback_needs_unique_index_entry_and_original_push(self):
        method = "Window_CreatePictureWindow"
        source = EXPORT.replace("  if (this", "  iVar1 = Window_CreatePictureWindow("
                                "DAT_0057c5e0,s_bg_00500000,KnownProc);\n  if (this", 1)
        methods = {**METHODS_FOR_TEST, method: (method, *METHODS[method])}
        with patch("generate_ui_builder.native_symbols", return_value={"0x401234": "KnownProc"}):
            candidate = extract(0x401000, source, methods)
            self.assertEqual(candidate["callbacks"], {"_KnownProc": 0x401234})
            self.assertIn("(void *)KnownProc", candidate["source"])
            callback_only = {**candidate, "calls": [], "methods": {}}
            code = bytes.fromhex("68 34 12 40 00 c3")
            section = [(".text", 0, len(code), 0, len(code))]
            verify_calls((code, 0x401000, section), 0x401000, len(code), callback_only)
            wrong_push = bytes.fromhex("68 35 12 40 00 c3")
            with self.assertRaisesRegex(ValueError, "is not pushed"):
                verify_calls((wrong_push, 0x401000, section), 0x401000, len(code), callback_only)
        with patch("generate_ui_builder.native_symbols", return_value={"0x401234": "KnownProc",
                                                                       "0x401235": "KnownProc"}):
            with self.assertRaisesRegex(ValueError, "unsupported argument 'KnownProc'"):
                extract(0x401000, source, methods)


if __name__ == "__main__":
    unittest.main()
