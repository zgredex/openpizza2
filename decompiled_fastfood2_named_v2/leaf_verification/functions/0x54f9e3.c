// rea decompile_all
// name: FUN_0054f9e3
// address: 0x54f9e3
// body: available
// range: 0x54f9e3-0x54fa51 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __cdecl FUN_0054f9e3(uint param_1)

{
  void *extraout_ECX;
  bool bVar1;
  void *this;
  
  if (DAT_005857cc == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      return param_1 - 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_00585be8);
    bVar1 = DAT_00585be4 != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_00585be8);
      this = (void *)0x13;
      FUN_0055395d(0x13);
    }
    param_1 = FUN_0054fa52(this,param_1);
    if (bVar1) {
      CS_LeaveIndexed(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_00585be8);
    }
  }
  return param_1;
}

