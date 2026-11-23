// SaveGame_Serialize: ported from Pizza Connection 2 at 0x487b50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x487b50
#include "pc2_port.h"

void __thiscall SaveGame_Serialize(void *self,int *arg1)

{
  int *this_00;
  void *pvVar1;
  int value2;
  int *ptr3;
  int local_34 [5];
  int local_20 [4];
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  this_00 = arg1;
  local_34[2] = 0x2e;
  local_34[3] = 0x2a;
  local_34[4] = Stream_GetWritePosition(arg1);
  ptr3 = local_20;
  for (value2 = 8; value2 != 0; value2 = value2 + -1) {
    *ptr3 = 0;
    ptr3 = ptr3 + 1;
  }
  CRT_Ostream_Write(this_00,local_20,0x20);
  CRT_Ostream_Write(this_00,local_34 + 2,4);
  CRT_Ostream_Write(this_00,&DAT_0057bb20,0x5b8);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x298,0x20);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2b8,0x20);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2d8,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2dc,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2ec,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2f0,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2f4,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2e8,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2f8,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x33c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x348,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x34c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x350,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x344,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x354,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x340,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x364,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x368,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x360,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x358,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x35c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2d90,4);
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
  GameCalendar_Save(*(void **)((intptr_t)self + 0x94),this_00);
  UI_BriefingList_Save((void *)((intptr_t)self + 0x304),this_00);
  Game_SaveTileNameTable(DAT_0057c5cc,this_00);
  arg1 = *(int **)((intptr_t)DAT_0057c5cc + 0x2c40c);
  CRT_Ostream_Write(this_00,&arg1,4);
  value2 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c5cc + 0x2c3f8),value2,(int *)0x0);
      local_34[0] = Game_RemoveIDMapEntry(DAT_0057c5cc,(intptr_t)pvVar1);
      CRT_Ostream_Write(this_00,local_34,4);
      IsoMap_Save(pvVar1,this_00,1);
      value2 = value2 + 1;
    } while (value2 < (intptr_t)arg1);
  }
  local_20[1] = Stream_GetWritePosition(this_00);
  arg1 = *(int **)((intptr_t)self + 0x34);
  CRT_Ostream_Write(this_00,&arg1,4);
  value2 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x20),value2,local_34);
      CRT_Ostream_Write(this_00,local_34,4);
      Character_Save(pvVar1,this_00);
      value2 = value2 + 1;
    } while (value2 < (intptr_t)arg1);
  }
  local_20[2] = Stream_GetWritePosition(this_00);
  arg1 = *(int **)((intptr_t)self + 0x18);
  CRT_Ostream_Write(this_00,&arg1,4);
  value2 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      ptr3 = this_00;
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),value2,(int *)0x0);
      MapObjectList_Save(pvVar1,ptr3);
      value2 = value2 + 1;
    } while (value2 < (intptr_t)arg1);
  }
  local_20[0] = Stream_GetWritePosition(this_00);
  arg1 = *(int **)((intptr_t)self + 0x50);
  CRT_Ostream_Write(this_00,&arg1,4);
  value2 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),value2,local_34);
      CRT_Ostream_Write(this_00,local_34,4);
      PersonList_Save(pvVar1,this_00);
      value2 = value2 + 1;
    } while (value2 < (intptr_t)arg1);
  }
  local_8 = Stream_GetWritePosition(this_00);
  arg1 = *(int **)((intptr_t)self + 0x6c);
  CRT_Ostream_Write(this_00,&arg1,4);
  value2 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x58),value2,local_34);
      CRT_Ostream_Write(this_00,local_34,4);
      CarList_Save(pvVar1,this_00);
      value2 = value2 + 1;
    } while (value2 < (intptr_t)arg1);
  }
  local_10 = Stream_GetWritePosition(this_00);
  ptr3 = (int *)((intptr_t)self + 0x224);
  value2 = 6;
  do {
    if (*ptr3 == 0) {
      local_34[0] = 0;
      CRT_Ostream_Write(this_00,local_34,4);
    }
    else {
      local_34[0] = 1;
      CRT_Ostream_Write(this_00,local_34,4);
      Player_Save((void *)*ptr3,this_00);
    }
    ptr3 = ptr3 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  local_20[3] = Stream_GetWritePosition(this_00);
  ptr3 = (int *)((intptr_t)self + 0x200);
  value2 = 6;
  do {
    if (*ptr3 == 0) {
      local_34[1] = 0;
      CRT_Ostream_Write(this_00,local_34 + 1,4);
    }
    else {
      local_34[1] = 1;
      CRT_Ostream_Write(this_00,local_34 + 1,4);
      CompanyData_Save((void *)*ptr3,this_00);
    }
    ptr3 = ptr3 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  local_c = Stream_GetWritePosition(this_00);
  AI_CompanySlots_Save(*(void **)((intptr_t)self + 0x90),this_00);
  if (*(int *)((intptr_t)self + 0x9c) == 0) {
    local_34[0] = 0;
  }
  else {
    local_34[0] = 1;
    CRT_Ostream_Write(this_00,local_34,4);
    local_34[0] = *(int *)(*(int *)((intptr_t)self + 0x9c) + 0x30);
    CRT_Ostream_Write(this_00,local_34,4);
    local_34[0] = *(int *)(*(int *)((intptr_t)self + 0x9c) + 0x3c);
  }
  CRT_Ostream_Write(this_00,local_34,4);
  SaveGame_SerializeRuntimeList(self,this_00);
  CRT_Ostream_Write(this_00,local_34 + 3,4);
  value2 = Stream_GetWritePosition(this_00);
  local_4 = value2;
  CRT_FileBufClose(this_00,local_34[4]);
  CRT_Ostream_Write(this_00,local_20,0x20);
  CRT_FileBufClose(this_00,value2);
  return;
}
