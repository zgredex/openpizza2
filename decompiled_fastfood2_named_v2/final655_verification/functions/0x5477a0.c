// rea decompile_all
// name: FUN_005477a0
// address: 0x5477a0
// body: available
// range: 0x5477a0-0x54780b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005477a0(void *this,undefined4 *param_1)

{
  uint uVar1;
  
  DAT_00575094 = param_1[1];
  DAT_00575098 = param_1[2];
  DAT_0057509c = param_1[3];
  DAT_00575090._2_2_ = (undefined2)((uint)*param_1 >> 0x10);
  DAT_00575090._0_2_ = CONCAT11(*(undefined1 *)((int)param_1 + 1),(char)*param_1);
  FUN_005478c0(this);
  *(undefined4 *)((int)this + 0x1d0) = param_1[1];
  uVar1 = FUN_00547a00(param_1[2]);
  *(uint *)((int)this + 0x1d4) = uVar1;
  uVar1 = FUN_00547a00(param_1[3]);
  *(uint *)((int)this + 0x1d8) = uVar1;
  return;
}

