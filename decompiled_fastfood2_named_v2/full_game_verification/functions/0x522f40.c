// rea decompile_all
// name: Array_InsertGrow
// address: 0x522f40
// body: available
// range: 0x522f40-0x522fda inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Array_InsertGrow(void *this,undefined4 param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  CS_Enter(0x584180);
  if (*(int *)((int)this + 0xc) <= *(int *)((int)this + 8)) {
    if (*(int *)((int)this + 4) == 0) {
      pvVar1 = operator_new(0x50);
      *(void **)((int)this + 4) = pvVar1;
    }
    else {
      puVar2 = operator_new(*(int *)((int)this + 0xc) * 4 + 0x50);
      puVar5 = *(undefined4 **)((int)this + 4);
      puVar6 = puVar2;
      for (uVar3 = *(uint *)((int)this + 0xc) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      Mem_Free(*(LPVOID *)((int)this + 4));
      *(undefined4 **)((int)this + 4) = puVar2;
    }
    *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 0x14;
  }
  *(undefined4 *)(*(int *)((int)this + 4) + *(int *)((int)this + 8) * 4) = param_1;
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
  CS_Leave(0x584180);
  return *(int *)((int)this + 8) + -1;
}

