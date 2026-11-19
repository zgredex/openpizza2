// rea decompile_all
// name: FUN_004e4060
// address: 0x4e4060
// body: available
// range: 0x4e4060-0x4e4132 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall FUN_004e4060(int param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = *(int *)(param_1 + 8);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  uStack_34 = 0x40340000;
  local_30 = 0;
  local_2c = 0x40590000;
  local_28 = 0;
  local_24 = 0x407f4000;
  local_20 = 0;
  local_1c = 0x4062c000;
  local_18 = 0;
  local_14 = 0x4072c000;
  local_10 = 0;
  local_c = 0x40668000;
  if ((iVar1 < 1) || (6 < iVar1)) {
    iVar1 = 1;
  }
  lVar2 = FUN_00403850((float)((*(int *)(param_2 + 0x54) + *(int *)(param_2 + 0x3c)) * -3 + 100) *
                       (float)*(double *)(&local_40 + iVar1 * 2) *
                       (float)*(double *)(param_1 + 0x70) * 0.01);
  return (float10)(int)lVar2;
}

