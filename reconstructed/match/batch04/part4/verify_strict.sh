#!/bin/sh
# Strict verification for batch04/part4.
#
# Each record is checked individually with the official matcher:
#   python3 tools/match_decomp.py ADDRESS SOURCE --length LEN --entry ENTRY \
#       --flags "/O2 /TP" --strict --auto-symbols
#
# Every candidate in this part reproduces the original /O2 module.  The only
# external symbol that auto-resolution cannot name is the embedded pak entry
# comparator at 0x53ffb0, which is supplied as an independent --symbol map.
#
# Usage: sh reconstructed/match/batch04/part4/verify_strict.sh [report.json]
set -eu

PART_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
ROOT=$(CDPATH= cd -- "$PART_DIR/../../../.." && pwd)
REPORT=${1:-${TMPDIR:-/tmp}/pc2-batch04-part4-strict.json}

exec python3 - "$ROOT" "$PART_DIR" "$REPORT" <<'PY'
import json
import subprocess
import sys
from pathlib import Path

root, part_dir, report_path = Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3])
manifest = json.loads((root / "reconstructed/match/batch04/part4.json").read_text())

FLAGS = "/O2 /TP"

# One function symbol per translation unit; pass it explicitly instead of
# relying on the matcher's single-symbol auto-detection.
ENTRIES = {
    "0x524970": "?NotifyMouseMove@Window@@QAEXXZ",
    "0x527ca0": "?ClearField230@UI@@QAEXH@Z",
    "0x52fd70": "?Slider_SetValue@Window@@QAEXHHH@Z",
    "0x52fdb0": "?Slider_AttachValueText@Window@@QAEXHHH@Z",
    "0x52ff30": "?GetRecordField40@Array@@QAEHH@Z",
    "0x531b70": "?SetButtonRecordVariant@Window@@QAEXHH@Z",
    "0x531dd0": "?OffsetPoint@UI@@QAEXPAH0@Z",
    "0x531df0": "?SubtractOrigin@UI@@QAEXPAH0@Z",
    "0x533540": "?GetWidthHeight@Object@@QAEXPAI0@Z",
    "0x533a50": "?Clear@RecordSet@@QAEXH@Z",
    "0x5355b0": "?GetPosition@Text@@QAEXPAH0@Z",
    "0x535d50": "?GetPtrChecked@Array@@QAEPAXH@Z",
    "0x5377d0": "?ConfigureFromOwner@SurfaceOwner@@QAEXPAUSurface@@@Z",
    "0x5396e0": "?Reset@Surface@@QAEXXZ",
    "0x539e70": "?CopyStateToChildren@Renderer@@QAEXXZ",
    "0x53d140": "?SetHotspot@Sprite@@QAEXGG@Z",
    "0x53ef70": "?RefCount_Release@@YGHPAURefCounted@@@Z",
    "0x53f820": "?StreamBuffer_Reset@@YGHPAUStreamBuffer@@@Z",
    "0x53ff90": "?Pak_SortEmbeddedEntries@@YGXPAXH@Z",
    "0x547580": "?ReloadSpeechSetIfNeeded@Sound@@QAEXXZ",
    "0x5482e0": "?PlayEffectByIndex@Sound@@QAEXH@Z",
    "0x54a5d0": "?Window_GetChildAndNotify@@YIPAUChild@@PAUWindow@@@Z",
    "0x54b2c0": "?SetField34@MessageList@@QAEXHH@Z",
    "0x54b440": "?GetPtr4@Array@@QAEPAXH@Z",
    "0x54c810": "?FreeValuesAndObject@List@@QAEXXZ",
}

# The pak comparator at 0x53ffb0 has no shipped symbol name; the candidate
# declares it as an extern "C" function and this map gives its real address.
SYMBOLS = {
    "0x53ff90": ["--symbol", "_Pak_CompareEmbeddedEntries=0x53ffb0"],
}

results = []
for record in manifest:
    address = record["address"]
    source = part_dir / f"{address}.c"
    if not source.is_file():
        results.append({"address": address, "name": record["name"],
                        "strict_match": False, "error": f"missing {source}"})
        continue
    text = source.read_text(errors="replace")
    if "__asm" in text or "asm {" in text:
        results.append({"address": address, "name": record["name"],
                        "strict_match": False,
                        "error": "inline assembly is not decompiled C"})
        continue
    command = [
        sys.executable, str(root / "tools/match_decomp.py"), address, str(source),
        "--length", str(record["length"]), "--entry", ENTRIES[address],
        "--flags", FLAGS, "--strict", "--auto-symbols",
        *SYMBOLS.get(address, []),
    ]
    run = subprocess.run(command, cwd=root, capture_output=True, text=True)
    try:
        result = json.loads(run.stdout)
    except json.JSONDecodeError:
        result = {"strict_match": False,
                  "error": run.stderr.strip() or run.stdout.strip()}
    result.update({"name": record["name"], "flags": FLAGS})
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
          "manifest": "reconstructed/match/batch04/part4.json",
          "results": results}
report_path.parent.mkdir(parents=True, exist_ok=True)
report_path.write_text(json.dumps(report, indent=2) + "\n")
print(f"report: {report_path}")
raise SystemExit(0 if strict == len(results) else 1)
PY
