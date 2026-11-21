#!/bin/sh
# Re-run the byte match for every record of batch01/part1.
# Usage: sh reconstructed/match/batch01/part1/verify.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
fail=0
check() {
    address=$1; length=$2; source=$3; shift 3
    if $M "$address" "$source" --length "$length" "$@" >/tmp/part1-match.json 2>&1; then
        echo "MATCH $address"
    else
        echo "FAIL  $address"
        cat /tmp/part1-match.json
        fail=1
    fi
}

check 0x401020 30 reconstructed/match/batch01/part1/0x401020.c \
  --entry '@StatsPeriodReport_Delete@12' \
  --symbol '@StatsPeriodReport_Destroy@4=0x401270' --symbol _Mem_Free=0x54dd78

check 0x401a20 204 reconstructed/match/batch01/part1/0x401a20.c --flags "/O2 /TP" \
  --entry _ResourceManager_Destruct \
  --symbol _pc2_fclose=0x54dee4 --symbol _pc2_free=0x54dd78 \
  --symbol _NamedLockable_Destroy=0x401300

check 0x477c80 440 reconstructed/match/batch01/part1/0x477c80.c --flags "/O2 /TP" \
  --entry _Stats_AddRecordValue \
  --symbol _DAT_0057c670=0x57c670 --symbol _ext_55c318=0x55c318 \
  --symbol _ext_55c310=0x55c310 --symbol _Stats_FindRecordByType=0x477c20 \
  --symbol _Game_GetCurrentPlayerCompanyName=0x482820 \
  --symbol _UI_AppendCommandIfActive=0x503250 \
  --symbol _MissionGoal_HandleEvent=0x502f10 \
  --symbol _Game_GetPlayerBySlot=0x488be0 \
  --symbol _Player_ResetDebtHours=0x4e3be0 \
  --symbol _Game_GetTimeSegment=0x488d90 \
  --symbol _Sound_UpdateListener=0x54bf70 \
  --symbol _UI_QueueControlCommand=0x5301c0 --symbol _pc2_ftol=0x54f140

check 0x48c1c0 92 reconstructed/match/batch01/part1/0x48c1c0.c \
  --entry '_Object_AbortOrderForTarget@12' \
  --symbol '@State_Is2DOr2E@4=0x50dbd0' \
  --symbol '@Object_AbortOrderAndReturnHome@4=0x50bc40'

check 0x498a70 352 reconstructed/match/batch01/part1/0x498a70.c --flags "/O2 /TP" \
  --entry _SaveGame_ScanSaveFileList \
  --symbol _DAT_0057ca04=0x57ca04 --symbol _pc2_new=0x54e221 \
  --symbol _List_Construct=0x4013a0 --symbol _String_Format=0x54dd83 \
  --symbol _pc2_strrchr=0x54e010 --symbol _UI_ListEntry_Construct=0x403370 \
  --symbol _List_Add=0x4014b0 --symbol _CRT_FindFirst=0x54f3d0 \
  --symbol _CRT_FindNext=0x54f49d --symbol _CRT_FindClose=0x54f565

check 0x49b720 352 reconstructed/match/batch01/part1/0x49b720.c --flags "/O2 /TP" \
  --entry _SaveMenu_ScanMenuFileList \
  --symbol _DAT_0057ca8c=0x57ca8c --symbol _pc2_new=0x54e221 \
  --symbol _List_Construct=0x4013a0 --symbol _String_Format=0x54dd83 \
  --symbol _pc2_strrchr=0x54e010 --symbol _UI_ListEntry_Construct=0x403370 \
  --symbol _List_Add=0x4014b0 --symbol _CRT_FindFirst=0x54f3d0 \
  --symbol _CRT_FindNext=0x54f49d --symbol _CRT_FindClose=0x54f565

