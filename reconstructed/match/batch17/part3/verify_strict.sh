#!/bin/bash
# Strict byte-match verification for batch17/part3.
# Every check passes the manifest length, the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Run from the repository root:
#   bash reconstructed/match/batch17/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch17/part3/$address.c" \
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

check 0x4859c0 182 '?SetupZoomedViewport@GameView@@QAEXPAX@Z'
check 0x4e0920 182 '?SumRecordFloatsByType@Stats@@QAEMHH@Z'
check 0x527e20 182 '?SetCursorPosition@Window@@QAEXHHHH@Z'
check 0x547ba0 182 '?ApplyVolumesForPlaybackMode@Sound@@QAEXH@Z'
check 0x4805d0 183 '?ResetAverages@Stats@@QAEXXZ'
check 0x488c00 183 '?RunSimulationFrame@Game@@QAEXXZ'
check 0x48b8a0 183 '?ScrollToClamped@Map@@QAEXPAU1@HH@Z'
check 0x52ad60 183 '?BuildListItem@UI@@QAEXPAUListItem@@@Z'
check 0x5405e0 183 '?BuildArchivePath@SoundPakManager@@QAEXPAD0@Z'
check 0x47e5e0 184 '?GetSizeName@SpriteManager@@QAEXHH@Z'
check 0x4fdb20 184 '?TryTakeOverRivalBranch@AI@@QAEHHHPAX@Z'
check 0x47d150 185 '?FindNearestCompanyBuilding@Map@@QAEPAXPAX@Z'
check 0x47e520 185 '?IsBuildingOpenAtHour@Game@@QAEHH@Z'
check 0x4d3e30 185 '?RemoveFromStaff@Person@@QAEXXZ'

echo "strict $pass / $((pass + fail))"
[ "$fail" -eq 0 ]
