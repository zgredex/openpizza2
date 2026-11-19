// rea decompile_all
// name: Win32_PumpMessages
// address: 0x539700
// body: available
// range: 0x539700-0x53976b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Win32_PumpMessages(void)

{
  int iVar1;
  BOOL BVar2;
  tagMSG local_1c;
  
                    /* Leaf reversal proposal batch 2. */
  iVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,0);
  while ((iVar1 != 0 && (BVar2 = GetMessageA(&local_1c,(HWND)0x0,0,0), BVar2 != 0))) {
    TranslateMessage(&local_1c);
    DispatchMessageA(&local_1c);
    iVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,0);
  }
  return;
}

