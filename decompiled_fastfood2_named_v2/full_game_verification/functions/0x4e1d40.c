// rea decompile_all
// name: Game_CountActiveObjectsByType
// address: 0x4e1d40
// body: available
// range: 0x4e1d40-0x4e1da9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Game_CountActiveObjectsByType(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  iVar1 = *(int *)((int)this + 0x1cc);
  iVar5 = 0;
  local_4 = 0;
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      piVar2 = (int *)IDMap_Lookup((void *)((int)this + 0x1b8),iVar5,(int *)0x0);
      iVar3 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*piVar2,(int *)0x0);
      iVar4 = State_Is2DOr2E(iVar3);
      if ((iVar4 == 0) && ((param_1 == -1 || (*(int *)(iVar3 + 0x30) == param_1)))) {
        local_4 = local_4 + 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
    iVar3 = local_4;
  }
  return iVar3;
}

