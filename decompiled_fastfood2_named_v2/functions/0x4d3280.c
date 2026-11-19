// rea decompile_all
// name: FUN_004d3280
// address: 0x4d3280
// body: available
// range: 0x4d3280-0x4d32d3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d3280(undefined4 *param_1)

{
  void *this;
  LPVOID pvVar1;
  
  *param_1 = &PTR_FUN_0055c4f8;
  this = (void *)((int *)param_1[2])[0x16];
  if (this != (void *)0x0) {
    FUN_00533a50(this,*(int *)param_1[2]);
  }
  pvVar1 = (LPVOID)param_1[2];
  if (pvVar1 != (LPVOID)0x0) {
    FUN_004d32e0((int)pvVar1);
    Mem_Free(pvVar1);
  }
  if (param_1[4] != -1) {
    FUN_00533a50(*(void **)(DAT_0057c5cc + 0x2c180 + param_1[3] * 4),param_1[4]);
  }
  return;
}

