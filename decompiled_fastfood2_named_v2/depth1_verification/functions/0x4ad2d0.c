// rea decompile_all
// name: FUN_004ad2d0
// address: 0x4ad2d0
// body: available
// range: 0x4ad2d0-0x4ad344 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __cdecl FUN_004ad2d0(int param_1,void *param_2)

{
  void *this;
  int iVar1;
  float10 fVar2;
  
  this = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  switch(DAT_0057d62c) {
  case 0:
    iVar1 = Game_SumStatGridAll(this,param_1,8,param_2);
    return (float10)iVar1;
  case 1:
    fVar2 = Stats_SumRecordFloatMatrix((int)this,param_1,8,(int)param_2);
    return fVar2;
  case 2:
    iVar1 = Game_SumPlayerMatrixValues(this,param_1,8,param_2);
    return (float10)iVar1;
  case 3:
  case 4:
  case 5:
    return (float10)-3.0;
  default:
    return (float10)(float)param_2;
  }
}

