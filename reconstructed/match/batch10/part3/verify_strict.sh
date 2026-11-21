#!/bin/bash
# Strict byte-match verification for batch10/part3.
# Every check passes the manifest length, the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Run from the repository root:
#   bash reconstructed/match/batch10/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch10/part3/$address.c" \
        --length "$length" --entry "$entry" --strict --auto-symbols \
        --flags "/O2 /TP" "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x4eac30 70 '?GetNestedArrayEntry@Game@@QAEHHH@Z' \
    --symbol '?Lookup@IDMap@@QAEPAXHPAH@Z=0x4017f0' \
    --symbol '?GetRecordChild14@Game@@QAEHH@Z=0x4eac00'
check 0x4ead00 70 '?TickWorldObjects@Game@@QAEXXZ'
check 0x4ead90 69 '?Get2DTableValue@Map@@QAEHHHH@Z'
check 0x4ed930 69 '?SetHoverTile@Map@@QAEXPAUHoverSource@@@Z'
check 0x4f4ed0 72 '?ResetLinkVisitedFlags@Object@@QAEXXZ' \
    --symbol '?CountValid8@Object@@QAEHPAD@Z=0x4edbd0' \
    --symbol '?GetRecord28@Object@@QAEPADHH@Z=0x4f0cc0'
check 0x4f6b80 69 '?TickGoalDeadline@Mission@@QAEXH@Z'
check 0x4f6e20 69 '?CompanySlots_Save@AI@@QAEXPAUOStream@@@Z' \
    --symbol '?Write@OStream@@QAEXPAXH@Z=0x54cc2b'
check 0x4fba90 70 '_Map_GridToScreenOffset@20'
check 0x4fd0a0 77 '?EnsureRequiredBranch@Company@@QAEXHPAXH@Z' \
    --symbol '?FindCheapestShop@Company@@QAEPAUShop@@HPAXH@Z=0x4f88c0' \
    --symbol '?BuildHeadquarters@Company@@QAEXHPAXPAUShop@@HH@Z=0x4fd0f0'
check 0x502360 71 '?Stats_GetLevelFromTenCounters@@YAHXZ'
check 0x5078d0 74 '?PathToTileAndStep@Person@@QAEHHH@Z' \
    --symbol '__imp__timeGetTime@0=0x55c294'
check 0x509170 76 '?Record_DoublePositionValue@@YIXH@Z' \
    --symbol '?SetEntryPosition@UIList@@QAEXHN@Z=0x534c30'
check 0x50b680 77 '?SendToBranchWithCarryMode@Person@@QAEXHH@Z'
check 0x50bbf0 72 '?ClearAssignedRecord@Object@@QAEHPAURecordMap@@@Z'
check 0x50e890 74 '?SetState@Object@@QAEXH@Z'
check 0x50f7f0 69 '?GetPercentModifier@Company@@QAEHH@Z'
check 0x514450 77 '?SetSupplierBuilding@Storage@@QAEXH@Z'
check 0x5144a0 75 '?Stats_GetAverageRecordValue@@YIHH@Z'
check 0x522e80 77 '?Construct@Array@@QAEPAU1@H@Z'
check 0x526870 73 '?UI_MessageBoxf@@YAHPAXPADZZ'
check 0x527250 76 '?ImageCache_Clear@@YIXH@Z'
check 0x528040 76 '?FindWindowByID@UI@@QAEHHPAH@Z'

echo "strict matches: $pass; failures: $fail"
for known in 0x4ede90 0x4f7a00 0x50fe70; do
    echo "known non-matching: $known (see reconstructed/match/batch10/part3/nonmatching/)"
done
[ "$fail" -eq 0 ]
