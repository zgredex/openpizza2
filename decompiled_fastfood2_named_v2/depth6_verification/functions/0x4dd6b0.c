// rea decompile_all
// name: FUN_004dd6b0
// address: 0x4dd6b0
// body: available
// range: 0x4dd6b0-0x4dd8c1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_004dd6b0(void *this,undefined4 param_1)

{
  void *this_00;
  undefined4 *puVar1;
  int iVar2;
  void *this_01;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005592f8;
  local_c = ExceptionList;
  this_01 = (void *)0x0;
  ExceptionList = &local_c;
  FUN_004013a0((void *)((int)this + 0x110),0);
  local_4 = 0;
  FUN_004013a0((void *)((int)this + 300),0);
  local_4._0_1_ = 1;
  FUN_004013a0((void *)((int)this + 0x148),0);
  local_4._0_1_ = 2;
  FUN_004013a0((void *)((int)this + 0x164),0);
  local_4._0_1_ = 3;
  FUN_004013a0((void *)((int)this + 0x180),0);
  local_4._0_1_ = 4;
  FUN_004013a0((void *)((int)this + 0x19c),0);
  local_4._0_1_ = 5;
  FUN_004013a0((void *)((int)this + 0x1b8),0);
  *(undefined4 *)((int)this + 0x48) = 0xffffffff;
  *(undefined4 *)((int)this + 0x50) = 0xffffffff;
  *(undefined4 *)((int)this + 0x4c) = param_1;
  *(undefined4 *)((int)this + 0x1e4) = 1;
  *(undefined4 *)((int)this + 100) = 1;
  *(undefined4 *)((int)this + 0x68) = 1;
  *(undefined4 *)((int)this + 0x6c) = 1;
  *(undefined4 *)((int)this + 0x108) = 0;
  *(undefined4 *)((int)this + 0xf0) = 100;
  *(undefined4 *)((int)this + 0xf4) = 100;
  *(undefined4 *)((int)this + 0xf8) = 100;
  *(undefined ***)this = &PTR_FUN_0055c568;
  *(undefined2 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x1d4) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x10c) = 0;
  *(undefined4 *)((int)this + 0x1e0) = 0;
  *(undefined4 *)((int)this + 0x1d8) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 0x1e8) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0xfc) = 0;
  *(undefined4 *)((int)this + 0x100) = 0;
  puVar1 = (undefined4 *)((int)this + 0x70);
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puVar1 = (undefined4 *)((int)this + 0x94);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  local_4._0_1_ = 6;
  *(undefined4 *)((int)this + 0xac) = 0;
  *(undefined2 *)((int)this + 0xb0) = 0;
  puVar1 = (undefined4 *)((int)this + 0xcc);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puVar1 = (undefined4 *)((int)this + 0xb4);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  *(undefined4 *)((int)this + 0xe4) = 0;
  *(undefined4 *)((int)this + 0xe8) = 0;
  *(undefined2 *)((int)this + 0xec) = 0;
  this_00 = operator_new(0x35c);
  local_4._0_1_ = 7;
  if (this_00 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_00401040(this_00,(uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10),
                          (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4),(int)this);
  }
  local_4._0_1_ = 6;
  FUN_004014b0((void *)((int)this + 0x164),puVar1);
  puVar1 = operator_new(0x30);
  local_4._0_1_ = 8;
  if (puVar1 != (undefined4 *)0x0) {
    this_01 = (void *)FUN_0050f630(puVar1);
  }
  local_4 = CONCAT31(local_4._1_3_,6);
  FUN_0050fb40(this_01,1);
  FUN_004014b0((void *)((int)this + 300),this_01);
  ExceptionList = local_c;
  return this;
}

