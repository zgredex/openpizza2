// rea decompile_all
// name: SaveGame_Serialize
// address: 0x487b50
// body: available
// range: 0x487b50-0x4880bb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall SaveGame_Serialize(void *this,int *param_1)

{
  int *this_00;
  void *pvVar1;
  int iVar2;
  int *piVar3;
  int local_34 [5];
  int local_20 [4];
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  this_00 = param_1;
  local_34[2] = 0x2e;
  local_34[3] = 0x2a;
  local_34[4] = Stream_GetWritePosition(param_1);
  piVar3 = local_20;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  CRT_Ostream_Write(this_00,local_20,0x20);
  CRT_Ostream_Write(this_00,local_34 + 2,4);
  CRT_Ostream_Write(this_00,&DAT_0057bb20,0x5b8);
  CRT_Ostream_Write(this_00,(int)this + 0x298,0x20);
  CRT_Ostream_Write(this_00,(int)this + 0x2b8,0x20);
  CRT_Ostream_Write(this_00,(int)this + 0x2d8,4);
  CRT_Ostream_Write(this_00,(int)this + 0x2dc,4);
  CRT_Ostream_Write(this_00,(int)this + 0x2ec,4);
  CRT_Ostream_Write(this_00,(int)this + 0x2f0,4);
  CRT_Ostream_Write(this_00,(int)this + 0x2f4,4);
  CRT_Ostream_Write(this_00,(int)this + 0x2e8,4);
  CRT_Ostream_Write(this_00,(int)this + 0x2f8,4);
  CRT_Ostream_Write(this_00,(int)this + 0x33c,4);
  CRT_Ostream_Write(this_00,(int)this + 0x348,4);
  CRT_Ostream_Write(this_00,(int)this + 0x34c,4);
  CRT_Ostream_Write(this_00,(int)this + 0x350,4);
  CRT_Ostream_Write(this_00,(int)this + 0x344,4);
  CRT_Ostream_Write(this_00,(int)this + 0x354,4);
  CRT_Ostream_Write(this_00,(int)this + 0x340,4);
  CRT_Ostream_Write(this_00,(int)this + 0x364,4);
  CRT_Ostream_Write(this_00,(int)this + 0x368,4);
  CRT_Ostream_Write(this_00,(int)this + 0x360,4);
  CRT_Ostream_Write(this_00,(int)this + 0x358,4);
  CRT_Ostream_Write(this_00,(int)this + 0x35c,4);
  CRT_Ostream_Write(this_00,(int)this + 0x2d90,4);
  IngredientPanel_Save(this_00);
  CityCompanyList_Save(this_00);
  AdvertisingPanel_Save(this_00);
  CompanyMarketShare_Save(this_00);
  CompanyOverview_Save(this_00);
  StatisticsBalance_Save(this_00);
  StatisticsBranchBalance_Save(this_00);
  Personnel_Save(this_00);
  BranchStats_SeriesFlags_Save(this_00);
  BranchDesign_ColorIndex_Save(this_00);
  BranchMenu_Category_Save(this_00);
  WarehouseProduct_Save(this_00);
  GameCalendar_Save(*(void **)((int)this + 0x94),this_00);
  UI_BriefingList_Save((void *)((int)this + 0x304),this_00);
  Game_SaveTileNameTable(DAT_0057c5cc,this_00);
  param_1 = *(int **)((int)DAT_0057c5cc + 0x2c40c);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((int)DAT_0057c5cc + 0x2c3f8),iVar2,(int *)0x0);
      local_34[0] = Game_RemoveIDMapEntry(DAT_0057c5cc,(int)pvVar1);
      CRT_Ostream_Write(this_00,local_34,4);
      IsoMap_Save(pvVar1,this_00,1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  local_20[1] = Stream_GetWritePosition(this_00);
  param_1 = *(int **)((int)this + 0x34);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((int)this + 0x20),iVar2,local_34);
      CRT_Ostream_Write(this_00,local_34,4);
      Character_Save(pvVar1,this_00);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  local_20[2] = Stream_GetWritePosition(this_00);
  param_1 = *(int **)((int)this + 0x18);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      piVar3 = this_00;
      pvVar1 = (void *)IDMap_Lookup((void *)((int)this + 4),iVar2,(int *)0x0);
      MapObjectList_Save(pvVar1,piVar3);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  local_20[0] = Stream_GetWritePosition(this_00);
  param_1 = *(int **)((int)this + 0x50);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),iVar2,local_34);
      CRT_Ostream_Write(this_00,local_34,4);
      PersonList_Save(pvVar1,this_00);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  local_8 = Stream_GetWritePosition(this_00);
  param_1 = *(int **)((int)this + 0x6c);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((int)this + 0x58),iVar2,local_34);
      CRT_Ostream_Write(this_00,local_34,4);
      CarList_Save(pvVar1,this_00);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  local_10 = Stream_GetWritePosition(this_00);
  piVar3 = (int *)((int)this + 0x224);
  iVar2 = 6;
  do {
    if (*piVar3 == 0) {
      local_34[0] = 0;
      CRT_Ostream_Write(this_00,local_34,4);
    }
    else {
      local_34[0] = 1;
      CRT_Ostream_Write(this_00,local_34,4);
      Player_Save((void *)*piVar3,this_00);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_20[3] = Stream_GetWritePosition(this_00);
  piVar3 = (int *)((int)this + 0x200);
  iVar2 = 6;
  do {
    if (*piVar3 == 0) {
      local_34[1] = 0;
      CRT_Ostream_Write(this_00,local_34 + 1,4);
    }
    else {
      local_34[1] = 1;
      CRT_Ostream_Write(this_00,local_34 + 1,4);
      CompanyData_Save((void *)*piVar3,this_00);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_c = Stream_GetWritePosition(this_00);
  AI_CompanySlots_Save(*(void **)((int)this + 0x90),this_00);
  if (*(int *)((int)this + 0x9c) == 0) {
    local_34[0] = 0;
  }
  else {
    local_34[0] = 1;
    CRT_Ostream_Write(this_00,local_34,4);
    local_34[0] = *(int *)(*(int *)((int)this + 0x9c) + 0x30);
    CRT_Ostream_Write(this_00,local_34,4);
    local_34[0] = *(int *)(*(int *)((int)this + 0x9c) + 0x3c);
  }
  CRT_Ostream_Write(this_00,local_34,4);
  SaveGame_SerializeRuntimeList(this,this_00);
  CRT_Ostream_Write(this_00,local_34 + 3,4);
  iVar2 = Stream_GetWritePosition(this_00);
  local_4 = iVar2;
  CRT_FileBufClose(this_00,local_34[4]);
  CRT_Ostream_Write(this_00,local_20,0x20);
  CRT_FileBufClose(this_00,iVar2);
  return;
}

