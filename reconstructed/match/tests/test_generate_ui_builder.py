"""Check the narrow builder translator without Wine or an installed game."""

from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools"))
from generate_ui_builder import METHODS, extract


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


if __name__ == "__main__":
    unittest.main()
