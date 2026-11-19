// rea decompile_all
// name: Object_UpdateCustomerQueue
// address: 0x409d80
// body: available
// range: 0x409d80-0x40a2fb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateCustomerQueue(void *this,void *param_1,void *param_2)

{
  void *this_00;
  void *pvVar1;
  undefined1 uVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  uint extraout_EDX;
  float10 fVar8;
  
                    /* Updates a customer-queue object's path and target. */
  pvVar1 = param_1;
  *(short *)((int)param_1 + 0x16e8) = *(short *)((int)param_1 + 0x16e8) + 1;
  iVar3 = IDMap_Lookup((void *)((int)this + 0x20),*(int *)((int)param_2 + 0x50),(int *)0x0);
  uVar2 = Object_IsVisibleThisFrame((int)param_2);
  pvVar7 = *(void **)((int)param_2 + 0xc4);
  if (CONCAT31(extraout_var,uVar2) != 0) {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 8:
      Person_ProcessMoveEvent(param_2);
      return;
    default:
      return;
    case 10:
      iVar3 = Person_ProcessMoveEvent(param_2);
      if (iVar3 != 0) {
        return;
      }
      pvVar7 = *(void **)((int)param_1 + 0x1758);
      if (0 < (int)pvVar7) {
        if ((int)*(void **)((int)param_2 + 0x98) < (int)pvVar7) {
          pvVar7 = *(void **)((int)param_2 + 0x98);
        }
        if (0 < (int)pvVar7) {
          this_00 = (void *)((int)param_1 + 0x1744);
          param_1 = pvVar7;
          do {
            iVar3 = IDMap_Lookup(this_00,0,(int *)0x0);
            iVar3 = IDMap_Lookup((void *)((int)this + 0x3c),iVar3,(int *)0x0);
            if (iVar3 != 0) {
              Screen_AddRecordToPanel(param_2,iVar3);
            }
            IDMap_RemoveRecursive(this_00,0);
            param_1 = (void *)((int)param_1 + -1);
          } while (param_1 != (void *)0x0);
        }
      }
      iVar3 = AdCampaign_GoToNextQueuedBuilding(this,(int)pvVar1,param_2);
      if (iVar3 != 0) {
        return;
      }
      iVar3 = AdCampaign_GoToNearestOwnBuilding(pvVar1,param_2);
      if (iVar3 == 0) {
        *(short *)((int)pvVar1 + 0x16e0) = *(short *)((int)pvVar1 + 0x16e0) + 1;
        return;
      }
      return;
    case 0xc:
      if (*(int *)((int)param_2 + 0x94) != -1) {
        iVar3 = *(int *)((int)param_2 + 0x94) + -1;
        *(int *)((int)param_2 + 0x94) = iVar3;
        if (iVar3 == 0) {
          pvVar7 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),
                                        (int *)0x0);
          UI_SetChildState(pvVar7,5);
          Game_GetTimeByMode(pvVar7,4);
          Object_SetFrame5(param_2,-1);
          Screen_AddRecordToPanel(param_2,(int)pvVar7);
          Customer_ApproachBranchEntrance(param_1,param_2);
          return;
        }
        return;
      }
      iVar3 = IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),(int *)0x0);
      if (*(int *)(iVar3 + 0x38) == 0xb) {
        return;
      }
      break;
    case 0xf:
      iVar3 = IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),(int *)0x0);
      if (*(int *)(iVar3 + 0x38) == 0xb) {
        return;
      }
      Object_AdvanceToQueuedTarget(this,param_1,param_2);
      return;
    case 0x10:
      iVar3 = *(int *)((int)param_2 + 0x94) + -1;
      *(int *)((int)param_2 + 0x94) = iVar3;
      if (iVar3 != 0) {
        return;
      }
      IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),(int *)0x0);
      iVar3 = Game_FindRecordByField10(param_1,*(int *)((int)param_2 + 0x10c));
      if (iVar3 != 0) {
        Stats_AddRecordValue(param_1,*(int *)(iVar3 + 0x2c),*(float *)(iVar3 + 0x1c),-1);
      }
      pvVar7 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),
                                    (int *)0x0);
      UI_SetChildState(pvVar7,0xffff);
      Object_SetState(pvVar7,0x11);
      UI_SetChildRecordVariant(pvVar7,*(int *)((int)pvVar7 + 0x84) + 0x14);
      UI_SetChildState(pvVar7,9);
      Game_GetTimeByMode(pvVar7,6);
      iVar3 = *(int *)((int)param_1 + 0x30);
      iVar5 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
      if (iVar3 == iVar5) {
        if (*(int *)((int)pvVar7 + 0x30) == 0xf) {
          MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),7,-1,-1);
          MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x12,-1,-1);
        }
        UI_AppendCommandIfActive(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x15,1);
        MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x15,-1,-1);
      }
      Object_SetFrame5(param_2,-1);
      UI_SetChildState(param_2,0xffff);
      Object_AdvanceToQueuedTarget(this,param_1,param_2);
      return;
    case 0x25:
      Person_TruncatePathToCurrentStep((int)param_2);
      return;
    }
    goto LAB_0040a11f;
  }
  switch(*(undefined4 *)((int)param_2 + 0x38)) {
  case 5:
    piVar4 = Map_LinkNeighbors(pvVar7,param_1);
    iVar5 = Array_GetRecord28(pvVar7,1,(int)*(short *)(*(int *)(*(int *)((int)pvVar7 + 0x4c) + 8 +
                                                               *piVar4 * 0xc) + 0x24));
    if (iVar5 == 0) {
      Object_SetState(param_2,6);
      return;
    }
    iVar6 = Rating_AdjustA(iVar3);
    fVar8 = Game_GetRatingMultiplier((int)param_1);
    UI_SetChildScale(param_2,(double)(fVar8 * (float10)iVar6));
    iVar3 = Rating_GetComposite(iVar3);
    *(int *)((int)param_2 + 0x98) = (iVar3 >> 4) + 1;
    _DAT_0057c610 = Person_WalkToCellOrAbort(param_2,iVar5);
    if (_DAT_0057c610 != 0) {
      *(int *)((int)param_2 + 0x88) = *piVar4;
      Object_SetState(param_2,8);
      return;
    }
    break;
  case 6:
    iVar3 = Array_GetRandomRecord28((int)pvVar7);
    if (iVar3 != 0) {
      Person_AdvanceRoute(param_2,iVar3);
      Object_SetState(param_2,7);
      return;
    }
    break;
  case 7:
    List_Node_Reset((int)param_2 + 0x114);
    Person_LeaveBuildingAndReset(param_2);
    Person_SetAtWork((int)param_2,extraout_EDX,(int)param_1,'\x01');
    return;
  case 8:
    UI_SetChildRecordVariant(param_2,0x32);
    Object_SetState(param_2,10);
    Game_MoveTypeBObjectsToStateList(param_2,param_1);
    return;
  default:
    Person_ResumeRouteOrDetach(param_2);
    return;
  case 0xc:
    pvVar7 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),
                                  (int *)0x0);
    if (*(int *)((int)pvVar7 + 0x38) == 0xb) {
      iVar3 = Building_MapSubtypeToState(*(undefined4 *)((int)pvVar7 + 0x84));
      UI_SetChildRecordVariant(param_2,iVar3 + 0x18);
      UI_SetChildState(pvVar7,0xffff);
      Object_SetFrame5(param_2,5);
      return;
    }
    goto LAB_0040a11f;
  case 0xf:
    pvVar7 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),
                                  (int *)0x0);
    if (*(int *)((int)pvVar7 + 0x38) == 0xb) {
      Object_SetState(param_2,0x10);
      UI_SetChildState(pvVar7,7);
      UI_SetChildState(param_2,7);
      Object_SetFrame5(param_2,2);
      Sound_HandleEvent(DAT_0057ba0c,(int)param_1,0x31);
      if (*(int *)((int)param_2 + 0x128) < 1) {
        iVar3 = Building_MapSubtypeToState(*(undefined4 *)((int)pvVar7 + 0x84));
        UI_SetChildRecordVariant(param_2,iVar3 + 0x28);
        return;
      }
      iVar3 = Building_MapSubtypeToState(*(undefined4 *)((int)pvVar7 + 0x84));
      UI_SetChildRecordVariant(param_2,iVar3 + 0x20);
      return;
    }
LAB_0040a11f:
    Customer_ApproachBranchEntrance(param_1,param_2);
    return;
  case 0x25:
    Object_SetState(param_2,6);
    UI_SetChildState(param_2,0x1d);
    return;
  }
  return;
}

