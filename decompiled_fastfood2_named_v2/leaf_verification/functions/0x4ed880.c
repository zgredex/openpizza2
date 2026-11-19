// rea decompile_all
// name: FUN_004ed880
// address: 0x4ed880
// body: available
// range: 0x4ed880-0x4ed92b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __thiscall FUN_004ed880(void *this,uint param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  void *this_00;
  void *this_01;
  uint local_c;
  uint local_8;
  uint local_4;
  
  uVar1 = param_1;
  this_00 = (void *)SparseMap_Lookup48(*(void **)((int)this + 4),*(int *)(*(int *)(param_1 + 8) + 4)
                                      );
  this_01 = (void *)SparseMap_Lookup48(*(void **)((int)this + 4),
                                       *(int *)(*(int *)(uVar1 + 8) + 0x10));
  if (this_00 == (void *)0x0) {
    param_1 = 0;
    local_c = 0;
  }
  else {
    Sprite_GetRenderSize(this_00,&param_1,&local_c);
  }
  if (this_01 == (void *)0x0) {
    local_8 = 0;
    local_4 = 0;
  }
  else {
    Sprite_GetRenderSize(this_01,&local_8,&local_4);
  }
  if ((int)local_8 < (int)param_1) {
    local_8 = param_1;
  }
  *param_2 = local_8;
  if ((int)local_4 < (int)local_c) {
    *param_3 = local_c;
    return this_01;
  }
  *param_3 = local_4;
  return this_01;
}

