// rea decompile_all
// name: UI_Group_SelectMemberByKey
// address: 0x532580
// body: available
// range: 0x532580-0x53261b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_Group_SelectMemberByKey(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Selects the option group member corresponding to a control id. */
  iVar3 = *(int *)((int)this + 0x158);
  iVar4 = 0;
  if (0 < iVar3) {
    while( true ) {
      piVar1 = (int *)Array_GetPtr((void *)((int)this + 0x148),iVar4);
      iVar2 = Array_IndexOfInt(piVar1 + 1,param_1);
      if (iVar2 != -1) break;
      iVar4 = iVar4 + 1;
      if (iVar3 <= iVar4) {
        return;
      }
    }
    if (*piVar1 == 3) {
      iVar2 = iVar2 + 1;
      if (piVar1[5] <= iVar2) {
        iVar2 = 0;
      }
      iVar3 = Array_GetPtr(piVar1 + 1,iVar2);
      piVar1 = (int *)Array_GetRecordByKeyPtr(this,iVar3);
      UI_SetActiveChild(*(void **)((int)this + 0x134),piVar1);
      UI_SelectObjectRecord(*(void **)((int)this + 0x134),this,iVar3);
      return;
    }
    UI_Group_ApplyMemberSelection(this,piVar1,param_1);
  }
  return;
}