check 0x4a6c20 806 reconstructed/match/batch01/part1/0x4a6c20.c --flags "/O2 /TP" \
  --entry _SubMenu_UpdateMenuPlanPage \
  --symbol _DAT_0057c670=0x57c670 --symbol _ext_55c4b8=0x55c4b8 \
  --symbol _DAT_0056938c=0x56938c --symbol _DAT_005691a4=0x5691a4 \
  --symbol _DAT_005691bc=0x5691bc --symbol _DAT_005691d4=0x5691d4 \
  --symbol _DAT_00583544=0x583544 --symbol _DAT_005822c8=0x5822c8 \
  --symbol _DAT_0058235c=0x58235c --symbol _DAT_00582344=0x582344 \
  --symbol _DAT_00582334=0x582334 --symbol _DAT_00582318=0x582318 \
  --symbol _DAT_00582488=0x582488 --symbol _DAT_00582480=0x582480 \
  --symbol _DAT_00582478=0x582478 --symbol _IDMap_Lookup=0x4017f0 \
  --symbol _CountObjectsByState=0x486910 --symbol _String_Format=0x54dd83 \
  --symbol _TextSetText=0x52f9b0 --symbol _Slider_SetValue=0x52fd70 \
  --symbol _RemoveObjectByKey=0x531740 --symbol _ShowChildByID=0x5316b0 \
  --symbol _GetWindowObject=0x531cf0 --symbol _GetPairByKey=0x5314a0 \
  --symbol _AddSprite=0x531850 --symbol _SetObjectTextByKey=0x531f50 \
  --symbol _CollectVacantLots=0x48c340 --symbol _Gadget_SetTextf=0x52f080 \
  --symbol _pc2_ftol=0x54f140

check 0x4aa740 546 reconstructed/match/batch01/part1/0x4aa740.c --flags "/O2 /TP" \
  --entry _StatisticsBalance_UpdateBranchList \
  --symbol _DAT_0057c670=0x57c670 --symbol _DAT_0057d5c8=0x57d5c8 \
  --symbol _DAT_00569354=0x569354 --symbol _DAT_0057dfbc=0x57dfbc \
  --symbol _DAT_00569358=0x569358 --symbol _DAT_005819f8=0x5819f8 \
  --symbol _DAT_00582e4c=0x582e4c --symbol _DAT_0056935c=0x56935c \
  --symbol _DAT_0056937c=0x56937c --symbol _DAT_0056939c=0x56939c \
  --symbol _DAT_0057d574=0x57d574 --symbol _DAT_0057d578=0x57d578 \
  --symbol _s_fmt_percent=0x5688b0 --symbol _ButtonSetState=0x52ff50 \
  --symbol _TextSetText=0x52f9b0 --symbol _String_Format=0x54dd83 \
  --symbol _SetChildVisibleByID=0x5316f0 --symbol _IDMap_Lookup=0x4017f0 \
  --symbol _RemoveObjectByKey=0x531740 --symbol _ShowChildByID=0x5316b0

check 0x4b1f40 745 reconstructed/match/batch01/part1/0x4b1f40.c --flags "/O2 /TP" \
  --entry _PersonnelPlan_LayoutEmployeeList \
  --symbol _jt_4b222c=0x4b222c --symbol _IDMap_Lookup=0x4017f0 \
  --symbol _CountObjectsByType=0x47aac0 --symbol _RemoveObjectByKey=0x531740 \
  --symbol _GetRecordByKeyPtr=0x52ff20 --symbol _UI_RemoveObject=0x5311a0 \
  --symbol _ShowChildByID=0x5316b0 --symbol _GetPairByKey=0x5314a0 \
  --symbol _GetButtonSprite=0x531980 --symbol _Slider_SetRange=0x52fd00 \
  --symbol _Slider_SetValue=0x52fd70 --symbol _CreateMovieWindow=0x5317b0 \
  --symbol _GetFieldF0=0x5312e0 --symbol _MoveElementToIndex=0x531d10 \
  --symbol _SetField14ByKey=0x531470

check 0x4ce450 437 reconstructed/match/batch01/part1/0x4ce450.c --flags "/O2 /TP" \
  --entry _FreePlaySubmenu_InitSaveGamePage \
  --symbol _DAT_00582464=0x582464 --symbol _DAT_00581ac0=0x581ac0 \
  --symbol _DAT_0057df88=0x57df88 --symbol _DAT_0057df8c=0x57df8c \
  --symbol _DAT_00581ab4=0x581ab4 --symbol _pc2_new=0x54e221 \
  --symbol _UI_SetPosition=0x532310 --symbol _Text_SetText=0x52f9b0 \
  --symbol _List_Construct=0x4013a0 --symbol _SaveGame_Scan=0x4a1940 \
  --symbol _RemoveObjectByKey=0x531740 --symbol _Slider_SetRange=0x52fd00 \
  --symbol _Slider_SetValue=0x52fd70 --symbol _Slider_SetChangeNotify=0x52fce0 \
  --symbol _UI_ListEntry_Construct=0x403370 --symbol _List_Add=0x4014b0 \
  --symbol _FillSaveGameRows=0x4ce3c0

