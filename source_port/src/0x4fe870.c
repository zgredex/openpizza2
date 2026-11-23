// Company_AllocateMenuSales: ported from Pizza Connection 2 at 0x4fe870.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fe870
#include "pc2_port.h"

void __thiscall Company_AllocateMenuSales(void *self,int arg1)

{
  int value1;
  int value2;
  void *pvVar3;
  int value4;
  int value5;
  int *ptr6;
  int value7;
  int value8;
  int value9;
  int64_t lvalue10;
  int64_t lvalue11;
  int local_334;
  int local_324;
  int local_320 [4];
  int local_310 [196];
  
  value9 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x70);
  value1 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x40);
  Player_ComputeNetStatTotal(value9);
  lvalue10 = __ftol();
  lvalue11 = __ftol();
  value7 = ((intptr_t)lvalue10 >> 5) + (intptr_t)lvalue11;
  value2 = *(int *)(value9 + 0x140);
  value8 = 0;
  local_334 = 0;
  if (0 < value2) {
    ptr6 = local_320 + 4;
    value5 = value7;
    do {
      pvVar3 = (void *)IDMap_Lookup((void *)(value9 + 300),value8,(int *)0x0);
      value4 = *(int *)((intptr_t)pvVar3 + 8);
      ptr6[-4] = (intptr_t)pvVar3;
      if (value4 == 1) {
        local_324 = *(int *)(value9 + 0x15c);
        value5 = 10000;
LAB_004fe920:
        *(int *)((intptr_t)pvVar3 + 0x20) = value5;
        value4 = GamePlan_ComputeAverageEffect(pvVar3,value1);
        ptr6[-3] = value4;
        if (value4 < 0x29) {
          ptr6[-2] = 0;
          GamePlan_SetActiveEffect((void *)ptr6[-4],0,value1);
          *ptr6 = 1;
        }
        else {
          *ptr6 = 0;
          ptr6[-2] = ptr6[-3] * local_324;
          ptr6[-1] = value5;
        }
        local_334 = local_334 + ptr6[-2];
      }
      else {
        if (value4 == 2) {
          local_324 = 1;
          value5 = 5000;
          goto LAB_004fe920;
        }
        if (value4 != 3) goto LAB_004fe920;
        *ptr6 = 1;
      }
      value8 = value8 + 1;
      ptr6 = ptr6 + 5;
    } while (value8 < value2);
  }
  while( true ) {
    value8 = -1;
    value5 = 0;
    value9 = 9999;
    if (value2 < 1) {
      return;
    }
    ptr6 = local_320 + 2;
    do {
      if ((ptr6[2] == 0) && ((value8 == -1 || (value9 < *ptr6)))) {
        value9 = *ptr6;
        value8 = value5;
      }
      value5 = value5 + 1;
      ptr6 = ptr6 + 5;
    } while (value5 < value2);
    if (value8 == -1) break;
    local_320[value8 * 5 + 4] = 1;
    if (*(int *)(local_320[value8 * 5] + 8) == 1) {
      value9 = local_320[value8 * 5 + 1];
      ptr6 = local_320 + 4;
      value5 = value2;
      do {
        if ((*ptr6 == 0) && (ptr6[-3] <= value9)) {
          *ptr6 = 1;
          local_334 = local_334 - ptr6[-2];
        }
        ptr6 = ptr6 + 5;
        value5 = value5 + -1;
      } while (value5 != 0);
    }
    if (local_334 < 1) {
      return;
    }
    value9 = local_320[value8 * 5 + 2];
    value5 = (value9 * value7) / local_334;
    if (local_320[value8 * 5 + 3] < value5) {
      value5 = local_320[value8 * 5 + 3];
    }
    pvVar3 = (void *)local_320[value8 * 5];
    *(int *)((intptr_t)pvVar3 + 0x20) = value5;
    GamePlan_SetActiveEffect(pvVar3,(uint32_t)(0 < value5),value1);
    value7 = value7 - value5;
    local_334 = local_334 - value9;
    if (value7 < 1) {
      return;
    }
  }
  return;
}
