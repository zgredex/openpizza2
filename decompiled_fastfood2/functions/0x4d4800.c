// rea decompile_all
// name: FUN_004d4800
// address: 0x4d4800
// body: available
// range: 0x4d4800-0x4d4870 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_004d4800(void *this,int *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558e2c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004013a0((void *)((int)this + 0xfac),0);
  local_4 = 0;
  FUN_004013a0((void *)((int)this + 0xfc8),0);
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined ***)this = &PTR_FUN_0055c500;
  FUN_004d6cb0(this,param_1);
  FUN_004d4880((int)this);
  ExceptionList = local_c;
  return this;
}

