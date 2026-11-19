// rea decompile_all
// name: Object_UpdateConstructionWorker
// address: 0x40a760
// body: available
// range: 0x40a760-0x40ac64 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateConstructionWorker(void *this,void *param_1,void *param_2)

{
  void *this_00;
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 unaff_SI;
  undefined4 unaff_EDI;
  float10 fVar8;
  
                    /* Updates a construction worker's plot and work state. */
  *(short *)((int)param_1 + 0x16ea) = *(short *)((int)param_1 + 0x16ea) + 1;
  iVar3 = IDMap_Lookup((void *)((int)this + 0x20),*(int *)((int)param_2 + 0x50),(int *)0x0);
  uVar2 = Object_IsVisibleThisFrame((int)param_2);
  this_00 = *(void **)((int)param_2 + 0xc4);
  if (CONCAT31(extraout_var,uVar2) == 0) {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 5:
      goto switchD_0040a7ba_caseD_5;
    case 6:
      iVar3 = Array_GetRandomRecord28((int)this_00);
      if (iVar3 != 0) {
        Person_AdvanceRoute(param_2,iVar3);
      }
      Object_SetState(param_2,7);
      return;
    case 7:
      Person_LeaveBuildingAndReset(param_2);
      return;
    case 8:
      if (*(int *)((int)param_2 + 0xa4) != 4) {
        UI_SetChildRecordVariant(param_2,10);
        Object_SetState(param_2,10);
        Object_SetFrame5(param_2,0xf);
        return;
      }
      uVar1 = *(uint *)((int)param_2 + 0x88);
      piVar4 = (int *)RecordMap_Lookup1998(param_1,uVar1);
      Object_SetChildField2C(param_2,0);
      if ((piVar4 == (int *)0x0) || (*piVar4 < 1)) {
        iVar3 = 10;
      }
      else {
        uVar5 = uVar1 & 0x80000001;
        if ((int)uVar5 < 0) {
          uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
        }
        iVar3 = (-(uint)(uVar5 != 0) & 0xfffffffc) + 0xe;
      }
      UI_SetChildRecordVariant(param_2,iVar3);
      Object_SetState(param_2,10);
      Object_SetFrame5(param_2,0xf);
      if ((piVar4 != (int *)0x0) && (0 < *piVar4)) {
        Branch_StartConstructionOnPlot(param_1,uVar1);
        Sound_HandleEvent(DAT_0057ba0c,(int)param_1,0x30);
      }
      Object_SetFieldA4Locked(param_2,0xffffffff);
      return;
    default:
      Person_ResumeRouteOrDetach(param_2);
      return;
    case 0x25:
      Object_SetState(param_2,6);
      UI_SetChildState(param_2,0x1d);
      return;
    case 0x30:
      UI_SetChildRecordVariant(param_2,10);
      Object_SetState(param_2,10);
      if (*(int *)((int)param_2 + 0x128) < 1) {
        return;
      }
      iVar3 = 0;
      if (*(int *)((int)param_2 + 0x128) < 1) {
        return;
      }
      do {
        iVar6 = IDMap_Lookup((void *)((int)param_2 + 0x114),iVar3,(int *)0x0);
        iVar6 = IDMap_Lookup((void *)((int)this + 0x3c),iVar6,(int *)0x0);
        if (*(int *)(iVar6 + 0x38) == 0x1a) {
          Game_AddObjectToStateList(param_1,iVar6);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)param_2 + 0x128));
      return;
    }
  }
  switch(*(undefined4 *)((int)param_2 + 0x38)) {
  case 8:
    iVar3 = Game_CountAvailableBusinessBuildings((int)param_1);
    if (0 < iVar3) {
      Person_ProcessMoveEvent(param_2);
      return;
    }
    break;
  case 10:
    iVar6 = Person_ProcessMoveEvent(param_2);
    if (iVar6 == 0) {
      if (*(char *)(iVar3 + 0x825) == '\x01') {
        if (0 < *(int *)((int)param_1 + 0x1774)) {
          List_Node_Reset((int)param_2 + 0x114);
          iVar6 = IDMap_Lookup((void *)((int)param_1 + 0x1760),0,(int *)0x0);
          iVar6 = IDMap_Lookup((void *)((int)this + 0x3c),iVar6,(int *)0x0);
          IDMap_RemoveRecursive((void *)((int)param_1 + 0x1760),0);
          if ((iVar6 != 0) && (*(int *)(iVar6 + 0x38) == 0x1a)) {
            Object_SetState(param_2,6);
            Object_SetFieldA4Locked(param_2,8);
            UI_DetachChildRecord((int)param_2);
            *(undefined4 *)((int)param_2 + 0x10c) = *(undefined4 *)(iVar6 + 0x164);
            Object_SetChildField2C(param_2,0x20);
            return;
          }
        }
        if ((*(int *)((int)param_2 + 0x128) == 0) &&
           (iVar6 = Object_FindNearbyCustomer(param_2,param_1), iVar6 != 0)) {
          piVar4 = Map_LinkNeighbors(this_00,param_1);
          iVar7 = Array_GetRecord28(this_00,1,
                                    (int)*(short *)(*(int *)(*(int *)((int)this_00 + 0x4c) + 8 +
                                                            *piVar4 * 0xc) + 0x24));
          if (iVar7 != 0) {
            Screen_AddRecordToPanel(param_2,iVar6);
            Object_SetState(param_2,0x30);
            _DAT_0057c610 = Person_AdvanceRoute(param_2,iVar7);
            return;
          }
        }
      }
      if ((*(char *)(iVar3 + 0x825) == '\x02') &&
         (iVar3 = Game_PickFreeConstructionPlot((int)param_1), iVar3 != -1)) {
        *(int *)((int)param_2 + 0x88) = iVar3;
        Object_SetFieldA4Locked(param_2,4);
        Object_SetFrame5(param_2,-1);
        UI_DetachChildRecord((int)param_2);
        Object_SetState(param_2,6);
        return;
      }
      *(short *)((int)param_1 + 0x16e2) = *(short *)((int)param_1 + 0x16e2) + 1;
      iVar3 = *(int *)((int)param_2 + 0x94) + -1;
      *(int *)((int)param_2 + 0x94) = iVar3;
      if (iVar3 == 0) {
        Object_SetFrame5(param_2,-1);
        UI_DetachChildRecord((int)param_2);
        Object_SetState(param_2,5);
      }
    }
    break;
  case 0x25:
    Person_TruncatePathToCurrentStep((int)param_2);
    return;
  case 0x30:
    iVar3 = Person_CanContinuePath((int)param_2);
    if (iVar3 == 0) {
      Person_ProcessMoveEvent(param_2);
      return;
    }
  }
  return;
