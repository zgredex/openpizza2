// rea decompile_all
// name: RecordList_FindFreeSlot
// address: 0x5338c0
// body: available
// range: 0x5338c0-0x533a41 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall RecordList_FindFreeSlot(void *this,int param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  
  CS_Enter(0x5842a0);
  if (param_1 == -1) {
    iVar7 = 0;
    param_1 = 0;
    if (0 < *(int *)((int)this + 0x48)) {
      piVar1 = *(int **)((int)this + 0x4c);
      do {
        if (*piVar1 == -1) break;
        iVar7 = iVar7 + 1;
        piVar1 = piVar1 + 0x12;
      } while (iVar7 < *(int *)((int)this + 0x48));
      param_1 = iVar7;
    }
  }
  if (*(int *)((int)this + 0x48) <= param_1) {
    if (*(int *)((int)this + 0x4c) == 0) {
      iVar7 = param_1 + 0x14;
      *(int *)((int)this + 0x48) = param_1;
      pvVar2 = operator_new(iVar7 * 0x48);
      *(void **)((int)this + 0x4c) = pvVar2;
      if (0 < iVar7) {
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 0x48;
          iVar7 = iVar7 + -1;
          *(undefined4 *)(*(int *)((int)this + 0x4c) + -0x48 + iVar3) = 0xffffffff;
        } while (iVar7 != 0);
      }
    }
    else {
      iVar7 = param_1 + 0x14;
      puVar4 = operator_new(iVar7 * 0x48);
      puVar5 = *(undefined4 **)((int)this + 0x4c);
      puVar8 = puVar4;
      for (uVar6 = (uint)(*(int *)((int)this + 0x48) * 0x48) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar8 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      iVar3 = *(int *)((int)this + 0x48);
      if (iVar3 < iVar7) {
        iVar7 = iVar7 - iVar3;
        puVar5 = puVar4 + iVar3 * 0x12;
        do {
          *puVar5 = 0xffffffff;
          puVar5 = puVar5 + 0x12;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      *(int *)((int)this + 0x48) = param_1;
      Mem_Free(*(LPVOID *)((int)this + 0x4c));
      *(undefined4 **)((int)this + 0x4c) = puVar4;
    }
    if (*(int *)((int)this + 0x4c) == 0) {
      NoOp_Stub();
    }
    *(int *)((int)this + 0x48) = *(int *)((int)this + 0x48) + 0x14;
  }
  iVar3 = param_1 * 0x48;
  puVar5 = (undefined4 *)(*(int *)((int)this + 0x4c) + iVar3);
  for (iVar7 = 0x12; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined1 *)(*(int *)((int)this + 0x4c) + 0x3c + iVar3) = 0;
  *(undefined1 *)(*(int *)((int)this + 0x4c) + 0x3e + iVar3) = 0;
  *(undefined1 *)(*(int *)((int)this + 0x4c) + 0x38 + iVar3) = 1;
  iVar7 = *(int *)((int)this + 0x4c);
  *(undefined4 *)(iVar7 + 0x18 + iVar3) = 0;
  *(undefined4 *)(iVar7 + 0x1c + iVar3) = 0;
  iVar7 = *(int *)((int)this + 0x4c);
  *(undefined4 *)(iVar7 + 0x20 + iVar3) = 0;
  *(undefined4 *)(iVar7 + 0x24 + iVar3) = 0;
  iVar7 = *(int *)((int)this + 0x4c);
  *(undefined4 *)(iVar7 + 0x28 + iVar3) = 0;
  *(undefined4 *)(iVar7 + 0x2c + iVar3) = 0x3ff00000;
  *(undefined2 *)(*(int *)((int)this + 0x4c) + 0x32 + iVar3) = 0;
  *(undefined2 *)(*(int *)((int)this + 0x4c) + 0x30 + iVar3) = 0;
  CS_Leave(0x5842a0);
  return param_1;
}

