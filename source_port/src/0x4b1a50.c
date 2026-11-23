// PersonnelPlan_UpdateEmployeeDetail: ported from Pizza Connection 2 at 0x4b1a50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b1a50
#include "pc2_port.h"

void __cdecl
PersonnelPlan_UpdateEmployeeDetail(void *arg1,int arg2,int arg3,char arg4,int arg5)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  uint8_t local_20 [32];
  
                    /* Fills the personnel-plan employee detail pane. */
  value1 = IDMap_Lookup((void *)(arg2 + 0x148),arg3,(int *)0x0);
  ptr2 = (int *)IDMap_Lookup((void *)(value1 + 0x1500),arg5,(int *)0x0);
  if (arg4 == '\0') {
    value3 = Game_GetRecordField814Value(*ptr2);
    Window_GadgetNotify_Text_SetText(arg1,0x52b,value3);
    String_Format(local_20,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x38));
    Window_GadgetNotify_Text_SetText(arg1,0x52e,local_20);
    Window_GadgetNotify_Text_SetText
              (arg1,0x52d,*(uint32_t *)(&DAT_005832a8 + (uint32_t)*(uint8_t *)(*ptr2 + 0x824) * 4));
    value3 = Rating_GetComposite(*ptr2);
    String_Format(local_20,&DAT_005686f4,value3);
    Window_GadgetNotify_Text_SetText(arg1,0x52a,local_20);
    String_Format(local_20,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x3c));
    Window_GadgetNotify_Text_SetText(arg1,0x529,local_20);
  }
  Window_GadgetNotify_Text_SetText
            (arg1,0x472,*(uint32_t *)(&DAT_005832d4 + (uint32_t)*(uint8_t *)(*ptr2 + 0x824) * 4));
  if (arg4 != '\0') {
    Window_GadgetNotify_Text_SetText
              (arg1,0x578,*(uint32_t *)(&DAT_005832d4 + (uint32_t)*(uint8_t *)(*ptr2 + 0x824) * 4));
  }
  if (*(char *)(*ptr2 + 0x824) == '\x03') {
    UI_RemoveObjectByKey(arg1,0x480);
    Window_GadgetNotify_Button_SetState(arg1,5000,(uint32_t)(*(char *)(*ptr2 + 0x825) == '\x01'));
    UI_ShowChildByID(arg1,5000);
    UI_ShowChildByID(arg1,0x1389);
  }
  else {
    UI_ShowChildByID(arg1,0x480);
    UI_RemoveObjectByKey(arg1,5000);
    UI_RemoveObjectByKey(arg1,0x1389);
  }
  uvalue6 = -(uint32_t)(arg4 != '\x01') & 0x1ed6;
  Window_GadgetNotify_Slider_SetRange(arg1,uvalue6 + 0x453,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,uvalue6 + 0x455,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,uvalue6 + 0x457,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,uvalue6 + 0x459,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,uvalue6 + 0x452,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,uvalue6 + 0x454,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,uvalue6 + 0x456,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,uvalue6 + 0x458,0,100,0);
  uvalue7 = 0;
  value3 = *ptr2;
  value4 = Rating_ClampAdjusted(value3);
  Window_GadgetNotify_Slider_SetValue(arg1,uvalue6 + 0x453,value4,uvalue7);
  uvalue7 = 0;
  value4 = Rating_AdjustA(value3);
  Window_GadgetNotify_Slider_SetValue(arg1,uvalue6 + 0x455,value4,uvalue7);
  Window_GadgetNotify_Slider_SetValue(arg1,uvalue6 + 0x457,*(uint32_t *)(value3 + 0xc),0);
  uvalue7 = 0;
  value4 = Rating_AdjustB(value3);
  Window_GadgetNotify_Slider_SetValue(arg1,uvalue6 + 0x459,value4,uvalue7);
  value4 = *(int *)(value3 + 0x14);
  uvalue7 = 0;
  value5 = Rating_ClampAdjusted(value3);
  Window_GadgetNotify_Slider_SetValue(arg1,uvalue6 + 0x452,value5 + value4,uvalue7);
  value4 = *(int *)(value3 + 0x18);
  uvalue7 = 0;
  value5 = Rating_AdjustA(value3);
  Window_GadgetNotify_Slider_SetValue(arg1,uvalue6 + 0x454,value5 + value4,uvalue7);
  Window_GadgetNotify_Slider_SetValue
            (arg1,uvalue6 + 0x456,*(int *)(value3 + 0x1c) + *(int *)(value3 + 0xc),0);
  value4 = *(int *)(value3 + 0x20);
  uvalue7 = 0;
  value5 = Rating_AdjustB(value3);
  Window_GadgetNotify_Slider_SetValue(arg1,uvalue6 + 0x458,value5 + value4,uvalue7);
  if (arg4 == '\0') {
    UI_ComposeOverlayWindowFromRecord(arg1,0x2332,value3);
    value3 = 0x2332;
  }
  else {
    UI_ComposeOverlayWindowFromRecord(arg1,0x1f53,value3);
    value3 = 0x1f53;
  }
  Array_SetField14ByKey(arg1,value3,1);
  uvalue6 = State_GetFlags(*ptr2);
  if ((char)uvalue6 == '\0') {
    UI_RemoveObjectByKey(arg1,0x480);
    UI_RemoveObjectByKey(arg1,0x483);
    UI_RemoveObjectByKey(arg1,0x485);
  }
  else {
    if (*(char *)(*ptr2 + 0x824) != '\x03') {
      UI_ShowChildByID(arg1,0x480);
    }
    UI_ShowChildByID(arg1,0x483);
    UI_ShowChildByID(arg1,0x485);
  }
  value3 = *(int *)(arg2 + 0x48);
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(value1 + 0x34),(int *)0x0);
  if (*(int *)(value1 + 0xc20 + value3 * 4) < 2) {
    UI_RemoveObjectByKey(arg1,0x480);
    UI_RemoveObjectByKey(arg1,0x483);
    UI_RemoveObjectByKey(arg1,0x484);
    UI_RemoveObjectByKey(arg1,0x485);
  }
  return;
}
