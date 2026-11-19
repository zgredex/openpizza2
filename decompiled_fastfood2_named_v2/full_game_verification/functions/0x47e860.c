// rea decompile_all
// name: AI_StepToNeighborCell
// address: 0x47e860
// body: available
// range: 0x47e860-0x47e8be inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall AI_StepToNeighborCell(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  uVar1 = Map_LookupLinear((void *)((int)this + 0x1998),param_1);
  uVar1 = uVar1 & 0x80000001;
  bVar4 = uVar1 == 0;
  if ((int)uVar1 < 0) {
    bVar4 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;
  }
  if (bVar4) {
    iVar2 = *(int *)(param_1 + 0x18);
    iVar3 = *(int *)(param_1 + 0x14) + 3;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x18);
    iVar3 = *(int *)(param_1 + 0x14) + -3;
  }
  iVar2 = Grid_GetCell(*(void **)((int)this + 0x14e0),iVar3,iVar2);
  Array_GetRecord28(*(void **)((int)this + 0x14e0),1,(int)*(short *)(*(int *)(iVar2 + 8) + 0x24));
  return;
}

