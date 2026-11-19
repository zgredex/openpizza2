// rea decompile_all
// name: FUN_0052e9d0
// address: 0x52e9d0
// body: available
// range: 0x52e9d0-0x52eb67 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_0052e9d0(void *this,undefined4 param_1,void *param_2,int param_3,int param_4,int param_5,
            int param_6,undefined4 param_7,undefined4 *param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint local_28;
  uint local_24;
  void *local_20;
  uint local_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a9ac;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_20 = this;
  FUN_00522e80((void *)((int)this + 0x148),0);
  local_4 = 0;
  FUN_00522e80((void *)((int)this + 0x2a8),0);
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined ***)this = &PTR_FUN_0055c808;
  SetRect((LPRECT)((int)this + 0x28),param_3,param_4,param_5,param_6);
  FUN_0052ee10(this,param_2,param_1,param_7);
  *(undefined4 *)((int)this + 0xfc) = param_9;
  *(undefined4 *)((int)this + 0x100) = param_10;
  *(undefined4 *)((int)this + 0x104) = param_11;
  *(undefined4 *)((int)this + 0x108) = param_12;
  puVar4 = (undefined4 *)((int)this + 0x114);
  iVar5 = 8;
  do {
    uVar1 = *param_8;
    param_8 = param_8 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_0053d040(*(void **)((int)this + 0x118),&local_24,&local_28);
  uVar2 = local_28;
  FUN_0053d040(*(void **)((int)this + 0x120),&local_24,&local_28);
  uVar3 = local_24;
  FUN_0053d040(*(void **)((int)this + 0x128),&local_24,&local_28);
  FUN_0053d040(*(void **)((int)this + 0x130),&local_24,&local_28);
  local_1c = local_24;
  FUN_0052ef20(this,param_3,param_4,local_24 + uVar3 + param_5,uVar2 + local_28 + param_6);
  *(uint *)((int)this + 0x1c) = *(int *)((int)this + 0xc) + uVar2;
  *(uint *)((int)this + 0x20) = *(int *)((int)this + 0x10) - uVar3;
  *(uint *)((int)this + 0x18) = *(int *)((int)this + 8) + local_1c;
  *(uint *)((int)this + 0x24) = *(int *)((int)this + 0x14) - local_28;
  *(undefined4 *)((int)this + 0x2c4) = 0;
  ExceptionList = local_c;
  return this;
}

