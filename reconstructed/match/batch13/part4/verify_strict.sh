#!/bin/sh
# Strict byte-match verification for batch13/part4 (13 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Unmatched functions are kept under nonmatching/ with matcher evidence.
# Usage: sh reconstructed/match/batch13/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch13/part4/$address.c" \
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

check 0x47eb30 110 '?PayConstructionOrder@Branch@@QAEXH@Z' --flags "/O2 /TP"
check 0x4e2a20 110 '?GetMostCommonTypeIndex@Game@@QAEHXZ' --flags "/O2 /TP"
check 0x520d90 110 '?SetLabelIdText@UI@@QAEXHPAD@Z' --flags "/O2 /TP"
check 0x4db310 111 '_Parse_ReadIntToken' --flags "/O2 /TP"
check 0x51eae0 111 '?ClearChildExtent@UI@@QAEXXZ' --flags "/O2 /TP"
check 0x4d2d10 112 '?SetObjectFlags@Map@@QAEXPAXI@Z' --flags "/O2 /TP"
check 0x4f5bb0 112 '?DrawCenteredSelectionRect@UI@@QAEXH@Z' --flags "/O2 /TP"
check 0x531400 112 '?SetObjectRangeByKey@UI@@QAEHHHH@Z' --flags "/O2 /TP"
check 0x4cb7e0 113 '_FreePlaySetup_FillGameLengthText' --flags "/O2 /TP"
check 0x4d5940 113 '?BuildOccupiedCellList@Map@@QAEXXZ' --flags "/O2 /TP"
check 0x4aeac0 112 '_Glossary_BuildingsPage_Init' --flags "/O2 /TP"
check 0x4e3e80 113 '?FindBestRatedBuilding@Game@@QAEPAXH@Z' --flags "/O2 /TP"
check 0x5476f0 113 '?InitSpeechVoice@Sound@@QAEXXZ' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail)) of 25 manifest functions"
[ "$fail" -eq 0 ]
