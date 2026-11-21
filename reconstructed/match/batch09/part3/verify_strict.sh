#!/bin/sh
# Strict byte-match verification for batch09/part3.
# Every check passes the manifest length and exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Run from the repository root:
#   sh reconstructed/match/batch09/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4; shift 4
    if python3 tools/match_decomp.py "$address" "reconstructed/match/batch09/part3/$address.c" \
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

check 0x48f860 66 _BranchInfo_UpdateRatingBars /O2
check 0x4f5c20 66 '?GetViewRect@UIView@@QAEXPAH@Z' '/O2 /TP'
check 0x4f7e80 66 '?Company_HireFreeGuard@@YGHPAX@Z' '/O2 /TP' --symbol '?CountFreeSlots@Game@@QAEHH@Z=0x48a200' --symbol '?FindFreeObjectByType@Game@@QAEHH@Z=0x48a270' --symbol '?AddStaffMember@Company@@QAEXHH@Z=0x4e2080'
check 0x50e6b0 66 '?WalkToCellOrAbort@Person@@QAEHH@Z' '/O2 /TP' --symbol '?AdvanceRoute@Person@@QAEHH@Z=0x507d90' --symbol '?SetState@Object@@QAEXH@Z=0x50e890' --symbol '?ProcessMoveEvent@Person@@QAEXXZ=0x50adf0'
check 0x510340 66 @UI_GetMaxChildField10@4 '/O2 /TP' --symbol '?Lookup@IDMap@@QAEPAHHPAH@Z=0x4017f0'
check 0x532aa0 66 @UI_FreeObjectPairs@4 '/O2 /TP' --symbol '?GetPtr@Array@@QAEPAXH@Z=0x5230b0' --symbol '?Clear@Array@@QAEXXZ=0x522ef0'
check 0x53e140 66 _Surface_SetPixel /O2
check 0x53e190 66 _Tilemap_GetCell /O2
check 0x47e180 67 '?FindRecordByField20@GameWorld@@QAEHH@Z' '/O2 /TP' --symbol '?Lookup@IDMap@@QAEPAHHPAH@Z=0x4017f0'
check 0x47e1d0 67 '?FindObjectByField20@UIObject@@QAEHH@Z' '/O2 /TP' --symbol '?Lookup@IDMap@@QAEPAHHPAH@Z=0x4017f0' --symbol '?Get_Field19F4@UIObject@@QAEHXZ=0x480050'
check 0x480ba0 67 @Game_CountRecordsWithFieldA0@4 '/O2 /TP' --symbol '?MapRecordToGlobal@GameMap@@QAEHH@Z=0x4d2a60'
check 0x4d34e0 67 '?LoadFromStream@Car@@QAEXPAX@Z' '/O2 /TP' --symbol '?Read@IStream@@QAEXPAXH@Z=0x54cbc1' --symbol '?UpdateIDMapEntry@CarManager@@QAEHH@Z=0x4eacd0' --symbol '?LoadSpriteRecord@Car@@QAEXPAX@Z=0x4d3470'
check 0x4e0f40 67 '?HasRecordField14DC@GameRecords@@QAE_NH@Z' '/O2 /TP' --symbol '?Lookup@IDMap@@QAEPAHHPAH@Z=0x4017f0'
check 0x4f57a0 67 '?SetCellObjectFrame@Map@@QAEXHD@Z' '/O2 /TP' --symbol '?DrawObjectWithBounds@UI@@QAEXPAH0@Z=0x4f5990'
check 0x507b40 67 '?WanderToRandomTile@Person@@QAEXXZ' '/O2 /TP' --symbol '?PathToTileAndStep@Person@@QAEXHH@Z=0x5078d0' --symbol '?ApplyRandomTileVariant@Map@@QAEHXZ=0x4d22c0'
check 0x5090e0 67 '?DetachChildRecord@UIChild@@QAEXXZ' '/O2 /TP' --symbol '?ClearFlags48@Record@@QAEXH@Z=0x533a70' --symbol '?SetShort28@Object@@QAEXH@Z=0x4f5c70'
check 0x51fb00 67 '?BeginTileWipeTransition@Screen@@QAEXII@Z' '/O2 /TP' --symbol '?AnimateTileWipe@Screen@@QAEXI@Z=0x51fda0'
check 0x525b70 67 '?SetEntryState22@EventQueue@@QAEXH@Z' '/O2 /TP'
check 0x534d60 67 '?Construct@RectList@@QAEPAU1@PAXHH@Z' '/O2 /TP'
check 0x541ca0 67 '?Sound_GetDeviceCaps@@YAHPAUICaps@@@Z' '/O2 /TP'
check 0x548070 67 '?SetState@Sound@@QAEXH@Z' '/O2 /TP' --symbol '?TriggerSoundById@Sound@@QAEXH@Z=0x548040'
check 0x54b160 67 '?FindFreeBriefing@BriefingMgr@@QAEHXZ' '/O2 /TP' --symbol '?Lookup@IDMap@@QAEPAHHPAH@Z=0x4017f0' --symbol '?GetChannelObject@BriefingMgr@@QAEXHH@Z=0x54acc0'

echo "strict matches: $pass; failures: $fail"
for known in 0x4d31f0 0x4ef0c0 0x505e60; do
    echo "known non-matching: $known (see reconstructed/match/batch09/part3/nonmatching/)"
done
[ "$fail" -eq 0 ]
