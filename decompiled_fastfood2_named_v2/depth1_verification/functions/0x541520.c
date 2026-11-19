// rea decompile_all
// name: FUN_00541520
// address: 0x541520
// body: available
// range: 0x541520-0x541651 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_00541520(void *this,int *param_1,undefined4 *param_2,undefined4 param_3,uint param_4,
            uint *param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055af30;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_005406a0(this,param_1,param_2,param_3,(undefined4 *)(param_4 | 0x14));
  puVar1 = (undefined4 *)((int)this + 0x5c);
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  local_4 = 0;
  *puVar1 = 0;
  *(undefined1 *)((int)this + 0xa0) = 0;
  *(undefined1 *)((int)this + 0xa1) = 0;
  DVar3 = timeGetTime();
  *(DWORD *)((int)this + 0xa4) = DVar3;
  *(DWORD *)((int)this + 0xa8) = DVar3;
  *(undefined ***)this = &PTR_LAB_0055c8c8;
  if (-1 < (int)*param_5) {
    uVar4 = (**(code **)**(undefined4 **)((int)this + 0x48))
                      (*(undefined4 **)((int)this + 0x48),&DAT_0055cb88,puVar1);
    if ((int)uVar4 < 0) {
      *puVar1 = 0;
    }
    else {
      puVar2 = (undefined4 *)((int)this + 0x60);
      puVar6 = puVar2;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *puVar2 = 0x40;
      (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,puVar2);
    }
    *(uint *)((int)this + 0x50) = *(uint *)((int)this + 0x50) | 3;
    if (param_5 != (uint *)0x0) {
      *param_5 = uVar4;
    }
  }
  *(undefined4 *)((int)this + 0xb0) = 0;
  *(undefined ***)this = &PTR_LAB_0055c8b0;
  local_4 = 1;
  *(undefined4 *)((int)this + 0xac) = 0;
  if (-1 < (int)*param_5) {
    uVar4 = (*(code *)**(undefined4 **)*puVar1)
                      ((undefined4 *)*puVar1,&DAT_0055cb78,(undefined4 *)((int)this + 0xac));
    if (-1 < (int)uVar4) {
      uVar4 = Sound_QueryFormatFlags((int)this);
    }
    if (param_5 != (uint *)0x0) {
      *param_5 = uVar4;
    }
  }
  ExceptionList = pvStack_c;
  return this;
}

