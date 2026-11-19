// rea decompile_all
// name: FUN_0052bc80
// address: 0x52bc80
// body: available
// range: 0x52bc80-0x52bd4d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_0052bc80(void *this,undefined4 param_1,int param_2,int param_3,char *param_4,char *param_5,
            int param_6,undefined4 *param_7)

{
  void *this_00;
  uint uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a8c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00520a80(this,param_1,param_2,param_3,param_6);
  *(undefined ***)this = &PTR_FUN_0055c7cc;
  this_00 = *(void **)(param_6 + 0x134);
  *param_7 = 0;
  local_4 = 0;
  *(undefined4 *)((int)this + 0x40) = 3;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 0x88) = 0;
  uVar1 = FUN_00527090(this_00,param_4);
  *(uint *)((int)this + 0x54) = uVar1;
  if (uVar1 == 0) {
    *param_7 = 1;
  }
  else {
    *(undefined4 *)((int)this + 0x88) = 0;
    *(undefined4 *)((int)this + 0x58) = 0xffffff;
    *(undefined2 *)((int)this + 100) = 0;
    *(undefined2 *)((int)this + 0x66) = 0xffff;
    *(undefined4 *)((int)this + 0x6c) = 0;
    *(undefined4 *)((int)this + 0x70) = 3;
    FUN_0052c500(this,param_5);
    UI_DrawTextControl(this);
    *(undefined4 *)((int)this + 0x14) = 0;
  }
  ExceptionList = local_c;
  return this;
}

