// Branch_Construct: ported from Pizza Connection 2 at 0x476b60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x476b60
#include "pc2_port.h"

uint32_t * __thiscall
Branch_Construct(void *self,int arg1,uint32_t arg2,uint32_t arg3)

{
  void *pvVar1;
  uint32_t *uptr2;
  int value3;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs a branch business object and its containers. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557e5a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x14e4),0);
  local_4 = 0;
  List_Construct((void *)((intptr_t)self + 0x1500),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x16f8),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x1728),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x1744),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x1760),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x1998),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x19c4),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((7) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x19e0),0);
  *(uint8_t ***)self = &PTR_Branch_Delete_0055c30c;
  *(uint32_t *)((intptr_t)self + 0x30) = arg2;
  *(uint32_t *)((intptr_t)self + 0x34) = arg3;
  *(int *)((intptr_t)self + 0x38) = arg1;
  *(uint32_t *)((intptr_t)self + 0x14dc) = 0;
  *(uint32_t *)((intptr_t)self + 0x14a8) = 100;
  *(uint32_t *)((intptr_t)self + 0x14ac) = 10;
  *(uint32_t *)((intptr_t)self + 0x14b8) = 0;
  *(uint32_t *)((intptr_t)self + 0x14bc) = 0;
  *(uint32_t *)((intptr_t)self + 0x1894) = 0;
  *(uint32_t *)((intptr_t)self + 0x1a28) = 0;
  local_4 = (local_4 & ~(0x0u << 8)) | (((8) & 0x0u) << 8);
  uptr2 = (uint32_t *)((intptr_t)self + 0x44);
  for (value3 = 0x51; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x188);
  for (value3 = 0x51; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x2cc);
  for (value3 = 0x51; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x410);
  for (value3 = 0x51; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x554);
  for (value3 = 900; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x1364);
  for (value3 = 9; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0x19b4) = 0;
  *(uint32_t *)((intptr_t)self + 0x19b8) = 0;
  *(uint32_t *)((intptr_t)self + 0x19bc) = 0;
  *(uint32_t *)((intptr_t)self + 0x19c0) = 0;
  uptr2 = (uint32_t *)((intptr_t)self + 5000);
  for (value3 = 0x12; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x13d0);
  for (value3 = 0x12; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x1418);
  for (value3 = 0x12; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x1460);
  for (value3 = 0x12; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0x1884) = 0;
  *(uint32_t *)((intptr_t)self + 0x1888) = 0;
  *(uint32_t *)((intptr_t)self + 0x188c) = 0;
  *(uint32_t *)((intptr_t)self + 0x1890) = 0;
  *(uint32_t *)((intptr_t)self + 0x14c8) = 0;
  *(uint32_t *)((intptr_t)self + 0x14cc) = 0;
  *(uint32_t *)((intptr_t)self + 0x14d0) = 0;
  *(uint32_t *)((intptr_t)self + 0x14d4) = 0;
  *(uint32_t *)((intptr_t)self + 0x14c0) = 0;
  *(uint32_t *)((intptr_t)self + 0x14b4) = 0;
  *(uint32_t *)((intptr_t)self + 0x14d8) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x24) = 0;
  *(uint32_t *)((intptr_t)self + 0x16f0) = 0;
  *(uint32_t *)((intptr_t)self + 0x28) = 0;
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  *(uint8_t *)((intptr_t)self + 0x16f4) = 1;
  *(uint32_t *)((intptr_t)self + 0x14b0) = 0;
  *(uint32_t *)((intptr_t)self + 0x14c4) = 0;
  *(uint32_t *)((intptr_t)self + 0x1714) = 0;
  *(uint32_t *)((intptr_t)self + 0x1718) = 0;
  *(uint32_t *)((intptr_t)self + 0x171c) = 0;
  *(uint32_t *)((intptr_t)self + 0x1720) = 0;
  *(uint32_t *)((intptr_t)self + 0x1724) = 0;
  *(uint8_t *)((intptr_t)self + 0x16f5) = 0;
  uptr2 = (uint32_t *)((intptr_t)self + 0x177c);
  for (value3 = 8; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x179c);
  for (value3 = 8; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x17bc);
  for (value3 = 8; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x1898);
  for (value3 = 0x10; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x18d8);
  for (value3 = 0x30; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x16bc);
  for (value3 = 0xd; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x151c);
  for (value3 = 0x68; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0x187c) = 0;
  *(uint32_t *)((intptr_t)self + 0x19fc) = 4;
  *(uint32_t *)((intptr_t)self + 0x1a00) = 0;
  *(uint32_t *)((intptr_t)self + 0x1a04) = 4;
  *(uint8_t *)((intptr_t)self + 0x1880) = 0;
  *(uint8_t *)((intptr_t)self + 0x1881) = 0;
  *(uint8_t *)((intptr_t)self + 0x1882) = 0;
  *(uint8_t *)((intptr_t)self + 0x1883) = 0;
  *(uint8_t *)((intptr_t)self + 0x1a20) = 0;
  *(uint8_t *)((intptr_t)self + 0x1a21) = 0;
  *(uint32_t *)((intptr_t)self + 0x3c) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x1a2c) = 1;
  *(uint32_t *)((intptr_t)self + 0x1a30) = 0;
  *(uint32_t *)((intptr_t)self + 0x1a34) = 0;
  *(uint32_t *)((intptr_t)self + 0x1a38) = 0;
  *(uint32_t *)((intptr_t)self + 0x1a24) = 0;
  if (arg1 == 0) {
    pvVar1 = operator_new(0x10178);
    local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),9);
    if (pvVar1 == (void *)0x0) {
LAB_00476ee2:
      uptr2 = (uint32_t *)0x0;
    }
    else {
      uptr2 = IsoMap_Construct(pvVar1,(intptr_t)DAT_0057c5cc);
    }
  }
  else if (arg1 == 1) {
    pvVar1 = operator_new(0x10178);
    local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),10);
    if (pvVar1 == (void *)0x0) goto LAB_00476ee2;
    uptr2 = IsoMap_Construct(pvVar1,(intptr_t)DAT_0057c5cc);
  }
  else {
    if (arg1 != 2) goto LAB_00476eef;
    pvVar1 = operator_new(0x10178);
    local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),0xb);
    if (pvVar1 == (void *)0x0) goto LAB_00476ee2;
    uptr2 = IsoMap_Construct(pvVar1,(intptr_t)DAT_0057c5cc);
  }
  *(uint32_t **)((intptr_t)self + 0x14e0) = uptr2;
