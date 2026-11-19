// rea decompile_all
// name: Building_EvictOccupants
// address: 0x4d2f10
// body: available
// range: 0x4d2f10-0x4d2f9e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Building_EvictOccupants(void *param_1)

{
  int iVar1;
  int iVar2;
  void *this;
  uint uVar3;
  
                    /* Evicts occupants when a building is removed or converted. */
  Game_ReassignDestroyedObjectReferences(DAT_0057c670,(int)param_1);
  iVar1 = *(int *)((int)param_1 + 0x8c);
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    this = (void *)Game_MapRecordToGlobal(param_1,iVar1);
    if (*(short *)((int)this + 0x40) == 0x11) {
      *(undefined4 *)((int)this + 0x4c) = 0;
      *(undefined4 *)((int)this + 0x54) = 0;
      UI_SetChildState(this,0xffff);
      Game_GetTimeByMode(this,0);
    }
    if (*(void **)((int)this + 0xfc) == param_1) {
      uVar3 = Game_GetTimeSegment((int)DAT_0057c670);
      iVar2 = *(int *)((int)this + uVar3 * 4 + 0xd4);
      Object_SetDestinationAndTarget(this,6,iVar2);
      *(int *)((int)this + 0xd0) = iVar2;
    }
    else {
      Game_RemoveObjectFromList(param_1,this,1);
    }
  }
  Game_ReassignObjectsFromRemovedBuilding(DAT_0057c670,(int)param_1);
  return;
}

