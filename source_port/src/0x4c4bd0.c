// PolicePage_FillContributionStats: ported from Pizza Connection 2 at 0x4c4bd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c4bd0
#include "pc2_port.h"

void __cdecl PolicePage_FillContributionStats(void *arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int *ptr5;
  int64_t lvalue6;
  int local_c [3];
  
                    /* Fills police contribution, crime, station, and officer stats. */
  value3 = 0;
  local_c[0] = 0;
  local_c[1] = 0;
  local_c[2] = 0;
  value4 = 0;
  value1 = Game_GetPlayerSupplyScore(DAT_0057dcf4,*(int *)(DAT_0057dcf8 + 0x48));
  Window_GadgetNotify_Slider_SetValue(arg1,0x1fe5,value1,0);
  value1 = Game_ComputeRatingShare(DAT_0057dcf4,*(int *)(DAT_0057dcf8 + 0x48));
  Gadget_SetTextf(arg1,0x1fe9,(uint8_t *)s__d____00568834,value1);
  Gadget_SetTextf(arg1,0x1fb8,&DAT_005686f4,*(uint32_t *)((intptr_t)DAT_0057dcf4 + 0x10ac));
  Gadget_SetTextf(arg1,0x1fb9,&DAT_005686f4,*(uint32_t *)((intptr_t)DAT_0057dcf4 + 0x10b0));
  Gadget_SetTextf(arg1,0x1ff4,&DAT_005686f4,*(uint32_t *)((intptr_t)DAT_0057dcf4 + 0x10b4));
  Gadget_SetTextf(arg1,0x1ff5,&DAT_005686f4,*(uint32_t *)((intptr_t)DAT_0057dcf4 + 0x10b8));
  value1 = 0;
  do {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,value1);
    if (value2 != 0) {
      value4 = value4 + *(int *)((intptr_t)DAT_0057dcf4 + *(int *)(value2 + 0x48) * 4 + 0xcb0);
    }
    value1 = value1 + 1;
  } while (value1 < 6);
  Gadget_SetTextf(arg1,0x1fed,&DAT_005683a4,
                  *(uint32_t *)((intptr_t)DAT_0057dcf4 + *(int *)(DAT_0057dcf8 + 0x48) * 4 + 0xcb0));
  Gadget_SetTextf(arg1,0x1ff1,&DAT_005683a4,value4);
  ptr5 = &DAT_0056aeb8;
  value1 = *(int *)((intptr_t)DAT_0057dcf4 + 0x10c4);
  do {
    UI_RemoveObjectByKey(arg1,*ptr5);
    UI_RemoveObjectByKey(arg1,*ptr5 + -1);
    if (value3 < value1) {
      value4 = value4 + -1000;
      if (value4 < 0) {
        value2 = *ptr5;
      }
      else {
        value2 = *ptr5 + -1;
      }
      UI_ShowChildByID(arg1,value2);
    }
    ptr5 = ptr5 + 1;
    value3 = value3 + 1;
  } while ((intptr_t)ptr5 < 0x56aecc);
  value1 = Game_ComputeCompanyValue(DAT_0057dcf4,local_c,local_c + 1,local_c + 2);
  value3 = 0;
  ptr5 = &DAT_0056aecc;
  do {
    if (value3 < value1) {
      UI_ShowChildByID(arg1,*ptr5);
    }
    else {
      UI_RemoveObjectByKey(arg1,*ptr5);
    }
    ptr5 = ptr5 + 1;
    value3 = value3 + 1;
  } while ((intptr_t)ptr5 < 0x56aef4);
  lvalue6 = __ftol();
  Gadget_SetTextf(arg1,0x1fcf,(uint8_t *)s__d____00568834,(intptr_t)lvalue6);
  lvalue6 = __ftol();
  Gadget_SetTextf(arg1,0x1fd1,(uint8_t *)s__d____00568834,(intptr_t)lvalue6);
  lvalue6 = __ftol();
  Gadget_SetTextf(arg1,0x1fd0,(uint8_t *)s__d____00568834,(intptr_t)lvalue6);
  return;
}
