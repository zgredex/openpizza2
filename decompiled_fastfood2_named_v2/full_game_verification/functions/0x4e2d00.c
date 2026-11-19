// rea decompile_all
// name: Player_ComputeAverageRating
// address: 0x4e2d00
// body: available
// range: 0x4e2d00-0x4e2dbd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall Player_ComputeAverageRating(int param_1)

{
  void *this;
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  int local_c;
  
  iVar5 = 0;
  local_c = 0;
  local_10 = 0;
  if (0 < *(int *)(param_1 + 0x15c)) {
    do {
      this = (void *)IDMap_Lookup((void *)(param_1 + 0x148),local_10,(int *)0x0);
      iVar1 = Game_CountObjectsByType(this,0xffffffff);
      local_c = local_c + iVar1;
      iVar6 = 0;
      if (0 < iVar1) {
        do {
          piVar2 = (int *)IDMap_Lookup((void *)((int)this + 0x1500),iVar6,(int *)0x0);
          iVar3 = Rating_ClampAdjusted(*piVar2);
          iVar4 = Rating_AdjustA(*piVar2);
          iVar5 = iVar5 + iVar3 + iVar4;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar1);
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(param_1 + 0x15c));
    if ((iVar5 != 0) && (local_c != 0)) {
      return iVar5 / local_c;
    }
  }
  return 0;
}

