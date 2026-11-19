// rea decompile_all
// name: FUN_004d1cb0
// address: 0x4d1cb0
// body: available
// range: 0x4d1cb0-0x4d1d79 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_004d1cb0(void *this,void *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558d16;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((int)this + 0x58),0);
  local_4 = 0;
  List_Construct((void *)((int)this + 0x78),0);
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined ***)this = &PTR_FUN_0055c4ec;
  if (param_1 == (void *)0x0) {
    *(undefined4 *)((int)this + 4) = 0xffffffff;
    *(undefined4 *)((int)this + 8) = 0xffffffff;
    SetRect((LPRECT)((int)this + 0x10),0,0,0,0);
    *(undefined4 *)((int)this + 0x20) = 0xffffffff;
    *(undefined4 *)((int)this + 0x24) = 0xffffffff;
    *(undefined4 *)((int)this + 0x28) = 0xffffffff;
    *(undefined4 *)((int)this + 0x54) = 0xffffffff;
    *(undefined4 *)((int)this + 0x2c) = 0xffffffff;
    *(undefined4 *)((int)this + 0x48) = 0xffffffff;
    *(undefined4 *)((int)this + 0xc) = 0xffffffff;
    *(undefined4 *)((int)this + 0x30) = 0xffffffff;
    *(undefined4 *)((int)this + 0x34) = 0xffffffff;
    *(undefined4 *)((int)this + 0x4c) = 0;
    *(undefined4 *)((int)this + 0x50) = 0;
    *(undefined4 *)((int)this + 0x74) = 0;
    *(undefined4 *)((int)this + 0x38) = 0;
    *(undefined4 *)((int)this + 0x40) = 0;
    *(undefined4 *)((int)this + 0x44) = 0;
    *(undefined4 *)((int)this + 0x3c) = 0;
    *(undefined4 *)((int)this + 0x94) = 0;
    ExceptionList = local_c;
    return this;
  }
  FUN_004d1da0(this,param_1);
  ExceptionList = local_c;
  return this;
}

