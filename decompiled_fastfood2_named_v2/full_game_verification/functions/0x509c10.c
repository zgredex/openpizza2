// rea decompile_all
// name: Building_PruneStaleListRow
// address: 0x509c10
// body: available
// range: 0x509c10-0x509ce4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Building_PruneStaleListRow(int param_1)

{
  short sVar1;
  undefined1 uVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  
                    /* Prunes a stale building list row and rebuilds the list. */
  if (*(int *)(param_1 + 200) != 0) {
    CS_Enter(*(int *)(DAT_0057c670 + 0x240));
    uVar2 = Object_IsVisibleThisFrame(param_1);
    if (CONCAT31(extraout_var,uVar2) == 0) {
      CS_Leave(*(int *)(DAT_0057c670 + 0x240));
      return;
    }
    sVar1 = *(short *)(*(int *)(param_1 + 200) + 0x28);
    if (sVar1 != -1) {
      iVar4 = (int)sVar1;
      iVar3 = Array_GetPtr4((void *)(*(int *)(param_1 + 200) + 0x14),iVar4);
      while (iVar3 != 0) {
        iVar3 = Array_GetPtr4((void *)(*(int *)(param_1 + 200) + 0x14),iVar4);
        if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc4) + 0x4c) + 8 +
                             *(int *)(iVar3 + 8) * 0xc) + 0x28) == 0) {
          UI_RemoveLastChild(param_1);
          Person_RecomputePathStep(param_1);
          CS_Leave(*(int *)(DAT_0057c670 + 0x240));
          return;
        }
        iVar4 = iVar4 + 1;
        iVar3 = Array_GetPtr4((void *)(*(int *)(param_1 + 200) + 0x14),iVar4);
      }
    }
    CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  }
  return;
}

