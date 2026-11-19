// rea decompile_all
// name: Game_FindBestQualityBuilding
// address: 0x4d8220
// body: available
// range: 0x4d8220-0x4d82a8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * Game_FindBestQualityBuilding(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 extraout_EDX;
  int iVar4;
  int iVar5;
  int local_8;
  void *local_4;
  
                    /* Finds the highest-rated owned building across all companies, or NULL below
                       30. */
  iVar4 = -1;
  local_4 = (void *)0x0;
  local_8 = 0;
  do {
    iVar1 = FUN_00488be0(DAT_0057c670,local_8);
    if ((iVar1 != 0) && (iVar5 = 0, 0 < *(int *)(iVar1 + 0x15c))) {
      do {
        pvVar2 = (void *)FUN_004017f0((void *)(iVar1 + 0x148),iVar5,(int *)0x0);
        if ((pvVar2 != (void *)0x0) &&
           (iVar3 = Branch_ComputeBuildingRating(pvVar2,extraout_EDX,-1), iVar4 < iVar3)) {
          iVar4 = iVar3;
          local_4 = pvVar2;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(iVar1 + 0x15c));
    }
    local_8 = local_8 + 1;
  } while (local_8 < 6);
  if (iVar4 < 0x1e) {
    return (void *)0x0;
  }
  return local_4;
}