check 0x4cf690 898 reconstructed/match/batch01/part1/0x4cf690.c --flags "/O2 /TP" \
  --entry '?RestaurantInfoPanel_UpdateTabButtons@@YAXPAXH@Z' \
  --symbol _DAT_0057c670=0x57c670 \
  --symbol '?ClearAll@UIManager@@QAEXXZ=0x532520' \
  --symbol '?CreateGroup@UIManager@@QAAXHHHZZ=0x532330' \
  --symbol '?ButtonSetState@UIManager@@QAEXHH@Z=0x52ff50' \
  --symbol '?ToggleObjectActive@UIManager@@QAEXHH@Z=0x531620' \
  --symbol '?SetChildVisibleByID@UIManager@@QAEXHH@Z=0x5316f0' \
  --symbol '?RemoveObjectByKey@UIManager@@QAEXH@Z=0x531740' \
  --symbol '?GetCurrentPlayerCompanyName@Game@@QAEHXZ=0x482820' \
  --symbol '?CountObjectsByType@Game@@QAEHH@Z=0x47aac0' \
  --symbol '?Lookup@IDMap@@QAEPAXHPAH@Z=0x4017f0'

check 0x4d3710 30 reconstructed/match/batch01/part1/0x4d3710.c \
  --entry '@Character_Delete@12' \
  --symbol '@Character_Destroy@4=0x4d3f80' --symbol _Mem_Free=0x54dd78

check 0x4dc540 286 reconstructed/match/batch01/part1/0x4dc540.c --flags "/O2 /TP" \
  --entry _Object_SetFacadeAndLogoVariant \
  --symbol _DAT_0057c670=0x57c670 --symbol _CS_Enter=0x401320 \
  --symbol _CS_Leave=0x401340 --symbol _Game_FindCityIndex=0x4e2250 \
  --symbol _String_Find=0x54e170 --symbol _Record_SelectVariant=0x533aa0 \
  --symbol _Record_ClearFlags48=0x533a70

check 0x4dd6b0 530 reconstructed/match/batch01/part1/0x4dd6b0.c --flags "/O2 /TP" \
  --entry _Company_ConstructDefault \
  --symbol _DAT_0057c670=0x57c670 --symbol _pc2_new=0x54e221 \
  --symbol _List_Construct=0x4013a0 --symbol _List_Add=0x4014b0 \
  --symbol _Stats_Report_Construct=0x401040 --symbol _GamePlan_Construct=0x50f630 \
  --symbol _Game_SetDifficulty=0x50fb40

check 0x4e4320 30 reconstructed/match/batch01/part1/0x4e4320.c \
  --entry '@BuildingValue_Delete@12' \
  --symbol '@BuildingValue_Destroy@4=0x4e4390' --symbol _Mem_Free=0x54dd78

check 0x4ecd70 662 reconstructed/match/batch01/part1/0x4ecd70.c --flags "/O2 /TP" \
  --entry _MapActor_ReadFromStream \
  --symbol _DAT_0057c668=0x57c668 --symbol _imp_SetRect=0x55c280 \
  --symbol _Read=0x54cbc1 --symbol _SetDoubles48=0x5342e0 \
  --symbol _SetDoubles48B=0x5335b0 --symbol _SetShort28=0x4f5c70 \
  --symbol _Clear=0x54b3c0 --symbol _Grow=0x54b3d0 \
  --symbol _FindRecord=0x4f0c60 --symbol _ClearActive48=0x533c60 \
  --symbol _SelectVariant=0x533aa0

check 0x4f2ac0 158 reconstructed/match/batch01/part1/0x4f2ac0.c --flags "/O2 /TP" \
  --entry '?Grid_CollectFootprintCellsAtCell@@YAXXZ' \
  --symbol _DAT_0057c670=0x57c670 --symbol _pc2_new=0x54e221 \
  --symbol _Map_FindIndex=0x401900 \
  --symbol _ConstructionOrder_Construct=0x4e5d60 \
  --symbol _Grid_CollectFootprintCells=0x4f2b60

