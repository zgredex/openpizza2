// PersonnelPanel_Update: ported from Pizza Connection 2 at 0x4b8da0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b8da0
#include "pc2_port.h"

void __cdecl PersonnelPanel_Update(void *arg1)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  int value4;
  
                    /* Updates the city personnel panel and selected person card. */
  DAT_0057d6c4 = *(void **)((intptr_t)DAT_0057c670 + 0x9c);
  DAT_0057d6c0 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)DAT_0057d6c4 + 0x30));
  value2 = Game_CountObjectsByType(DAT_0057d6c4,0xffffffff);
  Window_GadgetNotify_Text_SetText(arg1,0x51b,DAT_0057d6c0 + 8);
  Personnel_SetEmployeePhotoByKey(arg1,0x2333,DAT_0057d6c0);
  uvalue1 = (uint32_t)(value2 != 0);
  UI_SetChildVisibleByID(arg1,0x50a,uvalue1);
  UI_SetChildVisibleByID(arg1,0x50b,uvalue1);
  UI_SetChildVisibleByID(arg1,0x516,uvalue1);
  UI_SetChildVisibleByID(arg1,0x518,uvalue1);
  UI_SetChildVisibleByID(arg1,0x517,uvalue1);
  UI_SetChildVisibleByID(arg1,0x511,uvalue1);
  UI_SetChildVisibleByID(arg1,0x514,uvalue1);
  UI_SetChildVisibleByID(arg1,0x512,uvalue1);
  UI_SetChildVisibleByID(arg1,0x513,uvalue1);
  UI_SetChildVisibleByID(arg1,0x50c,uvalue1);
  UI_SetChildVisibleByID(arg1,0x2332,uvalue1);
  if (value2 == 0) {
    Window_GadgetNotify_Text_SetText(arg1,0x515,DAT_00582680);
    Window_GadgetNotify_Text_SetText(arg1,0x502,DAT_00581b30);
    DAT_0057d6bc = 0xffffffff;
    Window_GadgetNotify_Slider_SetRange(arg1,0x2329,0,100,0);
    Window_GadgetNotify_Slider_SetRange(arg1,0x232b,0,100,0);
    Window_GadgetNotify_Slider_SetRange(arg1,0x232d,0,100,0);
    Window_GadgetNotify_Slider_SetRange(arg1,0x232f,0,100,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x2329,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x232b,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x232d,0,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x232f,0,0);
    value2 = 0;
    do {
      Rating_UpdateBarByKey(arg1,0x5a7,value2,0,0);
      value2 = value2 + 1;
    } while (value2 < 8);
    return;
  }
  if (DAT_0057d6bc != -1) {
    value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057d6c4 + 0x1500),DAT_0057d6bc,(int *)0x0);
    if (value2 != 0) goto LAB_004b8f9b;
  }
  DAT_0057d6bc = 0;
LAB_004b8f9b:
  StaffPage_FillEmployeeDetails(arg1);
  value2 = 0;
  do {
    value4 = DAT_005826d8;
    value3 = Stats_GetAverage8(DAT_0057d6c4,value2);
    Rating_UpdateBarByKey(arg1,0x5a7,value2,value3,value4);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
