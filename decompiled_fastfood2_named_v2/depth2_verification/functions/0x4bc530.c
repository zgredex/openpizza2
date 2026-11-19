// rea decompile_all
// name: FUN_004bc530
// address: 0x4bc530
// body: available
// range: 0x4bc530-0x4bc856 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004bc530(void *param_1,char param_2)

{
  byte bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  void *this;
  uint uVar5;
  undefined4 uVar6;
  
  iVar3 = *(int *)((int)DAT_0057c670 + 0x21c);
  iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x20),*(int *)(iVar3 + 0x50),(int *)0x0);
  if (param_2 != '\0') {
    bVar1 = FUN_0050e550(iVar3);
    Sound_ProcessEvent(DAT_0057ba0c,*(int *)(iVar3 + 0x30),CONCAT31(extraout_var,bVar1),
                       *(int *)(iVar3 + 0x24) == 0);
  }
  FUN_0052f9b0(param_1,0x515,iVar3 + 4);
  FUN_0052f080(param_1,0x518,&DAT_005686f4,*(undefined4 *)(iVar2 + 0x38));
  FUN_0052f9b0(param_1,0x517,*(undefined4 *)(&DAT_005832a8 + (uint)*(byte *)(iVar2 + 0x824) * 4));
  iVar3 = FUN_004d4000(iVar2);
  FUN_0052f080(param_1,0x514,&DAT_005686f4,iVar3);
  FUN_0052f080(param_1,0x513,&DAT_005683a4,*(undefined4 *)(iVar2 + 0x3c));
  FUN_0052f9b0(param_1,0x502,*(undefined4 *)(&DAT_005832d4 + (uint)*(byte *)(iVar2 + 0x824) * 4));
  FUN_0052fd00(param_1,0x2329,0,100,0);
  FUN_0052fd00(param_1,0x232b,0,100,0);
  FUN_0052fd00(param_1,0x232d,0,100,0);
  FUN_0052fd00(param_1,0x232f,0,100,0);
  FUN_0052fd00(param_1,9000,0,100,0);
  FUN_0052fd00(param_1,0x232a,0,100,0);
  FUN_0052fd00(param_1,0x232c,0,100,0);
  FUN_0052fd00(param_1,0x232e,0,100,0);
  uVar6 = 0;
  iVar3 = FUN_004d3f90(iVar2);
  FUN_0052fd70(param_1,0x2329,iVar3,uVar6);
  uVar6 = 0;
  iVar3 = FUN_004d3fc0(iVar2);
  FUN_0052fd70(param_1,0x232b,iVar3,uVar6);
  FUN_0052fd70(param_1,0x232d,*(undefined4 *)(iVar2 + 0xc),0);
  uVar6 = 0;
  iVar3 = FUN_004d3fe0(iVar2);
  FUN_0052fd70(param_1,0x232f,iVar3,uVar6);
  iVar3 = *(int *)(iVar2 + 0x14);
  uVar6 = 0;
  iVar4 = FUN_004d3f90(iVar2);
  FUN_0052fd70(param_1,9000,iVar4 + iVar3,uVar6);
  iVar3 = *(int *)(iVar2 + 0x18);
  uVar6 = 0;
  iVar4 = FUN_004d3fc0(iVar2);
  FUN_0052fd70(param_1,0x232a,iVar4 + iVar3,uVar6);
  FUN_0052fd70(param_1,0x232c,*(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 0xc),0);
  iVar3 = *(int *)(iVar2 + 0x20);
  uVar6 = 0;
  iVar4 = FUN_004d3fe0(iVar2);
  FUN_0052fd70(param_1,0x232e,iVar4 + iVar3,uVar6);
  this = (void *)FUN_00489820(DAT_0057c670,*(int *)(iVar2 + 0x81c),*(int *)(iVar2 + 0x820));
  FUN_0052f9b0(param_1,0x1f41,(int)this + 4);
  iVar3 = FUN_00488be0(DAT_0057c670,*(int *)(iVar2 + 0x81c));
  FUN_0052f9b0(param_1,0x51b,iVar3 + 8);
  FUN_004a66d0(param_1,0x2334,iVar3);
  FUN_0054bb00(param_1,0x2333,iVar2);
  uVar5 = FUN_004d42f0(iVar2);
  if ((char)uVar5 == '\0') {
    UI_RemoveObjectByKey(param_1,0x50d);
    UI_RemoveObjectByKey(param_1,0x50e);
    UI_RemoveObjectByKey(param_1,0x50f);
    UI_RemoveObjectByKey(param_1,0x510);
  }
  else {
    FUN_005316b0(param_1,0x50d);
    FUN_005316b0(param_1,0x50e);
    FUN_005316b0(param_1,0x50f);
    FUN_005316b0(param_1,0x510);
  }
  iVar3 = 0;
  do {
    iVar2 = DAT_005826d8;
    iVar4 = FUN_004787f0(this,iVar3);
    FUN_004a80e0(param_1,0x5a7,iVar3,iVar4,iVar2);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  return;
}

