// JobMarketPanel_Update: ported from Pizza Connection 2 at 0x4b81e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b81e0
#include "pc2_port.h"

void __cdecl JobMarketPanel_Update(void *arg1)

{
  void *pvVar1;
  int value2;
  int value3;
  uint32_t extraout_EDX;
  int64_t lvalue4;
  uint32_t uvalue5;
  int value6;
  uint8_t local_20 [32];
  
                    /* Fills the job-market applicant counts and rating rows. */
  pvVar1 = *(void **)((intptr_t)DAT_0057c670 + 0x9c);
  value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar1 + 0x30));
  Window_GadgetNotify_Text_SetText(arg1,0x51b,value2 + 8);
  Window_GadgetNotify_Slider_SetRange(arg1,0x529,0,100,1);
  Personnel_SetEmployeePhotoByKey(arg1,0x1f42,value2);
  value2 = Game_CountFreeBuildingsByType(*(void **)((intptr_t)pvVar1 + 0x16f0),0x1a);
  String_Format(local_20,&DAT_005686f4,value2);
  Window_GadgetNotify_Text_SetText(arg1,0x524,local_20);
  value2 = Game_CountFreeBuildingsByType(*(void **)((intptr_t)pvVar1 + 0x16f0),0x1b);
  String_Format(local_20,&DAT_005686f4,value2);
  Window_GadgetNotify_Text_SetText(arg1,0x525,local_20);
  value2 = Game_CountFreeBuildingsByType(*(void **)((intptr_t)pvVar1 + 0x16f0),0x1c);
  String_Format(local_20,&DAT_005686f4,value2);
  Window_GadgetNotify_Text_SetText(arg1,0x526,local_20);
  if (*(int *)((intptr_t)pvVar1 + 0x14d8) < 0) {
    uvalue5 = DAT_00582afc;
  }
  else {
    uvalue5 = (&DAT_0058374c)[*(int *)((intptr_t)pvVar1 + 0x14d8)];
  }
  Window_GadgetNotify_Text_SetText(arg1,0x528,uvalue5);
  value2 = City_GetProductPriceLevel(pvVar1);
  if (value2 < 0x14) {
    Window_GadgetNotify_Slider_SetValue(arg1,0x529,(value2 * 5 + -0x32) * 2,0);
    value2 = 0;
  }
  else {
    Window_GadgetNotify_Slider_SetValue(arg1,0x529,0,0);
    value2 = (value2 * 5 + -100) * 2;
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x52a,value2,0);
  value2 = Rating_GetInverse100((intptr_t)pvVar1);
  Window_GadgetNotify_Slider_SetValue(arg1,0x52b,value2,0);
  lvalue4 = Stats_ComputeAverageGroupScoreThunk((intptr_t)pvVar1,extraout_EDX);
  Window_GadgetNotify_Slider_SetValue(arg1,0x52c,(intptr_t)lvalue4,0);
  value2 = 0;
  do {
    value6 = DAT_00582320;
    value3 = Branch_ComputeBuildingRating(pvVar1,DAT_00582320,value2);
    Rating_UpdateBarByKey(arg1,0x5be,value2,value3,value6);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
