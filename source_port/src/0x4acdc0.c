// StatisticsBranchBalance_UpdateWeeklyRows: ported from Pizza Connection 2 at 0x4acdc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4acdc0
#include "pc2_port.h"

void __cdecl StatisticsBranchBalance_UpdateWeeklyRows(void *arg1,char arg2)

{
  void *pvVar1;
  void *pvVar2;
  void *self;
  int value3;
  int *ptr4;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  int value5;
  int value6;
  uint32_t unaff_EDI;
  int value7;
  double fVar8;
  int64_t lvalue9;
  float local_f8;
  float local_f4;
  int local_f0 [7];
  int local_d4;
  int local_d0;
  void *local_cc;
  int local_c8 [7];
  int local_ac [9];
  int local_88 [9];
  int local_64 [9];
  uint8_t local_40 [64];
  
  local_f4 = 0.0;
  ptr4 = local_c8;
                    /* Recomputes the weekly branch-balance KPI rows. */
  for (value3 = 7; value3 != 0; value3 = value3 + -1) {
    *ptr4 = 0;
    ptr4 = ptr4 + 1;
  }
  ptr4 = local_88;
  for (value3 = 9; value3 != 0; value3 = value3 + -1) {
    *ptr4 = 0;
    ptr4 = ptr4 + 1;
  }
  ptr4 = local_ac;
  for (value3 = 9; value3 != 0; value3 = value3 + -1) {
    *ptr4 = 0;
    ptr4 = ptr4 + 1;
  }
  ptr4 = local_64;
  for (value3 = 9; value3 != 0; value3 = value3 + -1) {
    *ptr4 = 0;
    ptr4 = ptr4 + 1;
  }
  pvVar2 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_cc = pvVar2;
  local_d0 = *(int *)((intptr_t)pvVar2 + 0x15c);
  if (*(int *)((intptr_t)pvVar2 + 0x15c) == 0) {
    String_Format(local_40,DAT_00582e4c,unaff_EDI);
    value3 = 0x845;
    value7 = 0;
    do {
      value6 = 0;
      do {
        UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00569520 + value7) + -0x10 + value6);
        value6 = value6 + 0x11;
      } while (value6 < 0x55);
      Window_GadgetNotify_Text_SetText(arg1,*(int *)((intptr_t)&DAT_00569548 + value7),local_40);
      Window_GadgetNotify_Text_SetText(arg1,*(int *)((intptr_t)&DAT_00569548 + value7) + 1,local_40);
      Window_GadgetNotify_Text_SetText(arg1,value3,local_40);
      value3 = value3 + 3;
      value7 = value7 + 4;
    } while (value3 < 0x863);
    return;
  }
  if (DAT_0056951c == -1) {
    value3 = 0;
    do {
      value7 = local_d0;
      value5 = 0;
      ptr4 = local_f0;
      for (value6 = 7; value6 != 0; value6 = value6 + -1) {
        *ptr4 = 0;
        ptr4 = ptr4 + 1;
      }
      local_f8 = 0.0;
      local_d4 = 0;
      if (0 < value7) {
        do {
          pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),value5,(int *)0x0);
          value7 = Stats_GetAverage8(pvVar1,value3);
          local_f0[0] = local_f0[0] + value7;
          value7 = Branch_ComputeBuildingRating(pvVar1,extraout_EDX,value3);
          local_f0[1] = local_f0[1] + value7;
          value7 = Branch_GetMenuRating(pvVar1,value3);
          local_f0[2] = local_f0[2] + value7;
          pvVar2 = (void *)Player_FindRecordType2ByKey(pvVar2,value5);
          if ((pvVar2 == (void *)0x0) || (*(int *)((intptr_t)pvVar2 + 4) == 0)) {
            value7 = 0;
          }
          else {
            value7 = value3;
            value6 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
            value7 = GamePlan_ComputeCategoryEffect(pvVar2,value6,value7);
            value7 = Math_PiecewiseLinear(value7);
            local_d4 = local_d4 + 1;
          }
          local_f0[3] = local_f0[3] + value7;
          value7 = Branch_GetCustomerGroupRating(pvVar1,value3,1);
          local_f0[4] = local_f0[4] + value7;
          value7 = Game_SumStatGrid2(pvVar1,value3,-1);
          local_f0[5] = local_f0[5] + value7;
          value7 = Game_SumStatRow8(pvVar1,value3);
          local_f0[6] = local_f0[6] + value7;
          fVar8 = Stats_SumFilteredFloats
                            ((intptr_t)pvVar1,value3,(uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4),
                             (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10));
          value5 = value5 + 1;
          local_f8 = (float)(fVar8 + (double)local_f8);
          pvVar2 = local_cc;
        } while (value5 < local_d0);
      }
      value7 = local_d4;
      value6 = 0;
      ptr4 = local_f0;
      do {
        if (value6 != 3) {
          *ptr4 = *ptr4 / local_d0;
        }
        value6 = value6 + 1;
        ptr4 = ptr4 + 1;
      } while (value6 < 5);
      if (value7 != 0) {
        local_f0[3] = local_f0[3] / value7;
      }
      local_88[value3] = local_88[value3] + local_f0[5];
      local_ac[value3] = local_ac[value3] + local_f0[6];
      lvalue9 = __ftol();
      local_64[value3] = local_64[value3] + (intptr_t)lvalue9;
      StatisticsBranchBalance_DrawColumn(arg1,local_f0,local_f8,value3,arg2);
      value7 = 0;
      do {
        *(int *)((intptr_t)local_c8 + value7) =
             *(int *)((intptr_t)local_c8 + value7) + *(int *)((intptr_t)local_f0 + value7);
        value7 = value7 + 4;
      } while (value7 < 0x1c);
      local_f4 = local_f8 + local_f4;
      value3 = value3 + 1;
    } while (value3 < 9);
    value3 = 5;
    ptr4 = local_c8;
    do {
      value3 = value3 + -1;
      *ptr4 = *ptr4 / 9;
      ptr4 = ptr4 + 1;
    } while (value3 != 0);
  }
  else {
    pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),DAT_0056951c,(int *)0x0);
    value3 = 0;
    do {
      ptr4 = local_f0;
      for (value7 = 7; value7 != 0; value7 = value7 + -1) {
        *ptr4 = 0;
        ptr4 = ptr4 + 1;
      }
      local_f0[0] = Stats_GetAverage8(pvVar1,value3);
      local_f0[1] = Branch_ComputeBuildingRating(pvVar1,extraout_EDX_00,value3);
      local_f0[2] = Branch_GetMenuRating(pvVar1,value3);
      self = (void *)Player_FindRecordType2ByKey(pvVar2,*(int *)((intptr_t)pvVar1 + 0x3c));
      if ((self == (void *)0x0) || (*(int *)((intptr_t)self + 4) == 0)) {
        value7 = 0;
      }
      else {
        value7 = value3;
        value6 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
        value7 = GamePlan_ComputeCategoryEffect(self,value6,value7);
        value7 = Math_PiecewiseLinear(value7);
      }
      local_f0[3] = local_f0[3] + value7;
      local_f0[4] = Branch_GetCustomerGroupRating(pvVar1,value3,1);
      local_f0[5] = Game_SumStatGrid2(pvVar1,value3,-1);
      local_f0[6] = Game_SumStatRow8(pvVar1,value3);
      fVar8 = Stats_SumFilteredFloats
                        ((intptr_t)pvVar1,value3,(uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4),
                         (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10));
      local_88[value3] = local_88[value3] + local_f0[5];
      local_ac[value3] = local_ac[value3] + local_f0[6];
      lvalue9 = __ftol();
      local_64[value3] = local_64[value3] + (intptr_t)lvalue9;
      StatisticsBranchBalance_DrawColumn(arg1,local_f0,(float)fVar8,value3,arg2);
      value7 = 0;
      do {
        *(int *)((intptr_t)local_c8 + value7) =
             *(int *)((intptr_t)local_c8 + value7) + *(int *)((intptr_t)local_f0 + value7);
        value7 = value7 + 4;
      } while (value7 < 0x1c);
      local_f4 = (float)fVar8 + local_f4;
      value3 = value3 + 1;
    } while (value3 < 9);
    value3 = 5;
    ptr4 = local_c8;
    do {
      value3 = value3 + -1;
      *ptr4 = *ptr4 / 9;
      ptr4 = ptr4 + 1;
    } while (value3 != 0);
  }
  StatisticsBranchBalance_DrawColumn(arg1,local_c8,local_f4,9,arg2);
  StatisticsBranchBalance_DrawProfitBars(arg1,local_88,local_ac,(intptr_t)local_64);
  return;
}
