// SubMenu_BuildSelectedPage: ported from Pizza Connection 2 at 0x484650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x484650
#include "pc2_port.h"

void * __thiscall SubMenu_BuildSelectedPage(void *self,int *arg1)

{
  int *ptr1;
  int value2;
  int value3;
  void *local_4;
  
                    /* Builds and caches the selected submenu page. */
  *(uint32_t *)((intptr_t)self + 0x2d8) = 0;
  value3 = *(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x298);
  if (((value3 == 8) || (value3 == 7)) && (*(int *)((intptr_t)self + 0x218) == 0)) {
    *(uint32_t *)((intptr_t)self + 700) = *(uint32_t *)((intptr_t)self + 0x29c);
    *(uint32_t *)((intptr_t)self + 0x29c) = 1;
  }
  value3 = *(int *)((intptr_t)self + 0x218);
  local_4 = self;
  if (value3 != 0) {
    if (*(int *)(value3 + 0x38) == 0) {
      value2 = *(int *)(value3 + 4);
      if (value2 == 0x1c) {
        value3 = Game_GetPlayerBySlot(self,*(int *)(value3 + 8));
        value3 = Game_GetPlayerFieldC20(value3);
        value2 = 0x1c;
      }
      else {
        value3 = 0;
      }
    }
    else {
      value3 = 0;
      value2 = 0x1a;
    }
    Sound_PlaySfxByIndex(DAT_0057ba0c,value2,value3);
  }
  if (*(int *)((intptr_t)self + 0x268) != 0) {
    Game_CloseSelectionDialog((intptr_t)self);
  }
  switch(*(uint32_t *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x298)) {
  case 1:
    ptr1 = Window_BuildMarketAnalysisPage((int *)&local_4);
    SubMenu_UpdateMenuPlanPage(ptr1);
    break;
  case 2:
    ptr1 = Window_BuildCompanyProfilePage((int *)&local_4);
    Window_UpdateCompanyProfilePage(ptr1);
    break;
  case 3:
    ptr1 = BauenPage_Create((int *)&local_4);
    BauenPage_ResetBuildingSlots(ptr1);
    break;
  case 4:
    ptr1 = Screen_MissionGoals((int *)&local_4);
    Mission_UpdateObjectivesPanel(ptr1,'\x01');
    break;
  case 5:
    ptr1 = SubMenu_BuildTownBalance((int *)&local_4);
    FinancePage_UpdateBalanceSheet(ptr1);
    break;
  case 6:
    ptr1 = Screen_BuildingProject((int *)&local_4);
    Window_UpdateConstructionOrderPage(ptr1);
    break;
  case 7:
    ptr1 = Screen_Warehouse((int *)&local_4);
    WarehouseScreen_Refresh(ptr1);
    break;
  case 8:
    ptr1 = Screen_BranchOffer((int *)&local_4);
    Window_UpdateWarehousePage(ptr1);
    break;
  default:
    ptr1 = arg1;
    break;
  case 10:
    local_4 = (void *)SubMenu_OpenPage(self,*(uint32_t *)((intptr_t)self + 0x2e4));
    ptr1 = (int *)UI_FindWindowByID(DAT_0057c5e0,(intptr_t)local_4,(int *)0x0);
    break;
  case 0xb:
    ptr1 = Screen_BranchList((int *)&local_4);
    BauenPage_UpdateBuildingMarket(ptr1,'\x01');
  }
  *(int **)((intptr_t)self + 0x264) = ptr1;
  if ((char)arg1 != '\0') {
    if (*(int *)((intptr_t)self + 0x290) == 1) {
      SubMenu_UpdateButtonStatesVariant1(*(void **)((intptr_t)self + 0x260));
      return local_4;
    }
    if (*(int *)((intptr_t)self + 0x290) == 2) {
      SubMenu_UpdateButtonStatesVariant2(*(void **)((intptr_t)self + 0x260));
      return local_4;
    }
    CityAdminPanel_UpdateTabButtons(*(void **)((intptr_t)self + 0x260));
  }
  return local_4;
}
