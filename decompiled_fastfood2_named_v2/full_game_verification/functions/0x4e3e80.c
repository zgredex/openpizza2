// rea decompile_all
// name: Game_FindBestRatedBuilding
// address: 0x4e3e80
// body: available
// range: 0x4e3e80-0x4e3ef0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __thiscall Game_FindBestRatedBuilding(void *this,int param_1)

{
  int iVar1;
  void *this_00;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  
  iVar1 = *(int *)((int)this + 0x124);
  iVar5 = 0;
  pvVar4 = (void *)0x0;
  iVar3 = 0;
  if (iVar1 < 1) {
    return (void *)0x0;
  }
  do {
    this_00 = (void *)IDMap_Lookup((void *)((int)this + 0x110),iVar3,(int *)0x0);
    if (*(char *)((int)this_00 + 0x1dc) == '\0') {
      iVar2 = Index_Map8To5(this_00,param_1);
      if (iVar5 < iVar2) {
        pvVar4 = this_00;
        iVar5 = iVar2;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < iVar1);
  return pvVar4;
}

