// PersonInfoPanel_Update: ported from Pizza Connection 2 at 0x4bc530.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bc530
#include "pc2_port.h"

void __cdecl PersonInfoPanel_Update(void *arg1,char arg2)

{
  uint8_t flag1;
  int value2;
  uint32_t extraout_var;
  int value3;
  int value4;
  void *self;
  uint32_t uvalue5;
  uint32_t uvalue6;
  
                    /* Fills the selected person's info card and rating rows. */
  value3 = *(int *)((intptr_t)DAT_0057c670 + 0x21c);
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x20),*(int *)(value3 + 0x50),(int *)0x0);
  if (arg2 != '\0') {
    flag1 = Game_GetObjectStatusLevel(value3);
    Sound_ProcessEvent(DAT_0057ba0c,*(int *)(value3 + 0x30),CONCAT31(extraout_var,flag1),
                       *(int *)(value3 + 0x24) == 0);
  }
  Window_GadgetNotify_Text_SetText(arg1,0x515,value3 + 4);
  Gadget_SetTextf(arg1,0x518,&DAT_005686f4,*(uint32_t *)(value2 + 0x38));
  Window_GadgetNotify_Text_SetText
            (arg1,0x517,*(uint32_t *)(&DAT_005832a8 + (uint32_t)*(uint8_t *)(value2 + 0x824) * 4));
  value3 = Rating_GetComposite(value2);
  Gadget_SetTextf(arg1,0x514,&DAT_005686f4,value3);
  Gadget_SetTextf(arg1,0x513,&DAT_005683a4,*(uint32_t *)(value2 + 0x3c));
  Window_GadgetNotify_Text_SetText
            (arg1,0x502,*(uint32_t *)(&DAT_005832d4 + (uint32_t)*(uint8_t *)(value2 + 0x824) * 4));
  Window_GadgetNotify_Slider_SetRange(arg1,0x2329,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232b,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232d,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232f,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,9000,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232a,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232c,0,100,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x232e,0,100,0);
  uvalue6 = 0;
  value3 = Rating_ClampAdjusted(value2);
  Window_GadgetNotify_Slider_SetValue(arg1,0x2329,value3,uvalue6);
  uvalue6 = 0;
  value3 = Rating_AdjustA(value2);
  Window_GadgetNotify_Slider_SetValue(arg1,0x232b,value3,uvalue6);
  Window_GadgetNotify_Slider_SetValue(arg1,0x232d,*(uint32_t *)(value2 + 0xc),0);
  uvalue6 = 0;
  value3 = Rating_AdjustB(value2);
  Window_GadgetNotify_Slider_SetValue(arg1,0x232f,value3,uvalue6);
  value3 = *(int *)(value2 + 0x14);
  uvalue6 = 0;
  value4 = Rating_ClampAdjusted(value2);
  Window_GadgetNotify_Slider_SetValue(arg1,9000,value4 + value3,uvalue6);
  value3 = *(int *)(value2 + 0x18);
  uvalue6 = 0;
  value4 = Rating_AdjustA(value2);
  Window_GadgetNotify_Slider_SetValue(arg1,0x232a,value4 + value3,uvalue6);
  Window_GadgetNotify_Slider_SetValue
            (arg1,0x232c,*(int *)(value2 + 0x1c) + *(int *)(value2 + 0xc),0);
  value3 = *(int *)(value2 + 0x20);
  uvalue6 = 0;
  value4 = Rating_AdjustB(value2);
  Window_GadgetNotify_Slider_SetValue(arg1,0x232e,value4 + value3,uvalue6);
  self = (void *)Game_GetPlayerSubmapValue
                           (DAT_0057c670,*(int *)(value2 + 0x81c),*(int *)(value2 + 0x820));
  Window_GadgetNotify_Text_SetText(arg1,0x1f41,(intptr_t)self + 4);
  value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value2 + 0x81c));
  Window_GadgetNotify_Text_SetText(arg1,0x51b,value3 + 8);
  Personnel_SetEmployeePhotoByKey(arg1,0x2334,value3);
  UI_ComposeOverlayWindowFromRecord(arg1,0x2333,value2);
  uvalue5 = State_GetFlags(value2);
  if ((char)uvalue5 == '\0') {
    UI_RemoveObjectByKey(arg1,0x50d);
    UI_RemoveObjectByKey(arg1,0x50e);
    UI_RemoveObjectByKey(arg1,0x50f);
    UI_RemoveObjectByKey(arg1,0x510);
  }
  else {
    UI_ShowChildByID(arg1,0x50d);
    UI_ShowChildByID(arg1,0x50e);
    UI_ShowChildByID(arg1,0x50f);
    UI_ShowChildByID(arg1,0x510);
  }
  value3 = 0;
  do {
    value2 = DAT_005826d8;
    value4 = Stats_GetAverage8(self,value3);
    Rating_UpdateBarByKey(arg1,0x5a7,value3,value4,value2);
    value3 = value3 + 1;
  } while (value3 < 8);
  return;
}
