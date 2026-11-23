// StockPage_FillStorageDetails: ported from Pizza Connection 2 at 0x4be1a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4be1a0
#include "pc2_port.h"

void __cdecl StockPage_FillStorageDetails(void *arg1)

{
  void *self;
  int value1;
  int value2;
  void *pvVar3;
  int *ptr4;
  uint32_t uvalue5;
  int value6;
  double fVar7;
  int64_t lvalue8;
  uint32_t uvalue9;
  uint32_t uvalue10;
  float local_4;
  
                    /* Fills the other-stock storage detail page. */
  local_4 = 0.0;
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                              (int *)0x0);
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(DAT_0057d700 + 0x24));
  value6 = 0;
  do {
    value2 = Array_GetStride60(self,value6);
    fVar7 = BuildingValue_Compute(value1,self,value2);
    if ((double)local_4 < fVar7) {
      local_4 = (float)fVar7;
    }
    value6 = value6 + 1;
  } while (value6 < 5);
  value6 = Storage_GetFillPercent(DAT_0057d700);
  Window_GadgetNotify_Slider_SetValue(arg1,0x443,value6,0);
  value6 = Get_Field2C(DAT_0057d700);
  if (value6 == 0) {
    pvVar3 = (void *)0x1e;
  }
  else if (value6 == 1) {
    pvVar3 = (void *)0x3c;
  }
  else if (value6 == 2) {
    pvVar3 = (void *)0x5f;
  }
  else {
    pvVar3 = arg1;
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x444,pvVar3,0);
  value6 = Array_CountNonZero20(DAT_0057d700);
  Gadget_SetTextf(arg1,0x50d,&DAT_005686f4,value6);
  ptr4 = (int *)Array_GetStride60(self,*(int *)(DAT_0057d700 + 0x30));
  BuildingValue_Compute(value1,self,(intptr_t)ptr4);
  if (ptr4 == (int *)0x0) {
    Window_GadgetNotify_Text_SetText(arg1,0x50e,DAT_00581a2c);
    Window_GadgetNotify_Slider_SetValue(arg1,0x441,0,0);
    uvalue9 = 0;
    uvalue10 = 0;
  }
  else {
    Window_GadgetNotify_Text_SetText(arg1,0x50e,ptr4 + 0x11);
    Window_GadgetNotify_Slider_SetValue(arg1,0x441,*ptr4 / 10,0);
    uvalue9 = 0;
    lvalue8 = __ftol();
    uvalue10 = (uint32_t)lvalue8;
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x442,uvalue10,uvalue9);
  value1 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  value6 = Game_GetPlayerFieldC20(value1);
  uvalue5 = (uint32_t)(5 < value6);
  UI_SetChildVisibleByID(arg1,0x1f5d,uvalue5);
  UI_SetChildVisibleByID(arg1,0x1f5e,uvalue5);
  UI_SetChildVisibleByID(arg1,0x1f4c,uvalue5);
  UI_SetChildVisibleByID(arg1,0x1f4b,uvalue5);
  UI_SetChildVisibleByID(arg1,0x1f44,uvalue5);
  UI_SetChildVisibleByID(arg1,0x1f54,uvalue5);
  UI_SetChildVisibleByID(arg1,0x1f58,uvalue5);
  UI_SetChildVisibleByID(arg1,0x1f59,uvalue5);
  UI_SetChildVisibleByID(arg1,0x1f5b,uvalue5);
  UI_SetChildVisibleByID(arg1,0x1f55,uvalue5);
  UI_SetChildVisibleByID(arg1,0x1f5f,uvalue5);
  if (5 < value6) {
    value1 = Game_CountFreeBuildingsByType(*(void **)(value1 + 0x1d8),0x1f);
    if (value1 == 0) {
      uvalue10 = 0xff;
    }
    else {
      uvalue10 = 0;
    }
    Window_GadgetNotify_Text_SetTextColor(arg1,0x1f4b,uvalue10);
    Gadget_SetTextf(arg1,0x1f4b,&DAT_005686f4,value1);
    value1 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
    value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    value6 = Game_CountFilteredObjects2(DAT_0057c670,0x1d,0x1f,value1,value6);
    Gadget_SetTextf(arg1,0x1f55,&DAT_005686f4,value6);
    value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    value1 = Game_CountFilteredObjects(DAT_0057c670,0x1d,0x1f,value1,value6);
    Gadget_SetTextf(arg1,0x1f5b,&DAT_005686f4,value1);
  }
  return;
}
