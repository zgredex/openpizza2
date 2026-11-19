// rea decompile_all
// name: Game_GetStatBandByIndex
// address: 0x502430
// body: available
// range: 0x502430-0x5024ae inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall Game_GetStatBandByIndex(void *this,uint param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  uint uVar3;
  undefined8 uVar4;
  
  switch(param_1) {
  case 0:
    uVar2 = Game_GetPlayerStaffBand();
    return CONCAT31(extraout_var,uVar2);
  case 1:
    uVar2 = Game_GetActivityVolumeBand();
    return CONCAT31(extraout_var_00,uVar2);
  case 2:
    uVar3 = Game_GetPlayerWealthBand();
    return uVar3;
  case 3:
    uVar3 = Stats_GetCityShareRank();
    return uVar3;
  case 4:
    uVar3 = Game_GetBestBuildingRatingBand();
    return uVar3;
  case 5:
    uVar3 = Game_GetBuildingQualityBand();
    return uVar3;
  case 6:
    cVar1 = Game_GetPlayerSatisfactionBand();
    return CONCAT31(extraout_var_01,cVar1);
  case 7:
    uVar2 = Stats_ComputeCategory7();
    return CONCAT31(extraout_var_02,uVar2);
  case 8:
    uVar2 = Stats_GetLevelFromFourCounters();
    return CONCAT31(extraout_var_03,uVar2);
  case 9:
    uVar4 = Game_GetGlobalStatsBand();
    return (uint)uVar4;
  case 10:
    uVar3 = Game_GetMarketRank();
    return uVar3;
  case 0xb:
    uVar2 = Stats_GetLevelFromTenCounters();
    return CONCAT31(extraout_var_04,uVar2);
  case 0xc:
    uVar3 = Game_GetPlayerTierFromC20(this);
    return uVar3;
  default:
    return param_1;
  }
}

