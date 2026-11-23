// StaffPage_FillEmployeeDetails: ported from Pizza Connection 2 at 0x4b8a20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b8a20
#include "pc2_port.h"

void __cdecl StaffPage_FillEmployeeDetails(void *arg1)

{
  void *self;
  void *this_00;
  int *ptr1;
  int value2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  uint8_t local_40 [64];
  
                    /* Fills the staff page's employee detail pane. */
  ptr1 = (int *)IDMap_Lookup((void *)(DAT_0057d6c4 + 0x1500),DAT_0057d6bc,(int *)0x0);
  value2 = Game_GetRecordField814Value(*ptr1);
  Window_GadgetNotify_Text_SetText(arg1,0x515,value2);
  String_Format(local_40,&DAT_005686f4,*(uint32_t *)(*ptr1 + 0x38));
  Window_GadgetNotify_Text_SetText(arg1,0x518,local_40);
  Window_GadgetNotify_Text_SetText
            (arg1,0x517,*(uint32_t *)(&DAT_005832a8 + (uint32_t)*(uint8_t *)(*ptr1 + 0x824) * 4));
  value2 = Rating_GetComposite(*ptr1);
  String_Format(local_40,&DAT_005686f4,value2);
  Window_GadgetNotify_Text_SetText(arg1,0x514,local_40);
  String_Format(local_40,&DAT_005683a4,*(uint32_t *)(*ptr1 + 0x3c));
  Window_GadgetNotify_Text_SetText(arg1,0x513,local_40);
  Window_GadgetNotify_Text_SetText
            (arg1,0x502,*(uint32_t *)(&DAT_005832d4 + (uint32_t)*(uint8_t *)(*ptr1 + 0x824) * 4));
  Window_GadgetNotify_Slider_SetRange(arg1,0x2329,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232b,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232d,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232f,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,9000,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232a,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232c,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232e,0,100,0);
  uvalue5 = 0;
  value2 = Rating_ClampAdjusted(*ptr1);
  Window_GadgetNotify_Slider_SetValue(arg1,0x2329,value2,uvalue5);
  uvalue5 = 0;
  value2 = Rating_AdjustA(*ptr1);
  Window_GadgetNotify_Slider_SetValue(arg1,0x232b,value2,uvalue5);
  Window_GadgetNotify_Slider_SetValue(arg1,0x232d,*(uint32_t *)(*ptr1 + 0xc),0);
  uvalue5 = 0;
  value2 = Rating_AdjustB(*ptr1);
  Window_GadgetNotify_Slider_SetValue(arg1,0x232f,value2,uvalue5);
  uvalue5 = 0;
  value2 = *(int *)(*ptr1 + 0x14);
  value3 = Rating_ClampAdjusted(*ptr1);
  Window_GadgetNotify_Slider_SetValue(arg1,9000,value3 + value2,uvalue5);
  uvalue5 = 0;
  value2 = *(int *)(*ptr1 + 0x18);
  value3 = Rating_AdjustA(*ptr1);
  Window_GadgetNotify_Slider_SetValue(arg1,0x232a,value3 + value2,uvalue5);
  Window_GadgetNotify_Slider_SetValue
            (arg1,0x232c,*(int *)(*ptr1 + 0x1c) + *(int *)(*ptr1 + 0xc),0);
  uvalue5 = 0;
  value2 = *(int *)(*ptr1 + 0x20);
  value3 = Rating_AdjustB(*ptr1);
  Window_GadgetNotify_Slider_SetValue(arg1,0x232e,value3 + value2,uvalue5);
  UI_ComposeOverlayWindowFromRecord(arg1,0x2332,*ptr1);
  uvalue4 = State_GetFlags(*ptr1);
  if ((char)uvalue4 == '\0') {
    UI_RemoveObjectByKey(arg1,0x50d);
    UI_RemoveObjectByKey(arg1,0x50e);
    UI_RemoveObjectByKey(arg1,0x50f);
  }
  else {
    UI_ShowChildByID(arg1,0x50d);
    UI_ShowChildByID(arg1,0x50e);
    UI_ShowChildByID(arg1,0x50f);
  }
  self = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  Gadget_SetTextf(arg1,0x2335,&DAT_005683a4,5000);
  this_00 = *(void **)((intptr_t)self + 0x1d8);
  if (this_00 == (void *)0x0) {
    value2 = 0;
    uvalue5 = 0xff;
  }
  else {
    value2 = Game_CountFreeBuildingsByType(this_00,0x1e);
    if (value2 == 0) {
      uvalue5 = 0xff;
    }
    else {
      uvalue5 = 0;
    }
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x233b,uvalue5);
  Gadget_SetTextf(arg1,0x233b,&DAT_005686f4,value2);
  value2 = *(int *)(DAT_0057d6c4 + 0x16f0);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value2 = Game_CountFilteredObjects(DAT_0057c670,0x1c,0x1e,value2,value3);
  Gadget_SetTextf(arg1,0x2337,&DAT_005686f4,value2);
  value2 = Game_CountPlayerObjectsByType(self,DAT_0057d6c4,0x1e,-1);
  Gadget_SetTextf(arg1,0x2339,&DAT_005686f4,value2);
  return;
}
