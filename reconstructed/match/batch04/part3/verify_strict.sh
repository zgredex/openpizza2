#!/bin/sh
# Strict byte-match verification for batch04/part3 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# All candidates are built as C++ (/TP) so member functions use __thiscall.
# Usage: sh reconstructed/match/batch04/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch04/part3/$address.c" \
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

check 0x4e5dc0 25 '?StreamConstruct@ConstructionOrder@@QAEPAU1@PAX@Z'
check 0x4e5df0 30 '?Game_GetPlayerByte8@@YIEPAD@Z'
check 0x4e5e10 30 '?Game_GetRecordByteC@@YIEPAD@Z'
check 0x4e9d70 30 '?Delete@Game@@QAEPAU1@E@Z'
check 0x4eade0 30 '?Delete@IsoMap@@QAEPAU1@E@Z'
check 0x4ed310 25 '?Array_SetField4Stride12@@YGXPAHHH@Z'
check 0x4edbd0 30 '?Array_CountValid8@@YGHPAD@Z'
check 0x4f12c0 28 '?PickRandomActiveRecord28@Array@@QAEXHHH@Z'
check 0x4f6db0 30 '?Delete@Game_CompanyManager@@QAEPAU1@E@Z'
check 0x5078b0 29 '?SetChildShort8@Object@@QAEXH@Z'
check 0x509290 25 '?AddRecordToPanel@Screen@@QAEXPAD@Z'
check 0x509bf0 25 '?UI_RemoveLastChild@@YIPAXPAD@Z'
check 0x509fa0 27 '?State_Is1A1B1C@@YIHPAD@Z'
check 0x50ab10 26 '?ActivateAndSetState@Object@@QAEXXZ'
check 0x50f690 25 '?StreamConstruct@GamePlan@@QAEPAU1@PAX@Z'
check 0x512730 27 '?HasStock@Product@@QAEHI@Z'
check 0x5144f0 25 '?GetFillPercent@Storage@@QAEHXZ'
check 0x520b40 27 '?SetAbsolutePosition@UI@@QAEXHH@Z'
check 0x520cd0 26 '?Object_EnsureInit@@YIXPAUObject@@@Z'
check 0x520cf0 26 '?UI_ClearPendingCommand@@YIXPAUObject@@@Z'
check 0x520d70 28 '?Buffer_ReleaseField0C@@YIXPAD@Z'
check 0x520e60 29 '?UI_ClearPendingClipFlag@@YIXPAUClipOwner@@@Z'
check 0x521180 27 '?Object_ClearFieldsA@@YIXPAD@Z'
check 0x5230b0 27 '?GetPtr@Array@@QAEPAXH@Z'
check 0x5237e0 27 '?SetChildPosition@UI@@QAEXHH@Z'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
