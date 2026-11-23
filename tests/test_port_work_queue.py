import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

SCRIPT=Path(__file__).resolve().parents[1]/'tools/port_work_queue.py'
class QueueTests(unittest.TestCase):
    def test_queue_and_status(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td)
            pseudo=root/'decompiled_fastfood2_named_v2/full_game_verification/functions'
            pseudo.mkdir(parents=True)
            (pseudo/'0x401000.c').write_text('// name: Alpha\n// address: 0x401000\n// body: available\n// pseudocode: provider-specific\nint Alpha(int x) { return x+1; }\n')
            (pseudo/'0x401020.c').write_text('// name: Beta\n// address: 0x401020\n// body: available\n// pseudocode: provider-specific\nint Beta(int x) { return Alpha(x); }\n')
            (pseudo/'0x401030.c').write_text('// name: Gamma\n// address: 0x401030\n// body: available\n// pseudocode: provider-specific\nundefined4 Gamma(void) { return 1; }\n')
            port=root/'source_port/src'; port.mkdir(parents=True)
            (port/'Gamma.cpp').write_text('// original: 0x401030\n// PORT_STATUS: STUB\nint Gamma() {return 0;}')
            subprocess.run([sys.executable,str(SCRIPT),'--root',str(root)],check=True,capture_output=True)
            data=json.loads((root/'source_port/work_queue/queue.json').read_text())
            self.assertEqual(data['summary']['exported'],3)
            self.assertEqual(data['summary']['stubs_not_counted'],1)
            self.assertEqual(data['queue'],['0x401000','0x401020'])
    def test_submitted_is_not_verified(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td); pseudo=root/'decompiled_fastfood2_named_v2/full_game_verification/functions'; pseudo.mkdir(parents=True)
            (pseudo/'0x402000.c').write_text('// name: H\n// address: 0x402000\n// body: available\nint H(void) {return 1;}')
            port=root/'source_port/src'; port.mkdir(parents=True)
            (port/'h.cpp').write_text('// original: 0x402000\nint H() {return 1;}')
            subprocess.run([sys.executable,str(SCRIPT),'--root',str(root)],check=True,capture_output=True)
            data=json.loads((root/'source_port/work_queue/queue.json').read_text())
            self.assertEqual(data['summary']['submitted_not_verified'],1)
            self.assertEqual(data['summary']['queued'],0)
if __name__=='__main__': unittest.main()
