// RankingPanel_UpdatePlayerSummary: ported from Pizza Connection 2 at 0x4aa340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aa340
#include "pc2_port.h"

void __cdecl RankingPanel_UpdatePlayerSummary(void *arg1)

{
  void *self;
  int value1;
  uint32_t *uptr2;
  int value3;
  char *cptr4;
  int value5;
  uint32_t uvalue6;
  
                    /* Updates the player's ranking summary and top rows. */
  Sound_PlaySfxByIndex(DAT_0057ba0c,0x19,0);
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                              (int *)0x0);
  value3 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                  0x48);
  value1 = *(int *)((intptr_t)self + value3 * 4 + 0xd40);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1fa8,value1,0);
  value1 = (100 - value1) / 3;
  if (value1 == 0) {
    Window_GadgetNotify_Text_SetText(arg1,0x1fb0,&DAT_00569308);
  }
  else {
    Gadget_SetTextf(arg1,0x1fb0,(uint8_t *)s___d____00569300,value1);
  }
  value1 = Stats_GetPlayerSharePercent(self,value3);
  Gadget_SetTextf(arg1,0x1fac,(uint8_t *)s__d____00568834,value1);
  Gadget_SetTextf(arg1,0x1fd3,&DAT_005683a4,*(uint32_t *)((intptr_t)self + value3 * 4 + 0xdac));
  value1 = Game_GetMostAdvancedCompany((intptr_t)self);
  value1 = Game_GetPlayerBySlot(DAT_0057c670,value1);
  if (value1 == 0) {
    value5 = DAT_00582adc;
  }
  else {
    value5 = value1 + 8;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x1fc9,value5);
  Personnel_SetEmployeePhotoByKey(arg1,0x1fd4,value1);
  value3 = *(int *)((intptr_t)self + value3 * 4 + 0xcc8);
  value1 = 0x3c - value3;
  if (value1 / 2 < 0) {
    cptr4 = s__d____00568834;
  }
  else {
    cptr4 = s___d____005692f8;
  }
  Gadget_SetTextf(arg1,0x1fc5,(uint8_t *)cptr4,value1 / 2);
  Gadget_SetTextf(arg1,0x1fc7,&DAT_005686f4,((intptr_t)(value1 + (value1 >> 0x1f & 7U)) >> 3) + 0x4b);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1fc3,value3,0);
  value3 = 0;
  uptr2 = (uint32_t *)((intptr_t)self + 0xd8c);
  do {
    Gadget_SetTextf(arg1,DAT_005692ec + value3,&DAT_005686f4,uptr2[-1]);
    Gadget_SetTextf(arg1,DAT_005692f0 + value3 * 2,&DAT_005686f4,*uptr2);
    value1 = uptr2[1];
    if (value1 < 1) {
      uvalue6 = 0;
    }
    else {
      uvalue6 = 0xff;
    }
    Window_GadgetNotify_Text_SetTextColor(arg1,DAT_005692f4 + value3,uvalue6);
    Gadget_SetTextf(arg1,DAT_005692f4 + value3,&DAT_005686f4,value1);
    value3 = value3 + 1;
    uptr2 = uptr2 + 3;
  } while (value3 < 3);
  return;
}
