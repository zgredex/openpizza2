#!/bin/sh
# Strict byte-match verification for batch07/part1 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168 front end,
# C2.DLL 12.00.8447).  Default flags are /O2; 0x54d921 requires /O1.
# Every check passes the manifest length and the exact entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report
# "strict_match": true.
#
# 0x4d3f90 (Rating_ClampAdjusted) is not matched; its closest candidate is in
# nonmatching/ and fails on LEA operand encoding (see worklog.md).
#
# Usage: sh reconstructed/match/batch07/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch07/part1/$address.c" \
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

check 0x4e42f0 46 '?Construct@BuildingValue@@QAEPAU1@HH@Z' --flags "/O2 /TP"
check 0x4e4340 46 '?ConstructDefault@BuildingValue@@QAEPAU1@H@Z' --flags "/O2 /TP"
check 0x4ed330 46 '?SetTileFieldWithDefault@Map@@QAEXHHI@Z' --flags "/O2 /TP"
check 0x4f34c0 46 '?ComputeCenteredRect@UI@@QAEXPAH00@Z' --flags "/O2 /TP"
check 0x50be00 46 '?StartOrderAction9@Object@@QAEXH@Z' --flags "/O2 /TP"
check 0x50be30 46 '?StartHeadquartersBombing@Courier@@QAEXH@Z' --flags "/O2 /TP"
check 0x50bed0 46 '?SendToBranchForAction@Person@@QAEXPAUWorkSource@@H@Z' --flags "/O2 /TP"
check 0x50e7a0 46 '?CanContinuePath@Person@@QAEHXZ' --flags "/O2 /TP"
check 0x50fb40 46 '?SetDifficulty@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x52e850 46 '?FlushTarget@Renderer@@QAEXH@Z' --flags "/O2 /TP"
check 0x53a110 46 '?RestoreDisplay@Renderer@@QAEXXZ' --flags "/O2 /TP"
check 0x543e90 46 '?QueryFormatType@Sound@@QAEHXZ' --flags "/O2 /TP"
check 0x54a7f0 46 '?MoveToRect@Window@@QAEXPAH@Z' --flags "/O2 /TP"
check 0x402260 47 '@ResourceHandle_Alloc@4' --flags "/O2 /TP"
check 0x403b60 47 '?CompleteEvent@Input@@QAEHH@Z' --flags "/O2 /TP"
check 0x49d280 47 '_UI_RemoveAllObjects' --flags "/O2 /TP"
check 0x4e63f0 47 '?ComputeRecordCompanyPrice@Game@@QAEMH@Z' --flags "/O2 /TP"
check 0x4eab50 47 '?Lookup48@SparseMap@@QAEHH@Z' --flags "/O2 /TP"
check 0x514080 47 '?RemoveRecord@Storage@@QAEXH@Z' --flags "/O2 /TP"
check 0x52fef0 47 '?GetGadgetChecked@Window@@QAEHH@Z' --flags "/O2 /TP"
check 0x5405b0 47 '@Sound_AllocVoice@4' --flags "/O2 /TP"
check 0x548480 47 '?CheckSpeechState@Sound@@QAEXH@Z' --flags "/O2 /TP"
check 0x54d921 47 '?SetBuffer@Stream@@QAEXH@Z' --flags "/O1 /TP"
check 0x483fa0 48 '_Game_MapPlayerStatusToAnimation@4' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
