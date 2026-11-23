// MenuPage_FillRecipeDetails: ported from Pizza Connection 2 at 0x4c07c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c07c0
#include "pc2_port.h"

void __cdecl MenuPage_FillRecipeDetails(void *arg1)

{
  void *self;
  void *pvVar1;
  int value2;
  void *pvVar3;
  int *ptr4;
  int value5;
  void *pvVar6;
  int64_t lvalue7;
  int local_8;
  int *local_4;
  
                    /* Fills the menu page's recipe details and ratings. */
  pvVar1 = arg1;
  value5 = 0;
  self = *(void **)((intptr_t)DAT_0057c670 + 0x9c);
  local_4 = (int *)0x0;
  value2 = *(int *)((intptr_t)self + 0x38);
  if (value2 == 0) {
    pvVar3 = (void *)0x21;
    pvVar6 = (void *)0x1e;
  }
  else if (value2 == 1) {
    pvVar3 = (void *)0x42;
    pvVar6 = (void *)0x3c;
  }
  else if (value2 == 2) {
    pvVar3 = (void *)0x64;
    pvVar6 = (void *)0x5f;
  }
  else {
    pvVar3 = arg1;
    pvVar6 = arg1;
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x511,pvVar3,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x443,pvVar6,0);
  value2 = Stats_GetAverageFlaggedValue((intptr_t)self);
  Window_GadgetNotify_Slider_SetValue(arg1,0x444,value2,0);
  pvVar3 = Player_FindRecordByCityId
                     (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200
                                ),(intptr_t)self);
  if (pvVar3 == (void *)0x0) {
    UI_RemoveObjectByKey(arg1,0x512);
    UI_RemoveObjectByKey(arg1,0x1f62);
    UI_RemoveObjectByKey(arg1,0x1f69);
    UI_RemoveObjectByKey(arg1,0x1f42);
    UI_RemoveObjectByKey(arg1,0x1f6b);
    Window_GadgetNotify_Text_SetText(arg1,0x519,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(arg1,0x1f6c,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(arg1,0x1f6a,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(arg1,0x1f61,DAT_00582e4c);
  }
  else {
    value2 = Get_Subobject4((intptr_t)pvVar3);
    Window_GadgetNotify_Text_SetText(arg1,0x519,value2);
    UI_ShowChildByID(arg1,0x1f42);
    UI_ShowChildByID(arg1,0x512);
    UI_ShowChildByID(arg1,0x1f6b);
    value2 = Storage_GetFillPercent((intptr_t)pvVar3);
    Gadget_SetTextf(arg1,0x1f6c,(uint8_t *)s__d____00568834,value2);
    value2 = *(int *)((intptr_t)pvVar3 + 0x30);
    if (value2 == -1) {
      UI_RemoveObjectByKey(arg1,0x1f62);
      Window_GadgetNotify_Text_SetText(arg1,0x1f6a,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(arg1,0x1f61,DAT_00582e4c);
      UI_RemoveObjectByKey(arg1,0x1f69);
    }
    else {
      pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                    *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
      local_4 = (int *)Array_GetStride60(pvVar3,value2);
      Window_GadgetNotify_Text_SetText(arg1,0x1f61,local_4 + 0x11);
      UI_ShowChildByID(arg1,0x1f62);
      UI_ShowChildByID(arg1,0x1f69);
      Gadget_SetTextf(arg1,0x1f6a,(uint8_t *)s__d____00568834,*local_4 / 10);
    }
  }
  arg1 = (void *)0x0;
  local_8 = 0;
  value2 = Game_CountObjectsByType(self,0xffffffff);
  if (0 < value2) {
    do {
      ptr4 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),value5,(int *)0x0);
      if (*(char *)(*ptr4 + 0x824) == '\x03') {
        value2 = Game_GetRecordByField814(*ptr4);
        if ((*(char *)(value2 + 0x80) == '\0') &&
           (arg1 = (void *)((intptr_t)arg1 + 1), *(char *)(*ptr4 + 0x825) == '\x02')) {
          local_8 = local_8 + 1;
        }
      }
      value5 = value5 + 1;
      value2 = Game_CountObjectsByType(self,0xffffffff);
    } while (value5 < value2);
  }
  Gadget_SetTextf(pvVar1,0x521,&DAT_005686f4,arg1);
  Gadget_SetTextf(pvVar1,0x522,&DAT_005686f4,local_8);
  lvalue7 = Stats_GetAverageSpend(self,3);
  Gadget_SetTextf(pvVar1,0x523,(uint8_t *)s__d____00568834,(intptr_t)lvalue7);
  value2 = Game_ComputeRecordMapPercent((intptr_t)self);
  Gadget_SetTextf(pvVar1,0x524,(uint8_t *)s__d____00568834,value2);
  value2 = 0;
  do {
    if (local_4 == (int *)0x0) {
      value5 = 0;
    }
    else {
      value5 = Game_GetRatingPercent(DAT_0057c670,value2,*local_4 / 10);
    }
    Rating_UpdateBarByKey(pvVar1,0x207c,value2,value5,DAT_00581048);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
