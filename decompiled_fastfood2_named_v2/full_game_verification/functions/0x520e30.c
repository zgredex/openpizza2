// rea decompile_all
// name: UI_Child_Activate
// address: 0x520e30
// body: available
// range: 0x520e30-0x520e5c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall UI_Child_Activate(int param_1)

{
                    /* Activates a UI child once, selecting its group member and dirtying its rect.
                        */
  if (*(int *)(param_1 + 0x20) == 0) {
    *(undefined4 *)(param_1 + 0x20) = 1;
    UI_Group_SelectMemberByKey(*(void **)(param_1 + 8),*(int *)(param_1 + 4));
    UI_ClipRect(*(void **)(param_1 + 8),(int *)(param_1 + 0x28),1);
  }
  return;
}

