// rea decompile_all
// name: Game_GetBuildingQualityBand
// address: 0x502030
// body: available
// range: 0x502030-0x50211e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 Game_GetBuildingQualityBand(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *this;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_14;
  int local_10;
  
  local_10 = 0;
  local_14 = 0;
  iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar2 = *(int *)(iVar1 + 0x15c);
  if (0 < iVar2) {
    do {
      this = (void *)IDMap_Lookup((void *)(iVar1 + 0x148),local_14,(int *)0x0);
      iVar4 = Game_CountObjectsByType(this,0xffffffff);
      iVar7 = 0;
      iVar8 = 0;
      if (0 < iVar4) {
        do {
          piVar5 = (int *)IDMap_Lookup((void *)((int)this + 0x1500),iVar8,(int *)0x0);
          iVar3 = *(int *)(*piVar5 + 0xc);
          iVar6 = Rating_AdjustB(*piVar5);
          iVar7 = iVar7 + iVar6 + iVar3;
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar4);
      }
      if (iVar4 == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = iVar7 / (iVar4 * 2);
      }
      if (local_10 < iVar7) {
        local_10 = iVar7;
      }
      local_14 = local_14 + 1;
    } while (local_14 < iVar2);
    if (0x50 < local_10) {
      return 3;
    }
    if (0x3b < local_10) {
      return 2;
    }
    if (0x28 < local_10) {
      return 1;
    }
  }
  return 0;
}

