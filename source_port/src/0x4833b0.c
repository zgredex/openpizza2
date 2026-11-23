// UI_ShowAmountEntryDialog: ported from Pizza Connection 2 at 0x4833b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4833b0
#include "pc2_port.h"

void __thiscall
UI_ShowAmountEntryDialog
          (void *self,char arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4,
          uint32_t arg5,uint32_t arg6,uint32_t arg7,int arg8)

{
  void *this_00;
  int value1;
  void *local_4;
  
                    /* Shows the amount-entry dialog with two fields. */
  if (*(int *)((intptr_t)self + 0x268) == 0) {
    local_4 = self;
    this_00 = RequestDialog_Create((int *)&local_4);
    *(void **)((intptr_t)self + 0x268) = this_00;
    Window_GadgetNotify_Text_SetText(this_00,0x42f,arg3);
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x431,arg4);
    if (arg1 == '\0') {
      Window_GadgetNotify_Input_SetText(*(void **)((intptr_t)self + 0x268),0x437,arg5);
      Window_GadgetNotify_Input_SetFilter(*(void **)((intptr_t)self + 0x268),0x437,arg8);
      value1 = 0x436;
    }
    else {
      Window_GadgetNotify_Input_SetText(*(void **)((intptr_t)self + 0x268),0x436,arg5);
      Window_GadgetNotify_Input_SetFilter(*(void **)((intptr_t)self + 0x268),0x436,arg8);
      value1 = 0x437;
    }
    UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x268),value1);
    if (arg8 == 0) {
      UI_RemoveObjectByKey(*(void **)((intptr_t)self + 0x268),0x42e);
    }
    *(uint32_t *)((intptr_t)self + 0x274) = arg2;
    *(uint32_t *)((intptr_t)self + 0x278) = arg6;
    *(uint32_t *)((intptr_t)self + 0x270) = arg7;
    *(uint32_t *)((intptr_t)self + 0x27c) = 0;
    *(uint32_t *)((intptr_t)self + 0x280) = 0;
    Window_ShowWindowById(DAT_0057c5e0,(intptr_t)local_4);
    UI_AddUniquePair(*(void **)((intptr_t)self + 0x268),0x434,0x1b);
    UI_AddUniquePair(*(void **)((intptr_t)self + 0x268),0x435,0xd);
    if (arg1 != '\0') {
      UI_SelectObjectRecord(DAT_0057c5e0,*(void **)((intptr_t)self + 0x268),0x436);
      return;
    }
    UI_SelectObjectRecord(DAT_0057c5e0,*(void **)((intptr_t)self + 0x268),0x437);
  }
  return;
}
