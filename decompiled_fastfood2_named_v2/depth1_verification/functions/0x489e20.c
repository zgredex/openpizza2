// rea decompile_all
// name: FUN_00489e20
// address: 0x489e20
// body: available
// range: 0x489e20-0x489e99 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00489e20(void *this,void *param_1)

{
  void *this_00;
  bool bVar1;
  void *this_01;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  
  if (*(int *)((int)this + 0x9c) == 0) {
    return 1;
  }
  this_00 = *(void **)(*(int *)((int)this + 0x9c) + 0x16f0);
  if (this_00 == (void *)0x0) {
    return 1;
  }
  iVar2 = 0;
  if (0 < *(int *)((int)this_00 + 0x8c)) {
    do {
      this_01 = (void *)Game_MapRecordToGlobal(this_00,iVar2);
      if (this_01 != (void *)0x0) {
        bVar1 = FUN_00509cf0(this_01,param_1);
        if (CONCAT31(extraout_var,bVar1) != 0) {
          return 1;
        }
        bVar1 = FUN_00509eb0(this_01,param_1);
        if (CONCAT31(extraout_var_00,bVar1) != 0) {
          return 1;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this_00 + 0x8c));
  }
  return 0;
}

