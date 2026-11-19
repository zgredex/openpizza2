// rea decompile_all
// name: Branch_UpdateStarRating
// address: 0x48e6d0
// body: available
// range: 0x48e6d0-0x48e71f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Branch_UpdateStarRating(void *param_1)

{
  int iVar1;
  int iVar2;
  
                    /* Shows the branch's star sprites for its rating. */
  iVar1 = 0;
  iVar2 = *(int *)(*(int *)(DAT_0057c670 + 0x9c) + 0x14b4);
  if (0 < iVar2) {
    do {
      UI_ShowChildByID(param_1,iVar1 + 0x1f49);
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  for (; iVar2 < 5; iVar2 = iVar2 + 1) {
    UI_RemoveObjectByKey(param_1,iVar2 + 0x1f49);
  }
  return;
}

