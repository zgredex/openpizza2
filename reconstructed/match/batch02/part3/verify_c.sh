#!/usr/bin/env bash
# Verify every matched candidate in this directory against the shipped PE.
# Run from anywhere; the script locates the repository root.
set -u
cd "$(dirname "$0")/../../../.." || exit 1
M=tools/match_decomp.py
P=reconstructed/match/batch02/part3
FLAGS="/O2 /TP"

run() {
    python3 "$M" "$@" --flags "$FLAGS" --strict-symbols
}

echo "== 0x4dca70 City_GetLocalizedName"
run 0x4dca70 $P/0x4dca70.c --length 14 --entry '?City_GetLocalizedName@@YIHPAD@Z' \
    --symbol '?DAT_00582fd8@@3PAHA=0x582fd8'

echo "== 0x4ddcc0 Game_GetPlayerCity"
run 0x4ddcc0 $P/0x4ddcc0.c --length 17 --entry '?Game_GetPlayerCity@@YIHPAD@Z' \
    --symbol '?DAT_0057c670@@3PADA=0x57c670'

echo "== 0x4e4760 Object_SetField0C"
run 0x4e4760 $P/0x4e4760.c --length 10 --entry '?SetField0C@Object@@QAEXH@Z'

echo "== 0x4f0e20 Counter_IncrementShortBA"
run 0x4f0e20 $P/0x4f0e20.c --length 15 --entry '?Counter_IncrementShortBA@@YIFPAD@Z'

echo "== 0x4f5c70 Object_SetShort28"
run 0x4f5c70 $P/0x4f5c70.c --length 12 --entry '?SetShort28@Object@@QAEXF@Z'

echo "== 0x4f5fc0 Object_ClearField28"
run 0x4f5fc0 $P/0x4f5fc0.c --length 8 --entry '?Object_ClearField28@@YIXPAD@Z'

echo "== 0x501b70 Player_AIState_Destroy"
run 0x501b70 $P/0x501b70.c --length 14 --entry '?Player_AIState_Destroy@@YIXPAD@Z' \
    --symbol '?PTR_Player_AIState_Delete_0055c664@@3PAPAXA=0x55c664' \
    --symbol '?List_Node_Destroy@@YIXPAX@Z=0x401480'

echo "== 0x508d40 Object_ApplyPendingType"
run 0x508d40 $P/0x508d40.c --length 16 --entry '?ApplyPendingType@Object@@QAEXH@Z'

echo "== 0x509220 Object_SetChildShort"
run 0x509220 $P/0x509220.c --length 17 --entry '?Object_SetChildShort@@YIXPAD@Z'

echo "== 0x50e4a0 Object_GetChildField2C"
run 0x50e4a0 $P/0x50e4a0.c --length 17 --entry '?Object_GetChildField2C@@YIHPAD@Z'

echo "== 0x50e540 Object_IsState10"
run 0x50e540 $P/0x50e540.c --length 15 --entry '?Object_IsState10@@YIHPAD@Z'

echo "== 0x50e700 Set_Field168"
run 0x50e700 $P/0x50e700.c --length 13 --entry '?SetField168@Object@@QAEXH@Z'

echo "== 0x50e710 Object_SetFlag104"
run 0x50e710 $P/0x50e710.c --length 13 --entry '?SetFlag104@Object@@QAEXD@Z'

echo "== 0x50e720 Object_SetFieldFC"
run 0x50e720 $P/0x50e720.c --length 13 --entry '?SetFieldFC@Object@@QAEXH@Z'

echo "== 0x50e840 Object_Reset108"
run 0x50e840 $P/0x50e840.c --length 16 --entry '?Object_Reset108@@YIXPAD@Z'

echo "== 0x50efb0 Object_SetField8"
run 0x50efb0 $P/0x50efb0.c --length 10 --entry '?SetField8@Object@@QAEXH@Z'

echo "== 0x513fe0 Storage_Destroy"
run 0x513fe0 $P/0x513fe0.c --length 14 --entry '?Storage_Destroy@@YIXPAD@Z' \
    --symbol '?PTR_Storage_Delete_0055c700@@3PAPAXA=0x55c700' \
    --symbol '?List_Node_Destroy@@YIXPAX@Z=0x401480'

echo "== 0x514320 Storage_GetCapacity"
run 0x514320 $P/0x514320.c --length 11 --entry '?Storage_GetCapacity@@YIHPAD@Z'

echo "== 0x521380 UI_RealizeSprite"
run 0x521380 $P/0x521380.c --length 11 --entry '?UI_RealizeSprite@@YIXPAUUI@@@Z' \
    --symbol '?FillTransparentColor@Sprite@@QAEXH@Z=0x53d6c0'

echo "== 0x521b30 UI_ClipChildRect"
run 0x521b30 $P/0x521b30.c --length 15 --entry '?UI_ClipChildRect@@YIXPAUUI@@@Z' \
    --symbol '?ClipRect@Renderer@@QAEXPAHH@Z=0x5321f0'

echo "== 0x522e60 Atexit_RegisterListCritSectDtor"
run 0x522e60 $P/0x522e60.c --length 12 --entry '?Atexit_RegisterListCritSectDtor@@YAXXZ' \
    --symbol '?dtor_00522e70@@YAXXZ=0x522e70' \
    --symbol '?_atexit@@YAHP6AXXZ@Z=0x54dea3'

echo "== 0x526cf0 Set_Field228"
run 0x526cf0 $P/0x526cf0.c --length 13 --entry '?SetField228@Object@@QAEXH@Z'

echo "== 0x526d00 Clear_Field228"
run 0x526d00 $P/0x526d00.c --length 11 --entry '?Clear_Field228@@YIXPAD@Z'

echo "== 0x5272c0 UI_GetTextObject"
run 0x5272c0 $P/0x5272c0.c --length 11 --entry '?UI_GetTextObject@@YIXPAD@Z' \
    --symbol '?Renderer_GetTextObject@@YIXPAX@Z=0x52e8e0'

echo "== 0x527940 UI_SetWindowProc"
run 0x527940 $P/0x527940.c --length 13 --entry '?SetWindowProc@Object@@QAEXH@Z'
