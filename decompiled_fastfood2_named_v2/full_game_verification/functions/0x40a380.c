// rea decompile_all
// name: Object_UpdateProductionWorker
// address: 0x40a380
// body: available
// range: 0x40a380-0x40a6e3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateProductionWorker(void *this,void *param_1,void *param_2)

{
  void *pvVar1;
  undefined1 uVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  void *this_00;
  uint extraout_EDX;
  undefined4 unaff_EDI;
  float10 fVar6;
  longlong lVar7;
  
                    /* Updates a production worker's ingredients and work timer. */
  *(short *)((int)param_1 + 0x16e4) = *(short *)((int)param_1 + 0x16e4) + 1;
  iVar3 = IDMap_Lookup((void *)((int)this + 0x20),*(int *)((int)param_2 + 0x50),(int *)0x0);
  uVar2 = Object_IsVisibleThisFrame((int)param_2);
  pvVar1 = *(void **)((int)param_2 + 0xc4);
  if (CONCAT31(extraout_var,uVar2) == 0) {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 5:
      piVar4 = Map_LinkNeighbors(pvVar1,param_1);
      iVar5 = Array_GetRecord28(pvVar1,1,(int)*(short *)(*(int *)(*(int *)((int)pvVar1 + 0x4c) + 8 +
                                                                 *piVar4 * 0xc) + 0x24));
      if (iVar5 == 0) {
        Object_SetState(param_2,6);
        return;
      }
      iVar3 = Rating_AdjustA(iVar3);
      fVar6 = Game_GetRatingMultiplier((int)param_1);
      UI_SetChildScale(param_2,(double)(fVar6 * (float10)iVar3));
      _DAT_0057c610 = Person_WalkToCellOrAbort(param_2,iVar5);
      if (_DAT_0057c610 != 0) {
        *(int *)((int)param_2 + 0x88) = *piVar4;
        Object_SetState(param_2,8);
        return;
      }
      break;
    case 6:
      iVar3 = Array_GetRandomRecord28((int)pvVar1);
      if (iVar3 != 0) {
        Person_AdvanceRoute(param_2,iVar3);
        Object_SetState(param_2,7);
        return;
      }
      break;
    case 7:
      Person_LeaveBuildingAndReset(param_2);
      Person_SetAtWork((int)param_2,extraout_EDX,(int)param_1,'\x01');
      return;
    case 8:
switchD_0040a3d6_caseD_8:
      UI_SetChildRecordVariant(param_2,0x12);
      Object_SetState(param_2,10);
      break;
    default:
      Person_ResumeRouteOrDetach(param_2);
      return;
    case 0x25:
      Object_SetState(param_2,6);
      UI_SetChildState(param_2,0x1d);
      return;
    }
  }
  else {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 8:
      Person_ProcessMoveEvent(param_2);
      return;
    case 10:
      iVar5 = Person_ProcessMoveEvent(param_2);
      if (iVar5 == 0) {
        if (*(int *)((int)param_1 + 0x173c) < 1) {
          *(short *)((int)param_1 + 0x16dc) = *(short *)((int)param_1 + 0x16dc) + 1;
          return;
        }
        pvVar1 = (void *)((int)param_1 + 0x1728);
        iVar5 = IDMap_Lookup(pvVar1,0,(int *)0x0);
        this_00 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),iVar5,(int *)0x0);
        if (this_00 == (void *)0x0) {
          IDMap_RemoveRecursive(pvVar1,0);
          return;
        }
        if (((*(int *)((int)this_00 + 0xc4) == *(int *)((int)param_1 + 0x14e0)) &&
            (*(int *)((int)this_00 + 0x38) == 0xb)) || (*(int *)((int)this_00 + 0x38) == 0x1a)) {
          if (*(int *)((int)param_1 + 0x1a24) != 0) {
            return;
          }
          iVar5 = Action_AddBestRecipeToBranchMenu(this_00,*(int *)((int)param_1 + 0x16f0));
          if (iVar5 == 0) {
            UI_SetChildState(param_2,10);
            Game_GetTimeByMode(param_2,7);
            DebugConsole_Printf(DAT_0057c1e0,0xff,(byte *)s_Keine_Zutaten_00563cc0,unaff_EDI);
            *(undefined4 *)((int)param_1 + 0x1a24) = 1;
            return;
          }
          Branch_ComputeWorkDuration(param_1,iVar3);
          lVar7 = __ftol();
          Object_SetFrame5(param_2,(int)lVar7);
          Object_SetState(param_2,0xe);
          Sound_HandleEvent(DAT_0057ba0c,(int)param_1,0x32);
          *(undefined4 *)((int)param_2 + 0x10c) = *(undefined4 *)((int)this_00 + 0x164);
          UI_SetChildRecordVariant(param_2,10);
          UI_SetChildState(param_2,0xffff);
        }
        IDMap_RemoveRecursive(pvVar1,0);
        return;
      }
      break;
    case 0xe:
      iVar3 = *(int *)((int)param_2 + 0x94) + -1;
      *(int *)((int)param_2 + 0x94) = iVar3;
      if (iVar3 != 0) {
        return;
      }
      Object_SetFrame5(param_2,-1);
      iVar3 = IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),(int *)0x0);
      if (*(int *)(iVar3 + 0x38) == 0xb) {
        Screen_AddRecordToList(param_1,iVar3);
      }
      else if (*(int *)(iVar3 + 0x38) == 0x1a) {
        Game_QueueObjectTask(param_1,iVar3);
      }
      goto switchD_0040a3d6_caseD_8;
    case 0x25:
      Person_TruncatePathToCurrentStep((int)param_2);
      return;
    }
  }
  return;
}

