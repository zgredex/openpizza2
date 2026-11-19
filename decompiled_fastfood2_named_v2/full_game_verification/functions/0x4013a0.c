// rea decompile_all
// name: List_Construct
// address: 0x4013a0
// body: available
// range: 0x4013a0-0x40141d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall List_Construct(void *this,uint param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined ***)this = &PTR_List_Node_Delete_0055c2ec;
  if (param_1 == 0) {
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined4 *)((int)this + 0xc) = 0;
    *(undefined4 *)((int)this + 0x14) = 0;
    *(undefined4 *)((int)this + 0x18) = 100000;
    return this;
  }
  pvVar1 = operator_new(param_1 * 4);
  *(void **)((int)this + 4) = pvVar1;
  puVar2 = operator_new(param_1 * 4);
  uVar3 = param_1 & 0x3fffffff;
  *(undefined4 **)((int)this + 8) = puVar2;
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(uint *)((int)this + 0x10) = param_1;
  *(undefined4 *)((int)this + 0x18) = 100000;
  return this;
}

