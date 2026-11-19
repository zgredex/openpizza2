// rea decompile_all
// name: FUN_00502890
// address: 0x502890
// body: available
// range: 0x502890-0x502908 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00502890(int param_1)

{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  undefined4 extraout_EDX;
  undefined4 uVar6;
  undefined4 extraout_EDX_00;
  int iVar7;
  int iVar8;
  
  iVar7 = 0;
  uVar1 = *(uint *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  uVar2 = *(uint *)(uVar1 + 0x15c);
  uVar5 = uVar1;
  if (0 < (int)uVar2) {
    do {
      pvVar3 = (void *)FUN_004017f0((void *)(uVar1 + 0x148),iVar7,(int *)0x0);
      iVar8 = 0;
      uVar6 = extraout_EDX;
      do {
        iVar4 = Game_UpdateDailyStats(pvVar3,uVar6,iVar8);
        if (param_1 < iVar4) {
          return CONCAT31((int3)((uint)iVar4 >> 8),1);
        }
        iVar8 = iVar8 + 1;
        uVar6 = extraout_EDX_00;
      } while (iVar8 < 8);
      iVar7 = iVar7 + 1;
      uVar5 = uVar2;
    } while (iVar7 < (int)uVar2);
  }
  return uVar5 & 0xffffff00;
}

