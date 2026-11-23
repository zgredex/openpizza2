// Object_PickWeightedBuildingRecord: ported from Pizza Connection 2 at 0x506010.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x506010
#include "pc2_port.h"

int __thiscall
Object_PickWeightedBuildingRecord
          (void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4,uint32_t arg5,uint32_t arg6,
          uint32_t arg7,uint32_t arg8)

{
  uint8_t flag1;
  uint32_t uvalue2;
  void *pvVar3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  uint32_t uvalue9;
  uint32_t uvalue10;
  uint32_t uvalue11;
  uint32_t uvalue12;
  uint8_t *bptr13;
  int value14;
  char cVar15;
  uint32_t local_80;
  uint8_t local_64 [100];
  
  uvalue5 = arg6 & 0xff;
  uvalue8 = arg8 & 0xff;
  uvalue6 = arg7 & 0xff;
  uvalue2 = arg5 & 0xff;
  uvalue12 = arg4 & 0xff;
  uvalue9 = arg3 & 0xff;
  uvalue10 = arg2 & 0xff;
  uvalue11 = arg1 & 0xff;
  if (uvalue8 + uvalue6 + uvalue5 + uvalue2 + uvalue12 + uvalue9 + uvalue10 + uvalue11 != 100) {
    NoOp_Stub();
  }
  local_80 = 0;
  if (((char)arg1 != '\0') && (uvalue11 != 0)) {
    bptr13 = local_64;
    for (uvalue7 = uvalue11 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
      *(uint32_t *)bptr13 =
           CONCAT22(CONCAT11(DAT_00580ac8,DAT_00580ac8),CONCAT11(DAT_00580ac8,DAT_00580ac8));
      bptr13 = bptr13 + 4;
    }
    for (uvalue7 = arg1 & 3; local_80 = uvalue11, uvalue7 != 0; uvalue7 = uvalue7 - 1) {
      *bptr13 = DAT_00580ac8;
      bptr13 = bptr13 + 1;
    }
  }
  if (((char)arg2 != '\0') && (uvalue10 != 0)) {
    bptr13 = local_64 + local_80;
    for (uvalue11 = uvalue10 >> 2; uvalue11 != 0; uvalue11 = uvalue11 - 1) {
      *(uint32_t *)bptr13 =
           CONCAT22(CONCAT11(DAT_00580ac9,DAT_00580ac9),CONCAT11(DAT_00580ac9,DAT_00580ac9));
      bptr13 = bptr13 + 4;
    }
    local_80 = local_80 + uvalue10;
    for (uvalue10 = arg2 & 3; uvalue10 != 0; uvalue10 = uvalue10 - 1) {
      *bptr13 = DAT_00580ac9;
      bptr13 = bptr13 + 1;
    }
  }
  if (((char)arg3 != '\0') && (uvalue9 != 0)) {
    bptr13 = local_64 + local_80;
    for (uvalue10 = uvalue9 >> 2; uvalue10 != 0; uvalue10 = uvalue10 - 1) {
      *(uint32_t *)bptr13 =
           CONCAT22(CONCAT11(DAT_00580aca,DAT_00580aca),CONCAT11(DAT_00580aca,DAT_00580aca));
      bptr13 = bptr13 + 4;
    }
    local_80 = local_80 + uvalue9;
    for (uvalue9 = arg3 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
      *bptr13 = DAT_00580aca;
      bptr13 = bptr13 + 1;
    }
  }
  if (((char)arg4 != '\0') && (uvalue12 != 0)) {
    bptr13 = local_64 + local_80;
    for (uvalue9 = uvalue12 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
      *(uint32_t *)bptr13 =
           CONCAT22(CONCAT11(DAT_00580acb,DAT_00580acb),CONCAT11(DAT_00580acb,DAT_00580acb));
      bptr13 = bptr13 + 4;
    }
    for (uvalue9 = arg4 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
      *bptr13 = DAT_00580acb;
      bptr13 = bptr13 + 1;
    }
    local_80 = local_80 + uvalue12;
  }
  if (((char)arg5 != '\0') && (uvalue2 != 0)) {
    bptr13 = local_64 + local_80;
    for (uvalue9 = uvalue2 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
      *(uint32_t *)bptr13 =
           CONCAT22(CONCAT11(DAT_00580acc,DAT_00580acc),CONCAT11(DAT_00580acc,DAT_00580acc));
      bptr13 = bptr13 + 4;
    }
    for (uvalue9 = arg5 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
      *bptr13 = DAT_00580acc;
      bptr13 = bptr13 + 1;
    }
    local_80 = local_80 + uvalue2;
  }
  if (((char)arg6 != '\0') && (uvalue5 != 0)) {
    bptr13 = local_64 + local_80;
    for (uvalue2 = uvalue5 >> 2; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *(uint32_t *)bptr13 =
           CONCAT22(CONCAT11(DAT_00580acd,DAT_00580acd),CONCAT11(DAT_00580acd,DAT_00580acd));
      bptr13 = bptr13 + 4;
    }
    for (uvalue2 = arg6 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *bptr13 = DAT_00580acd;
      bptr13 = bptr13 + 1;
    }
    local_80 = local_80 + uvalue5;
  }
  if (((char)arg7 != '\0') && (uvalue6 != 0)) {
    bptr13 = local_64 + local_80;
    for (uvalue2 = uvalue6 >> 2; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *(uint32_t *)bptr13 =
           CONCAT22(CONCAT11(DAT_00580ace,DAT_00580ace),CONCAT11(DAT_00580ace,DAT_00580ace));
      bptr13 = bptr13 + 4;
    }
    for (uvalue2 = arg7 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *bptr13 = DAT_00580ace;
      bptr13 = bptr13 + 1;
    }
    local_80 = local_80 + uvalue6;
  }
  if (((char)arg8 != '\0') && (uvalue8 != 0)) {
    bptr13 = local_64 + local_80;
    for (uvalue8 = uvalue8 >> 2; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
      *(uint32_t *)bptr13 =
           CONCAT22(CONCAT11(DAT_00580acf,DAT_00580acf),CONCAT11(DAT_00580acf,DAT_00580acf));
      bptr13 = bptr13 + 4;
    }
    for (uvalue2 = arg8 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *bptr13 = DAT_00580acf;
      bptr13 = bptr13 + 1;
    }
  }
  uvalue2 = Random_RangeFast(0,99);
  flag1 = local_64[uvalue2];
  if (flag1 == 0) {
    return *(int *)((intptr_t)self + 0xcc);
  }
  pvVar3 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  value4 = Map_GetRandomBuildingOfType(pvVar3,(uint32_t)flag1,0,'\0');
  if (value4 == 0) {
    cVar15 = '\0';
    value14 = 0;
    value4 = 0;
    pvVar3 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
    value4 = Map_GetRandomBuildingOfType(pvVar3,value4,value14,cVar15);
  }
  return value4;
}
