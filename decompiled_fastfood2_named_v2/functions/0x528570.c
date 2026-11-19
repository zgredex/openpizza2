// rea decompile_all
// name: FUN_00528570
// address: 0x528570
// body: available
// range: 0x528570-0x5286d3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_00528570(void *this,void *param_1,int param_2,undefined4 param_3,int *param_4)

{
  void *pvVar1;
  void *this_00;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *local_11c;
  CHAR local_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0055a81e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = &PTR_FUN_0055c788;
  *(int *)((int)this + 100) = param_2;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x68) = 0;
  pvVar1 = *(void **)(param_2 + 0x10);
  local_11c = (undefined4 *)((int)this + 4);
  puVar2 = local_11c;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  iVar3 = 0;
  while( true ) {
    local_4 = 0xffffffff;
    String_Format(local_110,(byte *)s__s__02d_spr_00573b9c,param_3);
    this_00 = operator_new(0x50);
    local_4 = 0;
    if (this_00 == (void *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = Sprite_Load(this_00,param_1,pvVar1,local_110,param_4,0,(void *)0x0,0);
    }
    local_4 = 0xffffffff;
    *local_11c = puVar2;
    if ((param_4 != (int *)0x0) && (*param_4 != 0)) break;
    iVar3 = iVar3 + 1;
    local_11c = local_11c + 1;
    if (8 < iVar3) {
      *(undefined4 *)((int)this + 0x38) = 10;
      *(undefined4 *)((int)this + 0x3c) = 10;
      *(undefined4 *)((int)this + 0x28) = 0x50;
      *(undefined4 *)((int)this + 0x2c) = 200;
      *(undefined4 *)((int)this + 0x44) = 0;
      *(undefined4 *)((int)this + 0x54) = 0;
      *(undefined4 *)((int)this + 0x5c) = 0;
      *(undefined4 *)((int)this + 0x60) = 0xffffff;
      *(undefined4 *)((int)this + 0x68) = 0;
      *(undefined4 *)((int)this + 0x48) = 0xffffffff;
      FUN_0053d040(*(void **)((int)this + 4),(uint *)((int)this + 0x30),(uint *)((int)this + 0x34));
      puVar2 = FUN_00539ea0(param_1);
      *(undefined4 **)((int)this + 0x50) = puVar2;
      ExceptionList = local_c;
      return this;
    }
  }
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  *(undefined4 *)((int)this + iVar3 * 4 + 4) = 0;
  ExceptionList = local_c;
  return this;
}

