#!/bin/sh
# Strict byte-match verification for batch05/part3 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch05/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4
    shift 4
    if $M "$address" "reconstructed/match/batch05/part3/$address.c" \
        --length "$length" --entry "$entry" --flags "$flags" \
        --strict --auto-symbols "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address $entry"
        pass=$((pass + 1))
    else
        echo "FAIL   $address $entry"
        python3 - "$OUT/$address.json" <<'PY'
import json, sys
try:
    result = json.load(open(sys.argv[1]))
except Exception:
    print(open(sys.argv[1]).read())
    raise SystemExit
print("  first_difference:", result.get("first_difference"))
print("  strict_issues:", result.get("strict_issues"))
print("  relocation_issues:", result.get("relocation_issues"))
print("  error:", result.get("error"))
PY
        fail=$((fail + 1))
    fi
}

check 0x531980 31 '_UI_GetButtonSprite@4' '/O2' \
    --symbol '_Window_GadgetNotify@20=0x52fdd0'
check 0x53d460 31 '?GetPixelData@Sprite@@QAEHPAH@Z' '/O2 /TP'
check 0x4052a0 32 '?Screen_CloseSubStartMenu@@YAXXZ' '/O2 /TP'
check 0x47f210 32 '?UpdateActiveConstruction@Branch@@QAEXXZ' '/O2 /TP' \
    --symbol '?GetBestObject@Branch@@QAEXHHPAM@Z=0x47f2e0'
check 0x480880 32 '@City_IsIdle@4' '/O2'
check 0x4d35e0 32 '?PickRandomRoadStep@Car@@QAEXXZ' '/O2 /TP'
check 0x4f34f0 32 '?GetRecordCenteredRect@UI@@QAEXHPAH0@Z' '/O2 /TP'
check 0x539e00 32 '?PushFront@List@@QAEXPAX@Z' '/O2 /TP' \
    --symbol '??2@YAPAXI@Z=0x54e221'
check 0x54a5f0 32 '?Construct@DebugConsole@@QAEPAU1@H@Z' '/O2 /TP'
check 0x54a7b0 32 '?ToggleVisibility@Window@@QAEXXZ' '/O2 /TP' \
    --symbol '__imp_?IsWindowVisible@@YGHPAX@Z=0x55c200'
check 0x54a7d0 32 '@Dialog_SetItemText@4' '/O2' \
    --symbol '__imp__GetDlgItem@8=0x55c1f0' \
    --symbol '__imp__SetWindowTextA@8=0x55c1d0'
check 0x401f60 33 '?Init@ResourceIterator@@QAEXPAD@Z' '/O2 /TP'
check 0x4830e0 33 '?DestroyEventWindow@Game@@QAEXXZ' '/O2 /TP'
check 0x488db0 33 '?ShowBranchInteriorDefaultZoom@Game@@QAEXPAX@Z' '/O2 /TP' \
    --symbol '?SetVolumePreset@Game@@QAEXH@Z=0x485a80'
check 0x4db2e0 33 '_String_SkipDelimiters' '/O2'
check 0x4e0f10 33 '?IsRecordLinked@Game@@QAE_NH@Z' '/O2 /TP' \
    --symbol '?HasRecordField14DC@Game@@QAEDH@Z=0x4e0f40'
check 0x4eac00 33 '?GetRecordChild14@Game@@QAEHH@Z' '/O2 /TP'
check 0x50e200 33 '?CountMatchingSlots@Object@@QAEHH@Z' '/O2 /TP'
check 0x50e810 33 '@Object_GetClampedLevel@4' '/O2'
check 0x53d690 33 '?BlitOwnedRLE@Sprite@@QAEXPAXHH@Z' '/O2 /TP'
check 0x5445f0 33 '?RewindBuffer@Sound@@QAEII@Z' '/O2 /TP'
check 0x47fd20 34 '?ClearConstructionSites@Branch@@QAEXXZ' '/O2 /TP' \
    --symbol '?ConsumeObject@Branch@@QAEXH@Z=0x47eab0'
check 0x482590 34 '?AddScreenTimer@Game@@QAEXXZ' '/O2 /TP'
check 0x483120 34 '?SyncSelectedChild@UI@@QAEXXZ' '/O2 /TP'
check 0x489040 34 '?GetTileByte@Map@@QAEDHH@Z' '/O2 /TP'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
