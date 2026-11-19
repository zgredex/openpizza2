// rea decompile_all
// name: Window_SetVisible
// address: 0x54a770
// body: available
// range: 0x54a770-0x54a7a9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Window_SetVisible(void *this,int param_1)

{
  HWND hWnd;
  
                    /* Leaf reversal proposal batch 1. */
  hWnd = *(HWND *)((int)this + 4);
  if (hWnd != (HWND)0x0) {
    if (param_1 != 0) {
      ShowWindow(hWnd,1);
      *(undefined4 *)((int)this + 0x20) = 1;
      return;
    }
    ShowWindow(hWnd,0);
    *(undefined4 *)((int)this + 0x20) = 0;
  }
  return;
}

