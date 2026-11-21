#!/bin/sh
# Strict byte-match verification for batch10/part1 (24 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# 0x481140 (Branch_GetCachedBillboards) is not included: its best genuine
# C++ attempt matches 68 of 70 bytes; see nonmatching/0x481140.c.
# Usage: sh reconstructed/match/batch10/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch10/part1/$address.c" \
        --length "$length" --entry "$entry" --strict --auto-symbols "$@" \
        >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x4031b0 75 '?OpenOrCreate@RegistryKey@@QAEPAXPAXPBD@Z' --flags "/O2 /TP" \
    --symbol "__imp__RegCloseKey@4=0x55c010" \
    --symbol "__imp__RegOpenKeyExA@20=0x55c008" \
    --symbol "__imp__RegCreateKeyA@12=0x55c004"
check 0x403300 75 '?ConstructWithValue@UI_ListEntry@@QAEPAU1@PADHH@Z' --flags "/O2 /TP"
check 0x403370 73 '?Construct@UI_ListEntry@@QAEPAU1@PADH@Z' --flags "/O2 /TP"
check 0x403580 70 '?ResetScreenRegistry@@YAXXZ' --flags "/O2 /TP"
check 0x40bab0 71 '?UpdateIdleCars@Game@@QAEXXZ' --flags "/O2 /TP"
check 0x477b80 74 '?ClearAssignedEmployee@Branch@@QAEXXZ' --flags "/O2 /TP"
check 0x477bd0 76 '?SetAssignedEmployee@Branch@@QAEXH@Z' --flags "/O2 /TP"
check 0x47a4f0 71 '?SumStatGrid@Game@@QAEHHH@Z' --flags "/O2 /TP"
check 0x47a5d0 73 '?SumFloatMatrix@Stats@@QAEMHH@Z' --flags "/O2 /TP"
check 0x47a620 70 '?GetMaxValue@Grid@@QAEMXZ' --flags "/O2 /TP"
check 0x47c370 73 '?FindIndexByValue@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x47cd30 74 '?FindRecordByPair@Game@@QAEPAUPairRecord@@HH@Z' --flags "/O2 /TP"
check 0x47e0e0 73 '?EnqueueConstructionOrder@Branch@@QAEXPAUOrderRecord@@HH@Z' --flags "/O2 /TP"
check 0x47e130 78 '?FindRecordByPairChecked@Game@@QAEPAUPairRecord@@HH@Z' --flags "/O2 /TP"
check 0x480bf0 71 '?ContainsObjectPointer@Game@@QAEDPAX@Z' --flags "/O2 /TP"
check 0x480e30 75 '?RestoreSignLogoAnimations@MapObject@@QAEXXZ' --flags "/O2 /TP"
check 0x482740 74 '?Register@Game@@QAEXPAUCity@@HH@Z' --flags "/O2 /TP"
check 0x482790 70 '?AddObjectToRegistry@Game@@QAEHPAUObject@@@Z' --flags "/O2 /TP"
check 0x483c40 75 '?DestroyCachedScreens@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x48cae0 69 '?SetObjectInfoWindowVisible@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x48d0c0 71 '?RemoveScreenTimers@Game@@QAEXXZ' --flags "/O2 /TP"
check 0x491ea0 72 '?BuildingInfoMenu_Init@@YAXPAX@Z' --flags "/O2 /TP"
check 0x4986f0 69 '?Game_ResizeGlobalArray3@@YAXH@Z' --flags "/O2 /TP"
check 0x49b880 75 '?SaveMenu_MenuFileExists@@YADPAD@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
