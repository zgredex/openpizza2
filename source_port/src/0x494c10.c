// PersonnelPage_UpdateEmployee: ported from Pizza Connection 2 at 0x494c10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x494c10
#include "pc2_port.h"

void __cdecl PersonnelPage_UpdateEmployee(void *arg1)

{
  void *pvVar1;
  int value2;
  int value3;
  uint8_t *uptr4;
  int *ptr5;
  int64_t lvalue6;
  uint32_t uvalue7;
  int local_28;
  int local_24;
  int local_20 [8];
  
                    /* Fills the personnel page for the selected employee. */
  value2 = Game_GetPlayerFieldC20
                    (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  if (value2 < 2) {
    UI_RemoveObjectByKey(arg1,0x1fa8);
  }
  if (3 < DAT_0057c6d8) {
    CompanyProfileWindow_InitCategoryLayout(arg1);
    pvVar1 = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value3 = Game_GetPlayerCity((intptr_t)pvVar1);
    value2 = *(int *)(value3 + 0x68);
    value3 = *(int *)(value3 + 0x50);
    if (*(void **)((intptr_t)pvVar1 + 0x1d8) == (void *)0x0) {
      local_28 = 0;
      uvalue7 = 0xff;
    }
    else {
      local_28 = Game_CountFreeBuildingsByType(*(void **)((intptr_t)pvVar1 + 0x1d8),0x17);
      if (local_28 == 0) {
        uvalue7 = 0xff;
      }
      else {
        uvalue7 = 0;
      }
    }
    Window_GadgetNotify_Text_SetTextColor(arg1,0x1f64,uvalue7);
    Gadget_SetTextf(arg1,0x1f64,&DAT_005686f4,local_28);
    local_28 = Game_CountFreeSlots(DAT_0057c670,0x17);
    if (local_28 == 0) {
      uvalue7 = 0xff;
    }
    else {
      uvalue7 = 0;
    }
    Window_GadgetNotify_Text_SetTextColor(arg1,0x1f6a,uvalue7);
    Gadget_SetTextf(arg1,0x1f6a,&DAT_005686f4,local_28);
    local_28 = *(int *)((intptr_t)pvVar1 + 100);
    Gadget_SetTextf(arg1,0x1f6c,&DAT_005686f4,local_28);
    uptr4 = Economy_GetModifier(pvVar1,0x17,0);
    Gadget_SetTextf(arg1,0x1f6e,&DAT_005686f4,uptr4);
    uptr4 = Economy_GetModifier(pvVar1,0x17,1);
    Gadget_SetTextf(arg1,0x1f70,&DAT_005686f4,uptr4);
    uptr4 = Economy_GetModifier(pvVar1,0x17,2);
    Gadget_SetTextf(arg1,0x1f72,&DAT_005686f4,uptr4);
    Window_GadgetNotify_Text_SetText(arg1,0x5c6,DAT_00582930);
    Gadget_SetTextf(arg1,0x5c2,&DAT_005683a4,(((value2 + value3) * -0x1e + 100) * 500) / 100);
    Window_GadgetNotify_Text_SetText(arg1,0x5c4,DAT_0057c6f4 + 4);
    value2 = 0;
    do {
      Rating_UpdateBarByKey(arg1,0x5af,value2,0,0);
      value2 = value2 + 1;
    } while (value2 < 8);
    return;
  }
  if ((void *)(&DAT_0057c6e0)[DAT_0057c6d8] != (void *)0x0) {
    DAT_0057c6f0 = (int *)IDMap_Lookup((void *)(&DAT_0057c6e0)[DAT_0057c6d8],DAT_0057c6dc,(int *)0x0
                                      );
  }
  if (DAT_0057c6f0 == (int *)0x0) {
    DAT_0057c6dc = 0;
    DAT_0057c6f0 = (int *)IDMap_Lookup((void *)(&DAT_0057c6e0)[DAT_0057c6d8],0,(int *)0x0);
    if (DAT_0057c6f0 == (int *)0x0) {
      return;
    }
  }
  CompanyProfileWindow_InitCategoryLayout(arg1);
  value2 = 0x1f53;
  do {
    UI_RemoveObjectByKey(arg1,value2);
    value2 = value2 + 1;
  } while (value2 < 0x1f57);
  value2 = 0x1f5b;
  do {
    UI_RemoveObjectByKey(arg1,value2);
    value2 = value2 + 1;
  } while (value2 < 0x1f63);
  value3 = (uint32_t)*(uint8_t *)(*DAT_0057c6f0 + 0x824) * 4;
  value2 = *(int *)(&DAT_00568770 + value3);
  value3 = *(int *)(&DAT_00568780 + value3);
  UI_ShowChildByID(arg1,value2);
  Window_GadgetNotify_Slider_SetRange(arg1,value2,0,7,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,value2,1);
  Window_GadgetNotify_Slider_SetValue(arg1,value2,DAT_00568790,0);
  UI_ShowChildByID(arg1,value3);
  UI_ShowChildByID(arg1,value3 + 1);
  Array_GetPairByKey(arg1,0x1f48,&local_28,&local_24);
  local_28 = local_28 + 2 + DAT_00568790 * 0x14;
  if (DAT_00568790 < 1) {
    value2 = local_28 + 0x8c;
  }
  else {
    value2 = local_28 + -0x14;
  }
  UI_SetObjectRangeByKey(arg1,value3,value2,local_24);
  if (DAT_00568790 < 7) {
    value2 = local_28 + 0x14;
  }
  else {
    value2 = local_28 + -0x8c;
  }
  UI_SetObjectRangeByKey(arg1,value3 + 1,value2,local_24);
  pvVar1 = *(void **)((intptr_t)DAT_0057c670 + 0x9c);
  value2 = Game_GetRecordField814Value(*DAT_0057c6f0);
  Window_GadgetNotify_Text_SetText(arg1,0x5c4,value2);
  Gadget_SetTextf(arg1,0x5c7,&DAT_005686f4,*(uint32_t *)(*DAT_0057c6f0 + 0x38));
  Window_GadgetNotify_Text_SetText
            (arg1,0x5c6,
             *(uint32_t *)(&DAT_005832a8 + (uint32_t)*(uint8_t *)(*DAT_0057c6f0 + 0x824) * 4));
  value2 = Rating_GetComposite(*DAT_0057c6f0);
  Gadget_SetTextf(arg1,0x5c3,&DAT_005686f4,value2);
  Game_GetPlayerCity(*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  lvalue6 = Rating_GetCompositeTruncated(*DAT_0057c6f0);
  Gadget_SetTextf(arg1,0x5c2,&DAT_005683a4,(intptr_t)lvalue6);
  Window_GadgetNotify_Text_SetText
            (arg1,0x48a,
             *(uint32_t *)(&DAT_005832d4 + (uint32_t)*(uint8_t *)(*DAT_0057c6f0 + 0x824) * 4));
  Window_GadgetNotify_Slider_SetRange(arg1,0x466,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x468,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x465,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x469,0,100,0);
  uvalue7 = 0;
  value2 = Rating_ClampAdjusted(*DAT_0057c6f0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x466,value2,uvalue7);
  uvalue7 = 0;
  value2 = Rating_AdjustA(*DAT_0057c6f0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x468,value2,uvalue7);
  Window_GadgetNotify_Slider_SetValue(arg1,0x469,*(uint32_t *)(*DAT_0057c6f0 + 0xc),0);
  uvalue7 = 0;
  value2 = Rating_AdjustB(*DAT_0057c6f0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x465,value2,uvalue7);
  UI_ComposeOverlayWindowFromRecord(arg1,0x1f43,*DAT_0057c6f0);
  Rating_ComputeEightCategories((int *)*DAT_0057c6f0,local_20);
  value2 = 0;
  ptr5 = local_20;
  do {
    Rating_UpdateBarByKey(arg1,0x5af,value2,*ptr5,DAT_00582f94);
    value2 = value2 + 1;
    ptr5 = ptr5 + 1;
  } while (value2 < 8);
  value2 = Game_CountObjectsByType(pvVar1,0);
  Gadget_SetTextf(arg1,0x5c9,&DAT_005686f4,value2);
  value2 = Game_CountObjectsByType(pvVar1,2);
  Gadget_SetTextf(arg1,0x5ca,&DAT_005686f4,value2);
  value2 = Game_CountObjectsByType(pvVar1,3);
  Gadget_SetTextf(arg1,0x5cb,&DAT_005686f4,value2);
  value2 = Game_CountObjectsByType(pvVar1,1);
  Gadget_SetTextf(arg1,0x5cc,&DAT_005686f4,value2);
  return;
}
