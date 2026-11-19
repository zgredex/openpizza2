// rea decompile_all
// name: Object_UpdateSupplyBuilding
// address: 0x4082d0
// body: available
// range: 0x4082d0-0x408597 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateSupplyBuilding(void *this,int param_1,void *param_2)

{
  undefined1 uVar1;
  undefined3 extraout_var;
  void *pvVar2;
  uint uVar3;
  char *this_00;
  int iVar4;
  
                    /* Updates a supply building and spawns delivery trucks. */
  uVar1 = Object_IsVisibleThisFrame((int)param_2);
  pvVar2 = *(void **)((int)param_2 + 0xc4);
  if (CONCAT31(extraout_var,uVar1) != 0) {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 8:
      Person_ProcessMoveEvent(param_2);
      return;
    case 0x12:
      iVar4 = Person_ProcessMoveEvent(param_2);
      if ((iVar4 == 0) &&
         (iVar4 = *(int *)((int)param_2 + 0x94) + -1, *(int *)((int)param_2 + 0x94) = iVar4,
         iVar4 == 0)) {
        FUN_0050d200(param_2,-1);
        FUN_005090e0((int)param_2);
        FUN_0050e890(param_2,5);
        return;
      }
      break;
    case 0x2b:
      iVar4 = Person_ProcessMoveEvent(param_2);
      if (iVar4 != 0) {
        return;
      }
      iVar4 = *(int *)((int)param_2 + 0x94) + -1;
      *(int *)((int)param_2 + 0x94) = iVar4;
      if (iVar4 != 0) {
        return;
      }
      FUN_005090e0((int)param_2);
      FUN_0050d200(param_2,-1);
      *(undefined1 *)((int)param_2 + 0x81) = 1;
    case 0x16:
      Person_ProcessMoveEvent(param_2);
      break;
    case 0x39:
      FUN_005090e0((int)param_2);
      FUN_0050e4c0(param_2,0x10);
      FUN_0050e890(param_2,6);
      return;
    }
    return;
  }
  switch(*(undefined4 *)((int)param_2 + 0x38)) {
  case 5:
    MissionGoal_HandleEvent
              (*(void **)(*(int *)((int)this + 0x224) + 0xa8),4,*(int *)((int)param_2 + 0x164),-1);
    if (*(int *)((int)param_2 + 0xa4) == 1) {
      iVar4 = FUN_004f4f20(pvVar2,1);
      if (iVar4 == 0) goto switchD_00408305_caseD_14;
    }
    else {
      if (*(int *)((int)param_2 + 0xa4) != 2) break;
      iVar4 = FUN_004f4f20(pvVar2,2);
      if (iVar4 == 0) {
        iVar4 = FUN_00509ff0((int)param_2);
        Person_AdvanceRoute(param_2,iVar4);
        FUN_0050e890(param_2,0x14);
        return;
      }
    }
    _DAT_0057c610 = Person_WalkToCellOrAbort(param_2,iVar4);
    return;
  case 6:
    iVar4 = FUN_004f3ad0((int)pvVar2);
    if (iVar4 == 0) {
      return;
    }
    Person_AdvanceRoute(param_2,iVar4);
    FUN_0050e890(param_2,7);
    return;
  case 7:
    *(undefined4 *)((int)param_2 + 0x110) = 0xffffffff;
    FUN_0050e850(param_2,0xffffffff);
    Person_LeaveBuildingAndReset(param_2);
    return;
  case 8:
    if (*(int *)((int)param_2 + 0xa4) == 1) {
      UI_SetChildRecordVariant(param_2,0x20);
      FUN_0050e890(param_2,0x12);
      FUN_0050d200(param_2,0xf);
      FUN_00548210(DAT_0057ba0c,param_1,0x2a);
      return;
    }
    if (*(int *)((int)param_2 + 0xa4) == 2) {
      UI_SetChildRecordVariant(param_2,0x31);
      FUN_0050e890(param_2,0x16);
      pvVar2 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
      uVar3 = FUN_004034d0(0x2b,0x2c);
      this_00 = FUN_004d50a0(pvVar2,uVar3,param_1);
      if (*(int *)((int)param_2 + 200) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(*(int *)((int)param_2 + 200) + 0x20);
      }
      FUN_00505e60(this_00,1,iVar4);
      FUN_0050e890(this_00,0x18);
      *(undefined4 *)(this_00 + 0x10c) = *(undefined4 *)((int)param_2 + 0x164);
      return;
    }
    break;
  case 0x14:
switchD_00408305_caseD_14:
    FUN_0050e890(param_2,6);
    return;
  case 0x2a:
    UI_SetChildRecordVariant(param_2,*(int *)((int)param_2 + 0x88) + 0x28);
    FUN_0050d200(param_2,1);
    FUN_0050e890(param_2,0x2b);
    return;
  case 0x38:
    UI_SetChildRecordVariant(param_2,*(int *)((int)param_2 + 0x88) + 0x28);
    return;
  }
  Person_ResumeRouteOrDetach(param_2);
  return;
}

