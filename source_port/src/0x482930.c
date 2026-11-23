// Game_ShowDatedMessageDialog: ported from Pizza Connection 2 at 0x482930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482930
#include "pc2_port.h"

void __thiscall Game_ShowDatedMessageDialog(void *self,uint32_t arg1)

{
  int value1;
  void *this_00;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int local_204;
  uint8_t local_200 [512];
  
                    /* Shows a dated message dialog. */
  if (*(int *)((intptr_t)self + 0x268) == 0) {
    value1 = *(int *)(*(int *)((intptr_t)self + 0x224) + 0xa8);
    this_00 = MissionOfferDialog_Create(&local_204);
    *(void **)((intptr_t)self + 0x268) = this_00;
    Window_GadgetNotify_Text_SetText(this_00,0x42d,DAT_0058213c);
    String_Format(local_200,&DAT_005630d0,
                  *(uint32_t *)
                   (&DAT_00583c58 + (*(int *)(value1 + 0x44) + *(int *)(value1 + 0x58) * 4) * 4));
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x42f,local_200);
    String_Format(local_200,&DAT_005630d0,
                  *(uint32_t *)(&DAT_00583d28 + *(int *)(value1 + 0x48) * 4));
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x436,local_200);
    String_Format(local_200,&DAT_005630d0,
                  *(uint32_t *)(&DAT_00583e10 + *(int *)(value1 + 0x50) * 4));
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x437,local_200);
    uvalue4 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 0x94) + 8);
    value2 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 0x94) + 7) + *(int *)(value1 + 0x4c);
    if (0x18 < value2) {
      uvalue3 = (value2 - 1U) / 0x18;
      do {
        uvalue4 = uvalue4 + 1;
        if (3 < (intptr_t)uvalue4) {
          uvalue4 = 0;
        }
        uvalue3 = uvalue3 - 1;
      } while (uvalue3 != 0);
    }
    String_Format(local_200,(uint8_t *)s__d___s__d__02d_00__s_005680bc,uvalue4 + 1);
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x439,local_200);
    *(uint32_t *)(value1 + 100) = arg1;
    *(uint32_t *)((intptr_t)self + 0x274) = arg1;
    *(uint32_t *)((intptr_t)self + 0x278) = 0x11d7;
    *(uint32_t *)((intptr_t)self + 0x270) = 0;
    *(uint32_t *)((intptr_t)self + 0x27c) = 0;
    *(uint32_t *)((intptr_t)self + 0x280) = 0;
    if (*(char *)(value1 + 0x60) != '\0') {
      UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x268),0x430);
      UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x268),0x435);
    }
    Window_ShowWindowById(DAT_0057c5e0,local_204);
    UI_AddUniquePair(*(void **)((intptr_t)self + 0x268),0x431,0xd);
    UI_AddUniquePair(*(void **)((intptr_t)self + 0x268),0x430,0x1b);
  }
  return;
}
