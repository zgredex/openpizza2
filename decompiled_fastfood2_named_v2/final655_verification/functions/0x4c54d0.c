// rea decompile_all
// name: BranchWindow_InitCostPanel
// address: 0x4c54d0
// body: available
// range: 0x4c54d0-0x4c5715 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl BranchWindow_InitCostPanel(void *param_1)

{
  int iVar1;
  uint uVar2;
  void *this;
  void *this_00;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  bool bVar6;
  
                    /* Fills the branch cost panel and type-0x12 counters. */
  this = param_1;
  iVar4 = *(int *)((int)DAT_0057c670 + 0x21c);
  FUN_005499f0(DAT_0057ba0c,0x17,0,'\x01');
  FUN_0052fd70(param_1,0x1f4f,*(undefined4 *)(iVar4 + 0xa8),0);
  bVar6 = *(int *)(iVar4 + 0xa4) == 0x12;
  this_00 = (void *)FUN_00488be0(DAT_0057c670,*(int *)(iVar4 + 0x110));
  iVar3 = FUN_004ddcc0((int)this_00);
  iVar1 = *(int *)(iVar3 + 0x68);
  iVar3 = *(int *)(iVar3 + 0x50);
  param_1 = (void *)0x1b58;
  uVar2 = (uint)bVar6;
  do {
    UI_SetChildVisibleByID(this,(int)param_1,uVar2);
    param_1 = (void *)((int)param_1 + 1);
  } while ((int)param_1 < 0x1b64);
  UI_SetChildVisibleByID(this,0x1f4a,uVar2);
  UI_SetChildVisibleByID(this,0x1f52,uVar2);
  iVar1 = (((iVar1 + iVar3) * -0x1e + 100) * 500) / 100;
  if (bVar6) {
    iVar4 = FUN_004017f0((void *)((int)this_00 + 0x148),*(int *)(iVar4 + 0x10c),(int *)0x0);
    FUN_0052f9b0(this,0x1f52,iVar4 + 4);
    FUN_0052f9b0(this,0x1b63,iVar4 + 4);
    FUN_0052f080(this,0x1b5d,&DAT_005686f4,*(undefined4 *)(iVar4 + 0x1884));
    FUN_0052f080(this,0x1b5e,&DAT_005686f4,*(undefined4 *)(iVar4 + 0x1888));
    FUN_0052f080(this,0x1b61,&DAT_005686f4,*(undefined4 *)(iVar4 + 0x188c));
    FUN_0052f080(this,0x1b62,&DAT_005686f4,*(undefined4 *)(iVar4 + 0x1890));
    iVar4 = FUN_004e2750(this_00,iVar4,0x17);
    FUN_0052f080(this,0x1b59,&DAT_005683a4,iVar4 * iVar1);
  }
  FUN_0052f080(this,0x1b65,&DAT_005683a4,iVar1);
  FUN_0052f080(this,0x1f76,(byte *)s__s__d_00568964,DAT_00581044);
  puVar5 = FUN_004e25b0(this_00,0x17,0);
  FUN_0052f080(this,0x1f68,&DAT_005686f4,puVar5);
  puVar5 = FUN_004e25b0(this_00,0x17,1);
  FUN_0052f080(this,0x1f67,&DAT_005686f4,puVar5);
  puVar5 = FUN_004e25b0(this_00,0x17,2);
  FUN_0052f080(this,0x1f54,&DAT_005686f4,puVar5);
  return;
}

