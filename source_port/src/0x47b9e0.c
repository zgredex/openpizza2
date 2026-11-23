// Branch_Save: ported from Pizza Connection 2 at 0x47b9e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47b9e0
#include "pc2_port.h"

void __thiscall Branch_Save(void *self,void *arg1)

{
  void *pvVar1;
  int *ptr2;
  uint32_t uvalue3;
  int value4;
  int local_14;
  int local_10;
  int local_c;
  void *local_8;
  int local_4;
  
  local_8 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x34),
                                 (int *)0x0);
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,0x20);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x2c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x24,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x28,4);
  CRT_Ostream_Write(arg1,(int *)((intptr_t)self + 0x30),4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x34,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x3c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x40,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x44,0x144);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x188,0x144);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x554,0xe10);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1364,0x24);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x2cc,0x144);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x410,0x144);
  CRT_Ostream_Write(arg1,(intptr_t)self + 5000,0x48);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x13d0,0x48);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1418,0x48);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1460,0x48);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14a8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14ac,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14c8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14cc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14d0,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14d4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14c0,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14d8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x16f5,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x16f4,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14b0,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1714,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1718,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x171c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1720,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1724,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x151c,0x1a0);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x16bc,0x34);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x177c,0x20);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x179c,0x20);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x17bc,0x20);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x17dc,0x20);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x17fc,0x20);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x181c,0x20);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x183c,0x14);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1850,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1854,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1858,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x185c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1860,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1864,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1868,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x186c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1870,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1874,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1878,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x38,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1898,0x40);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x18d8,0xc0);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x187c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x19fc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1a00,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1a04,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1880,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x19b4,0x10);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14b4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1a20,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1a21,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1884,0x10);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1a2c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1a30,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1a34,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1a38,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1a24,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14b8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14bc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1894,4);
  if (*(int *)((intptr_t)self + 0x14dc) == 0) {
    ptr2 = &local_10;
    local_10 = 0;
  }
  else {
    local_10 = 1;
    CRT_Ostream_Write(arg1,&local_10,4);
    value4 = *(int *)((intptr_t)self + 0x14dc);
    pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
    local_c = Game_FindCompanyIndex(pvVar1,value4);
    ptr2 = &local_c;
  }
  CRT_Ostream_Write(arg1,ptr2,4);
  local_10 = Game_RemoveIDMapEntry(DAT_0057c5cc,*(int *)((intptr_t)self + 0x14e0));
  CRT_Ostream_Write(arg1,&local_10,4);
  local_14 = *(int *)((intptr_t)self + 0x14f8);
  CRT_Ostream_Write(arg1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x14e4),local_10,(int *)0x0);
      StatsPeriodReport_Save(pvVar1,arg1);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_c = Array_FindIndexByPtr(local_8,*(int *)((intptr_t)self + 0x16f0));
  CRT_Ostream_Write(arg1,&local_c,4);
  local_14 = *(int *)((intptr_t)self + 0x1514);
  CRT_Ostream_Write(arg1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),local_10,(int *)0x0);
      local_4 = ptr2[1];
      CRT_Ostream_Write(arg1,&local_4,4);
      local_c = Map_LookupLinear((void *)((intptr_t)DAT_0057c670 + 0x20),*ptr2);
      CRT_Ostream_Write(arg1,&local_c,4);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((intptr_t)self + 0x170c);
  CRT_Ostream_Write(arg1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x16f8),local_10,&local_c);
      CRT_Ostream_Write(arg1,&local_c,4);
      ConstructionOrder_Save(pvVar1,arg1);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((intptr_t)self + 0x173c);
  CRT_Ostream_Write(arg1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      local_c = IDMap_Lookup((void *)((intptr_t)self + 0x1728),local_10,(int *)0x0);
      CRT_Ostream_Write(arg1,&local_c,4);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((intptr_t)self + 0x1758);
  CRT_Ostream_Write(arg1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      local_c = IDMap_Lookup((void *)((intptr_t)self + 0x1744),local_10,(int *)0x0);
      CRT_Ostream_Write(arg1,&local_c,4);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((intptr_t)self + 0x1774);
  CRT_Ostream_Write(arg1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      local_c = IDMap_Lookup((void *)((intptr_t)self + 0x1760),local_10,(int *)0x0);
      CRT_Ostream_Write(arg1,&local_c,4);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((intptr_t)self + 0x19ac);
  CRT_Ostream_Write(arg1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      uvalue3 = IDMap_Lookup((void *)((intptr_t)self + 0x1998),local_10,&local_c);
      CRT_Ostream_Write(arg1,&local_c,4);
      CRT_Ostream_Write(arg1,uvalue3,0x20);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((intptr_t)self + 0x19d8);
  CRT_Ostream_Write(arg1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      uvalue3 = IDMap_Lookup((void *)((intptr_t)self + 0x19c4),local_10,(int *)0x0);
      CRT_Ostream_Write(arg1,uvalue3,0x30);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((intptr_t)self + 0x19f4);
  CRT_Ostream_Write(arg1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x19e0),local_10,&local_c);
      CRT_Ostream_Write(arg1,&local_c,4);
      ConstructionOrder_Save(pvVar1,arg1);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  return;
}