check 0x4fecc0 367 reconstructed/match/batch01/part1/0x4fecc0.c --flags "/O2 /TP" \
  --entry '?AI_UpdateAdvertisingCampaigns@@YIHPAXHH@Z' \
  --symbol _DAT_0057c670=0x57c670 --symbol _DAT_0057bb24=0x57bb24 \
  --symbol _DAT_00580f04=0x580f04 --symbol _DAT_005816b4=0x5816b4 \
  --symbol _DAT_00581ab8=0x581ab8 --symbol _DAT_00582984=0x582984 \
  --symbol '?GetPlayerCount@Game@@QAEHXZ=0x482720' \
  --symbol '?GetPlayerBySlot@Game@@QAEPAXH@Z=0x488be0' \
  --symbol '?ComputeNetStatTotal@Player@@QAENXZ=0x4e3780' \
  --symbol '?InitSlotFlags@Player@@QAEXH@Z=0x4e3dd0' \
  --symbol '?StopCampaign@Player@@QAEXHHH@Z=0x4e3d80' \
  --symbol _UI_Briefing_Printf=0x48bf90 --symbol __ftol=0x54f140

check 0x509060 57 reconstructed/match/batch01/part1/0x509060.c \
  --entry '@UI_SetChildRecordVariant@12' \
  --symbol '@Record_SelectVariant@16=0x533aa0'

check 0x51ef80 651 reconstructed/match/batch01/part1/0x51ef80.c --flags "/O2 /TP" \
  --entry _UI_Image_Construct \
  --symbol _UI_Child_Construct=0x520a80 --symbol _pc2_strchr=0x54efd0 \
  --symbol _pc2_atoi=0x54e157 --symbol _String_Format=0x54dd83 \
  --symbol _Window_LoadSpriteCached=0x527580 \
  --symbol _Sprite_GetHotspot=0x53d100 \
  --symbol _Sprite_GetSize=0x53d090 \
  --symbol _UI_SetAbsolutePosition=0x520b40

check 0x5235b0 551 reconstructed/match/batch01/part1/0x5235b0.c --flags "/O2 /TP" \
  --entry _UI_Manager_Destroy \
  --symbol _DAT_0057c5c8=0x57c5c8 --symbol _imp_55c250=0x55c250 \
  --symbol _imp_55c0a8=0x55c0a8 --symbol _imp_55c08c=0x55c08c \
  --symbol _pc2_free=0x54dd78 --symbol _DecrementRowCounter=0x5277d0 \
  --symbol _SetBackgroundSurfaceEnabled=0x526e80 \
  --symbol _ReleasePendingSprite=0x527a50 \
  --symbol _CompactEmpty48=0x527850 --symbol _NoOp_Stub=0x48e0a0 \
  --symbol _Movie_ReleasePlayer=0x5238c0 --symbol _RefPtr_Release=0x51ea00 \
  --symbol _Object_GetRootType=0x539f00 --symbol _ImageCache_Clear=0x527250 \
  --symbol _Array_Destroy=0x522f20 --symbol _NamedLockable_Destroy=0x401300

check 0x5316b0 49 reconstructed/match/batch01/part1/0x5316b0.c \
  --entry '@UI_ShowChildByID@12' \
  --symbol '@BinarySearch8@16=0x531330' \
  --symbol '@UI_Child_Activate@4=0x520e30'

check 0x532330 196 reconstructed/match/batch01/part1/0x532330.c --flags "/O2 /TP" \
  --entry _UI_Group_Create --symbol _pc2_new=0x54e221 \
  --symbol _Array_Construct=0x522e80 \
  --symbol _Array_InsertGrow=0x522f40 \
  --symbol _UI_Group_ApplyMemberSelection=0x532620

check 0x532c40 1739 reconstructed/match/batch01/part1/0x532c40.c --flags "/O2 /TP" \
  --entry _Anim_Load --symbol _SpriteBase_Construct=0x53a1e0 \
  --symbol _CRT_Fopen=0x54dfe0 --symbol _NoOp_Stub=0x48e0a0 \
  --symbol _CRT_FreadLocked=0x54e978 --symbol _pc2_new=0x54e221 \
  --symbol _Record_CopyTemplate98=0x533310 \
  --symbol _Resource_Open=0x402290 --symbol _Resource_Read=0x402750 \
  --symbol _Resource_Close=0x402990 --symbol _Stream_Seek=0x540000 \
  --symbol _Palette_Init=0x535d70 --symbol _pc2_fclose=0x54dee4

check 0x53cf40 244 reconstructed/match/batch01/part1/0x53cf40.c --flags "/O2 /TP" \
  --entry _Sprite_Destruct --symbol _pc2_free=0x54dd78 \
  --symbol _Palette_Free=0x535e10 \
  --symbol _SpriteBase_Destructor=0x53a210

exit $fail
