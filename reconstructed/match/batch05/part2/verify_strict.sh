#!/bin/sh
# Strict byte-match verification for batch05/part2 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch05/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch05/part2/$address.c" \
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

check 0x53f000 30 '@SoundBuffer_Delete@12'
check 0x53f5b0 30 '@SoundSample_Delete@12'
check 0x53fca0 30 '@SoundPakManager_Delete@12'
check 0x540890 30 '@SoundBuffer_DeleteObject@12'
check 0x541730 30 '@SoundBuffer_ScalarDeletingDestructor@12'
check 0x541770 30 '@SoundStreamBuffer_DeleteObject@12'
check 0x541f10 30 '@SoundTrack_Delete@12'
check 0x5427c0 30 '@SoundMixerThread_Delete@12'
check 0x545b00 30 '@List_ContainerDestroy@12'
check 0x546730 30 '@SoundBuffer_Delete2@12'
check 0x548d90 30 '?PlayPoliceSfx@Sound@@QAEXXZ' --flags "/O2 /TP"
check 0x54a8c0 30 '@UI_BriefingList_Delete@12'
check 0x54b620 30 '@EmployeeAvatar_Delete@12'
check 0x54bf50 30 '?SetListenerPosition@Sound@@QAEXNH@Z' --flags "/O2 /TP"
check 0x54dc89 30 '?GetStatus@Stream@@QAEHXZ' --flags "/O1 /TP"
check 0x47fd50 31 '?IncrementVisitCounter@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x485ac0 31 '?GetSpeedSetting@Game@@QAEHXZ' --flags "/O2 /TP"
check 0x488bc0 31 '?FindPlayerSlot@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x4e3dd0 31 '?InitSlotFlags@Player@@QAEXH@Z' --flags "/O2 /TP"
check 0x4e41a0 31 '?CountGroupSlots@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x4f13b0 31 '?HideLinkedElements@Object@@QAEXXZ' --flags "/O2 /TP"
check 0x4f2a80 31 '_IsMenuId351Or355@4'
check 0x4f2aa0 31 '_IsMenuId34EOr350@4'
check 0x4f5fa0 31 '?SearchSet@Array@@QAEXH@Z' --flags "/O2 /TP"
check 0x520fd0 31 '?DispatchCallback@Dispatcher@@QAEXPAX@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
