#!/bin/sh
# Strict byte-match verification for batch08/part4 (25 functions, 22 matched).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and the exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch08/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3
    if $M "$address" "reconstructed/match/batch08/part4/$address.c" \
        --length "$length" --entry "$entry" --strict --auto-symbols \
        --flags "/O2 /TP" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x4dc660 59 '?SumSixSlotValues@Stats@@QAEHHH@Z'
check 0x4f43c0 59 '?AppendQuad@Object@@QAEXPAUQuad@@@Z'
check 0x500e80 59 '?GetPlayerSubrecord@Game@@QAEPAXHHH@Z'
check 0x5090a0 59 '?SetRecordFrame@MapObject@@QAEXH@Z'
check 0x510580 59 '?CountRecordsWithoutFlag@Game@@QAEHXZ'
check 0x512820 59 '?IDMap_FindIndexByPointer@@YGHPAUIDMap@@H@Z'
check 0x47a8e0 60 '?Matrix_Max4x9@@YIHPAX@Z'
check 0x485a80 60 '?SetVolumePreset@Sound@@QAEXH@Z'
check 0x488de0 60 '?EnterBranchInterior@Game@@QAEXPAX@Z'
check 0x49cf10 60 '?CompanyRating_UpdateScoreText@@YAXPAX@Z'
check 0x4fc5f0 60 '?RefreshMenuSalesIfDue@Company@@QAEHH@Z'
check 0x4ffeb0 60 '?AdjustPlayerObjectPercent@Game@@QAEXHH@Z'
check 0x5288f0 60 '?FinishDragAndExpandDirtyRect@UIDrag@@QAEXPAX@Z'
check 0x409d40 61 '?AdvanceToQueuedTarget@Actor@@QAEHPAX0@Z'
check 0x480010 61 '?Stats_HasCurrentSales@@YIHPAUStats@@@Z'
check 0x48d020 61 '?Building_GetAreaByLevel@@YGMH@Z'
check 0x48d070 61 '?Stats_GetAmountByType@@YGMH@Z'
check 0x4b8830 61 '?CompanyProfile_UpdateRatingBars@@YAXPAX@Z'
check 0x4e34a0 61 '?FindRecordType2ByKey@Player@@QAEPAXH@Z'
check 0x4e6300 61 '?SetModeByte@Game@@QAEXI@Z'
check 0x4ea400 61 '?BlitScaledObjectSprite@Game@@QAEXXZ'
check 0x508d50 61 '?ApplyDeferredType@Object@@QAEXH@Z'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
