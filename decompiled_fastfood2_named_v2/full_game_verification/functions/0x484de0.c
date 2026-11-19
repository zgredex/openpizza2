// rea decompile_all
// name: Statistics_InitSelectedPage
// address: 0x484de0
// body: available
// range: 0x484de0-0x484f32 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __fastcall Statistics_InitSelectedPage(void *param_1)

{
  void *pvVar1;
  int iVar2;
  void *local_4;
  
                    /* Initializes the selected statistics sub-page. */
  local_4 = param_1;
  if (*(int *)((int)param_1 + 0x268) != 0) {
    Game_CloseSelectionDialog((int)param_1);
  }
  switch(*(undefined4 *)((int)param_1 + *(int *)((int)param_1 + 0x290) * 4 + 0x298)) {
  case 1:
    pvVar1 = Window_BuildStatisticsBranchBalancePage((int *)&local_4);
    StatisticsBranchBalance_InitPage(pvVar1,'\x01');
    break;
  case 2:
    pvVar1 = Screen_StatisticsPersonnel((int *)&local_4);
    StatisticsPersonnel_UpdateWindow(pvVar1);
    break;
  case 3:
    pvVar1 = StatisticsRecipes_CreateWindow((int *)&local_4);
    CompanyOverview_InitWindow(pvVar1,'\x01');
    break;
  case 4:
    pvVar1 = Screen_StatisticsBalance((int *)&local_4);
    StatisticsBalance_InitPage(pvVar1);
    break;
  case 5:
    pvVar1 = Screen_StatisticsBackdrop((int *)&local_4);
    StatisticsBackdrop_InitCompanyRows(pvVar1);
    break;
  case 6:
    switch(*(undefined4 *)((int)param_1 + 0x2e8)) {
    case 0:
      pvVar1 = Glossary_BuildTargetGroupsPage((int *)&local_4);
      Glossary_UpdatePeoplePage(pvVar1);
      break;
    case 1:
      pvVar1 = Glossary_BuildCityBuildingsPage((int *)&local_4);
      Glossary_BranchesPage_Init(pvVar1);
      break;
    case 2:
      pvVar1 = Glossary_BuildCompanyBuildingsPage((int *)&local_4);
      Glossary_BuildingsPage_Init(pvVar1);
      break;
    case 3:
      pvVar1 = Glossary_BuildHeadSymbolsPage((int *)&local_4);
      Glossary_InitIngredientPage(pvVar1);
      break;
    default:
      goto switchD_00484e0b_default;
    }
    break;
  default:
switchD_00484e0b_default:
    pvVar1 = local_4;
  }
  *(void **)((int)param_1 + 0x264) = pvVar1;
  iVar2 = Object_GetId(*(int *)((int)param_1 + 0x260));
  UI_RemoveWindowByID(DAT_0057c5e0,iVar2);
  return local_4;
}

