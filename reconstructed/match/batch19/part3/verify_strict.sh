#!/bin/sh
# Strict verification for batch19 part3.
set -u
cd "$(dirname "$0")/../../../.." || exit 1
PART=reconstructed/match/batch19/part3
failed=0

check() {
    address=$1 length=$2 entry=$3
    shift 3
    if result=$(python3 tools/match_decomp.py "$address" "$PART/$address.c" \
        --length "$length" --entry "$entry" --flags '/O2 /TP' --strict \
        --auto-symbols "$@" 2>&1); then
        printf 'STRICT %s\n' "$address"
    else
        printf 'FAIL %s\n%s\n' "$address" "$result"
        failed=1
    fi
}

check 0x4d2b90 235 '?SetMarketValueByType@Object@@QAEXXZ'
check 0x47a9d0 237 '?RemoveStaffMember@Branch@@QAEXPAHH@Z'
check 0x4f57f0 236 '?Grid_GetDirectionBetweenNodes@@YGHPAUGridNode@@0@Z'
check 0x4fc630 237 '?TickBranches@City@@QAEHH@Z'
check 0x502030 239 '_Game_GetBuildingQualityBand'
check 0x507ee0 236 '?SelectRouteStopForTimeSlot@Person@@QAEHH@Z'
check 0x525fd0 237 '?DispatchWindowMessage@Window@@QAEXIPAXI@Z'
check 0x5346a0 233 '?BlitIndexedRLE@RecordList@@QAEXHPAIHNN@Z'
check 0x54b770 233 '?DrawOverlaySprites@OverlaySprites@@QAEXHHPAXHHH@Z'

exit "$failed"
