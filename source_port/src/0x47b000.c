// Branch_Load: ported from Pizza Connection 2 at 0x47b000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47b000
#include "pc2_port.h"


void __thiscall Branch_Load(void *self,void *arg1,uint32_t *arg2)

{
  void *this_00;
  uint32_t uvalue1;
  uint32_t *uptr2;
  void *pvVar3;
  int *ptr4;
  int local_1c;
  int local_18;
  int local_14;
  uint32_t local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  this_00 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557f6c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CRT_Istream_Read(arg1,(intptr_t)self + 4,0x20);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x2c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x24,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x28,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x30,4);
  CRT_Istream_Read(this_00,(int *)((intptr_t)self + 0x34),4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x3c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x40,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x44,0x144);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x188,0x144);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x554,0xe10);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1364,0x24);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x2cc,0x144);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x410,0x144);
  CRT_Istream_Read(this_00,(intptr_t)self + 5000,0x48);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x13d0,0x48);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1418,0x48);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1460,0x48);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14a8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14ac,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14c8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14cc,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14d0,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14d4,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14c0,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14d8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x16f5,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x16f4,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14b0,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1714,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1718,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x171c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1720,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1724,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x151c,0x1a0);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x16bc,0x34);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x177c,0x20);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x179c,0x20);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x17bc,0x20);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x17dc,0x20);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x17fc,0x20);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x181c,0x20);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x183c,0x14);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1850,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1854,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1858,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x185c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1860,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1864,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1868,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x186c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1870,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1874,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1878,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x38,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1898,0x40);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x18d8,0xc0);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x187c,4);
  CRT_Istream_Read(this_00,(int *)((intptr_t)self + 0x19fc),4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1a00,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1a04,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1880,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x19b4,0x10);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14b4,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1a20,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1a21,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1884,0x10);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1a2c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1a30,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1a34,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1a38,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1a24,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14b8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14bc,4);
  if (DAT_0057c668 < 0x2c) {
    *(uint32_t *)((intptr_t)self + 0x1894) = 0;
  }
  else {
    CRT_Istream_Read(this_00,(intptr_t)self + 0x1894,4);
  }
  local_14 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x34),(int *)0x0);
  CRT_Istream_Read(this_00,&arg1,4);
  if (arg1 == (void *)0x1) {
    CRT_Istream_Read(this_00,&local_18,4);
    uvalue1 = IDMap_Lookup(arg2 + 0x44,local_18,(int *)0x0);
    *(uint32_t *)((intptr_t)self + 0x14dc) = uvalue1;
  }
  else {
    *(uint32_t *)((intptr_t)self + 0x14dc) = 0;
  }
  CRT_Istream_Read(this_00,&arg1,4);
  uvalue1 = Game_UpdateIDMapEntry(DAT_0057c5cc,(intptr_t)arg1);
  *(uint32_t *)((intptr_t)self + 0x14e0) = uvalue1;
  Game_GetSizeName(self,*(int *)((intptr_t)self + 0x19fc));
  Branch_ApplyBuildingStyleVariant(self,*(int *)((intptr_t)self + 0x1a04));
  CRT_Istream_Read(this_00,&local_1c,4);
  arg1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      arg2 = operator_new(0x35c);
      local_4 = 0;
      if (arg2 == (uint32_t *)0x0) {
        uptr2 = (uint32_t *)0x0;
      }
      else {
        uptr2 = StatsPeriodReport_StreamConstruct(arg2,this_00);
      }
      local_4 = 0xffffffff;
      List_Add((void *)((intptr_t)self + 0x14e4),uptr2);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_18,4);
  if (local_18 == -1) {
    *(uint32_t *)((intptr_t)self + 0x16f0) = 0;
  }
  else {
    uvalue1 = IDMap_Lookup((void *)(local_14 + 0xfac),local_18,(int *)0x0);
    *(uint32_t *)((intptr_t)self + 0x16f0) = uvalue1;
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  arg1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_10,4);
      CRT_Istream_Read(this_00,&local_18,4);
      uptr2 = operator_new(8);
      local_4 = 1;
      arg2 = uptr2;
      if (uptr2 == (uint32_t *)0x0) {
        uptr2 = (uint32_t *)0x0;
      }
      else {
        uvalue1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),local_18,(int *)0x0);
        *uptr2 = uvalue1;
        uptr2[1] = local_10;
      }
      local_4 = 0xffffffff;
      List_Add((void *)((intptr_t)self + 0x1500),uptr2);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  arg1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      arg2 = operator_new(0x24);
      local_4 = 2;
      if (arg2 == (uint32_t *)0x0) {
        uptr2 = (uint32_t *)0x0;
      }
      else {
        uptr2 = ConstructionOrder_StreamConstruct(arg2,this_00);
      }
      local_4 = 0xffffffff;
      IDMap_InsertGrow((void *)((intptr_t)self + 0x16f8),uptr2,local_18);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  arg1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      if (0 < local_18) {
        List_Add((void *)((intptr_t)self + 0x1728),local_18);
      }
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  arg1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      List_Add((void *)((intptr_t)self + 0x1744),local_18);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  arg1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      List_Add((void *)((intptr_t)self + 0x1760),local_18);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  arg1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      pvVar3 = operator_new(0x20);
      CRT_Istream_Read(this_00,pvVar3,0x20);
      IDMap_InsertGrow((void *)((intptr_t)self + 0x1998),pvVar3,local_18);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  arg1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      pvVar3 = operator_new(0x30);
      CRT_Istream_Read(this_00,pvVar3,0x30);
      List_Add((void *)((intptr_t)self + 0x19c4),pvVar3);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  arg1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      arg2 = operator_new(0x24);
      local_4 = 3;
      if (arg2 == (uint32_t *)0x0) {
        uptr2 = (uint32_t *)0x0;
      }
      else {
        uptr2 = ConstructionOrder_StreamConstruct(arg2,this_00);
      }
      local_4 = 0xffffffff;
      IDMap_InsertGrow((void *)((intptr_t)self + 0x19e0),uptr2,local_18);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  IsoMap_MarkPlayerFootprints(*(void **)((intptr_t)self + 0x14e0),(intptr_t)self);
  if (*(char *)((intptr_t)self + 0x1a20) != '\0') {
    Game_ShowBuildingOverlay(self,1);
  }
  *(uint32_t *)((intptr_t)self + 0x14c4) = 0;
  local_1c = *(int *)((intptr_t)self + 0x1514);
  arg1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      ptr4 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),(intptr_t)arg1,(int *)0x0);
      if (*(char *)(*ptr4 + 0x824) == '\x01') {
        *(int *)((intptr_t)self + 0x14c4) = *ptr4;
        ExceptionList = local_c;
        return;
      }
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  ExceptionList = local_c;
  return;
}
