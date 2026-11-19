// rea decompile_all
// name: Debug_WarningMessageBox
// address: 0x403510
// body: available
// range: 0x403510-0x403572 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Debug_WarningMessageBox(void)

{
  undefined1 local_res0;
  byte *in_stack_00001004;
  undefined4 auStack_7ffffffc [536870904];
  
                    /* Formats and shows a developer warning message box. */
  FUN_0054f110(local_res0);
  FUN_0054f084(&local_res0,in_stack_00001004,(undefined4 *)((int)register0x00000010 + 0x1008));
  MessageBoxA(DAT_0057c5d0,&local_res0,s_Achtung_00563774,0);
  if (DAT_0057c5d0 != (HWND)0x0) {
    SetWindowPos(DAT_0057c5d0,(HWND)0x0,0,0,0,0,3);
  }
  return;
}

