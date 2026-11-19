// rea decompile_all
// name: FUN_004f0e30
// address: 0x4f0e30
// body: available
// range: 0x4f0e30-0x4f1065 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004f0e30(void *this,int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 uVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *local_8;
  undefined4 *local_4;
  
  FUN_004f0850(this,(int)param_1,(int *)&param_1,(int *)&local_8,(undefined4 *)0x0,(undefined4 *)0x0
              );
  if (*param_1 == 0) {
    pvVar3 = operator_new(0x28);
    *param_1 = (int)pvVar3;
  }
  else {
    local_4 = operator_new((*local_8 + 1) * 0x28);
    puVar7 = (undefined4 *)*param_1;
    puVar8 = local_4;
    for (uVar5 = (uint)(*local_8 * 0x28) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    FUN_0054dd78((LPVOID)*param_1);
    *param_1 = (int)local_4;
  }
  iVar1 = param_3;
  iVar6 = param_2;
  iVar4 = FUN_004ed5a0(this,param_2,param_3,(int *)0x0,0);
  if (iVar4 == 0) {
    FUN_0048e0a0();
  }
  else {
    *(undefined4 *)(*param_1 + 8 + *local_8 * 0x28) = **(undefined4 **)(iVar4 + 8);
  }
  *(undefined1 *)(*param_1 + *local_8 * 0x28) = 0;
  uVar2 = FUN_004f0e20((int)this);
  *(undefined2 *)(*param_1 + 2 + *local_8 * 0x28) = uVar2;
  *(short *)(*param_1 + 4 + *local_8 * 0x28) = (short)*local_8;
  *(undefined1 *)(*param_1 + 6 + *local_8 * 0x28) = 0;
  *(int *)(*param_1 + 0xc + *local_8 * 0x28) = *(int *)((int)this + 0x24) + iVar6;
  *(int *)(*param_1 + 0x10 + *local_8 * 0x28) = *(int *)((int)this + 0x28) + iVar1;
  *(undefined2 *)(*param_1 + 0x14 + *local_8 * 0x28) = 0xffff;
  *(undefined2 *)(*param_1 + 0x16 + *local_8 * 0x28) = 0xffff;
  *(undefined2 *)(*param_1 + 0x18 + *local_8 * 0x28) = 0xffff;
  *(undefined2 *)(*param_1 + 0x1a + *local_8 * 0x28) = 0xffff;
  *(undefined2 *)(*param_1 + 0x1c + *local_8 * 0x28) = 0xffff;
  *(undefined2 *)(*param_1 + 0x1e + *local_8 * 0x28) = 0xffff;
  *(undefined2 *)(*param_1 + 0x20 + *local_8 * 0x28) = 0xffff;
  *(undefined2 *)(*param_1 + 0x22 + *local_8 * 0x28) = 0xffff;
  *(undefined1 *)(*param_1 + 0x24 + *local_8 * 0x28) = 0;
  *local_8 = *local_8 + 1;
  return *param_1 + -0x28 + *local_8 * 0x28;
}

