// rea decompile_all
// name: FUN_0054b3d0
// address: 0x54b3d0
// body: available
// range: 0x54b3d0-0x54b43b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0054b3d0(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (*(int *)((int)this + 8) <= *(int *)((int)this + 4)) {
    puVar1 = operator_new(*(int *)((int)this + 8) * 4 + 0x50);
    puVar4 = *(undefined4 **)this;
    puVar5 = puVar1;
    for (uVar2 = *(uint *)((int)this + 4) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    FUN_0054dd78(*(LPVOID *)this);
    *(undefined4 **)this = puVar1;
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + 0x14;
  }
  *(undefined4 *)(*(int *)this + *(int *)((int)this + 4) * 4) = param_1;
  iVar3 = *(int *)((int)this + 4);
  *(int *)((int)this + 4) = iVar3 + 1;
  return iVar3;
}

