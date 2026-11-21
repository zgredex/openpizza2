#!/bin/sh
# Strict verification for batch03/part4.
#
# Each record is checked individually with the official matcher:
#   python3 tools/match_decomp.py ADDRESS SOURCE --length LEN \
#       --flags "<flags>" --strict --auto-symbols
#
# The part contains two CRT/library-style helpers (0x54dc72 and 0x551f8b)
# whose shipped bytes are the /O1 (size) codegen; the remaining candidates are
# /O2.  A single uniform flag set therefore cannot verify the whole part, so
# this script applies the per-function optimization flag that reproduces the
# original module.
#
# Usage: sh reconstructed/match/batch03/part4/verify_strict.sh [report.json]
set -eu

PART_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
ROOT=$(CDPATH= cd -- "$PART_DIR/../../../.." && pwd)
REPORT=${1:-${TMPDIR:-/tmp}/pc2-batch03-part4-strict.json}

exec python3 - "$ROOT" "$PART_DIR" "$REPORT" <<'PY'
import json
import subprocess
import sys
from pathlib import Path

root, part_dir, report_path = Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3])
manifest = json.loads((root / "reconstructed/match/batch03/part4.json").read_text())

# 0x54dc72 and 0x551f8b reproduce the original /O1 bytes exactly; all other
# records reproduce the original /O2 bytes.
OPT_FLAGS = {
    "0x54dc72": "/O1 /TP",
    "0x551f8b": "/O1 /TP",
}
DEFAULT_FLAGS = "/O2 /TP"

# One function symbol per translation unit; pass it explicitly instead of
# relying on the matcher's single-symbol auto-detection.
ENTRIES = {
    "0x52fbe0": "?Input_GetText@Window@@QAEXH@Z",
    "0x52fcc0": "?Slider_SetGradientColors@Window@@QAEXHH@Z",
    "0x52fce0": "?Slider_SetChangeNotify@Window@@QAEXHH@Z",
    "0x52fd90": "?Slider_GetValue@Window@@QAEXHH@Z",
    "0x52ff80": "?DisableButton@Window@@QAEXH@Z",
    "0x531960": "?SetButtonColorVariant@Window@@QAEXHH@Z",
    "0x5319a0": "?GetButtonSpriteRecord@Window@@QAEXH@Z",
    "0x531b50": "?ClearButtonRecordAnimation@Window@@QAEXH@Z",
    "0x531b90": "?GetButtonContext@Window@@QAEXHH@Z",
    "0x531c40": "?StartButtonMovie@Window@@QAEXHH@Z",
    "0x531cf0": "?GetWindowObject@Window@@QAEXH@Z",
    "0x532310": "?SetPosition@UI@@QAEXHH@Z",
    "0x535160": "?GetPair4@Object@@QAEXPAH0@Z",
    "0x5354e0": "?FreePixelData@Image@@QAEXXZ",
    "0x5355d0": "?SetCursor@Text@@QAEXHH@Z",
    "0x539180": "?Surface_IsReady@@YGHPAH@Z",
    "0x539260": "?Surface_Unlock@@YIXH@Z",
    "0x539f00": "?Object_GetRootType@@YIHH@Z",
    "0x53d440": "?SetColorKey@Sprite@@QAEXH@Z",
    "0x53d480": "?GetPixelBuffer@Sprite@@QAEPAXXZ",
    "0x53fbf0": "?DirectSoundBuffer_Destructor@@YIXPAH@Z",
    "0x548d70": "?Sound_SetTimeout@@YIXH@Z",
    "0x54dc72": "?Stream_ValidateRange@@YIHH@Z",
    "0x551f8b": "__malloc",
    "0x552385": "?FileObject_InitBase@@YAXH@Z",
}

results = []
for record in manifest:
    address = record["address"]
    source = part_dir / f"{address}.c"
    text = source.read_text(errors="replace") if source.is_file() else ""
    if not source.is_file():
        results.append({"address": address, "name": record["name"],
                        "strict_match": False, "error": f"missing {source}"})
        continue
    if "__asm" in text or "asm {" in text:
        results.append({"address": address, "name": record["name"],
                        "strict_match": False,
                        "error": "inline assembly is not decompiled C"})
        continue
    flags = OPT_FLAGS.get(address, DEFAULT_FLAGS)
    command = [
        sys.executable, str(root / "tools/match_decomp.py"), address, str(source),
        "--length", str(record["length"]), "--entry", ENTRIES[address],
        "--flags", flags, "--strict", "--auto-symbols",
    ]
    run = subprocess.run(command, cwd=root, capture_output=True, text=True)
    try:
        result = json.loads(run.stdout)
    except json.JSONDecodeError:
        result = {"strict_match": False, "error": run.stderr.strip() or run.stdout.strip()}
    result.update({"name": record["name"], "flags": flags})
    results.append(result)
    status = "STRICT" if result.get("strict_match") else "FAIL"
    print(f"{address} {record['name']}: {status}")

strict = sum(1 for result in results if result.get("strict_match"))
print(f"strict {strict}/{len(results)}")
for result in results:
    if not result.get("strict_match"):
        print(f"  first failure {result['address']} {result['name']}: "
              f"{result.get('first_difference')} issues={result.get('strict_issues')} "
              f"error={result.get('error')}")
report = {"strict_matched": strict, "total": len(results),
          "manifest": "reconstructed/match/batch03/part4.json",
          "results": results}
report_path.parent.mkdir(parents=True, exist_ok=True)
report_path.write_text(json.dumps(report, indent=2) + "\n")
print(f"report: {report_path}")
raise SystemExit(0 if strict == len(results) else 1)
PY
