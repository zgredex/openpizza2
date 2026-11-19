// rea decompile_all
// name: Stats_GetMaxCategoryValue
// address: 0x510390
// body: available
// range: 0x510390-0x5103fa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall Stats_GetMaxCategoryValue(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float local_4;
  
  local_4 = 0.0;
  if (*(int *)(param_1 + 0x304) == 0) {
    return (float10)0.0;
  }
  iVar1 = Stats_GetMinMapField10(param_1);
  iVar2 = UI_GetMaxChildField10(param_1);
  for (; iVar1 <= iVar2; iVar1 = iVar1 + 1) {
    fVar3 = Stats_SumValuesByCategory(param_1,iVar1,param_2);
    if ((float10)local_4 < fVar3) {
      local_4 = (float)fVar3;
    }
  }
  return (float10)local_4;
}

