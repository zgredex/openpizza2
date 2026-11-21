#!/bin/bash
# Strict byte-match verification for batch15/part3.
# Every check passes the manifest length, the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Run from the repository root:
#   bash reconstructed/match/batch15/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch15/part3/$address.c" \
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

check 0x4f5e50 138 '?MissionState_Load@Player@@QAEXPAX@Z'
check 0x4f5ee0 138 '?MissionState_Save@Player@@QAEXPAX@Z'
check 0x547de0 138 '?StopPlaybackMode@Sound@@QAEXXZ'
check 0x489bc0 139 '?CommitObjectPlacement@Game@@QAEHHH@Z'
check 0x4eda60 139 '?ScreenToTileCoords@Map@@QAEXPAH00@Z'
check 0x4fc560 139 '?Game_PurgeUnusedCompanyRecipes@@YIXPAD@Z'
check 0x4ddc10 140 '?RemoveBranch@Player@@QAEXPAX@Z'
check 0x541130 140 '?SetVolumeLogarithmic@Sound@@QAEHH@Z'
check 0x54b230 141 '?BriefingList_Load@UI@@QAEXPAX@Z'
check 0x4a52d0 142 '_TradeOffer_Page_Init'

echo "strict $pass / $((pass + fail))"
[ "$fail" -eq 0 ]
