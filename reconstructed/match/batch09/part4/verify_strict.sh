#!/bin/sh
# Strict byte-match verification for batch09/part4.
# Every check passes the manifest length and exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Run from the repository root:
#   sh reconstructed/match/batch09/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4; shift 4
    if python3 tools/match_decomp.py "$address" "reconstructed/match/batch09/part4/$address.c" \
        --length "$length" --entry "$entry" --strict --auto-symbols \
        --flags "$flags" "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x47a540 68 '?SumStatGrid2@StatGrid@@QAEHHH@Z' '/O2 /TP'
check 0x480070 68 @Game_CountObjectsType1DSub19@4 '/O2 /TP' --symbol '?MapRecordToGlobal@GameMap@@QAEHH@Z=0x4d2a60'
check 0x486910 68 '?CountObjectsByState@GameObjectList@@QAEHH@Z' '/O2 /TP' --symbol '?Lookup@IDMap@@QAEPAHHPAH@Z=0x4017f0'
check 0x4c7040 68 '?CharacterSelect_SetPhotoSprite@@YAXPAX@Z' '/O2 /TP' --symbol '?SetButtonSpriteByName@UI@@QAEXHPAD@Z=0x531910'
check 0x4cb8b0 68 '?UI_SetPlayerLogoSprite@@YAXPAXHHH@Z' '/O2 /TP' --symbol '?SetButtonSpriteByName@UI@@QAEXHPAD@Z=0x531910'
check 0x4d1b30 68 '?StreamConstruct@RecipeTopping@@QAEPAU1@PAX@Z' '/O2 /TP' --symbol '?Load@RecipeTopping@@QAEXPAX@Z=0x4d1c20'
check 0x4d3940 68 '?GetOrSumSeries@StatsGrid@@QAEHHH@Z' '/O2 /TP'
check 0x4de670 68 '?GetMaxMatrixValue@GameMatrix@@QAEHH@Z' '/O2 /TP' --symbol '?Max4x9@Matrix4x9@@QAEHXZ=0x47a8e0' --symbol '?SumPlayerMatrixValues@GameMatrix@@QAEHHHPAX@Z=0x4de600'
check 0x4eeef0 68 '?Buffer_FreeLockedGlobal@@YGXPAX@Z' '/O2 /TP'
check 0x4f6dd0 68 '?CompanySlots_Load@AISlots@@QAEXPAX@Z' '/O2 /TP' --symbol '?Read@IStream@@QAEXPAXH@Z=0x54cbc1'
check 0x501980 68 '?GetRandomPlayerRecordValue@PlayerSlots@@QAEHH@Z' '/O2 /TP' --symbol '?Lookup@IDMap@@QAEPAHHPAH@Z=0x4017f0'
check 0x501df0 68 '?Game_GetPlayerStaffBand@@YAHXZ' '/O2 /TP'
check 0x502180 68 '?Stats_ComputeCategory7@@YAHXZ' '/O2 /TP'
check 0x5021d0 68 '?Stats_GetLevelFromFourCounters@@YAHXZ' '/O2 /TP'
check 0x5102f0 68 @Stats_GetMinMapField10@4 '/O2 /TP' --symbol '?Lookup@IDMap@@QAEPAHHPAH@Z=0x4017f0'
check 0x520f30 68 '?BeginScrollAnimation@UI@@QAEXHH@Z' '/O2 /TP' --symbol '?AddEffectObject@UI@@QAEXPAX@Z=0x527c60'
check 0x52f750 68 '?SetButtonColors@Gadget@@QAEXHHHH@Z' '/O2 /TP' --symbol '?GadgetNotify@Window@@QAEXHHHHH@Z=0x52fdd0'
check 0x53d040 68 '?GetRenderSize@Sprite@@QAEXPAI0@Z' '/O2 /TP'
check 0x541290 68 '?SetFreqAndPan@SoundBuffer@@QAEHHH@Z' '/O2 /TP'
check 0x548430 68 '?StopSpeech@Sound@@QAEXH@Z' '/O2 /TP' --symbol '?UpdateVolumeByCitySize@Sound@@QAEXH@Z=0x548350'
check 0x548db0 68 '?StopCurrentBuffer@Sound@@QAEXXZ' '/O2 /TP'
check 0x404760 69 '?ShutdownScreens@@YAXXZ' '/O2 /TP'
check 0x4880c0 69 '?Game_UpdateLoadProgress@@YAHPAUIStream@@H@Z' '/O2 /TP' --symbol '?GetReadPosition@IStream@@QAEHXZ=0x54d2dc' --symbol '?GadgetNotifySliderSetValue@Window@@QAEXHHH@Z=0x52fd70' --symbol '?ProcessMessageQueue@Window@@QAEHH@Z=0x525a10'

echo "strict matches: $pass; failures: $fail"
for known in 0x54f000 0x4edee0; do
    echo "known non-matching: $known (see reconstructed/match/batch09/part4/nonmatching/)"
done
[ "$fail" -eq 0 ]
