// rea decompile_all
// name: Stats_UpdateAverages
// address: 0x479ca0
// body: available
// range: 0x479ca0-0x479da5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Stats_UpdateAverages(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  iVar1 = Map_CountEdgeMatchedTiles(this,param_1);
  iVar2 = Game_CountPlayersByByte(this,1);
  iVar2 = iVar2 - iVar1;
  if (0 < iVar2) {
    do {
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  Game_CountPlayersByByte(this,1);
  Game_CountPlayersByByte(this,2);
  City_HasRoomForBuilding(this);
  iVar1 = *(int *)((int)this + 0x187c);
  if (0 < iVar1) {
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  Grid_ScoreRuns(param_1);
  lVar3 = __ftol();
  *(int *)((int)this + 0x1878) = (int)lVar3;
  if ((int)lVar3 < 0) {
    *(undefined4 *)((int)this + 0x1878) = 0;
  }
  return;
}

