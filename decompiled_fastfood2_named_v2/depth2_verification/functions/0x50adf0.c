// rea decompile_all
// name: FUN_0050adf0
// address: 0x50adf0
// body: available
// range: 0x50adf0-0x50b047 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_0050adf0(void *param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  
  if ((*(char *)((int)param_1 + 0x80) == '\0') && (*(char *)((int)param_1 + 0x81) == '\0')) {
    return 0;
  }
  switch(*(undefined4 *)((int)param_1 + 0x30)) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 0xb:
  case 0xf:
  case 0x21:
    if (*(char *)((int)param_1 + 0x81) != '\0') {
      iVar2 = *(int *)((int)param_1 + 0x38);
      if (((iVar2 == 0xb) || (iVar2 == 0xd)) || (iVar2 == 0x11)) {
        if ((*(short *)((int)param_1 + 0x40) == 9) &&
           (piVar3 = (int *)Game_ApplyObjectEvent((int)param_1), piVar3 != (int *)0x0)) {
          UI_DrawCenteredSelectionRect(*(void **)((int)param_1 + 0xc4),piVar3);
        }
        if (*(short *)((int)param_1 + 0x40) != 0xb) {
          FUN_00507550(param_1,0xffff);
          FUN_00504a90(param_1,0);
          *(undefined4 *)((int)param_1 + 0x4c) = 0;
          *(undefined4 *)((int)param_1 + 0x54) = 0;
        }
        FUN_005090e0((int)param_1);
        FUN_0050e890(param_1,9);
      }
      else if ((iVar2 != 6) && (iVar2 != 7)) {
        iVar2 = FUN_0050e7a0((int)param_1);
        if (iVar2 == 0) {
          FUN_005090e0((int)param_1);
        }
        else {
          FUN_00507a80((int)param_1);
        }
        FUN_0050e890(param_1,6);
        if (*(short *)((int)param_1 + 0x40) != 0xb) {
          FUN_00507550(param_1,0xffff);
          *(undefined1 *)((int)param_1 + 0x81) = 0;
          return 1;
        }
      }
      *(undefined1 *)((int)param_1 + 0x81) = 0;
      return 1;
    }
    break;
  case 10:
  case 0xe:
  case 0x16:
  case 0x18:
  case 0x20:
    if (*(char *)((int)param_1 + 0x81) != '\0') {
      FUN_0050e850(param_1,0xffffffff);
LAB_0050af4e:
      iVar2 = FUN_0050e7a0((int)param_1);
      if (iVar2 == 0) {
        FUN_005090e0((int)param_1);
        FUN_0050e890(param_1,6);
        return 1;
      }
      FUN_00507a80((int)param_1);
      FUN_0050e890(param_1,6);
      return 1;
    }
    break;
  case 0x11:
  case 0x12:
    iVar2 = FUN_0050e7a0((int)param_1);
    if (iVar2 == 0) {
      FUN_005090e0((int)param_1);
      FUN_0050e890(param_1,6);
    }
    else {
      FUN_00507a80((int)param_1);
      FUN_0050e890(param_1,6);
    }
    goto LAB_0050aee8;
  case 0x13:
    iVar2 = FUN_0050e7a0((int)param_1);
    if (iVar2 == 0) {
      FUN_005090e0((int)param_1);
    }
    else {
      FUN_00507a80((int)param_1);
    }
    FUN_0050e890(param_1,6);
    FUN_0050e4c0(param_1,0x10);
    iVar2 = *(int *)((int)param_1 + 0xf4);
    if ((iVar2 != 0) &&
       (pvVar1 = (void *)FUN_00489820(DAT_0057c670,*(int *)(iVar2 + 8),*(int *)(iVar2 + 0x2c)),
       pvVar1 != (void *)0x0)) {
      Game_MoveTypeBObjectsToStateList(param_1,pvVar1);
    }
    goto LAB_0050aee8;
  case 0x14:
    FUN_0050e850(param_1,0xffffffff);
    iVar2 = FUN_0050e7a0((int)param_1);
    if (iVar2 == 0) {
      FUN_005090e0((int)param_1);
    }
    else {
      FUN_00507a80((int)param_1);
    }
    FUN_0050e890(param_1,6);
    FUN_0050e4c0(param_1,0);
LAB_0050aee8:
    if (*(char *)((int)param_1 + 0x80) == '\0') {
      return 1;
    }
    FUN_00507550(param_1,0x12);
    FUN_00504a90(param_1,7);
    return 1;
  case 0x17:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    if (*(char *)((int)param_1 + 0x81) != '\0') {
      FUN_0050bc40(param_1);
      goto LAB_0050af4e;
    }
  }
  return 0;
}

