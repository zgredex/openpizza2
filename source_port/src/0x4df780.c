// Game_ComputeCompanyRankStats: ported from Pizza Connection 2 at 0x4df780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4df780
#include "pc2_port.h"

void __thiscall Game_ComputeCompanyRankStats(void *self,int *arg1)

{
  int *ptr1;
  void *pvVar2;
  int value3;
  void *this_00;
  int value4;
  int value5;
  int value6;
  int64_t lvalue7;
  int64_t lvalue8;
  int64_t lvalue9;
  int local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  ptr1 = arg1;
  local_10 = 1;
  local_c = 1;
  local_8 = 1;
  local_4 = 1;
  local_24 = 0;
  local_2c = 0;
  local_28 = 0;
  value5 = 0;
  value6 = 0;
  value4 = *(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10) - 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  if (0 < *(int *)((intptr_t)self + 0x15c)) {
    do {
      pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),value6,(int *)0x0);
      Stats_SumFilteredFloats2((intptr_t)pvVar2,0x10,-1,value4);
      lvalue7 = __ftol();
      if (local_20 < (intptr_t)lvalue7) {
        local_20 = (intptr_t)lvalue7;
      }
      value3 = *(int *)(*(int *)((intptr_t)pvVar2 + 0x16f0) + 0x74);
      if (value3 == 0) {
        value3 = -1;
      }
      else {
        value3 = Game_GetAdjustedValue(value3);
      }
      local_2c = local_2c + value3;
      if (local_1c < value3) {
        local_1c = value3;
      }
      value3 = Game_SumStatGrid(pvVar2,-1,-1);
      local_28 = local_28 + value3;
      if (local_18 < value3) {
        local_18 = value3;
      }
      value3 = Game_SumStatRow8(pvVar2,-1);
      local_24 = local_24 + value3;
      if (value5 < value3) {
        value5 = value3;
      }
      value6 = value6 + 1;
    } while (value6 < *(int *)((intptr_t)self + 0x15c));
  }
  Stats_SumFilteredFloats4((intptr_t)self,0xf,-1,value4);
  lvalue7 = __ftol();
  Stats_SumFilteredFloats4((intptr_t)self,0x10,-1,value4);
  lvalue8 = __ftol();
  Stats_SumFilteredFloats4((intptr_t)self,0x11,-1,value4);
  lvalue9 = __ftol();
  value6 = (intptr_t)lvalue7 + (intptr_t)lvalue8 + (intptr_t)lvalue9;
  local_34 = 0;
  *(int *)(*arg1 + 0x7c) = value6;
  *(int *)(*arg1 + 0x80) = local_20;
  *(int *)(*arg1 + 0x84) = local_2c;
  *(int *)(*arg1 + 0x88) = local_1c;
  *(int *)(*arg1 + 0x8c) = local_28;
  *(int *)(*arg1 + 0x90) = local_18;
  *(int *)(*arg1 + 0x94) = local_24;
  *(int *)(*arg1 + 0x98) = value5;
  do {
    pvVar2 = (void *)Game_GetPlayerBySlot(DAT_0057c670,local_34);
    if (((pvVar2 != (void *)0x0) && (pvVar2 != self)) &&
       (arg1 = (int *)0x0, 0 < *(int *)((intptr_t)pvVar2 + 0x15c))) {
      do {
        this_00 = (void *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),(intptr_t)arg1,(int *)0x0);
        Stats_SumFilteredFloats2((intptr_t)this_00,0x10,-1,value4);
        lvalue7 = __ftol();
        if (local_20 <= (intptr_t)lvalue7) {
          local_10 = 0;
        }
        value3 = *(int *)(*(int *)((intptr_t)this_00 + 0x16f0) + 0x74);
        if (value3 == 0) {
          value3 = -1;
        }
        else {
          value3 = Game_GetAdjustedValue(value3);
        }
        if (local_1c <= value3) {
          local_c = 0;
        }
        value3 = Game_SumStatGrid2(this_00,-1,-1);
        if (local_18 <= value3) {
          local_8 = 0;
        }
        value3 = Game_SumStatRow8(this_00,-1);
        if (value5 <= value3) {
          local_4 = 0;
        }
        arg1 = (int *)((intptr_t)arg1 + 1);
      } while ((intptr_t)arg1 < *(int *)((intptr_t)pvVar2 + 0x15c));
    }
    local_34 = local_34 + 1;
  } while (local_34 < 6);
  if (value6 == 0) {
    local_10 = 0;
  }
  if (local_2c == 0) {
    local_c = 0;
  }
  if (local_28 == 0) {
    local_8 = 0;
  }
  value5 = 0;
  if (local_24 != 0) {
    value5 = local_4;
  }
  *(int *)(*ptr1 + 0x160) = (value6 * 2) / 5 + local_10 * 5000;
  *(int *)(*ptr1 + 0x164) = (local_2c + local_c * 500) * 10;
  *(int *)(*ptr1 + 0x168) = (local_28 + local_8 * 500) * 10;
  *(int *)(*ptr1 + 0x16c) = (local_24 + value5 * 0x32) * 100;
  return;
}
