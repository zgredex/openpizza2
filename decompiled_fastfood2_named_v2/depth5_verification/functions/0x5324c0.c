// rea decompile_all
// name: FUN_005324c0
// address: 0x5324c0
// body: available
// range: 0x5324c0-0x532509 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_005324c0(void *this,int param_1)

{
  LPVOID pvVar1;
  undefined4 uVar2;
  
  pvVar1 = (LPVOID)FUN_005230b0((void *)((int)this + 0x148),param_1);
  if (pvVar1 == (LPVOID)0x0) {
    return 0;
  }
  uVar2 = FUN_00522fe0((void *)((int)this + 0x148),param_1);
  FUN_00532510((int)pvVar1);
  FUN_0054dd78(pvVar1);
  return uVar2;
}

