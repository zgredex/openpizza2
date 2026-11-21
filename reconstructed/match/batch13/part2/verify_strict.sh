#!/bin/sh
# Strict byte-match verification for batch13/part2 (16 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Functions not listed here are genuine C/C++ attempts kept under nonmatching/
# with first-diff evidence in worklog.md.
# Usage: sh reconstructed/match/batch13/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch13/part2/$address.c" \
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

check 0x5418c0 103 '?RequestBlock@Stream@@QAEHHHPAHPAI@Z' --flags "/O2 /TP"
check 0x4a1450 104 '?SaveGame_AnyExist@@YAHXZ' --flags "/O2 /TP"
check 0x4e46f0 104 '?DecayCityDateBonus@Game@@QAEXXZ' --flags "/O2 /TP"
check 0x532a30 104 '?AddUniquePair@UI@@QAEXHH@Z' --flags "/O2 /TP"
check 0x4055d0 105 '?Game_ShutdownSubsystems@@YAXXZ' --flags "/O2 /TP"
check 0x47a430 105 '?SumPlayerGrid@Stats@@QAEHHH@Z' --flags "/O2 /TP"
check 0x47c830 105 '?ComputeServiceLevel@City@@QAEHXZ' --flags "/O2 /TP"
check 0x4e3b70 105 '?RestorePlanTargetAnimations@Player@@QAEXXZ' --flags "/O2 /TP"
check 0x50e230 105 '?UpdateBuildingStates@Game@@QAEXXZ' --flags "/O2 /TP"
check 0x5322a0 105 '?GetWindowRect@UI@@QAEXPAURECT@@@Z' --flags "/O2 /TP"
check 0x534060 105 '?GetBounds48@RecordList@@QAEXHPAH0PAI1@Z' --flags "/O2 /TP"
check 0x488d20 106 '?ResumeSimulation@Game@@QAEXXZ' --flags "/O2 /TP"
check 0x4c0ff0 106 '?StorageMenu_Init@@YAXPAX@Z' --flags "/O2 /TP"
check 0x4e1d40 106 '?CountActiveObjectsByType@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x4e3660 106 '?Game_UpgradeProductionLevel@@YIHPAUService@@@Z' --flags "/O2 /TP"
check 0x4fe300 106 '?Company_DispatchWorkerToBranch@@YGHPAUCompany@@PAUBranch@@@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
