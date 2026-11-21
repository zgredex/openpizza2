#!/bin/sh
# Strict byte-match verification for batch07/part3 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and the exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch07/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
P=reconstructed/match/batch07/part3
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "$P/$address.c" --length "$length" --entry "$entry" \
        --flags "/O2 /TP" --strict --auto-symbols "$@" \
        >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x4c70b0 49 '?UI_SetMultipleLabels@@YAXPAUUI@@PAH@Z'
check 0x4ed440 49 '?SetScrollPosition@Map@@QAEHHH@Z'
check 0x50be90 49 '?StartWorkOrderAndSetState@Object@@QAEXPAUWorkSource@@HH@Z'
check 0x52ffa0 49 '?ContainsPoint@Rect@@QAEHPAUPoint@@@Z'
check 0x531670 49 '?EnsureChildInitialized@UI@@QAEHH@Z' \
    --symbol '?search@BinarySearch8_t@@QAEHHH@Z=0x531330'
check 0x547300 49 '?SetParam@Sound@@QAEXHH@Z'
check 0x54b2e0 49 '?FindByField34@IDMap_t@@QAEPAURecord@@H@Z'
check 0x4018c0 50 '?Update@IDMap@@QAEXPAH@Z'
check 0x4808c0 50 '?SetMapRenderParams@Game@@QAEXHHHH@Z'
check 0x489b20 50 '?IndexOfListValue@City@@QAEHHHH@Z'
check 0x4d35a0 50 '?DriveToPoint@Car@@QAEXHH@Z'
check 0x4f5730 50 '?AlignSpriteToObject@UI@@QAEXPAH00PAI1@Z'
check 0x4f78e0 50 '?Game_MarkObjectsDirtyForState@@YGXPAUGame@@H@Z'
check 0x508780 50 '?SetRandomResidentialTarget@Object@@QAEXXZ'
check 0x50d710 50 '?BeginServiceDecision@Object@@QAEXPAUState@@@Z'
check 0x50e4e0 50 '?WatchTVProgram@Person@@QAEXXZ'
check 0x50e850 50 '?SetFieldA4Locked@Object@@QAEXH@Z'
check 0x527810 50 '?FindStringRecord@UI@@QAEHPAD@Z'
check 0x534a80 50 '?GetTypeIndex48@RecordTable@@QAEHH@Z'
check 0x537350 50 '?Window_Destroy@@YIXPAPAX@Z'
check 0x53d650 50 '?BlitRLEEnsureFormat@Surface@@QAEXHPAXHH@Z'
check 0x5499b0 50 '?ProcessEventWithCooldown@Sound@@QAEXHD@Z'
check 0x47e6a0 51 '?ApplyBuildingStyleVariant@Branch@@QAEXH@Z'
check 0x4810a0 51 '?SetStageIfHigher@Game@@QAEHH@Z'
check 0x492ae0 51 '?TakeoverScreen_UpdateRatingBars@@YAXPAX@Z'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
