// rea decompile_all
// name: UI_SetChildVisibleByID
// address: 0x5316f0
// body: available
// range: 0x5316f0-0x53173f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall UI_SetChildVisibleByID(void *this,int param_1,int param_2)

{
  int iVar1;
  
                    /* Shows or hides a child element by id. */
  iVar1 = BinarySearch8(this,param_1,'\0');
  if (iVar1 == -1) {
    return 0;
  }
  if (param_2 == 0) {
    UI_ClearPendingClipFlag(*(int *)(*(int *)((int)this + 0xe8) + iVar1 * 8));
    return 1;
  }
  UI_Child_Activate(*(int *)(*(int *)((int)this + 0xe8) + iVar1 * 8));
  return 1;
}

