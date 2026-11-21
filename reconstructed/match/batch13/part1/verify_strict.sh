#!/bin/sh
# Strict byte-match verification for batch13/part1 (12 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Functions not listed here are genuine C/C++ attempts kept under nonmatching/
# with first-diff evidence in worklog.md.
# Usage: sh reconstructed/match/batch13/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch13/part1/$address.c" \
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

check 0x47d010 101 '?CountAgedAdjacentBuildings@Game@@QAEHXZ' --flags "/O2 /TP"
check 0x489750 101 '?FindRecordByTripleKey@Game@@QAEPAUTripleRecord@@HHIPAH@Z' --flags "/O2 /TP"
check 0x4f5b40 101 '?Object_CanAssignSlot@@YGHPAUObject@@PAURequest@@PAH2@Z' --flags "/O2 /TP"
check 0x50e2a0 101 '?Person_SetAtWork@@YIXPAUPerson@@HHD@Z' --flags "/O2 /TP"
check 0x4a13e0 102 '?SaveGame_NextFreeSlot@@YAHXZ' --flags "/O2 /TP"
check 0x4b0020 102 '?StatisticsBackdrop_UpdateCompanyValues@@YAXPAUWindow@@@Z' --flags "/O2 /TP"
check 0x4dc080 102 '?Mission_ApplySettings@@YIXPAUMission@@@Z' --flags "/O2 /TP"
check 0x500fd0 102 '?RemoveListEntryAt@UI@@QAEXHH@Z' --flags "/O2 /TP"
check 0x522fe0 102 '?RemoveAt@Array@@QAEHH@Z' --flags "/O2 /TP"
check 0x5247f0 102 '?HandleKeyInput@Window@@QAEXH@Z' --flags "/O2 /TP"
check 0x4a7370 103 '?BuildingMarket_BuildSortedIndex@@YAXH@Z' --flags "/O2 /TP" --symbol "?BuildingMarket_Compare@@YAHPBX0@Z=0x4a73e0"
check 0x4f6d30 103 '?Game_CompanyManager_Construct@@YIPAUCompanyManager@@PAU1@@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
