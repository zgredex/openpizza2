// rea decompile_all
// name: FUN_00489070
// address: 0x489070
// body: available
// range: 0x489070-0x489150 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 FUN_00489070(int param_1,undefined4 param_2)

{
  float fVar1;
  float10 fVar2;
  
  fVar1 = *(float *)(param_1 + 0x98);
  fVar2 = (float10)(0xb - DAT_0057bb24) * (float10)0.5;
  switch(param_2) {
  case 0:
    return (float10)fVar1 * (float10)3.0 + fVar2 + (float10)4.0;
  case 1:
    return (float10)fVar1 * (float10)4.0 + fVar2 + (float10)5.0;
  case 2:
    return (float10)fVar1 * (float10)4.0 + fVar2 + (float10)8.0;
  case 3:
    return (float10)fVar1 * (float10)3.0 + fVar2 + (float10)8.0;
  case 4:
    return (float10)fVar1 * (float10)7.0 + fVar2 + (float10)10.0;
  case 5:
  case 8:
    return (float10)fVar1 * (float10)10.0 + fVar2 + (float10)8.0;
  case 6:
    return (float10)fVar1 * (float10)3.0 + fVar2 + (float10)7.0;
  case 7:
    fVar2 = fVar2 + (float10)12.0;
  }
  return fVar2;
}

