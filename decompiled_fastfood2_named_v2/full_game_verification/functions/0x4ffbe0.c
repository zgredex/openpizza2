// rea decompile_all
// name: Game_AddPoliceStations
// address: 0x4ffbe0
// body: available
// range: 0x4ffbe0-0x4ffcac inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Game_AddPoliceStations(int param_1)

{
  int iVar1;
  void *this;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int local_8;
  int local_4;
  
                    /* Adds police/security buildings during scenario setup. */
  iVar1 = Game_GetPlayerCount(DAT_0057c670);
  this = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  while ((0 < param_1 && (iVar2 = Game_CountRecordsByOwner(this,0x11), iVar2 < 5))) {
    uVar3 = Random_RangeFast(0,iVar1 - 1);
    pvVar4 = (void *)AI_PickInitialBranchPlot(this);
    if (pvVar4 == (void *)0x0) {
      return;
    }
    Game_ComputeTradeOffers(this,(int)pvVar4,2,&local_4,&local_8,uVar3,(int *)0x0);
    iVar2 = *(int *)((int)pvVar4 + 0x48);
    *(int *)((int)pvVar4 + 0x3c) = local_8;
    if ((-1 < iVar2) && (iVar2 < 4)) {
      iVar2 = *(int *)(&DAT_00568188 + iVar2 * 4);
    }
    MapObject_SpawnByKind(this,pvVar4,6,uVar3,(void *)0x11,iVar2 + 0x975);
    param_1 = param_1 + -1;
    *(undefined4 *)((int)pvVar4 + 0x4c) = 0;
    *(undefined4 *)((int)pvVar4 + 0x50) = 0;
  }
  return;
}

