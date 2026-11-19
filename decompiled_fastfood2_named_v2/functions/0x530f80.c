// rea decompile_all
// name: FUN_00530f80
// address: 0x530f80
// body: available
// range: 0x530f80-0x531196 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00530f80(void *this,int param_1,int param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  CS_Enter(*(int *)(*(int *)((int)this + 0x134) + 0x1c8));
  if (*(int *)((int)this + 0xf4) <= *(int *)((int)this + 0xf0)) {
    if (*(int *)((int)this + 0xe8) == 0) {
      pvVar1 = operator_new(0x140);
      *(void **)((int)this + 0xe8) = pvVar1;
      pvVar1 = operator_new(0x140);
      *(void **)((int)this + 0xec) = pvVar1;
      uVar5 = *(int *)((int)this + 0xf4) + 0x28;
      *(uint *)((int)this + 0xf4) = uVar5;
      puVar4 = *(undefined4 **)((int)this + 0xe8);
      for (iVar3 = (uVar5 & 0x1fffffff) << 1; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      puVar4 = *(undefined4 **)((int)this + 0xec);
      for (iVar3 = (*(uint *)((int)this + 0xf4) & 0x1fffffff) << 1; iVar3 != 0; iVar3 = iVar3 + -1)
      {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    }
    else {
      puVar2 = operator_new(*(int *)((int)this + 0xf4) * 8 + 0x140);
      puVar4 = *(undefined4 **)((int)this + 0xe8);
      puVar6 = puVar2;
      for (iVar3 = (*(uint *)((int)this + 0xf4) & 0x1fffffff) << 1; iVar3 != 0; iVar3 = iVar3 + -1)
      {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      puVar4 = puVar2 + *(int *)((int)this + 0xf4) * 2;
      for (iVar3 = 0x50; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      Mem_Free(*(LPVOID *)((int)this + 0xe8));
      *(undefined4 **)((int)this + 0xe8) = puVar2;
      puVar2 = operator_new(*(int *)((int)this + 0xf4) * 8 + 0x140);
      puVar4 = *(undefined4 **)((int)this + 0xec);
      puVar6 = puVar2;
      for (iVar3 = (*(uint *)((int)this + 0xf4) & 0x1fffffff) << 1; iVar3 != 0; iVar3 = iVar3 + -1)
      {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      puVar4 = puVar2 + *(int *)((int)this + 0xf4) * 2;
      for (iVar3 = 0x50; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      Mem_Free(*(LPVOID *)((int)this + 0xec));
      *(undefined4 **)((int)this + 0xec) = puVar2;
      *(int *)((int)this + 0xf4) = *(int *)((int)this + 0xf4) + 0x28;
    }
  }
  iVar3 = FUN_00531330(this,param_2,'\x01');
  uVar5 = (*(int *)((int)this + 0xf0) - iVar3) * 8;
  if (0 < (int)uVar5) {
    FUN_0054e230((undefined4 *)(*(int *)((int)this + 0xe8) + 8 + iVar3 * 8),
                 (undefined4 *)(*(int *)((int)this + 0xe8) + iVar3 * 8),uVar5);
  }
  *(int *)(*(int *)((int)this + 0xe8) + iVar3 * 8) = param_1;
  *(int *)(*(int *)((int)this + 0xe8) + 4 + iVar3 * 8) = param_2;
  *(int *)(*(int *)((int)this + 0xec) + *(int *)((int)this + 0xf0) * 8) = param_1;
  *(int *)(*(int *)((int)this + 0xec) + 4 + *(int *)((int)this + 0xf0) * 8) = param_2;
  *(int *)((int)this + 0xf0) = *(int *)((int)this + 0xf0) + 1;
  if (*(int *)((int)this + 0x298) != 0) {
    FUN_00522f40((void *)(*(int *)((int)this + 0x298) + 4),*(undefined4 *)(param_1 + 4));
  }
  CS_Leave(*(int *)(*(int *)((int)this + 0x134) + 0x1c8));
  FUN_00521b30(param_1);
  return;
}