LAB_00476eef:
  local_4 = (local_4 & ~(0x0u << 8)) | (((8) & 0x0u) << 8);
  value3 = Object_GetBufferCount(*(void **)((intptr_t)self + 0x14e0),(uint32_t *)0x1);
  if (value3 == 0) {
    Grid_RebuildStreetNodes(*(void **)((intptr_t)self + 0x14e0),(intptr_t)self);
  }
  Game_GetSizeName(self,*(int *)((intptr_t)self + 0x19fc));
  Branch_ApplyBuildingStyleVariant(self,*(int *)((intptr_t)self + 0x1a04));
  Game_RegisterWorldObject(DAT_0057c5cc,*(uint32_t *)((intptr_t)self + 0x14e0),-1);
  *(uint32_t *)((intptr_t)self + 0x40) = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  pvVar1 = operator_new(0x35c);
  local_4 = (local_4 & ~(0x0u << 8)) | (((0xc) & 0x0u) << 8);
  if (pvVar1 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = Stats_Report_ConstructEmpty
                       (pvVar1,(uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10),
                        (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4));
  }
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),8);
  List_Add((void *)((intptr_t)self + 0x14e4),uptr2);
  Map_CollectType351ToList((intptr_t)self);
  Stats_ResetAverages(self);
  ExceptionList = local_c;
  return self;
}
