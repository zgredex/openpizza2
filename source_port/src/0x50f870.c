// GamePlan_ComputeCategoryEffect: ported from Pizza Connection 2 at 0x50f870.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50f870
#include "pc2_port.h"

int __thiscall GamePlan_ComputeCategoryEffect(void *self,int arg1,int arg2)

{
  int value1;
  void *pvVar2;
  int value3;
  int value4;
  int value5;
  int value6;
  uint32_t local_14;
  int local_c;
  int local_8;
  int local_4;
  
  value1 = Game_GetPlayerBySlot(DAT_0057c670,arg1);
  if (*(int *)(value1 + 0x15c) == 0) {
    return 0;
  }
  arg1 = 0x28;
  if (*(int *)((intptr_t)self + 0x10) != 0) {
    arg1 = (*(int *)(&DAT_005730ac + (arg2 + *(int *)((intptr_t)self + 0x10) * 8) * 4) + 8) * 5;
  }
  if (*(int *)((intptr_t)self + 0x1c) < 1) {
    local_c = 0;
  }
  else {
    local_c = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x1c));
  }
  if (*(int *)((intptr_t)self + 0x14) != 0) {
    local_14 = 1;
    do {
      if ((*(uint32_t *)((intptr_t)self + 0x14) & local_14) != 0) {
        local_8 = 0x2d;
        local_4 = 0x37;
        if (local_c != 0) {
          value6 = *(int *)(local_c + 0x15c);
          value4 = 0;
          value5 = 0;
          if (0 < value6) {
            do {
              pvVar2 = (void *)IDMap_Lookup((void *)(local_c + 0x148),value5,(int *)0x0);
              value3 = GamePlan_GetCompanyCategoryMetric(self,local_14,pvVar2,arg2,local_14);
              value4 = value4 + value3;
              value5 = value5 + 1;
            } while (value5 < value6);
            if (0 < value6) {
              local_8 = value4 / value6 + -5;
              local_4 = value4 / value6 + 5;
            }
          }
        }
        if ((*(int *)((intptr_t)self + 8) == 2) || (*(int *)((intptr_t)self + 8) == 3)) {
          pvVar2 = (void *)IDMap_Lookup((void *)(value1 + 0x148),*(int *)((intptr_t)self + 0xc),(int *)0x0
                                       );
          value6 = GamePlan_GetCompanyCategoryMetric(self,arg2,pvVar2,arg2,local_14);
        }
        else {
          value6 = 0;
          value5 = 0;
          value4 = *(int *)(value1 + 0x15c);
          if (0 < value4) {
            do {
              pvVar2 = (void *)IDMap_Lookup((void *)(value1 + 0x148),value5,(int *)0x0);
              value3 = GamePlan_GetCompanyCategoryMetric(self,local_14,pvVar2,arg2,local_14);
              value6 = value6 + value3;
              value5 = value5 + 1;
            } while (value5 < value4);
            if (0 < value4) {
              value6 = value6 / value4;
            }
          }
        }
        if (value6 < local_8) {
          arg1 = arg1 - (local_8 - value6 >> 2);
        }
        if (local_4 < value6) {
          arg1 = arg1 + (value6 - local_4 >> 1);
        }
      }
      local_14 = local_14 * 2;
    } while ((intptr_t)local_14 < 0xf);
  }
  value6 = Company_GetPercentModifier(self,-1);
  value1 = Game_GetPlayerCity(value1);
  value1 = (((*(int *)(value1 + 100) + *(int *)(value1 + 0x4c)) * -3 + 100) *
          ((value6 * (arg1 + -0x28)) / 100 + 0x28)) / 100;
  if (value1 < 0) {
    return 0;
  }
  if (100 < value1) {
    value1 = 100;
  }
  return value1;
}
