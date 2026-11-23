// Statistics_InitSelectedPage: ported from Pizza Connection 2 at 0x484de0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x484de0
#include "pc2_port.h"

void * __fastcall Statistics_InitSelectedPage(void *arg1)

{
  void *pvVar1;
  int value2;
  void *local_4;
  
                    /* Initializes the selected statistics sub-page. */
  local_4 = arg1;
  if (*(int *)((intptr_t)arg1 + 0x268) != 0) {
    Game_CloseSelectionDialog((intptr_t)arg1);
  }
  switch(*(uint32_t *)((intptr_t)arg1 + *(int *)((intptr_t)arg1 + 0x290) * 4 + 0x298)) {
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
    switch(*(uint32_t *)((intptr_t)arg1 + 0x2e8)) {
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
  *(void **)((intptr_t)arg1 + 0x264) = pvVar1;
  value2 = Object_GetId(*(int *)((intptr_t)arg1 + 0x260));
  UI_RemoveWindowByID(DAT_0057c5e0,value2);
  return local_4;
}
