// rea decompile_all
// name: Game_AllBuildingCategoryRatingsAbove
// address: 0x502a10
// body: available
// range: 0x502a10-0x502a8a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint Game_AllBuildingCategoryRatingsAbove(int param_1)

{
  int iVar1;
  int iVar2;
  void *this;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar2 = *(int *)(iVar1 + 0x15c);
  iVar5 = iVar1;
  if (0 < iVar2) {
    do {
      this = (void *)IDMap_Lookup((void *)(iVar1 + 0x148),iVar4,(int *)0x0);
      iVar5 = 0;
      do {
        uVar3 = Branch_GetCustomerGroupRating(this,iVar5,1);
        if ((int)uVar3 < param_1) {
          return uVar3 & 0xffffff00;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      iVar4 = iVar4 + 1;
      iVar5 = iVar2;
    } while (iVar4 < iVar2);
  }
  return CONCAT31((int3)((uint)iVar5 >> 8),1);
}

