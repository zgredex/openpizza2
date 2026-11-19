// rea decompile_all
// name: Object_UpdateFallback
// address: 0x40acf0
// body: available
// range: 0x40acf0-0x40b0a5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateFallback(void *this,void *param_1,void *param_2)

{
  int *piVar1;
  void *this_00;
  undefined1 uVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 uVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int local_18;
  int local_14 [5];
  
                    /* Runs fallback behavior for object types without a handler. */
  this_00 = param_2;
  local_14[1] = 2;
  local_14[2] = 3;
  local_14[3] = 0;
  local_14[4] = 1;
  uVar2 = Object_IsVisibleThisFrame((int)param_2);
  pvVar6 = *(void **)((int)this_00 + 0xc4);
  if (CONCAT31(extraout_var,uVar2) == 0) {
    switch(*(undefined4 *)((int)this_00 + 0x38)) {
    case 5:
      Game_IncrementVisitCounter(param_1,*(int *)((int)this_00 + 0x34));
      iVar5 = Building_IsSpecialType((int)this_00);
      if ((iVar5 != 0) &&
         (iVar5 = Game_CountFilteredObjects2(this,1,0x16,*(int *)((int)param_1 + 0x16f0),-1),
         iVar5 != 0)) {
        iVar5 = UI_RandomChildEffect((int)this_00);
        Person_AdvanceRoute(this_00,iVar5);
        Object_SetState(this_00,0x13);
        return;
      }
      uVar2 = Game_GetHourlyValue(param_1,0x3c);
      if (CONCAT31(extraout_var_00,uVar2) == 0) {
        iVar5 = UI_RandomChildEffect((int)this_00);
        Person_AdvanceRoute(this_00,iVar5);
        Object_SetState(this_00,0x15);
        *(short *)((int)param_1 + 0x16d8) = *(short *)((int)param_1 + 0x16d8) + 1;
        return;
      }
      bVar3 = Game_IsRatingBelowThreshold(param_1,*(int *)((int)this_00 + 0x34));
      if (CONCAT31(extraout_var_01,bVar3) == 0) {
        iVar5 = UI_RandomChildEffect((int)this_00);
        Person_AdvanceRoute(this_00,iVar5);
        Object_SetState(this_00,0x3d);
        *(short *)((int)param_1 + 0x16d8) = *(short *)((int)param_1 + 0x16d8) + 1;
        return;
      }
      iVar5 = Game_UpdatePlayerObject(this_00,local_14);
      if (iVar5 == 0) {
        *(short *)((int)param_1 + 0x16d6) = *(short *)((int)param_1 + 0x16d6) + 1;
        iVar5 = UI_RandomChildEffect((int)this_00);
        Person_AdvanceRoute(this_00,iVar5);
        Object_SetState(this_00,0x14);
        return;
      }
      _DAT_0057c610 = Person_WalkToCellOrAbort(this_00,iVar5);
      if ((_DAT_0057c610 != 0) &&
         (Sound_CheckSpeechState(DAT_0057ba0c,(int)param_1), *(int *)((int)this_00 + 0x30) == 0xb))
      {
        uVar4 = Game_GetDateField0C((int)this);
        *(undefined4 *)((int)this_00 + 0x98) = uVar4;
        return;
      }
      break;
    case 6:
      iVar5 = Array_GetRandomRecord28((int)pvVar6);
      if (iVar5 != 0) {
        Person_AdvanceRoute(this_00,iVar5);
      }
      Object_SetState(this_00,7);
      Map_DetachObjectFromTile((int)this_00);
      return;
    case 7:
      UI_SetChildState(this_00,0xffff);
      Person_LeaveBuildingAndReset(this_00);
      return;
    case 8:
      iVar5 = Person_ProcessMoveEvent(this_00);
      if (iVar5 == 0) {
        iVar5 = *(int *)((int)this_00 + 0x84);
        UI_ComputeCenteredRect
                  (pvVar6,(int *)(*(int *)((int)pvVar6 + 0x4c) + *(int *)((int)this_00 + 0x88) * 0xc
                                 ),&local_18,(int *)&param_2);
        piVar1 = *(int **)((int)this_00 + 200);
        if (piVar1 == (int *)0x0) {
          iVar7 = -1;
          pvVar6 = (void *)0x0;
        }
        else {
          iVar7 = *piVar1;
          pvVar6 = (void *)piVar1[0x16];
        }
        Record_SetDoubles48(pvVar6,iVar7,local_18 + -0xa0,(int)param_2 + -0xd0);
        UI_SetChildRecordVariant(this_00,iVar5 + 0x10);
        UI_SetChildState(this_00,2);
        Game_GetTimeByMode(this_00,3);
        Object_SetState(this_00,0xd);
        return;
      }
      break;
    case 9:
      Game_RemoveTrackedRecord(param_1,(int)this_00);
      iVar5 = local_14[*(int *)((int)this_00 + 0x84) + 1];
      UI_ComputeCenteredRect
                (pvVar6,(int *)(*(int *)((int)pvVar6 + 0x4c) + *(int *)((int)this_00 + 0x8c) * 0xc),
                 &local_18,(int *)&param_2);
      piVar1 = *(int **)((int)this_00 + 200);
      if (piVar1 == (int *)0x0) {
        iVar7 = -1;
        pvVar6 = (void *)0x0;
      }
      else {
        iVar7 = *piVar1;
        pvVar6 = (void *)piVar1[0x16];
      }
      Record_SetDoubles48(pvVar6,iVar7,local_18 + -0xa0,(int)param_2 + -0xd0);
      UI_SetChildRecordVariant(this_00,iVar5 + 8);
      UI_DetachChildRecord((int)this_00);
      Object_SetState(this_00,6);
      return;
    default:
      Person_ResumeRouteOrDetach(this_00);
      return;
    case 0x13:
      UI_SetChildState(this_00,0xc);
      Game_GetTimeByMode(this_00,7);
      Object_SetState(this_00,6);
      return;
    case 0x14:
      UI_SetChildState(this_00,0xf);
      Game_GetTimeByMode(this_00,7);
      Object_SetState(this_00,6);
      return;
    case 0x15:
      UI_SetChildState(this_00,0x23);
      Game_GetTimeByMode(this_00,7);
      Object_SetState(this_00,6);
      return;
    case 0x3d:
      UI_SetChildState(this_00,0x1f);
      Game_GetTimeByMode(this_00,7);
      Object_SetState(this_00,6);
      return;
    }
  }
  else {
    Person_ProcessMoveEvent(this_00);
  }
  return;
}

