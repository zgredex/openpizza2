// StatisticsBranchBalance_InitMetricSliders: ported from Pizza Connection 2 at 0x4ac800.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ac800
#include "pc2_port.h"

void __cdecl StatisticsBranchBalance_InitMetricSliders(void *arg1)

{
  int value1;
  void *self;
  void *pvVar2;
  int value3;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  int value4;
  int64_t lvalue5;
  int value6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
                    /* Averages branch metrics into the branch-balance sliders. */
  self = arg1;
  value6 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value4 = 0;
  value1 = *(int *)(value6 + 0x15c);
  if (value1 == 0) {
    Window_GadgetNotify_Text_SetText(arg1,0x861,DAT_00581328);
    UI_RemoveObjectByKey(arg1,0x4bd);
    Window_GadgetNotify_Slider_SetValue(arg1,0x4be,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x4bf,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x4c0,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x4c1,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x4c3,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x4c2,0,0);
    return;
  }
  if (DAT_0056951c == -1) {
    UI_ShowChildByID(arg1,0x4bd);
    Window_GadgetNotify_Text_SetText(arg1,0x861,DAT_00581004);
    local_c = 0;
    local_10 = 0;
    arg1 = (void *)0x0;
    local_14 = 0;
    local_8 = 0;
    if (0 < value1) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(value6 + 0x148),value4,(int *)0x0);
        value3 = City_GetProductPriceLevel(pvVar2);
        local_c = local_c + value3;
        value3 = Rating_GetInverse100((intptr_t)pvVar2);
        local_10 = local_10 + value3;
        lvalue5 = Stats_ComputeAverageGroupScoreThunk((intptr_t)pvVar2,extraout_EDX_00);
        arg1 = (void *)((intptr_t)arg1 + (intptr_t)lvalue5);
        value3 = Game_ComputeRecordMapPercent((intptr_t)pvVar2);
        local_14 = local_14 + value3;
        value3 = Game_AverageObjectField0C((intptr_t)pvVar2);
        local_8 = local_8 + value3;
        value4 = value4 + 1;
      } while (value4 < value1);
    }
    local_c = local_c / value1;
    local_10 = local_10 / value1;
    arg1 = (void *)((intptr_t)arg1 / value1);
    local_14 = local_14 / value1;
    local_8 = local_8 / value1;
  }
  else {
    pvVar2 = (void *)IDMap_Lookup((void *)(value6 + 0x148),DAT_0056951c,(int *)0x0);
    Window_GadgetNotify_Text_SetText(arg1,0x861,(intptr_t)pvVar2 + 4);
    local_c = City_GetProductPriceLevel(pvVar2);
    local_10 = Rating_GetInverse100((intptr_t)pvVar2);
    lvalue5 = Stats_ComputeAverageGroupScoreThunk((intptr_t)pvVar2,extraout_EDX);
    arg1 = (void *)lvalue5;
    local_14 = Game_ComputeRecordMapPercent((intptr_t)pvVar2);
    local_8 = Game_AverageObjectField0C((intptr_t)pvVar2);
  }
  if (local_c < 0x14) {
    Window_GadgetNotify_Slider_SetValue(self,0x4be,(local_c * 5 + -0x32) * 2,0);
    value6 = 0;
  }
  else {
    Window_GadgetNotify_Slider_SetValue(self,0x4be,0,0);
    value6 = (local_c * 5 + -100) * 2;
  }
  Window_GadgetNotify_Slider_SetValue(self,0x4bf,value6,0);
  Window_GadgetNotify_Slider_SetValue(self,0x4c0,local_10,0);
  Window_GadgetNotify_Slider_SetValue(self,0x4c1,arg1,0);
  Window_GadgetNotify_Slider_SetValue(self,0x4c3,local_14,0);
  Window_GadgetNotify_Slider_SetValue(self,0x4c2,local_8,0);
  return;
}
