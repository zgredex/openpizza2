// rea decompile_all
// name: FUN_005087c0
// address: 0x5087c0
// body: available
// range: 0x5087c0-0x508bc0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_005087c0(void *param_1)

{
  void *pvVar1;
  int iVar2;
  void *this;
  void *this_00;
  uint extraout_EDX;
  uint extraout_EDX_00;
  undefined4 uVar3;
  
  pvVar1 = (void *)FUN_00489820(DAT_0057c670,*(int *)(*(int *)((int)param_1 + 0xf4) + 8),
                                *(int *)(*(int *)((int)param_1 + 0xf4) + 0x2c));
  *(undefined4 *)((int)param_1 + 0x74) = 0;
  FUN_004d2960(*(void **)((int)param_1 + 0xf4),param_1,0);
  Object_SetFlag104(param_1,0);
  FUN_00548480(DAT_0057ba0c,(int)pvVar1);
  FUN_00507550(param_1,0xffff);
  FUN_00504a90(param_1,0);
  *(undefined4 *)((int)param_1 + 0x4c) = 0;
  *(undefined4 *)((int)param_1 + 0x54) = 0;
  FUN_0050e890(param_1,2);
  FUN_005086e0((int)param_1);
  iVar2 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),
                       *(int *)(*(int *)((int)param_1 + 0xf4) + 0x28),(int *)0x0);
  FUN_00508c20(param_1,0,*(undefined4 *)(iVar2 + 0xfa8));
  this = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)param_1 + 0x28),
                              (int *)0x0);
  iVar2 = State_IsMenuState((int)param_1);
  if (iVar2 != 0) {
    Object_SetChildShort((int)param_1);
  }
  switch(*(undefined4 *)((int)param_1 + 0x30)) {
  case 10:
    iVar2 = *(int *)((int)param_1 + 0x10c);
    if (iVar2 == 0) {
      FUN_00507550(param_1,0x17);
    }
    else if (iVar2 == 1) {
      FUN_00507550(param_1,0x18);
    }
    else if (iVar2 == 2) {
      FUN_00507550(param_1,0x19);
    }
    break;
  case 0xd:
    iVar2 = Object_GetClampedLevel((int)param_1);
    goto LAB_005088dd;
  case 0x20:
    FUN_0047fe70(pvVar1,1);
  case 0x17:
  case 0x1d:
    iVar2 = -1;
LAB_005088dd:
    FUN_0050b6d0(param_1,iVar2);
  }
  iVar2 = *(int *)((int)param_1 + 0x108);
  if (iVar2 == 10) {
    FUN_00508780(param_1);
    *(undefined4 *)((int)param_1 + 0xf4) = 0;
    return;
  }
  if (iVar2 != 6) {
    if (iVar2 == 1) {
      if (*(int *)((int)param_1 + 0x30) == 0x14) {
        FUN_00401440((int)param_1 + 0x114);
        FUN_0050bbf0(param_1,pvVar1);
        Object_SetChildField2C(param_1,0);
      }
      iVar2 = IDMap_Lookup((void *)((int)DAT_0057c670 + 0x3c),*(int *)((int)param_1 + 0x10c),
                           (int *)0x0);
      iVar2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(iVar2 + 0x110));
      FUN_00507e20(param_1,2,*(int *)(iVar2 + 0x1d8));
      FUN_00507550(param_1,0x1d);
      *(undefined4 *)((int)param_1 + 0xf4) = 0;
      return;
    }
    if ((*(char *)((int)param_1 + 0x80) == '\0') && (*(char *)((int)param_1 + 0x81) == '\0')) {
      switch(*(undefined4 *)((int)param_1 + 0x30)) {
      default:
        FUN_00507fd0(param_1);
        *(undefined4 *)((int)param_1 + 0xf4) = 0;
        return;
      case 0x14:
        goto switchD_005089e3_caseD_14;
      }
    }
    if (*(int *)((int)param_1 + 0x30) == 0x14) {
      FUN_00401440((int)param_1 + 0x114);
      FUN_0050e2a0((int)param_1,extraout_EDX_00,(int)pvVar1,'\x01');
    }
    if (*(int *)((int)param_1 + 0xa4) == 0x13) {
      iVar2 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      iVar2 = IDMap_Lookup((void *)(iVar2 + 0xfac),0x22,(int *)0x0);
      uVar3 = 7;
    }
    else {
      if (*(int *)((int)param_1 + 0xa0) != 0) {
        FUN_00507e20(param_1,6,*(int *)((int)param_1 + *(int *)((int)param_1 + 0x3c) * 4 + 0xd4));
        uVar3 = *(undefined4 *)((int)param_1 + *(int *)((int)param_1 + 0x3c) * 4 + 0xd4);
        *(undefined1 *)((int)param_1 + 0x81) = 0;
        *(undefined4 *)((int)param_1 + 0xd0) = uVar3;
        *(undefined4 *)((int)param_1 + 0xf4) = 0;
        return;
      }
      iVar2 = *(int *)((int)param_1 + 0xcc);
      uVar3 = 3;
    }
    FUN_00507e20(param_1,uVar3,iVar2);
    *(undefined1 *)((int)param_1 + 0x81) = 0;
