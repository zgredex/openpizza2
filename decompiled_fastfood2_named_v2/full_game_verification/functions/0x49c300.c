// rea decompile_all
// name: RankingScreen_UpdateRows
// address: 0x49c300
// body: available
// range: 0x49c300-0x49c440 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl RankingScreen_UpdateRows(void *param_1,int param_2)

{
  void *this;
  int iVar1;
  int iVar2;
  bool bVar3;
  float10 fVar4;
  int local_38;
  int local_34;
  int local_30;
  undefined1 local_28 [36];
  
  this = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_30 = Game_CountActiveCompanies((int)this);
  if (local_30 < 9) {
    param_2 = 0;
  }
  else {
    local_30 = 8;
  }
  iVar2 = 0;
  if (0 < local_30) {
    local_34 = param_2 * 4;
    local_38 = 0x51b;
    do {
      bVar3 = *(int *)(local_34 + DAT_0057ca94) != DAT_0057ca90;
      if (bVar3) {
        iVar1 = (&DAT_00568a14)[iVar2];
      }
      else {
        iVar1 = (&DAT_00568a14)[iVar2];
      }
      Window_GadgetNotify_Button_SetState(param_1,iVar1,(uint)!bVar3);
      iVar1 = Game_GetActiveCompanyById(this,*(int *)(local_34 + DAT_0057ca94));
      Window_GadgetNotify_Text_SetText(param_1,local_38,iVar1 + 4);
      if (DAT_005689f0 == '\0') {
        fVar4 = Game_ComputeCompanySharePercent(this,iVar1,-1);
      }
      else {
        fVar4 = Game_GetPlayerWeightedStat(iVar1);
      }
      String_Format(local_28,(byte *)s__0_2f_005685f4,SUB84((double)fVar4,0));
      Window_GadgetNotify_Text_SetText(param_1,(&DAT_005689f4)[iVar2],local_28);
      iVar2 = iVar2 + 1;
      local_38 = local_38 + -1;
      local_34 = local_34 + 4;
    } while (iVar2 < local_30);
  }
  return;
}

