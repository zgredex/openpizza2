// rea decompile_all
// name: Game_CountGoalTargets
// address: 0x480130
// body: available
// range: 0x480130-0x4801fd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Game_CountGoalTargets(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  void *this_00;
  int iVar3;
  int iVar4;
  
  this_00 = *(void **)((int)this + 0x16f0);
  iVar3 = 0;
  iVar4 = 0;
  if (*(int *)((int)this_00 + 0x8c) < 1) {
    return 0;
  }
  do {
    iVar2 = Game_MapRecordToGlobal(this_00,iVar4);
    if (param_1 == 0x16) {
      if ((((*(int *)(iVar2 + 0x30) == 0x1d) || (*(int *)(iVar2 + 0x30) == 0x1e)) &&
          (*(int *)(iVar2 + 0x38) != 0x38)) &&
         ((*(int *)(iVar2 + 0x38) != 0x39 && (*(int *)(iVar2 + 0x108) != 6)))) {
        iVar2 = *(int *)(iVar2 + 0xa4);
        goto joined_r0x004801d2;
      }
    }
    else if (((((param_1 == 0x17) || (param_1 == 0x1b)) &&
              ((iVar1 = *(int *)(iVar2 + 0x30), iVar1 == 0x1d ||
               (((iVar1 == 0x1e || (iVar1 == 0x1f)) || (iVar1 == 0x16)))))) &&
             ((*(int *)(iVar2 + 0x38) != 0x38 && (*(int *)(iVar2 + 0x38) != 0x39)))) &&
            (*(int *)(iVar2 + 0x108) != 6)) {
      iVar2 = *(int *)(iVar2 + 0xa4);
joined_r0x004801d2:
      if ((iVar2 != 0x19) && (iVar2 != 0x1a)) {
        iVar3 = iVar3 + 1;
      }
    }
    this_00 = *(void **)((int)this + 0x16f0);
    iVar4 = iVar4 + 1;
    if (*(int *)((int)this_00 + 0x8c) <= iVar4) {
      return iVar3;
    }
  } while( true );
}

