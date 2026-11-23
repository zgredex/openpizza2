// GamePlan_Optimize: ported from Pizza Connection 2 at 0x4fe5f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fe5f0
#include "pc2_port.h"

uint32_t __thiscall GamePlan_Optimize(void *self,int arg1,uint32_t *arg2)

{
  void *this_00;
  int value1;
  uint32_t uvalue2;
  bool flag3;
  int value4;
  int value5;
  int value6;
  int value7;
  int value8;
  int *ptr9;
  uint32_t uvalue10;
  int *ptr11;
  int64_t lvalue12;
  int local_16c;
  uint32_t local_160;
  int local_15c;
  int local_158 [86];
  
                    /* Optimizes an advertising plan's budget, category, and target. */
  this_00 = *(void **)((intptr_t)self + arg1 * 0x168 + 0x70);
  value1 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x40);
  if (arg2[2] != 3) {
    Company_DeactivatePlanEntry(this_00,arg2,0);
  }
  value8 = arg2[2];
  if (value8 == 1) {
    local_160 = 10000;
    value8 = Game_GetPlayerFieldC20((intptr_t)this_00);
    if (value8 < 3) {
      return 0;
    }
    if (*(int *)((intptr_t)this_00 + 0x15c) < 3) {
      return 0;
    }
  }
  else if (value8 == 2) {
    local_160 = 5000;
  }
  else if (value8 == 3) {
    local_160 = 0xdac;
  }
  arg2[8] = local_160;
  value8 = *(int *)((intptr_t)this_00 + 0x124);
  if (0 < value8) {
    ptr9 = local_158;
    for (value7 = 0x56; value7 != 0; value7 = value7 + -1) {
      *ptr9 = 0;
      ptr9 = ptr9 + 1;
    }
    local_15c = 0;
    if (0 < value8) {
      do {
        value7 = IDMap_Lookup((void *)((intptr_t)this_00 + 0x110),local_15c,(int *)0x0);
        if ((value7 != 0) && (*(char *)(value7 + 0x1dc) != '\0')) {
          ptr11 = local_158;
          ptr9 = (int *)(value7 + 100);
          local_16c = 0x56;
          do {
            if (0 < *ptr9) {
              lvalue12 = __ftol();
              *ptr11 = *ptr11 + (intptr_t)lvalue12 * *ptr9;
            }
            ptr9 = ptr9 + 1;
            ptr11 = ptr11 + 1;
            local_16c = local_16c + -1;
          } while (local_16c != 0);
        }
        local_15c = local_15c + 1;
      } while (local_15c < value8);
    }
    value7 = 0;
    value8 = 0;
    value4 = 0;
    ptr9 = local_158;
    do {
      if (value8 < *ptr9) {
        value8 = *ptr9;
        value7 = value4;
      }
      value4 = value4 + 1;
      ptr9 = ptr9 + 1;
    } while (value4 < 0x56);
    if (0 < value8) {
      arg2[6] = value7 + 1;
    }
  }
  arg2[4] = 0;
  arg2[5] = 0;
  arg2[7] = 0xffffffff;
  value4 = GamePlan_ComputeAverageEffect(arg2,value1);
  value7 = 0;
  local_16c = 0;
  value8 = 1;
  do {
    arg2[4] = value8;
    value5 = GamePlan_ComputeAverageEffect(arg2,value1);
    if (value7 == 0) {
LAB_004fe794:
      value7 = value5 - value4;
      local_16c = value8;
    }
    else if (value7 < value5 - value4) goto LAB_004fe794;
    flag3 = value8 < 0xc;
    value8 = value8 + 1;
  } while (flag3);
  if (value7 < 1) {
    arg2[4] = 0;
  }
  else {
    value4 = value4 + value7;
    arg2[4] = local_16c;
  }
  uvalue10 = 1;
  do {
    uvalue2 = arg2[5];
    arg2[5] = uvalue2 | uvalue10;
    value8 = GamePlan_ComputeAverageEffect(arg2,value1);
    if (value8 - value4 < 1) {
      arg2[5] = uvalue2;
    }
    else {
      value4 = value4 + (value8 - value4);
    }
    uvalue10 = uvalue10 * 2;
  } while ((intptr_t)uvalue10 < 0x10);
  value5 = 0;
  local_16c = 0;
  value8 = 0;
  value7 = Game_GetPlayerCount(DAT_0057c670);
  if (0 < value7) {
    do {
      if (value5 != value1) {
        arg2[7] = value5;
        value6 = GamePlan_ComputeAverageEffect(arg2,value1);
        if (value8 != 0) {
          if (value6 - value4 <= value8) goto LAB_004fe826;
        }
        value8 = value6 - value4;
        local_16c = value5;
      }
LAB_004fe826:
      value5 = value5 + 1;
    } while (value5 < value7);
    if (0 < value8) {
      arg2[7] = local_16c;
      return 1;
    }
  }
  arg2[7] = 0xffffffff;
  return 1;
}
