// rea decompile_all
// name: AttacksPage_FillProtectionMoney
// address: 0x4b7430
// body: available
// range: 0x4b7430-0x4b79fe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl AttacksPage_FillProtectionMoney(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
                    /* Fills the attacks tab's protection-money contract and costs. */
  iVar5 = *(int *)((int)DAT_0057c670 + 0x9c);
  this = *(void **)(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                   0x1d8);
  iVar2 = FUN_00488be0(DAT_0057c670,*(int *)(iVar5 + 0x30));
  iVar1 = *(int *)(iVar2 + 0x48);
  uVar6 = 100000;
  iVar3 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar3 + 0x158) == 0) {
    if (*(int *)(iVar3 + 0x23c) != 0) {
      uVar6 = 150000;
    }
  }
  else {
    uVar6 = 0;
  }
  FUN_0052f080(param_1,0x1fb4,&DAT_005683a4,uVar6);
  if (this == (void *)0x0) {
    iVar3 = 0;
    uVar6 = 0xff;
  }
  else {
    iVar3 = FUN_004d2ae0(this,0x1f);
    if (iVar3 == 0) {
      uVar6 = 0xff;
    }
    else {
      uVar6 = 0;
    }
  }
  FUN_0052f910(param_1,0x1fd6,uVar6);
  FUN_0052f080(param_1,0x1fd6,&DAT_005686f4,iVar3);
  iVar3 = FUN_004e27d0(*(void **)((int)DAT_0057c670 +
                                 *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),iVar5,0x1f,0x11);
  FUN_0052f080(param_1,0x1fb8,&DAT_005686f4,iVar3);
  iVar3 = *(int *)(iVar5 + 0x16f0);
  iVar4 = FUN_00482820((int)DAT_0057c670);
  iVar3 = FUN_0048a130(DAT_0057c670,0x11,0x1f,iVar3,iVar4);
  FUN_0052f080(param_1,0x1fb6,&DAT_005686f4,iVar3);
  FUN_004e27d0(*(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),iVar5
               ,0x1d,0x19);
  iVar3 = FUN_004e27d0(*(void **)((int)DAT_0057c670 +
                                 *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),iVar5,0x1d,0x1a);
  FUN_0052f080(param_1,0x1fd1,&DAT_005686f4,iVar3);
  iVar3 = *(int *)(iVar5 + 0x16f0);
  iVar4 = FUN_00482820((int)DAT_0057c670);
  FUN_0048a130(DAT_0057c670,0x19,0x1d,iVar3,iVar4);
  iVar3 = *(int *)(iVar5 + 0x16f0);
  iVar4 = FUN_00482820((int)DAT_0057c670);
  iVar3 = FUN_0048a130(DAT_0057c670,0x1a,0x1d,iVar3,iVar4);
  FUN_0052f080(param_1,0x1fcf,&DAT_005686f4,iVar3);
  if (this == (void *)0x0) {
    iVar3 = 0;
    uVar6 = 0xff;
  }
  else {
    iVar3 = FUN_004d2ae0(this,0x1d);
    if (iVar3 == 0) {
      uVar6 = 0xff;
    }
    else {
      uVar6 = 0;
    }
  }
  FUN_0052f910(param_1,0x1fb1,uVar6);
  FUN_0052f080(param_1,0x1fb1,&DAT_005686f4,iVar3);
  uVar6 = 5000;
  iVar3 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar3 + 0x134) == 0) {
    if (*(int *)(iVar3 + 0x98) == 0) {
      if ((*(int *)(iVar3 + 0x218) != 0) || (*(int *)(iVar3 + 0x17c) != 0)) {
        uVar6 = 0x1d4c;
      }
    }
    else {
      uVar6 = 0x9c4;
    }
  }
  else {
    uVar6 = 0;
  }
  FUN_0052f080(param_1,0x1fbc,&DAT_0056a850,uVar6);
  if (this == (void *)0x0) {
    iVar3 = 0;
    uVar6 = 0xff;
  }
  else {
    iVar3 = FUN_004d2ae0(this,0x1d);
    if (iVar3 == 0) {
      uVar6 = 0xff;
    }
    else {
      uVar6 = 0;
    }
  }
  FUN_0052f910(param_1,0x1fc4,uVar6);
  FUN_0052f080(param_1,0x1fc4,&DAT_005686f4,iVar3);
  iVar3 = FUN_004e27d0(*(void **)((int)DAT_0057c670 +
                                 *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),iVar5,0x1d,-1);
  FUN_0052f080(param_1,0x1fc0,&DAT_005686f4,iVar3);
  iVar3 = *(int *)(iVar5 + 0x16f0);
  iVar4 = FUN_00482820((int)DAT_0057c670);
  iVar3 = FUN_0048a130(DAT_0057c670,0x10,0x1d,iVar3,iVar4);
  FUN_0052f080(param_1,0x1fbe,&DAT_005686f4,iVar3);
  uVar6 = 5000;
  iVar3 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar3 + 0x130) == 0) {
    if (*(int *)(iVar3 + 0x98) == 0) {
      if ((*(int *)(iVar3 + 0x214) != 0) || (*(int *)(iVar3 + 0x17c) != 0)) {
        uVar6 = 0x1d4c;
      }
    }
    else {
      uVar6 = 0x9c4;
    }
  }
  else {
    uVar6 = 0;
  }
  FUN_0052f080(param_1,0x1f6e,&DAT_0056a850,uVar6);
  if (this == (void *)0x0) {
    iVar3 = 0;
    uVar6 = 0xff;
  }
  else {
    iVar3 = FUN_004d2ae0(this,0x1e);
    if (iVar3 == 0) {
      uVar6 = 0xff;
    }
    else {
      uVar6 = 0;
    }
  }
  FUN_0052f910(param_1,0x1fc6,uVar6);
  FUN_0052f080(param_1,0x1fc6,&DAT_005686f4,iVar3);
  iVar3 = FUN_004e27d0(*(void **)((int)DAT_0057c670 +
                                 *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),iVar5,0x1e,-1);
  FUN_0052f080(param_1,0x1f78,&DAT_005686f4,iVar3);
  iVar5 = *(int *)(iVar5 + 0x16f0);
  iVar3 = FUN_00482820((int)DAT_0057c670);
  iVar5 = FUN_0048a130(DAT_0057c670,0xf,0x1e,iVar5,iVar3);
  FUN_0052f080(param_1,0x1f76,&DAT_005686f4,iVar5);
  iVar5 = *(int *)(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                   0x94 + iVar1 * 4);
  if (iVar5 < 1) {
    FUN_0052f830(param_1,0x1fcb,DAT_00582cc0);
    FUN_00531740(param_1,0x1fd3);
    FUN_00531740(param_1,0x1fd4);
  }
  else {
    FUN_0052f080(param_1,0x1fac,&DAT_005683a4,iVar5);
    FUN_0052f830(param_1,0x1fcb,DAT_005829d8);
    UI_ShowChildByID(param_1,0x1fd3);
    UI_ShowChildByID(param_1,0x1fd4);
  }
  if (*(char *)(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0xac
               + *(int *)(iVar2 + 0x48)) == '\0') {
    FUN_0052f9b0(param_1,0x1fd3,DAT_005824d0);
    FUN_00531740(param_1,0x1fd4);
    FUN_00531740(param_1,0x1fcc);
    FUN_00531740(param_1,0x1fcd);
    return;
  }
  UI_ShowChildByID(param_1,0x1fcc);
  UI_ShowChildByID(param_1,0x1fcd);
  FUN_0052f9b0(param_1,0x1fd3,DAT_005816a4);
  FUN_0052f080(param_1,0x1fd4,&DAT_005683a4,
               *(undefined4 *)
                (*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                 0xb4 + iVar1 * 4));
  FUN_0052f080(param_1,0x1fcd,&DAT_0056a848,
               *(undefined4 *)
                (*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                 0xcc + iVar1 * 4));
  FUN_0052f9b0(param_1,0x1fcc,DAT_00582620);
  return;
}

