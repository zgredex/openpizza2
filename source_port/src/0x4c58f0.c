// BranchWindow_InitCompetitorRows: ported from Pizza Connection 2 at 0x4c58f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c58f0
#include "pc2_port.h"

void __cdecl BranchWindow_InitCompetitorRows(void *arg1)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  int value4;
  int *ptr5;
  
                    /* Fills the branch window's competitor comparison sliders. */
  if (DAT_0057dcfc != 0) {
    if (*(int *)(DAT_0057dcfc + 0x4c) == 0) {
      uvalue1 = *(uint32_t *)(DAT_0057dcfc + 0x44);
    }
    else {
      uvalue1 = 0;
    }
    Window_GadgetNotify_Slider_SetValue(arg1,0x4cd,uvalue1,0);
    value4 = 0;
    value3 = 0x4c1;
    do {
      value2 = Game_GetPlayerBySlot(DAT_0057c670,value4);
      if (value2 != 0) {
        Gadget_SetTextf(arg1,(&DAT_0056afb8)[value4],&DAT_005686f4,
                        *(uint32_t *)(DAT_0057dcfc + 0x14c + *(int *)(value2 + 0x48) * 4));
        Gadget_SetTextf(arg1,(&DAT_0056afd0)[value4],&DAT_005686f4,
                        *(uint32_t *)(DAT_0057dcfc + 0xac + *(int *)(value2 + 0x48) * 4));
        value2 = *(int *)(DAT_0057dcfc + 0x5c + *(int *)(value2 + 0x48) * 4);
        if (value2 < 0) {
          Window_GadgetNotify_Slider_SetValue(arg1,value3 + -1,-value2,0);
          value2 = 0;
        }
        else {
          Window_GadgetNotify_Slider_SetValue(arg1,value3 + -1,0,0);
        }
        Window_GadgetNotify_Slider_SetValue(arg1,value3,value2,0);
      }
      value3 = value3 + 2;
      value4 = value4 + 1;
    } while (value3 < 0x4cd);
    value3 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    value4 = 0x439;
    do {
      UI_RemoveObjectByKey(arg1,value4);
      value4 = value4 + 1;
    } while (value4 < 1099);
    ptr5 = &DAT_0056afe8;
    value4 = 0xa0;
    do {
      value2 = *(int *)(value3 + (*(int *)(DAT_0057dcfc + 0x34) + value4) * 4);
      if (value2 == 0) {
        value2 = *ptr5 + 0xc;
      }
      else if (value2 == 1) {
        value2 = *ptr5;
      }
      else {
        value2 = *ptr5 + 6;
      }
      UI_ShowChildByID(arg1,value2);
      value4 = value4 + 8;
      ptr5 = ptr5 + 1;
    } while (value4 < 0xd0);
  }
  return;
}