LAB_00508bb6:
    *(undefined4 *)((int)param_1 + 0xf4) = 0;
    return;
  }
  iVar2 = *(int *)((int)param_1 + 0x30);
  if (iVar2 == 0x16) {
    uVar3 = 0x10;
  }
  else if (iVar2 == 0x1e) {
    uVar3 = 0x28;
  }
  else {
    if (iVar2 != 0x1f) goto LAB_00508927;
    uVar3 = 0x20;
  }
  Object_SetChildField2C(param_1,uVar3);
LAB_00508927:
  FUN_00507e20(param_1,3,*(int *)((int)param_1 + 0xcc));
  *(undefined4 *)((int)param_1 + 0xf4) = 0;
  return;
switchD_005089e3_caseD_14:
  if (*(int *)((int)param_1 + 0xa4) == 4) {
    iVar2 = FUN_0050bbf0(param_1,pvVar1);
    if (iVar2 != 0) {
      Object_SetChildField2C(param_1,0);
      FUN_0050e2a0((int)param_1,extraout_EDX,(int)pvVar1,'\x01');
      FUN_00507e20(param_1,3,*(int *)((int)param_1 + 0xcc));
      *(undefined4 *)((int)param_1 + 0xf4) = 0;
      return;
    }
    Object_SetChildField2C(param_1,0x30);
    this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)pvVar1 + 0x30));
    if ((this_00 == (void *)0x0) ||
       (pvVar1 = FUN_004e23b0(this_00,(int)pvVar1), pvVar1 == (void *)0x0)) {
      iVar2 = FUN_004d8be0(this,*(int *)((int)param_1 + 0xf4));
      FUN_00507e20(param_1,4,iVar2);
      *(undefined4 *)((int)param_1 + 0xf4) = 0;
      return;
    }
    FUN_00507e20(param_1,4,*(int *)((int)pvVar1 + 0x34));
    *(undefined4 *)((int)param_1 + 0xf4) = 0;
    return;
  }
  if (*(int *)((int)param_1 + 0xa4) == 8) {
    Object_SetChildField2C(param_1,0x30);
    iVar2 = IDMap_Lookup((void *)((int)DAT_0057c670 + 0x3c),*(int *)((int)param_1 + 0x10c),
                         (int *)0x0);
    if ((((iVar2 == 0) || (*(int *)(iVar2 + 0x38) != 0x1a)) || (*(char *)(iVar2 + 0x104) == '\0'))
       || (*(int *)(iVar2 + 0xfc) == 0)) {
      FUN_00507e20(param_1,1,*(int *)((int)pvVar1 + 0x16f0));
      *(undefined4 *)((int)param_1 + 0xf4) = 0;
      return;
    }
    FUN_00507e20(param_1,8,*(int *)(iVar2 + 0xfc));
    *(undefined4 *)((int)param_1 + 0xf4) = 0;
    return;
  }
  goto LAB_00508bb6;
}

