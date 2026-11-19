// rea decompile_all
// name: Object_UpdateCitizen
// address: 0x409730
// body: available
// range: 0x409730-0x409aca inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Object_UpdateCitizen(void *param_1,void *param_2)

{
  undefined1 uVar1;
  undefined3 extraout_var;
  void *this;
  int iVar2;
  undefined4 uVar3;
  undefined1 unaff_SI;
  undefined4 unaff_EDI;
  uint local_30;
  int local_2c;
  undefined4 local_28 [5];
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Updates a citizen's residential/service target and timers. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557d98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004013a0(local_28,0);
  local_4 = 0;
  uVar1 = Object_IsVisibleThisFrame((int)param_2);
  if (CONCAT31(extraout_var,uVar1) == 0) {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 5:
      if (*(int *)((int)param_2 + 0xa4) == 2) {
        iVar2 = FUN_0047fed0((int)param_1);
        if ((0 < iVar2) && (iVar2 = FUN_00480e80(param_1,(int)param_2), iVar2 != 0)) {
          iVar2 = *(int *)(iVar2 + 0x164);
          *(int *)((int)param_2 + 0x8c) = iVar2;
          iVar2 = FUN_0050bf50(param_2,param_1,iVar2,&local_30);
          if (iVar2 != 0) {
            _DAT_0057c610 = Person_WalkToCellOrAbort(param_2,iVar2);
            goto LAB_00409aa5;
          }
        }
      }
      else {
        iVar2 = FUN_004f50d0(0,0,0,unaff_EDI,unaff_SI);
        if (iVar2 != 0) {
          _DAT_0057c610 = Person_WalkToCellOrAbort(param_2,iVar2);
          break;
        }
      }
      FUN_0050e890(param_2,6);
      break;
    case 6:
      iVar2 = FUN_004f3ad0(*(int *)((int)param_2 + 0xc4));
      if (iVar2 != 0) {
        Person_AdvanceRoute(param_2,iVar2);
        FUN_0050e890(param_2,7);
      }
      break;
    case 7:
      FUN_0050e850(param_2,0xffffffff);
      Person_LeaveBuildingAndReset(param_2);
      break;
    case 8:
      UI_SetChildRecordVariant(param_2,*(int *)((int)param_2 + 0x88) + 8);
      FUN_0050e890(param_2,0x21);
      FUN_0050d200(param_2,1);
      break;
    default:
      Person_ResumeRouteOrDetach(param_2);
      break;
    case 0x20:
      UI_SetChildRecordVariant(param_2,*(int *)((int)param_2 + 0x88) + 0x10);
      FUN_00548210(DAT_0057ba0c,(int)param_1,0x33);
      FUN_0050b200(param_2,param_1,&local_30,local_28);
      iVar2 = 0;
      if (0 < local_14) {
        do {
          this = (void *)FUN_004017f0(local_28,iVar2,(int *)0x0);
          FUN_0050e890(this,0x23);
          iVar2 = iVar2 + 1;
        } while (iVar2 < local_14);
      }
      break;
    case 0x22:
      FUN_0050e890(param_2,5);
    }
  }
  if (CONCAT31(extraout_var,uVar1) != 0) {
    iVar2 = *(int *)((int)param_2 + 0x38);
    if (iVar2 == 8) {
      iVar2 = Person_ProcessMoveEvent(param_2);
      if (iVar2 == 0) {
        iVar2 = FUN_0047fed0((int)param_1);
        if (iVar2 == 0) {
          FUN_005090e0((int)param_2);
          FUN_0050e890(param_2,6);
          if (*(void **)(local_2c + 0x9c) == param_1) {
            FUN_005499f0(DAT_0057ba0c,0x20,0xf,'\x01');
          }
        }
        else {
          if (*(int *)((int)param_2 + 200) == 0) {
            uVar3 = 0xffffffff;
          }
          else {
            uVar3 = *(undefined4 *)(*(int *)((int)param_2 + 200) + 0xc);
          }
          *(undefined4 *)((int)param_2 + 0x88) = uVar3;
          iVar2 = FUN_0050b200(param_2,param_1,&local_30,(void *)0x0);
          if (iVar2 == 0) {
            if ((*(int *)((int)param_2 + 0xa4) == 2) &&
               (iVar2 = FUN_00480e80(param_1,(int)param_2), iVar2 != 0)) {
              iVar2 = *(int *)(iVar2 + 0x164);
              *(int *)((int)param_2 + 0x8c) = iVar2;
              iVar2 = FUN_0050bf50(param_2,param_1,iVar2,&local_30);
              if (iVar2 != 0) {
                Person_AdvanceRoute(param_2,iVar2);
              }
            }
          }
          else {
            *(uint *)((int)param_2 + 0x88) = local_30;
            Person_TruncatePathToCurrentStep((int)param_2);
            FUN_0050e890(param_2,0x20);
          }
        }
      }
    }
    else if (iVar2 == 0x20) {
      iVar2 = FUN_0050b200(param_2,param_1,&local_30,(void *)0x0);
      if (iVar2 == 0) {
        FUN_0050e890(param_2,0x22);
        FUN_005090a0(param_2,*(int *)((int)param_2 + 0x88) + 0x10);
      }
      else if (*(uint *)((int)param_2 + 0x88) != local_30) {
        *(uint *)((int)param_2 + 0x88) = local_30;
        UI_SetChildRecordVariant(param_2,local_30 + 0x10);
      }
    }
    else if (iVar2 == 0x21) {
      iVar2 = FUN_0050b200(param_2,param_1,&local_30,(void *)0x0);
      if (iVar2 == 0) {
        iVar2 = *(int *)((int)param_2 + 0x94) + -1;
        *(int *)((int)param_2 + 0x94) = iVar2;
        if (iVar2 == 0) {
          FUN_0050d200(param_2,-1);
          FUN_005090e0((int)param_2);
          FUN_0050e890(param_2,5);
        }
      }
      else {
        *(uint *)((int)param_2 + 0x88) = local_30;
        FUN_0050d200(param_2,-1);
        FUN_005090e0((int)param_2);
        FUN_0050e890(param_2,0x20);
      }
    }
  }
LAB_00409aa5:
  local_4 = 0xffffffff;
  FUN_00401480(local_28);
  ExceptionList = local_c;
  return;
}

