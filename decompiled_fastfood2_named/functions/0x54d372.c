// rea decompile_all
// name: FUN_0054d372
// address: 0x54d372
// body: available
// range: 0x54d372-0x54d3bd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __fastcall FUN_0054d372(int *param_1)

{
  uint uVar1;
  
  if (param_1[2] != 0) {
    if (param_1[3] == -1) {
      (**(code **)(*param_1 + 0x20))();
    }
    uVar1 = (**(code **)(*param_1 + 0x20))();
    param_1[3] = uVar1;
    return uVar1;
  }
  if ((param_1[0xb] == 0) || ((uint)param_1[0xb] <= (uint)param_1[10])) {
    (**(code **)(*param_1 + 0x20))();
  }
  param_1[10] = param_1[10] + 1;
  if ((byte *)param_1[10] < (byte *)param_1[0xb]) {
    return (uint)*(byte *)param_1[10];
  }
  uVar1 = (**(code **)(*param_1 + 0x20))();
  return uVar1;
}

