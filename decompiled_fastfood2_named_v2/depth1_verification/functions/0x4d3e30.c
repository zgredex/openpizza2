// rea decompile_all
// name: FUN_004d3e30
// address: 0x4d3e30
// body: available
// range: 0x4d3e30-0x4d3ee8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x4d3ee4 to 0x507a80 FUN_00507a80 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d3e30(int param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x820) != -1) {
    pvVar1 = (void *)Game_GetPlayerSubmapValue
                               (DAT_0057c670,*(int *)(param_1 + 0x81c),*(int *)(param_1 + 0x820));
    if (pvVar1 != (void *)0x0) {
      iVar2 = IDMap_FindIndexByValue(pvVar1,param_1);
      if (iVar2 != -1) {
        iVar4 = 0;
        piVar3 = (int *)FUN_004017f0((void *)((int)pvVar1 + 0x1500),iVar2,(int *)0x0);
        FUN_0047a9d0(pvVar1,piVar3,iVar4);
      }
    }
  }
  pvVar1 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)(param_1 + 0x818),(int *)0x0
                               );
  if (pvVar1 != (void *)0x0) {
    piVar3 = Map_FindRecordByFirstField(pvVar1,param_1);
    if (piVar3 != (int *)0x0) {
      FUN_004d6c00(pvVar1,piVar3);
      FUN_0054dd78(piVar3);
    }
  }
  iVar2 = Game_GetRecordByField814(param_1);
  if (*(int *)(iVar2 + 0x78) != 0x23) {
    *(undefined4 *)(iVar2 + 0x78) = 0x23;
    if (*(int *)(iVar2 + 0x74) == 0) {
      FUN_00507a80(iVar2);
      return;
    }
    *(undefined1 *)(iVar2 + 0x81) = 1;
  }
  return;
}

