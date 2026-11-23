// SubMenu_CreateBuildingPage: ported from Pizza Connection 2 at 0x484270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x484270
#include "pc2_port.h"

void * __fastcall SubMenu_CreateBuildingPage(void *arg1)

{
  int value1;
  void *pvVar2;
  void *local_4;
  
                    /* Dispatches and creates the active building/interior submenu page. */
  *(uint32_t *)((intptr_t)arg1 + 0x2d8) = 0;
  local_4 = arg1;
  if (*(int *)((intptr_t)arg1 + 0x268) != 0) {
    Game_CloseSelectionDialog((intptr_t)arg1);
  }
  switch(*(uint32_t *)((intptr_t)arg1 + *(int *)((intptr_t)arg1 + 0x290) * 4 + 0x298)) {
  case 1:
    pvVar2 = SubMenu_BuildBranchInformation((int *)&local_4);
    BuildingInfoMenu_Init(pvVar2);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 2:
    pvVar2 = SubMenu_BuildPersonnelPlan((int *)&local_4);
    Window_UpdateStaffPlanPage(pvVar2,'\0','\0');
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 3:
    pvVar2 = SubMenu_BuildFurnishings((int *)&local_4);
    MusicMenu_Init(pvVar2);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 4:
    pvVar2 = SubMenu_BuildMenuOverview((int *)&local_4);
    CityBuildingListPage_Update(pvVar2,'\x01');
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 5:
    pvVar2 = SubMenu_BuildBranchBalance((int *)&local_4);
    FinanceScreen_UpdateStatement(pvVar2);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 6:
    pvVar2 = SubMenu_BuildBranchAdvertising((int *)&local_4);
    AdvertisingScreen_UpdatePlan(pvVar2);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 7:
    pvVar2 = SubMenu_BuildInteriorDesigner((int *)&local_4);
    CompanyMenu_InitStylePage(pvVar2);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 8:
    pvVar2 = Window_BuildBranchPriceSettingsPage((int *)&local_4);
    ManagerPage_Update(pvVar2);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 9:
    break;
  case 10:
    local_4 = (void *)SubMenu_OpenPage(arg1,*(uint32_t *)((intptr_t)arg1 + 0x2e4));
    value1 = UI_FindWindowByID(DAT_0057c5e0,(intptr_t)local_4,(int *)0x0);
    *(int *)((intptr_t)arg1 + 0x264) = value1;
    return local_4;
  case 0xb:
    pvVar2 = Screen_PersonnelOverview((int *)&local_4);
    PersonnelOverview_Refresh(pvVar2,0);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  default:
    *(void **)((intptr_t)arg1 + 0x264) = local_4;
    return local_4;
  }
  if (*(char *)(*(int *)((intptr_t)arg1 + 0x9c) + 0x16f5) == '\0') {
    pvVar2 = SubMenu_BuildBranchExpansion((int *)&local_4);
    BranchInfo_UpdateRatingBars(pvVar2);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  }
  pvVar2 = SubMenu_BuildConstructionInfo((int *)&local_4);
  *(uint32_t *)((intptr_t)arg1 + 0x218) = *(uint32_t *)(*(int *)((intptr_t)arg1 + 0x9c) + 0x16f0);
  ConstructionMenu_Fill(pvVar2);
  *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
  return local_4;
}
