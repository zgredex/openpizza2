// Stats_ComputePlayerAggregateStats: ported from Pizza Connection 2 at 0x4df480.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4df480
#include "pc2_port.h"

void __thiscall Stats_ComputePlayerAggregateStats(void *self,int *arg1)

{
  int value1;
  int value2;
  void *pvVar3;
  int value4;
  int value5;
  int64_t lvalue6;
  uint64_t uvalue7;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_c = 1;
  local_8 = 1;
  local_4 = 1;
  value4 = 0;
  value5 = *(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10) - 1;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (0 < *(int *)((intptr_t)self + 0x15c)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value4,(int *)0x0);
      Stats_SumFilteredRecordFloats20(value1,-1,value5);
      lvalue6 = __ftol();
      value2 = (intptr_t)lvalue6;
      local_24 = local_24 + value2;
      if (local_18 < value2) {
        local_18 = value2;
      }
      Stats_SumFilteredFloats(value1,-1,-1,value5);
      uvalue7 = __ftol();
      Stats_SumFilteredFloats2(value1,-1,-1,value5);
      lvalue6 = __ftol();
      value1 = (intptr_t)lvalue6;
      value2 = (intptr_t)uvalue7 - value1;
      if (value2 < 0) {
        value2 = 0;
      }
      local_20 = local_20 + value2;
      if (local_14 < value2) {
        local_14 = value2;
      }
      if (value1 < 1) {
        value1 = 0;
      }
      else {
        value1 = (intptr_t)((int64_t)((uint64_t)(uint32_t)((intptr_t)uvalue7 >> 0x1f) << 0x20 | uvalue7 & 0xffffffff)
                     / (int64_t)value1);
      }
      local_1c = local_1c + value1;
      if (local_10 < value1) {
        local_10 = value1;
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)((intptr_t)self + 0x15c));
  }
  local_28 = 0;
  do {
    pvVar3 = (void *)Game_GetPlayerBySlot(DAT_0057c670,local_28);
    if (((pvVar3 != (void *)0x0) && (pvVar3 != self)) &&
       (value4 = 0, 0 < *(int *)((intptr_t)pvVar3 + 0x15c))) {
      do {
        value1 = IDMap_Lookup((void *)((intptr_t)pvVar3 + 0x148),value4,(int *)0x0);
        Stats_SumFilteredRecordFloats20(value1,-1,value5);
        lvalue6 = __ftol();
        if (local_18 < (intptr_t)lvalue6) {
          local_c = 0;
        }
        Stats_SumFilteredFloats(value1,-1,-1,value5);
        uvalue7 = __ftol();
        Stats_SumFilteredFloats2(value1,-1,-1,value5);
        lvalue6 = __ftol();
        value1 = (intptr_t)lvalue6;
        value2 = (intptr_t)uvalue7 - value1;
        if (value2 < 0) {
          value2 = 0;
        }
        if (local_14 < value2) {
          local_8 = 0;
        }
        if (value1 < 1) {
          value1 = 0;
        }
        else {
          value1 = (intptr_t)((int64_t)
                        ((uint64_t)(uint32_t)((intptr_t)uvalue7 >> 0x1f) << 0x20 | uvalue7 & 0xffffffff) /
                       (int64_t)value1);
        }
        if (local_10 < value1) {
          local_4 = 0;
        }
        value4 = value4 + 1;
      } while (value4 < *(int *)((intptr_t)pvVar3 + 0x15c));
    }
    local_28 = local_28 + 1;
  } while (local_28 < 6);
  if (local_24 == 0) {
    local_c = 0;
  }
  if (local_20 == 0) {
    local_8 = 0;
  }
  if (local_1c == 0) {
    local_4 = 0;
  }
  *(int *)(*arg1 + 0x60) = local_24;
  *(int *)(*arg1 + 100) = local_18;
  *(int *)(*arg1 + 400) = local_24 / 100 + local_c * 5000;
  *(int *)(*arg1 + 0x68) = local_20;
  *(int *)(*arg1 + 0x6c) = local_14;
  *(int *)(*arg1 + 0x194) = local_20 / 10 + local_8 * 5000;
  *(int *)(*arg1 + 0x70) = local_1c;
  *(int *)(*arg1 + 0x74) = local_10;
  *(int *)(*arg1 + 0x198) = (local_1c + local_4 * 10) * 500;
  lvalue6 = __ftol();
  *(int *)(*arg1 + 0x78) = (intptr_t)lvalue6;
  lvalue6 = __ftol();
  *(int *)(*arg1 + 0x19c) = (intptr_t)lvalue6;
  return;
}
