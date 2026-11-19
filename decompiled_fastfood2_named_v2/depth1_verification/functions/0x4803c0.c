// rea decompile_all
// name: FUN_004803c0
// address: 0x4803c0
// body: available
// range: 0x4803c0-0x48045a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004803c0(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = param_1;
  IDMap_RemoveByKey((void *)((int)this + 0x19e0),param_1);
  piVar1 = (int *)(*(int *)((int)*(void **)((int)this + 0x14e0) + 0x4c) +
                  *(int *)(iVar2 + 0x20) * 0xc);
  Map_SetTileFieldWithDefault(*(void **)((int)this + 0x14e0),(int)piVar1,-1,1);
  FUN_004f34c0(*(void **)((int)this + 0x14e0),piVar1,&param_1,&local_14);
  param_1 = param_1 - *(int *)(*(int *)((int)this + 0x14e0) + 0x24);
  local_14 = local_14 - *(int *)(*(int *)((int)this + 0x14e0) + 0x28);
  local_10 = param_1 - 0x10;
  local_c = local_14 + -8;
  local_4 = local_14 + 8;
  local_8 = param_1 + 0x10;
  Gfx_BlitRectList(DAT_0058072c,&local_10);
  return;
}

