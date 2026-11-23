// Game_ShowQuestionDialog: ported from Pizza Connection 2 at 0x482c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482c40
#include "pc2_port.h"

void __thiscall
Game_ShowQuestionDialog
          (void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4,
          uint32_t arg5,int arg6,char arg7)

{
  void *pvVar1;
  int value2;
  void *local_4;
  
                    /* Shows the generic question dialog. */
  value2 = arg6;
  if (*(int *)((intptr_t)self + 0x268) == 0) {
    DAT_00567da0 = arg6;
    local_4 = self;
    pvVar1 = Dialog_Confirm(&arg6);
    *(void **)((intptr_t)self + 0x268) = pvVar1;
    *(uint32_t *)((intptr_t)self + 0x274) = arg1;
    *(uint32_t *)((intptr_t)self + 0x278) = arg4;
    if (arg7 == '\0') {
      *(uint32_t *)((intptr_t)self + 0x2e14) = 0xffffffff;
    }
    else {
      *(uint32_t *)((intptr_t)self + 0x2e14) = 0;
    }
    *(uint32_t *)((intptr_t)self + 0x270) = arg5;
    *(uint32_t *)((intptr_t)self + 0x27c) = 0;
    *(uint32_t *)((intptr_t)self + 0x280) = 1;
    *(int *)((intptr_t)self + 0x284) = value2;
    if (value2 != -1) {
      value2 = MessageList_FindKeyByValue((void *)((intptr_t)self + 0x304),value2,(int *)&local_4);
      if (*(int *)(value2 + 0x24) != -1) {
        Gadget_SetText(*(void **)((intptr_t)self + 0x268),0x431,DAT_00581650);
      }
    }
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x42d,arg2);
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x42f,arg3);
    Window_GadgetNotify_Text_SetMode(*(void **)((intptr_t)self + 0x268),0x42f,2);
    UI_AddUniquePair(*(void **)((intptr_t)self + 0x268),0x431,0xd);
    UI_AddUniquePair(*(void **)((intptr_t)self + 0x268),0x430,0x1b);
    Window_ShowWindowById(DAT_0057c5e0,arg6);
  }
  return;
}
