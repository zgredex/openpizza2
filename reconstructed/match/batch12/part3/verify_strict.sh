#!/bin/sh
# Strict byte-match verification for batch12/part3 (23 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# 0x478140 (City_GetProductPriceLevel) is not included: its best genuine
# C attempt differs in 2 bytes (scratch register of the table index); see
# nonmatching/0x478140.notes.md.
# 0x4dd090 (Game_RebuildLocalRecordOwners) is not included: MSVC assigns the
# callee-saved registers in a different order; see
# nonmatching/0x4dd090.notes.md.
# Usage: sh reconstructed/match/batch12/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch12/part3/$address.c" \
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

check 0x47fe70 94 '?HideBuildingOverlay@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x489b60 94 '?AdvanceAnimFrame@Anim@@QAEXXZ' --flags "/O2 /TP"
check 0x48a270 94 '?FindFreeObjectByType@Game@@QAEPAXH@Z' --flags "/O2 /TP"
check 0x48e000 94 '?IsPlayerBestInStat@Game@@QAEHPAPAHHH@Z' --flags "/O2 /TP"
check 0x5142c0 94 '?ReceivePendingOrder@Storage@@QAEHH@Z' --flags "/O2 /TP"
check 0x4783c0 95 '?GetPriceRating@Branch@@QAEHH@Z' --flags "/O2 /TP"
check 0x47e860 95 '?StepToNeighborCell@AI@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x486b80 95 '?CountUnassignedObjectsByClass@Game@@QAEHHD@Z' --flags "/O2 /TP"
check 0x488cc0 95 '?SuspendSimulation@Game@@QAEXXZ' --flags "/O2 /TP"
check 0x5052e0 95 '?Save@Person@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x507170 95 '?Person_DebugPrintLocation@@YIXPAX@Z' --flags "/O2 /TP"
check 0x53d6c0 95 '?FillTransparentColor@Sprite@@QAEXH@Z' --flags "/O2 /TP"
check 0x47ffb0 96 '?GetBuildingConditionCode@Game@@QAEHXZ' --flags "/O2 /TP"
check 0x528510 96 '?ScrollChildByVelocity@UI@@QAE_NHH@Z' --flags "/O2 /TP"
check 0x534c30 96 '?SetListEntryPosition@UI@@QAEXHN@Z' --flags "/O2 /TP"
check 0x539ea0 96 '?CreateChild@Renderer@@QAEPAURendererChild@@XZ' \
    --flags "/O2 /TP /GX"
check 0x401190 97 '?Load@StatsPeriodReport@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x401200 97 '?Save@StatsPeriodReport@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x4781e0 97 '?ComputeRecordMapPercent@Game@@QAEHXZ' --flags "/O2 /TP"
check 0x538a80 97 '?Destroy@Renderer@@QAEXXZ' --flags "/O2 /TP"
check 0x47e8c0 98 '?CancelConstructionAt@Branch@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x4f5cd0 98 '?IsCarSpawnCellFree@CityView@@QAEHPAX@Z' --flags "/O2 /TP"
check 0x50ad80 98 '?MoveTypeBObjectsToStateList@Game@@QAEXPAX@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
