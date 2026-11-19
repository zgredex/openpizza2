// rea decompile_all
// name: SubMenu_OpenPage
// address: 0x483740
// body: available
// range: 0x483740-0x483bb5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall SubMenu_OpenPage(void *this,undefined4 param_1)

{
  int *piVar1;
  void *pvVar2;
  void *local_4;
  
                    /* Opens and fills a selected submenu page. */
  local_4 = this;
  if (*(int *)((int)this + 0x268) != 0) {
    FUN_00482890((int)this);
  }
  switch(param_1) {
  case 1:
    SubMenu_BuildPersonnelChoice((int *)&local_4);
    FUN_0048e0a0();
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 2:
    pvVar2 = SubMenu_BuildCourierMission((int *)&local_4);
    BuildingInfo_Fill(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 3:
    pvVar2 = SubMenu_BuildWarehouse((int *)&local_4);
    StorageMenu_Init(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 4:
    pvVar2 = SubMenu_BuildStockInformation((int *)&local_4);
    LeaseBuilding_UpdatePage(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 5:
    pvVar2 = SubMenu_BuildHeadquarters((int *)&local_4);
    CompanyOverview_FillTotals(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 6:
    pvVar2 = SubMenu_BuildMayor((int *)&local_4);
    StarAward_Fill(pvVar2,'\x01');
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 7:
    pvVar2 = SubMenu_BuildCriminalHiring((int *)&local_4);
    CriminalsPage_FillRecruitOptions(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 8:
    pvVar2 = SubMenu_BuildPosterAdvertisingSetup((int *)&local_4);
    PosterAdvertisingPage_Update(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 9:
    pvVar2 = FUN_00468bd0((int *)&local_4);
    CityInfo_UpdateDemandRatingBars(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 10:
    piVar1 = SubMenu_BuildSupplierInfo((int *)&local_4);
    MarketShareMenu_Init(piVar1);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0xb:
    pvVar2 = SubMenu_CreateFurniturePage((int *)&local_4);
    FurnitureMenu_InitChairPage(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0xc:
    pvVar2 = SubMenu_BuildGuardHiring((int *)&local_4);
    FUN_004bd340(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0xd:
    pvVar2 = SubMenu_BuildGuardAssignment((int *)&local_4);
    GuardMenu_UpdateOrderPage(pvVar2,'\x01');
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0xe:
    pvVar2 = Screen_PersonnelOverview((int *)&local_4);
    PersonnelOverview_Refresh(pvVar2,1);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0xf:
    pvVar2 = SubMenu_BuildAdvertisingCampaign((int *)&local_4);
    AdvertisingPage_FillCampaign(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x10:
    pvVar2 = SubMenu_BuildBranchReport((int *)&local_4);
    FUN_004bade0(pvVar2,'\x01');
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x11:
    pvVar2 = SubMenu_BuildCriminalOrderStatus((int *)&local_4);
    GangsterWeaponPanel_RefreshWithSound(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x12:
    pvVar2 = SubMenu_BuildSchool((int *)&local_4);
    SchoolMenu_UpdatePage(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x13:
    pvVar2 = SubMenu_BuildGuardOverview((int *)&local_4);
    BranchWindow_InitCostPanel(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x14:
    pvVar2 = FUN_00458f50((int *)&local_4);
    FUN_004c03c0(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x15:
    pvVar2 = SubMenu_BuildBranchRating((int *)&local_4);
    FurniturePriceMenu_Init(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x16:
    pvVar2 = SubMenu_BuildBranchStorerooms((int *)&local_4);
    PriceMenu_Init(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x17:
    pvVar2 = Screen_BranchDetails((int *)&local_4);
    PersonInfoPanel_Update(pvVar2,'\x01');
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x18:
    pvVar2 = PestMenu_CreateWindow((int *)&local_4);
    FUN_004c5280(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x19:
    pvVar2 = SubMenu_BuildPosterAdvertisingStatus((int *)&local_4);
    BranchInfoPanel_Update(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x1a:
    pvVar2 = SubMenu_BuildBranchOverview((int *)&local_4);
    BranchRatingPanel_Update(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x1c:
    pvVar2 = SubMenu_CreatePolicePage((int *)&local_4);
    Window_UpdatePolicePage(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x1d:
    pvVar2 = Screen_PersonnelRecord((int *)&local_4);
    Window_UpdateStaffPlanPage(pvVar2,'\x01','\x01');
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x1e:
    pvVar2 = Screen_Warehouse((int *)&local_4);
    WarehouseScreen_Refresh(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x1f:
    pvVar2 = Screen_BranchOffer((int *)&local_4);
    Window_UpdateWarehousePage(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x20:
    pvVar2 = SubMenu_BuildKitchen((int *)&local_4);
    FurnitureMenu_InitOvenPage(pvVar2);
  }
  *(undefined4 *)((int)this + 0x2d8) = param_1;
  return (int)local_4;
}

