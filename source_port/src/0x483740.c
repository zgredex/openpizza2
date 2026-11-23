// SubMenu_OpenPage: ported from Pizza Connection 2 at 0x483740.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483740
#include "pc2_port.h"

int __thiscall SubMenu_OpenPage(void *self,uint32_t arg1)

{
  int *ptr1;
  void *pvVar2;
  void *local_4;
  
                    /* Opens and fills a selected submenu page. */
  local_4 = self;
  if (*(int *)((intptr_t)self + 0x268) != 0) {
    Game_CloseSelectionDialog((intptr_t)self);
  }
  switch(arg1) {
  case 1:
    SubMenu_BuildPersonnelChoice((int *)&local_4);
    NoOp_Stub();
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 2:
    pvVar2 = SubMenu_BuildCourierMission((int *)&local_4);
    BuildingInfo_Fill(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 3:
    pvVar2 = SubMenu_BuildWarehouse((int *)&local_4);
    StorageMenu_Init(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 4:
    pvVar2 = SubMenu_BuildStockInformation((int *)&local_4);
    LeaseBuilding_UpdatePage(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 5:
    pvVar2 = SubMenu_BuildHeadquarters((int *)&local_4);
    CompanyOverview_FillTotals(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 6:
    pvVar2 = SubMenu_BuildMayor((int *)&local_4);
    StarAward_Fill(pvVar2,'\x01');
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 7:
    pvVar2 = SubMenu_BuildCriminalHiring((int *)&local_4);
    CriminalsPage_FillRecruitOptions(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 8:
    pvVar2 = SubMenu_BuildPosterAdvertisingSetup((int *)&local_4);
    PosterAdvertisingPage_Update(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 9:
    pvVar2 = SubMenu_BuildStadiumInfo((int *)&local_4);
    CityInfo_UpdateDemandRatingBars(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 10:
    ptr1 = SubMenu_BuildSupplierInfo((int *)&local_4);
    MarketShareMenu_Init(ptr1);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0xb:
    pvVar2 = SubMenu_CreateFurniturePage((int *)&local_4);
    FurnitureMenu_InitChairPage(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0xc:
    pvVar2 = SubMenu_BuildGuardHiring((int *)&local_4);
    GuardMenu_Fill(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0xd:
    pvVar2 = SubMenu_BuildGuardAssignment((int *)&local_4);
    GuardMenu_UpdateOrderPage(pvVar2,'\x01');
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0xe:
    pvVar2 = Screen_PersonnelOverview((int *)&local_4);
    PersonnelOverview_Refresh(pvVar2,1);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0xf:
    pvVar2 = SubMenu_BuildAdvertisingCampaign((int *)&local_4);
    AdvertisingPage_FillCampaign(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x10:
    pvVar2 = SubMenu_BuildBranchReport((int *)&local_4);
    BranchPage_UpdateInfoPanel(pvVar2,'\x01');
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x11:
    pvVar2 = SubMenu_BuildCriminalOrderStatus((int *)&local_4);
    GangsterWeaponPanel_RefreshWithSound(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x12:
    pvVar2 = SubMenu_BuildSchool((int *)&local_4);
    SchoolMenu_UpdatePage(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x13:
    pvVar2 = SubMenu_BuildGuardOverview((int *)&local_4);
    BranchWindow_InitCostPanel(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x14:
    pvVar2 = SubMenu_BuildConstructionInfo((int *)&local_4);
    ConstructionMenu_Fill(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x15:
    pvVar2 = SubMenu_BuildBranchRating((int *)&local_4);
    FurniturePriceMenu_Init(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x16:
    pvVar2 = SubMenu_BuildBranchStorerooms((int *)&local_4);
    PriceMenu_Init(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x17:
    pvVar2 = Screen_BranchDetails((int *)&local_4);
    PersonInfoPanel_Update(pvVar2,'\x01');
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x18:
    pvVar2 = PestMenu_CreateWindow((int *)&local_4);
    PestMenu_FillPricesAndCounts(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x19:
    pvVar2 = SubMenu_BuildPosterAdvertisingStatus((int *)&local_4);
    BranchInfoPanel_Update(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x1a:
    pvVar2 = SubMenu_BuildBranchOverview((int *)&local_4);
    BranchRatingPanel_Update(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x1c:
    pvVar2 = SubMenu_CreatePolicePage((int *)&local_4);
    Window_UpdatePolicePage(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x1d:
    pvVar2 = Screen_PersonnelRecord((int *)&local_4);
    Window_UpdateStaffPlanPage(pvVar2,'\x01','\x01');
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x1e:
    pvVar2 = Screen_Warehouse((int *)&local_4);
    WarehouseScreen_Refresh(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x1f:
    pvVar2 = Screen_BranchOffer((int *)&local_4);
    Window_UpdateWarehousePage(pvVar2);
    *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
    return (intptr_t)local_4;
  case 0x20:
    pvVar2 = SubMenu_BuildKitchen((int *)&local_4);
    FurnitureMenu_InitOvenPage(pvVar2);
  }
  *(uint32_t *)((intptr_t)self + 0x2d8) = arg1;
  return (intptr_t)local_4;
}
