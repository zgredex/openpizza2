// rea decompile_all
// name: Branch_RecalculateRatings
// address: 0x478db0
// body: available
// range: 0x478db0-0x478ea8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Branch_RecalculateRatings(void)

{
  int *piVar1;
  void *this;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_res0;
  
  __chkstk(local_res0);
  puVar3 = (undefined4 *)register0x00000010;
  for (iVar2 = 0x3200; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)((int)this + 0x1718) = 1;
  Map_BuildObjectGrid(*(void **)((int)this + 0x14e0),(undefined4 *)&local_res0);
  Company_ComputeTypePercentages((int)this);
  Stats_ComputeBestPairShareAverage(this);
  Game_ComputeCategoryDominance((int)this);
  iVar2 = Stats_ComputeOccupancyPercent(this,(int)&local_res0);
  Stats_GetAverageValue(this,(int)&local_res0);
  Game_ComputeCityScore(this,iVar2,(int)&local_res0);
  Map_ComputeBuildableAverage(this,(int)&local_res0);
  Stats_ComputeTypeThreeShare(this);
  Game_UpdateActivePlayerCount(this);
  Game_ComputeCityConditionScore((int)this,extraout_EDX);
  NoOp_Stub();
  Stats_UpdateAverages(this,(int)&local_res0);
  Stats_ComputeWeightedTotals((int)this);
  Rating_ComputeBranchScores((int)this);
  piVar1 = (int *)((int)this + 0x17fc);
  iVar2 = 8;
  do {
    iVar4 = *piVar1 - *(int *)((int)this + 0x1878);
    *piVar1 = iVar4;
    if (iVar4 < 0) {
      *piVar1 = 0;
    }
    if (100 < *piVar1) {
      *piVar1 = 100;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

