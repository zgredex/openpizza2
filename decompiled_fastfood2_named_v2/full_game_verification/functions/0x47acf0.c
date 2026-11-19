// rea decompile_all
// name: Product_ComputeFreshness
// address: 0x47acf0
// body: available
// range: 0x47acf0-0x47afff inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int Product_ComputeFreshness(int param_1)

{
  longlong lVar1;
  
  Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  if (*(double *)(param_1 + 0x70) == 14.1) {
    lVar1 = __ftol();
    return 0x26 - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 15.5) {
    lVar1 = __ftol();
    return 0x1e - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 16.9) {
    lVar1 = __ftol();
    return 0x16 - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 6.5) {
    lVar1 = __ftol();
    return 0x22 - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 7.5) {
    lVar1 = __ftol();
    return 0x1b - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 8.6) {
    lVar1 = __ftol();
    return 0x14 - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 2.5) {
    lVar1 = __ftol();
    return 0x1e - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 2.9) {
    lVar1 = __ftol();
    return 0x18 - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 3.6) {
    lVar1 = __ftol();
    return 0x12 - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 1.0) {
    lVar1 = __ftol();
    return 0x19 - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 1.2) {
    lVar1 = __ftol();
    return 0x14 - (int)lVar1;
  }
  if (*(double *)(param_1 + 0x70) == 1.6) {
    lVar1 = __ftol();
    return 0xf - (int)lVar1;
  }
  return 0;
}

