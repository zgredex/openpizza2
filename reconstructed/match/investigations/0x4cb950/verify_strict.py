"""Verify the registry reader with a handler anchor recovered from the PE."""

from pathlib import Path
import subprocess
import sys
from tempfile import TemporaryDirectory


if __name__ == "__main__":
    root = Path(__file__).resolve().parents[4]
    with TemporaryDirectory(prefix="pc2-registry-reader-") as directory:
        raise SystemExit(subprocess.call([
            sys.executable, "tools/verify_vc6_eh_anchor.py", "0x4cb950",
            "--source", "reconstructed/match/batch20/part1/nonmatching/0x4cb950.c",
            "--entry", "?HighScore_ReadRegistryBlob@@YAIPBDPAE@Z", "--flags", "/O2 /TP /GX",
            "--symbol", "??0RegistryKey@@QAE@XZ=0x403190",
            "--symbol", "??1RegistryKey@@QAE@XZ=0x4031a0",
            "--out", str(Path(directory) / "receipt.json"),
        ], cwd=root))
