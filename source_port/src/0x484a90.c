// SubMenu_BuildPolicePanelPage: ported from Pizza Connection 2 at 0x484a90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x484a90
#include "pc2_port.h"

int __fastcall SubMenu_BuildPolicePanelPage(int arg1)

{
  int *ptr1;
  void *pvVar2;
  int local_4;
  
                    /* Builds a police-panel submenu page. */
  local_4 = arg1;
  if (*(int *)(arg1 + 0x268) != 0) {
    Game_CloseSelectionDialog(arg1);
  }
  *(uint32_t *)(arg1 + 0x2d8) = 0;
  switch(*(uint32_t *)(arg1 + 0x298 + *(int *)(arg1 + 0x290) * 4)) {
  case 1:
    pvVar2 = Window_BuildMarketAnalysisPage(&local_4);
    SubMenu_UpdateMenuPlanPage(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 2:
    pvVar2 = Window_BuildCompanyProfilePage(&local_4);
    Window_UpdateCompanyProfilePage(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  default:
    *(int *)(arg1 + 0x264) = local_4;
    return local_4;
  case 4:
    ptr1 = Screen_MissionGoals(&local_4);
    Mission_UpdateObjectivesPanel(ptr1,'\x01');
    *(int **)(arg1 + 0x264) = ptr1;
    return local_4;
  case 5:
    pvVar2 = SubMenu_BuildTownBalance(&local_4);
    FinancePage_UpdateBalanceSheet(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 6:
    pvVar2 = Screen_BuildingProject(&local_4);
    Window_UpdateConstructionOrderPage(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 8:
    pvVar2 = SubMenu_BuildPolice(&local_4);
    CompanyMenu_InitPolicePage(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 9:
    pvVar2 = Screen_PersonnelOverview(&local_4);
    PersonnelOverview_Refresh(pvVar2,0);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 0xb:
    pvVar2 = Screen_BranchList(&local_4);
    BauenPage_UpdateBuildingMarket(pvVar2,'\x01');
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 0xc:
    pvVar2 = SubMenu_BuildTownAdministration(&local_4);
    RankingPanel_UpdatePlayerSummary(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  }
}
