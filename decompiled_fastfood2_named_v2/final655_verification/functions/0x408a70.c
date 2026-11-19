// rea decompile_all
// name: Object_UpdateBranchOpenClose
// address: 0x408a70
// body: available
// range: 0x408a70-0x408f16 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateBranchOpenClose(void *this,char *param_1,void *param_2)

{
  undefined1 uVar1;
  undefined3 extraout_var;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined1 unaff_SI;
  undefined4 unaff_EDI;
  
                    /* Handles branch opening/closing and occupant spawning. */
  uVar1 = Object_IsVisibleThisFrame((int)param_2);
  if (CONCAT31(extraout_var,uVar1) == 0) {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 5:
      switch(*(undefined4 *)((int)param_2 + 0xa4)) {
      default:
        goto switchD_00408aa5_caseD_9;
      case 3:
      case 7:
      case 9:
      case 0xd:
      case 0x11:
        FUN_004ffeb0(*(void **)((int)this + 0x90),*(int *)(param_1 + 0x30),5);
        iVar2 = FUN_004f50d0(0,0,0,unaff_EDI,unaff_SI);
        if (iVar2 == 0) {
          iVar2 = FUN_00509ff0((int)param_2);
          Person_AdvanceRoute(param_2,iVar2);
          FUN_0050e890(param_2,0x14);
          return;
        }
        _DAT_0057c610 = Person_WalkToCellOrAbort(param_2,iVar2);
        return;
      case 0xffffffff:
        goto switchD_00408aa5_caseD_14;
      }
    case 6:
      iVar2 = FUN_004f3ad0(*(int *)((int)param_2 + 0xc4));
      if (iVar2 != 0) {
        Person_AdvanceRoute(param_2,iVar2);
        FUN_0050e890(param_2,7);
        return;
      }
      break;
    case 7:
      FUN_0050e850(param_2,0xffffffff);
      Person_LeaveBuildingAndReset(param_2);
      return;
    case 8:
      switch(*(undefined4 *)((int)param_2 + 0xa4)) {
      case 3:
      case 7:
      case 9:
      case 0xd:
      case 0x11:
        UI_SetChildRecordVariant(param_2,0x19);
        FUN_0050e890(param_2,0x17);
        FUN_0050d200(param_2,2);
        return;
      }
    default:
switchD_00408aa5_caseD_9:
      Person_ResumeRouteOrDetach(param_2);
      return;
    case 0x14:
switchD_00408aa5_caseD_14:
      FUN_0050e890(param_2,6);
      return;
    case 0x2a:
      UI_SetChildRecordVariant(param_2,*(int *)((int)param_2 + 0x88) + 0x40);
      FUN_0050d200(param_2,1);
      FUN_0050e890(param_2,0x2b);
      return;
    case 0x38:
      UI_SetChildRecordVariant(param_2,*(int *)((int)param_2 + 0x88) + 0x40);
      return;
    }
  }
  else {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 8:
      Person_ProcessMoveEvent(param_2);
      return;
    case 0x17:
      iVar2 = Person_ProcessMoveEvent(param_2);
      if (iVar2 == 0) {
        switch(*(undefined4 *)((int)param_2 + 0xa4)) {
        case 3:
        case 7:
        case 9:
        case 0xd:
        case 0x11:
          iVar2 = *(int *)((int)param_2 + 0x94) + -1;
          *(int *)((int)param_2 + 0x94) = iVar2;
          if (iVar2 == 0) {
            FUN_0050d200(param_2,-1);
            FUN_005090e0((int)param_2);
            FUN_0050e4c0(param_2,0);
            FUN_0050e890(param_2,6);
            FUN_00507550(param_2,0xffff);
            switch(*(undefined4 *)((int)param_2 + 0xa4)) {
            case 3:
              pvVar3 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),
                                            (int *)0x0);
              param_1 = FUN_004d50a0(pvVar3,0x1a,(int)param_1);
              iVar2 = *(int *)((int)param_2 + 0x110);
              iVar4 = FUN_00482820((int)this);
              if (iVar2 == iVar4) {
                FUN_004f5f70(*(void **)(*(int *)((int)this + 0x224) + 0xac),1,1);
              }
              break;
            default:
              break;
            case 7:
              pvVar3 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),
                                            (int *)0x0);
              param_1 = FUN_004d50a0(pvVar3,0x1b,(int)param_1);
              MissionGoal_HandleEvent
                        (*(void **)(*(int *)((int)this + 0x224) + 0xa8),5,
                         *(int *)((int)param_2 + 0x164),-1);
              break;
            case 9:
              pvVar3 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),
                                            (int *)0x0);
              param_1 = FUN_004d50a0(pvVar3,0x1c,(int)param_1);
              MissionGoal_HandleEvent
                        (*(void **)(*(int *)((int)this + 0x224) + 0xa8),3,
                         *(int *)((int)param_2 + 0x164),-1);
              break;
            case 0xd:
              pvVar3 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),
                                            (int *)0x0);
              param_1 = FUN_004d50a0(pvVar3,0x2d,(int)param_1);
              break;
            case 0x11:
              pvVar3 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),
                                            (int *)0x0);
              param_1 = FUN_004d50a0(pvVar3,0x2f,(int)param_1);
              iVar2 = FUN_00488be0(this,*(int *)((int)param_2 + 0x110));
              *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0x88) + 1;
              iVar2 = *(int *)((int)param_2 + 0x110);
              iVar4 = FUN_00482820(DAT_0057c670);
              if (iVar2 == iVar4) {
                iVar2 = *(int *)((int)param_2 + 0x164);
                FUN_004f5fa0(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xac),0x12);
                MissionGoal_HandleEvent
                          (*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),9,iVar2,-1);
              }
              iVar2 = FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
              *(int *)(iVar2 + 0x10b8) = *(int *)(iVar2 + 0x10b8) + 1;
              Game_AbortOrdersTargetingObject(*(int *)((int)param_2 + 0xfc),1,param_2);
            }
            if (*(int *)((int)param_2 + 200) == 0) {
              iVar2 = 0;
            }
            else {
              iVar2 = *(int *)(*(int *)((int)param_2 + 200) + 0x20);
            }
            FUN_00505e60(param_1,1,iVar2);
            FUN_0050e890(param_1,0x18);
            FUN_0050e850(param_2,0xffffffff);
          }
        }
      }
      break;
    case 0x2b:
      iVar2 = Person_ProcessMoveEvent(param_2);
      if ((iVar2 == 0) &&
         (iVar2 = *(int *)((int)param_2 + 0x94) + -1, *(int *)((int)param_2 + 0x94) = iVar2,
         iVar2 == 0)) {
        FUN_005090e0((int)param_2);
        FUN_0050d200(param_2,-1);
        *(undefined1 *)((int)param_2 + 0x81) = 1;
        Person_ProcessMoveEvent(param_2);
        return;
      }
      break;
    case 0x39:
      FUN_005090e0((int)param_2);
      FUN_0050e4c0(param_2,0x20);
      FUN_0050e890(param_2,6);
      return;
    }
  }
  return;
}

