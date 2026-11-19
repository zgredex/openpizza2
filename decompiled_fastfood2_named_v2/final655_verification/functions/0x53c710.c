// rea decompile_all
// name: FUN_0053c710
// address: 0x53c710
// body: available
// range: 0x53c710-0x53c7c4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_0053c710(void *this,uint param_1,int param_2,undefined4 param_3,int param_4,undefined1 param_5)

{
  uint uVar1;
  void *pvVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ad58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  SpriteBase_Construct(this);
  *(undefined ***)this = &PTR_Sprite_ScalarDeletingDestructor_0055c82c;
  local_4 = 0;
  *(undefined1 *)((int)this + 0x38) = 0;
  *(undefined1 *)((int)this + 0x39) = 1;
  *(undefined4 *)((int)this + 0x3c) = 0;
  FUN_0053a220(this,(short)param_1,(short)param_2,param_3,param_4,2,0,0);
  uVar1 = (param_1 * param_2 + (param_1 & 1)) * (param_4 >> 3);
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined1 *)((int)this + 0x34) = 1;
  *(undefined2 *)((int)this + 0xe) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  *(undefined1 *)((int)this + 4) = param_5;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(uint *)((int)this + 0x18) = uVar1;
  pvVar2 = operator_new(uVar1);
  *(void **)((int)this + 0x2c) = pvVar2;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined1 *)((int)this + 0x36) = 0xff;
  ExceptionList = local_c;
  return this;
}

