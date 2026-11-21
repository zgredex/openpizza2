#!/bin/sh
# Strict byte-match verification for batch08/part2 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch08/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4; file=$5; shift 5
    if $M "$address" "$file" --length "$length" --entry "$entry" \
        --strict --auto-symbols --flags "$flags" "$@" \
        >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

D=reconstructed/match/batch08/part2
check 0x4ddce0 55 '?FindRecordByField4@Game@@QAEHH@Z' "/O2 /TP" $D/0x4ddce0.c
check 0x4ddd20 55 '?InvalidateAllBranchRatings@Company@@QAEXXZ' "/O2 /TP" $D/0x4ddd20.c
check 0x4e2330 55 '?FindRecordByField34@Game@@QAEHH@Z' "/O2 /TP" $D/0x4e2330.c
check 0x4e3460 55 '?SetOnMenu@Recipe@@QAEXHE@Z' "/O2 /TP" $D/0x4e3460.c
check 0x4ead50 55 '?HideAllLinkedElements@Game@@QAEXXZ' "/O2 /TP" $D/0x4ead50.c
check 0x4ef4b0 55 '?GetCell@Grid@@QAEPAXHH@Z' "/O2 /TP" $D/0x4ef4b0.c
check 0x5273c0 55 '_SpriteCache_MakeKey@8' "/O2" $D/0x5273c0.c
check 0x531740 55 '?RemoveObjectByKey@UI@@QAEHH@Z' "/O2 /TP" $D/0x531740.c \
    --symbol '?BinarySearch8@UI@@QAEHHD@Z=0x531330'
check 0x532850 55 '?PurgeChildFromLists@UI@@QAEXH@Z' "/O2 /TP" $D/0x532850.c
check 0x53f840 55 '_SoundFormat_Init@4' "/O2" $D/0x53f840.c
check 0x5414e0 55 '_Input_GetDeviceObjectInfo' "/O2" $D/0x5414e0.c
check 0x549970 55 '?ProcessEventForSelectedObject@Sound@@QAEXHHHD@Z' "/O2 /TP" $D/0x549970.c
check 0x402990 56 '?Close@Resource@@QAEXH@Z' "/O2 /TP" $D/0x402990.c
check 0x403750 56 '_String_RegisterSlot' "/O2" $D/0x403750.c
check 0x48e060 56 '?HasIdleOtherPlayer@Game@@QAEDXZ' "/O2 /TP" $D/0x48e060.c
check 0x4dd050 56 '?RemoveRecordFromAllLocalMaps@Game@@QAEXPAX@Z' "/O2 /TP" $D/0x4dd050.c
check 0x4dd670 56 '?Destroy@GameClock@@QAEXXZ' "/O2 /TP" $D/0x4dd670.c \
    --symbol '__imp__Sleep@4=0x55c08c'
check 0x4e43a0 56 '?SetHQLevel@Game@@QAEXH@Z' "/O2 /TP" $D/0x4e43a0.c
check 0x500030 56 '?UpdateAllSlots@UI@@QAEXXZ' "/O2 /TP" $D/0x500030.c
check 0x5043f0 56 '?DecrementTimer@UI@@QAEXHD@Z' "/O2 /TP" $D/0x5043f0.c
check 0x52e530 56 '?Destroy@UI_Tooltip@@QAEXXZ' "/O2 /TP" $D/0x52e530.c
check 0x540260 56 '?Close@SoundStream@@QAEXH@Z' "/O2 /TP" $D/0x540260.c \
    --symbol '__imp__EnterCriticalSection@4=0x55c1b8' \
    --symbol '__imp__LeaveCriticalSection@4=0x55c1a0'
check 0x547230 56 '_Sound_ClampGlobalLimits' "/O2" $D/0x547230.c
check 0x54b930 56 '_IDMap_DeleteContents@4' "/O2 /TP" $D/0x54b930.c

echo "strict $pass/$((pass + fail)) (+1 nonmatching record)"
[ "$fail" -eq 0 ]
