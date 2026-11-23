// OvenPage_FillStatistics: ported from Pizza Connection 2 at 0x4c3310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c3310
#include "pc2_port.h"

void __cdecl OvenPage_FillStatistics(void *arg1)

{
  void *self;
  void *this_00;
  int value1;
  int value2;
  void *this_01;
  int *ptr3;
  uint32_t uvalue4;
  int value5;
  uint32_t extraout_EDX;
  uint32_t uvalue6;
  uint32_t extraout_EDX_00;
  int64_t lvalue7;
  int local_18;
  int local_14;
  int local_c;
  int local_4;
  
                    /* Fills the oven/interior statistics page. */
  this_00 = arg1;
  self = *(void **)((intptr_t)DAT_0057c670 + 0x9c);
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
  value1 = Game_GetPlayerCity(value1);
  local_c = 0;
  lvalue7 = Stats_GetAverageSpend(self,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x5ce,(intptr_t)lvalue7,0);
  value2 = Rating_GetInverse100((intptr_t)self);
  Window_GadgetNotify_Slider_SetValue(arg1,0x5cf,value2,0);
  value2 = Game_CountPlayersByByte(self,5);
  Gadget_SetTextf(arg1,0x5d2,(uint8_t *)s__d__s_00568324,value2);
  local_18 = 0;
  local_14 = 0;
  DAT_0057d73c = Branch_CollectOrdersByCategory(self,5);
  arg1 = (void *)0x0;
  if ((intptr_t)DAT_0057d73c[5] < 1) {
    this_01 = (void *)0x0;
  }
  else {
    do {
      this_01 = (void *)IDMap_Lookup(DAT_0057d73c,(intptr_t)arg1,(int *)0x0);
      if (this_01 != (void *)0x0) {
        value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x74),*(int *)((intptr_t)this_01 + 4),
                             (int *)0x0);
        value2 = Product_ComputeFreshness(value2);
        value2 = ((0xf - value2) * 10) / 3 + 100;
        if (value2 < 0) {
          value2 = 0;
        }
        local_18 = local_18 + value2;
        value2 = Game_ComputeEventValue(this_01,value1,(int *)0x0);
        local_14 = local_14 + value2;
        local_c = local_c + *(int *)((intptr_t)this_01 + 0xc);
      }
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < (intptr_t)DAT_0057d73c[5]);
  }
  if (DAT_0057d73c[5] == 0) {
    local_18 = 0;
    local_c = 0;
  }
  else {
    local_c = local_c / (intptr_t)DAT_0057d73c[5];
  }
  Gadget_SetTextf(this_00,0x58b,&DAT_005686f4,local_18);
  local_18 = 0;
  value2 = Game_CountObjectsByType(self,0xffffffff);
  arg1 = (void *)0x0;
  if (0 < value2) {
    do {
      ptr3 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),(intptr_t)arg1,(int *)0x0);
      if (*(char *)(*ptr3 + 0x824) == '\0') {
        uvalue4 = Game_GetTimeSegment((intptr_t)DAT_0057c670);
        value5 = AI_IsDirectionOnRoute(self,(int *)*ptr3,uvalue4);
        if (value5 != 0) {
          value5 = Rating_GetComposite(*ptr3);
          local_18 = local_18 + value5;
        }
      }
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < value2);
  }
  Gadget_SetTextf(this_00,0x58d,&DAT_005686f4,local_18);
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x74),*(int *)((intptr_t)DAT_0057d734 + 4),(int *)0x0
                      );
  value5 = Game_GetPlayerCity(*(int *)((intptr_t)DAT_0057c670 +
                                     *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  Game_ComputePrice(value2,value5);
  lvalue7 = __ftol();
  Gadget_SetTextf(this_00,0x58f,&DAT_005683a4,(intptr_t)lvalue7);
  value1 = Game_ComputeEventValue(DAT_0057d734,value1,&local_4);
  Gadget_SetTextf(this_00,0x591,&DAT_005683a4,local_4);
  Gadget_SetTextf(this_00,0x595,&DAT_005683a4,value1);
  Gadget_SetTextf(this_00,0x5ca,&DAT_005683a4,local_14);
  Window_GadgetNotify_Slider_SetValue(this_00,0x5c6,local_c,0);
  Window_GadgetNotify_Slider_SetValue(this_00,0x586,*(uint32_t *)((intptr_t)this_01 + 0xc),0);
  value1 = 0;
  uvalue6 = extraout_EDX;
  do {
    value2 = Branch_ComputeBuildingRating(self,uvalue6,value1);
    Rating_UpdateBarByKey(this_00,0x559,value1,value2,DAT_00582320);
    value1 = value1 + 1;
    uvalue6 = extraout_EDX_00;
  } while (value1 < 8);
  return;
}