switchD_0040a7ba_caseD_5:
  if (*(int *)((int)param_2 + 0xa4) == 4) {
    piVar4 = (int *)RecordMap_Lookup1998(param_1,*(int *)((int)param_2 + 0x88));
    if ((piVar4 != (int *)0x0) && (0 < *piVar4)) {
      iVar6 = AI_StepToNeighborCell(param_1,(int)piVar4);
      if (iVar6 == 0) {
        NoOp_Stub();
        return;
      }
      iVar3 = Rating_AdjustA(iVar3);
      fVar8 = Game_GetRatingMultiplier((int)param_1);
      UI_SetChildScale(param_2,(double)(fVar8 * (float10)iVar3));
      _DAT_0057c610 = Person_WalkToCellOrAbort(param_2,iVar6);
      return;
    }
  }
  else if (*(char *)(iVar3 + 0x825) == '\x01') {
    piVar4 = Map_LinkNeighbors(this_00,param_1);
    iVar3 = Array_GetRecord28(this_00,1,
                              (int)*(short *)(*(int *)(*(int *)((int)this_00 + 0x4c) + 8 +
                                                      *piVar4 * 0xc) + 0x24));
    if (iVar3 == 0) {
      NoOp_Stub();
      return;
    }
    goto LAB_0040a8c5;
  }
  iVar3 = Map_PickRandomType355Cell(unaff_EDI,unaff_SI);
  if (iVar3 == 0) {
    Object_SetState(param_2,6);
    return;
  }
LAB_0040a8c5:
  _DAT_0057c610 = Person_WalkToCellOrAbort(param_2,iVar3);
  return;
}

