#!/bin/sh
set -eu
cd "$(dirname "$0")/../../.."

python3 - <<'PY'
import json
import subprocess
from pathlib import Path

directory = Path("reconstructed/match/runtime01")
cases = (
    ("0x54c4d0", 26, "@Memory_FreeAndClear@4", "/O2"),
    ("0x54f0d5", 13, "_CRT_Srand", "/O2"),
    ("0x551944", 13, "_CRT_GetVaArg", "/O1"),
    ("0x551961", 14, "_CRT_ReadArg16", "/O1"),
    ("0x5558b1", 12, "_CRT_BitSetClear", "/O1"),
    ("0x5577aa", 43, "_CRT_Strnlen", "/O1"),
)

matched = 0
for address, length, entry, flags in cases:
    result = subprocess.run(
        ["python3", "tools/match_decomp.py", address, str(directory / f"{address}.c"),
         "--length", str(length), "--entry", entry, "--strict", "--auto-symbols",
         "--flags", flags],
        capture_output=True, text=True,
    )
    try:
        strict = json.loads(result.stdout).get("strict_match") is True
    except (json.JSONDecodeError, AttributeError):
        strict = False
    if result.returncode == 0 and strict:
        print(f"STRICT {address} ({length} bytes)", flush=True)
        matched += 1
    else:
        print(f"FAIL {address}\n{result.stdout}{result.stderr}", flush=True)

print(f"strict matches: {matched}/{len(cases)}")
raise SystemExit(matched != len(cases))
PY
