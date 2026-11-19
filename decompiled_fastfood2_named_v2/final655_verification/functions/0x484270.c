// rea decompile_all
// name: SubMenu_CreateBuildingPage
// address: 0x484270
// body: available
// range: 0x484270-0x484493 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __fastcall SubMenu_CreateBuildingPage(void *param_1)

{
  int iVar1;
  void *pvVar2;
  void *local_4;
  
                    /* Dispatches and creates the active building/interior submenu page. */
  *(undefined4 *)((int)param_1 + 0x2d8) = 0;
  local_4 = param_1;
  if (*(int *)((int)param_1 + 0x268) != 0) {
    FUN_00482890((int)param_1);
  }
  switch(*(undefined4 *)((int)param_1 + *(int *)((int)param_1 + 0x290) * 4 + 0x298)) {
  case 1:
    pvVar2 = SubMenu_BuildBranchInformation((int *)&local_4);
    BuildingInfoMenu_Init(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 2:
    pvVar2 = SubMenu_BuildPersonnelPlan((int *)&local_4);
    Window_UpdateStaffPlanPage(pvVar2,'\0','\0');
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 3:
    pvVar2 = SubMenu_BuildFurnishings((int *)&local_4);
    MusicMenu_Init(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 4:
    pvVar2 = SubMenu_BuildMenuOverview((int *)&local_4);
    CityBuildingListPage_Update(pvVar2,'\x01');
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 5:
    pvVar2 = FUN_0040cee0((int *)&local_4);
    FUN_0048fad0(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 6:
    pvVar2 = SubMenu_BuildBranchAdvertising((int *)&local_4);
    AdvertisingScreen_UpdatePlan(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 7:
    pvVar2 = SubMenu_BuildInteriorDesigner((int *)&local_4);
    CompanyMenu_InitStylePage(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 8:
    pvVar2 = Window_BuildBranchPriceSettingsPage((int *)&local_4);
    ManagerPage_Update(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 9:
    break;
  case 10:
    local_4 = (void *)SubMenu_OpenPage(param_1,*(undefined4 *)((int)param_1 + 0x2e4));
    iVar1 = FUN_00528040(DAT_0057c5e0,(int)local_4,(int *)0x0);
    *(int *)((int)param_1 + 0x264) = iVar1;
    return local_4;
  case 0xb:
    pvVar2 = Screen_PersonnelOverview((int *)&local_4);
    PersonnelOverview_Refresh(pvVar2,0);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  default:
    *(void **)((int)param_1 + 0x264) = local_4;
    return local_4;
  }
  if (*(char *)(*(int *)((int)param_1 + 0x9c) + 0x16f5) == '\0') {
    pvVar2 = SubMenu_BuildBranchExpansion((int *)&local_4);
    BranchInfo_UpdateRatingBars(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  }
  pvVar2 = FUN_00458f50((int *)&local_4);
  *(undefined4 *)((int)param_1 + 0x218) = *(undefined4 *)(*(int *)((int)param_1 + 0x9c) + 0x16f0);
  FUN_004c03c0(pvVar2);
  *(void **)((int)param_1 + 0x264) = pvVar2;
  return local_4;
}

