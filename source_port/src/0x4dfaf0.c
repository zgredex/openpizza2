// Game_ComputeCompanyOverviewStats: ported from Pizza Connection 2 at 0x4dfaf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dfaf0
#include "pc2_port.h"

void __thiscall Game_ComputeCompanyOverviewStats(void *self,int *arg1)

{
  uint16_t uvalue1;
  int value2;
  int *ptr3;
  int value4;
  int value5;
  void *this_00;
  int *ptr6;
  int value7;
  int local_18;
  int local_10;
  int local_c;
  
  ptr3 = arg1;
  uvalue1 = *(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10);
  local_18 = 0;
  value2 = *(int *)((intptr_t)self + 0x124);
  local_c = 0;
  value7 = 1;
  *(int *)(*arg1 + 0x9c) = value2;
  value4 = Game_CountActiveCompanies((intptr_t)self);
  value5 = *arg1;
  arg1 = (int *)0x0;
  *(int *)(value5 + 0xa0) = value4;
  do {
    value5 = Game_GetPlayerBySlot(DAT_0057c670,(intptr_t)arg1);
    if (value5 != 0) {
      value5 = Game_CountActiveCompanies(value5);
      if (value4 < value5) {
        value7 = 0;
      }
    }
    arg1 = (int *)((intptr_t)arg1 + 1);
  } while ((intptr_t)arg1 < 6);
  value4 = 0;
  ptr6 = (int *)0x0;
  local_10 = 0;
  arg1 = (int *)0x0;
  *(int *)(*ptr3 + 0x170) = (value2 + value7 * 10) * 500;
  value2 = *(int *)((intptr_t)self + 0x124);
  value5 = 0;
  if (0 < value2) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x110),value4,(int *)0x0);
      value5 = AI_CountPlanSteps(this_00,uvalue1 - 1,0,-1);
      local_10 = local_10 + value5;
      if (local_18 < value5) {
        local_18 = value5;
      }
      value5 = 0;
      do {
        value7 = Game_MapInputIndex(this_00,value5);
        if (local_c < value7) {
          local_c = value7;
        }
        value5 = value5 + 1;
      } while (value5 < 8);
      value5 = Game_MapInputIndex(this_00,value4);
      ptr6 = (int *)((intptr_t)arg1 + value5);
      value4 = value4 + 1;
      arg1 = ptr6;
    } while (value4 < value2);
    value5 = local_18;
  }
  if (value2 != 0) {
    ptr6 = (int *)((intptr_t)ptr6 / value2);
  }
  *(int *)(*ptr3 + 0xa4) = local_10;
  *(int *)(*ptr3 + 0xa8) = value5;
  *(int **)(*ptr3 + 0xac) = ptr6;
  *(int *)(*ptr3 + 0xb0) = local_c;
  *(int *)(*ptr3 + 0x174) = local_10 / 5 + value5;
  *(int *)(*ptr3 + 0x178) = (intptr_t)ptr6 * 400;
  value2 = *(int *)((intptr_t)self + 0x54);
  value5 = *(int *)((intptr_t)self + 0x58);
  *(int *)(*ptr3 + 0xb4) = value2;
  *(int *)(*ptr3 + 0xb8) = value5;
  *(int *)(*ptr3 + 0x17c) = (value2 + value5) * 1000;
  return;
}
