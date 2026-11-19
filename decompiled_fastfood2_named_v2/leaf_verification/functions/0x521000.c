// rea decompile_all
// name: FUN_00521000
// address: 0x521000
// body: available
// range: 0x521000-0x52115c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_00521000(void *this,undefined4 param_1,int param_2,int param_3,uint param_4,int param_5,
            uint param_6,undefined4 param_7)

{
  void *this_00;
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a5b1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00520a80(this,param_1,param_2,param_3,param_7);
  local_4 = 0;
  FUN_00522e80((void *)((int)this + 0x84),0);
  local_4._0_1_ = 1;
  *(undefined ***)this = &PTR_FUN_0055c73c;
  if ((int)param_6 < 8) {
    param_6 = (int)param_6 >> 3;
  }
  uVar4 = param_6 & 0x38;
  if (uVar4 == 0) {
    uVar4 = 0x10;
  }
  Object_ClearFieldsA((int)this);
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x98) = 0;
  *(undefined4 *)((int)this + 0x40) = 7;
  UI_SetAbsolutePosition(this,param_4,param_5);
  if ((int)param_4 < 1) {
    param_4 = 1;
  }
  if (param_5 < 1) {
    param_5 = 1;
  }
  puVar1 = FUN_00539ea0(DAT_0057c5c8);
  *(undefined4 **)((int)this + 0x68) = puVar1;
  pvVar2 = operator_new(0x50);
  local_4._0_1_ = 2;
  if (pvVar2 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_0053c710(pvVar2,param_4,param_5,0,uVar4,0);
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined4 **)((int)this + 0x60) = puVar1;
  if (uVar4 == 0x10) {
    uVar3 = FUN_00539840(*(void **)((int)this + 0x68),0xff00);
    puVar1 = *(undefined4 **)((int)this + 0x60);
  }
  else {
    uVar3 = 0;
  }
  Sprite_SetColorKey(puVar1,uVar3);
  FUN_0053d6c0(*(void **)((int)this + 0x60),-1);
  pvVar2 = *(void **)((int)this + 0x60);
  this_00 = *(void **)((int)this + 0x68);
  if (*(char *)((int)pvVar2 + 0x39) == '\0') {
    FUN_0053cea0(pvVar2);
  }
  FUN_00539280(this_00,*(undefined4 *)((int)pvVar2 + 0x2c),
               (ushort)((int)*(short *)((int)pvVar2 + 6) >> 1),*(ushort *)((int)pvVar2 + 8),
               (int)*(short *)((int)pvVar2 + 6));
  ExceptionList = local_c;
  return this;
}

