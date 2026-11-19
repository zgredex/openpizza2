// rea decompile_all
// name: FUN_0050a280
// address: 0x50a280
// body: available
// range: 0x50a280-0x50a3b1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0050a280(void *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *this;
  void *this_00;
  LPVOID pvVar4;
  float10 fVar5;
  int iVar6;
  
  iVar1 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x20),*(int *)((int)param_1 + 0x50),(int *)0x0);
  iVar6 = *(int *)((int)param_1 + 0xfc);
  pvVar2 = (void *)FUN_00489820(DAT_0057c670,*(int *)(iVar1 + 0x81c),*(int *)(iVar1 + 0x820));
  if (pvVar2 == (void *)0x0) {
    FUN_00507e20(param_1,3,*(int *)((int)param_1 + 0xcc));
    return;
  }
  FUN_00507e20(param_1,1,*(int *)((int)pvVar2 + 0x16f0));
  puVar3 = (undefined4 *)FUN_0047f400(pvVar2,*(int *)((int)param_1 + 0x88));
  if (puVar3 == (undefined4 *)0x0) {
    return;
  }
  this = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)pvVar2 + 0x30));
  if ((this == (void *)0x0) || (this_00 = (void *)FUN_004e2330(this,iVar6), this_00 == (void *)0x0))
  {
    *puVar3 = 200000;
    iVar6 = 0;
    pvVar2 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)pvVar2 + 0x34),
                                  (int *)0x0);
    fVar5 = FUN_004e2410((int)this,pvVar2,iVar6);
    puVar3[4] = (float)fVar5;
    puVar3[3] = 0x28;
    puVar3[1] = 600;
    puVar3[2] = 600;
    return;
  }
  pvVar4 = (LPVOID)FUN_005142c0(this_00,*(int *)((int)pvVar2 + 0x3c));
  if (pvVar4 == (LPVOID)0x0) {
    *puVar3 = 0;
    FUN_00507550(param_1,10);
    return;
  }
  *puVar3 = 200000;
  puVar3[4] = *(undefined4 *)((int)pvVar4 + 0x10);
  puVar3[1] = *(undefined4 *)((int)pvVar4 + 4);
  puVar3[2] = *(undefined4 *)((int)pvVar4 + 4);
  puVar3[3] = *(undefined4 *)((int)pvVar4 + 0xc);
  FUN_0054dd78(pvVar4);
  return;
}

