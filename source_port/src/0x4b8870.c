// OtherManagerPage_Update: ported from Pizza Connection 2 at 0x4b8870.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b8870
#include "pc2_port.h"

void __cdecl OtherManagerPage_Update(void *arg1)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  
                    /* Refreshes the other-manager page. */
  value1 = *(int *)((intptr_t)DAT_0057c670 + 0x9c);
  value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value1 + 0x30));
  Window_GadgetNotify_Slider_SetRange(arg1,0x441,0,100,0);
  if (*(int *)(value1 + 0x14c4) == 0) {
    uvalue3 = 0xffffffff;
  }
  else {
    uvalue3 = *(uint32_t *)(value1 + 0x14cc);
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x441,uvalue3,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x442,0,100,0);
  if (*(int *)(value1 + 0x14c4) == 0) {
    uvalue3 = 0xffffffff;
  }
  else {
    uvalue3 = *(uint32_t *)(value1 + 0x14c8);
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x442,uvalue3,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x443,-0x32,0x32,0);
  if (*(int *)(value1 + 0x14c4) == 0) {
    uvalue3 = 0;
  }
  else {
    uvalue3 = *(uint32_t *)(value1 + 0x14d0);
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x443,uvalue3,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x444,0,0x32,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x444,*(uint32_t *)(value1 + 0x14d4),0);
  Window_GadgetNotify_Slider_SetRange(arg1,3000,-0x32,0x32,0);
  if (*(int *)(value1 + 0x14c4) == 0) {
    uvalue3 = 0;
  }
  else {
    uvalue3 = *(uint32_t *)(value1 + 0x14c0);
  }
  Window_GadgetNotify_Slider_SetValue(arg1,3000,uvalue3,0);
  Window_GadgetNotify_Text_SetText(arg1,0x501,value2 + 8);
  Personnel_SetEmployeePhotoByKey(arg1,0x1f41,value2);
  CompanyProfile_UpdateRatingBars(arg1);
  return;
}
