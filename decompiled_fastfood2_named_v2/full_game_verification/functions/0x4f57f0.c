// rea decompile_all
// name: Grid_GetDirectionBetweenNodes
// address: 0x4f57f0
// body: available
// range: 0x4f57f0-0x4f58db inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 Grid_GetDirectionBetweenNodes(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(param_2 + 0xc);
  if ((iVar1 == iVar2) && (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10))) {
    return 6;
  }
  bVar3 = iVar1 - iVar2 < 0;
  if (iVar1 < iVar2) {
    if (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) {
      return 2;
    }
    bVar3 = iVar1 - iVar2 < 0;
    if (iVar1 < iVar2) {
      if (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10)) {
        return 5;
      }
      bVar3 = iVar1 - iVar2 < 0;
      if (iVar1 < iVar2) {
        if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
          return 1;
        }
        bVar3 = iVar1 - iVar2 < 0;
      }
    }
  }
  if (iVar1 == iVar2) {
    if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
      return 4;
    }
    bVar3 = iVar1 - iVar2 < 0;
  }
  if (iVar1 != iVar2 && SBORROW4(iVar1,iVar2) == bVar3) {
    if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
      return 0;
    }
    if (iVar2 < iVar1) {
      if (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10)) {
        return 7;
      }
      if ((iVar2 < iVar1) && (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10))) {
        return 3;
      }
    }
  }
  Debug_WarningMessageBox();
  return 0xffffffff;
}

