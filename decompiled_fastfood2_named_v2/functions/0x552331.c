// rea decompile_all
// name: FUN_00552331
// address: 0x552331
// body: available
// range: 0x552331-0x552384 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00552331(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_00553934();
  DAT_00576ac4 = TlsAlloc();
  if (DAT_00576ac4 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_005539d3(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_00576ac4,lpTlsValue);
      if (BVar1 != 0) {
        FUN_00552385((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}

