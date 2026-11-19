// rea decompile_all
// name: SubMenu_BuildGangsterPanelPage
// address: 0x4848b0
// body: available
// range: 0x4848b0-0x484a5f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall SubMenu_BuildGangsterPanelPage(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int local_4;
  
                    /* Builds a gangster-panel submenu page. */
  local_4 = param_1;
  if (*(int *)(param_1 + 0x268) != 0) {
    Game_CloseSelectionDialog(param_1);
  }
  *(undefined4 *)(param_1 + 0x2d8) = 0;
  switch(*(undefined4 *)(param_1 + 0x298 + *(int *)(param_1 + 0x290) * 4)) {
  case 1:
    pvVar1 = Window_BuildMarketAnalysisPage(&local_4);
    SubMenu_UpdateMenuPlanPage(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 2:
    pvVar1 = Window_BuildCompanyProfilePage(&local_4);
    Window_UpdateCompanyProfilePage(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  default:
    *(int *)(param_1 + 0x264) = local_4;
    return local_4;
  case 4:
    piVar2 = Screen_MissionGoals(&local_4);
    Mission_UpdateObjectivesPanel(piVar2,'\x01');
    *(int **)(param_1 + 0x264) = piVar2;
    return local_4;
  case 5:
    pvVar1 = SubMenu_BuildTownBalance(&local_4);
    FinancePage_UpdateBalanceSheet(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 6:
    pvVar1 = Screen_BuildingProject(&local_4);
    Window_UpdateConstructionOrderPage(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 7:
    pvVar1 = SubMenu_BuildSyndicate(&local_4);
    CompanyMenu_InitBranchOverview(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 8:
    pvVar1 = SubMenu_BuildGuards(&local_4);
    CompanyOverview_UpdatePanel(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 9:
    pvVar1 = HeadquartersExpansionPage_Create(&local_4);
    CompanyInfo_FillActions(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 10:
    pvVar1 = SubMenu_BuildCompanyComparison(&local_4);
    HeadquartersCompanyPage_Update(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 0xb:
    pvVar1 = Screen_BranchList(&local_4);
    BauenPage_UpdateBuildingMarket(pvVar1,'\x01');
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  }
}

