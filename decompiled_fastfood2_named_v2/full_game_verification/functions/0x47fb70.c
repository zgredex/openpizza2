// rea decompile_all
// name: Branch_RefreshConstructionButtons
// address: 0x47fb70
// body: available
// range: 0x47fb70-0x47fbc2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Branch_RefreshConstructionButtons(void *param_1)

{
  int iVar1;
  
  if (*(int *)((int)param_1 + 0x2c) == 7) {
    iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
    Map_ClearObjectFlags(*(void **)((int)param_1 + 0x16f0),*(void **)(iVar1 + 0xfa8),0xffffffff);
    return;
  }
  Game_ClearObjectFlag20((int)param_1);
  Game_ToggleObjectFlag2(param_1);
  Game_UpdateObjectList2((int)param_1);
  Game_CheckObjectUpgrade(param_1);
  return;
}

