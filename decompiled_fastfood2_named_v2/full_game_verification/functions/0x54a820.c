// rea decompile_all
// name: Window_MoveToSidePanel
// address: 0x54a820
// body: available
// range: 0x54a820-0x54a87c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Window_MoveToSidePanel(int param_1)

{
  HWND hWnd;
  tagRECT *lpRect;
  tagRECT local_20;
  tagRECT local_10;
  
  if (*(int *)(param_1 + 4) != 0) {
    GetWindowRect(*(HWND *)(param_1 + 8),&local_20);
    lpRect = &local_10;
    hWnd = GetDesktopWindow();
    GetWindowRect(hWnd,lpRect);
    MoveWindow(*(HWND *)(param_1 + 4),local_20.right,local_20.top,
               (local_10.right - local_20.right) - local_10.left,local_20.bottom - local_20.top,1);
  }
  return;
}

