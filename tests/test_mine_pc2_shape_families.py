"""Tests for read-only family miner. Uses game exe only when installed."""
import importlib.util
import pathlib
import sys
import tempfile
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[1]
MODULE = ROOT / 'tools' / 'mine_pc2_shape_families.py'
spec = importlib.util.spec_from_file_location('pc2_shape', MODULE)
mod = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = mod
spec.loader.exec_module(mod)


class ParserTests(unittest.TestCase):
    def test_imm_refs(self):
        self.assertEqual(list(mod.refs_in_instruction('DWORD PTR ds:0x55c1b8')), [0x55c1b8])
        self.assertEqual(list(mod.refs_in_instruction('[eax+0xc]')), [])

    def test_immediate_normalization(self):
        left = mod.shape_instruction('mov', 'DWORD PTR [esi+0x38],0x55c8e0')
        right = mod.shape_instruction('mov', 'DWORD PTR [esi+0x28],0x55c864')
        self.assertEqual(left, right)

    def test_exact_exe_and_known_imports(self):
        path = ROOT / 'game' / 'fastfood2.exe'
        if not path.exists():
            self.skipTest('Optional local target binary not present')
        pe = mod.PE(path)
        self.assertEqual(pe.hash, mod.TARGET_SHA)
        self.assertEqual(pe.imports[0x55c1b8], 'KERNEL32.dll!EnterCriticalSection')
        self.assertEqual(pe.imports[0x55c1a0], 'KERNEL32.dll!LeaveCriticalSection')
        self.assertTrue(mod.vtable_like_at(pe, 0x55c8e0))
        self.assertFalse(mod.vtable_like_at(pe, 0x55c1b8))


if __name__ == '__main__':
    unittest.main()
