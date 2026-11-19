// rea decompile_all
// name: FUN_004de1a0
// address: 0x4de1a0
// body: available
// range: 0x4de1a0-0x4de209 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004de1a0(void *this,int param_1,int param_2,void *param_3)

{
  int iVar1;
  void *this_00;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (param_3 != (void *)0x0) {
    iVar3 = Game_SumStatGrid(param_3,param_1,param_2);
    return iVar3;
  }
  iVar1 = *(int *)((int)this + 0x15c);
  iVar4 = 0;
  if (iVar1 < 1) {
    return 0;
  }
  do {
    this_00 = (void *)IDMap_Lookup((void *)((int)this + 0x148),iVar4,(int *)0x0);
    iVar2 = Game_SumStatGrid(this_00,param_1,param_2);
    iVar3 = iVar3 + iVar2;
    iVar4 = iVar4 + 1;
  } while (iVar4 < iVar1);
  return iVar3;
}

