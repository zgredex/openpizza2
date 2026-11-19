// rea decompile_all
// name: AI_UpdateAdvertisingCampaigns
// address: 0x4fecc0
// body: available
// range: 0x4fecc0-0x4fee2e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall AI_UpdateAdvertisingCampaigns(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  void *this_00;
  char *pcVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  byte *pbVar9;
  
                    /* Starts or stops AI advertising campaigns based on player totals. */
  iVar1 = *(int *)((int)this + param_1 * 0x168 + 0x70);
  iVar2 = *(int *)((int)this + param_1 * 0x168 + 0x40);
  iVar4 = Game_GetPlayerCount((int)DAT_0057c670);
  param_1 = 0;
  if (iVar4 < 1) {
    return 1;
  }
  do {
    this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,param_1);
    if (*(int *)((int)this_00 + iVar2 * 4 + 0x94) != 0) {
      Player_ComputeNetStatTotal(iVar1);
      lVar7 = __ftol();
      Player_ComputeNetStatTotal((int)this_00);
      lVar8 = __ftol();
      bVar3 = (0x14 - DAT_0057bb24) * (int)lVar8 * 10 < (int)lVar7 * 100;
      iVar6 = (int)lVar7 >> 3;
      if (*(char *)((int)this_00 + iVar2 + 0xac) == '\0') {
        if (((!bVar3) && (*(int *)((int)this_00 + iVar2 * 4 + 0x94) <= iVar6)) &&
           (Player_InitSlotFlags(this_00,iVar2),
           this_00 ==
           *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200))) {
          pcVar5 = DAT_00582984;
          pbVar9 = DAT_00581ab8;
          goto LAB_004fede8;
        }
      }
      else if (((bVar3) || (iVar6 < *(int *)((int)this_00 + iVar2 * 4 + 0x94))) &&
              (Advertising_StopCampaign(this_00,iVar2,*(int *)(iVar1 + 0x48),1),
              this_00 ==
              *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200))) {
        pcVar5 = DAT_00580f04;
        pbVar9 = DAT_005816b4;
LAB_004fede8:
        UI_Briefing_Printf((int)DAT_0057c670,-1,4,-1,-1,0,pcVar5,pbVar9,iVar1 + 8);
      }
    }
    param_1 = param_1 + 1;
    if (iVar4 <= param_1) {
      return 1;
    }
  } while( true );
}

