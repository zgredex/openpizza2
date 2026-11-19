// rea decompile_all
// name: AI_StartAdvertisingCampaign
// address: 0x4fee30
// body: available
// range: 0x4fee30-0x4fefa2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 AI_StartAdvertisingCampaign(void *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  longlong lVar7;
  longlong lVar8;
  
                    /* Starts or stops an AI advertising campaign. */
  iVar2 = *(int *)(param_2 + 0x30);
  iVar4 = Game_GetPlayerBySlot(DAT_0057c670,iVar2);
  cVar1 = *(char *)(iVar2 + 0xac + (int)param_1);
  Player_ComputeNetStatTotal(iVar4);
  lVar7 = __ftol();
  Player_ComputeNetStatTotal((int)param_1);
  lVar8 = __ftol();
  if ((int)lVar8 < 0) {
    iVar5 = _rand();
    if (((byte)iVar5 & 3) != 3) {
      return 1;
    }
    iVar5 = (int)lVar7 / 0x19;
  }
  else {
    iVar5 = (int)lVar8 / 0x14;
  }
  iVar3 = (int)lVar7 / 0x14;
  if (iVar3 <= iVar5) {
    iVar5 = iVar3;
  }
  if (999 < iVar5) {
    if (cVar1 != '\0') {
      if (iVar5 * 2 < *(int *)((int)param_1 + iVar2 * 4 + 0x94) * 3) {
        return 1;
      }
      Advertising_StopCampaign(param_1,iVar2,*(int *)((int)param_1 + 0x48),1);
      if (iVar4 == *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200)) {
        UI_Briefing_Printf((int)DAT_0057c670,-1,4,-1,-1,0,DAT_00580f04,DAT_00581d3c,iVar4 + 8);
      }
    }
    piVar6 = Game_FindFreeStaffRecord(param_1,0x1d);
    if ((piVar6 != (int *)0x0) &&
       (Advertising_StartCampaignAgainstPlayer(param_1,param_2,iVar5,piVar6),
       iVar4 == *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200))) {
      UI_Briefing_Printf((int)DAT_0057c670,-1,4,-1,-1,0,DAT_005825a8,DAT_005817bc,(int)param_1 + 8);
    }
  }
  return 1;
}

