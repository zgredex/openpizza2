// rea decompile_all
// name: FUN_004fe370
// address: 0x4fe370
// body: available
// range: 0x4fe370-0x4fe415 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_004fe370(void *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  void *this;
  
  iVar1 = Game_CountObjectsForOwner(param_1,param_2,0x17);
  if (iVar1 == 0) {
    return 0;
  }
  piVar2 = Game_FindAssignedSubrecord(param_1,param_2,0);
  if (piVar2 == (int *)0x0) {
    piVar2 = Game_FindAssignedSubrecord(param_1,param_2,1);
    if (piVar2 == (int *)0x0) {
      return 0;
    }
  }
  this = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x3c),*piVar2,(int *)0x0);
  if (*(int *)((int)this + 0x74) == 0) {
    if (*(int *)((int)param_1 + 0x1d8) == 0) {
      FUN_004e2110(param_1,*piVar2);
    }
    else {
      FUN_0050a080(this,*(int *)((int)param_1 + 0x1d8));
    }
  }
  else {
    *(undefined1 *)((int)this + 0x81) = 1;
  }
  Object_SetFieldA4Locked(this,0xffffffff);
  *(undefined4 *)((int)this + 0x10c) = 0xffffffff;
  return 1;
}

