// SubMenu_BuildGangsterPanelPage: ported from Pizza Connection 2 at 0x4848b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4848b0
#include "pc2_port.h"

int __fastcall SubMenu_BuildGangsterPanelPage(int arg1)

{
  void *pvVar1;
  int *ptr2;
  int local_4;
  
                    /* Builds a gangster-panel submenu page. */
  local_4 = arg1;
  if (*(int *)(arg1 + 0x268) != 0) {
    Game_CloseSelectionDialog(arg1);
  }
  *(uint32_t *)(arg1 + 0x2d8) = 0;
  switch(*(uint32_t *)(arg1 + 0x298 + *(int *)(arg1 + 0x290) * 4)) {
  case 1:
    pvVar1 = Window_BuildMarketAnalysisPage(&local_4);
    SubMenu_UpdateMenuPlanPage(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 2:
    pvVar1 = Window_BuildCompanyProfilePage(&local_4);
    Window_UpdateCompanyProfilePage(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  default:
    *(int *)(arg1 + 0x264) = local_4;
    return local_4;
  case 4:
    ptr2 = Screen_MissionGoals(&local_4);
    Mission_UpdateObjectivesPanel(ptr2,'\x01');
    *(int **)(arg1 + 0x264) = ptr2;
    return local_4;
  case 5:
    pvVar1 = SubMenu_BuildTownBalance(&local_4);
    FinancePage_UpdateBalanceSheet(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 6:
    pvVar1 = Screen_BuildingProject(&local_4);
    Window_UpdateConstructionOrderPage(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 7:
    pvVar1 = SubMenu_BuildSyndicate(&local_4);
    CompanyMenu_InitBranchOverview(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 8:
    pvVar1 = SubMenu_BuildGuards(&local_4);
    CompanyOverview_UpdatePanel(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 9:
    pvVar1 = HeadquartersExpansionPage_Create(&local_4);
    CompanyInfo_FillActions(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 10:
    pvVar1 = SubMenu_BuildCompanyComparison(&local_4);
    HeadquartersCompanyPage_Update(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 0xb:
    pvVar1 = Screen_BranchList(&local_4);
    BauenPage_UpdateBuildingMarket(pvVar1,'\x01');
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  }
}
