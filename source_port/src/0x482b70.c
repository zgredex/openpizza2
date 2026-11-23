// Game_ShowConfirmationDialog: ported from Pizza Connection 2 at 0x482b70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482b70
#include "pc2_port.h"

void __thiscall
Game_ShowConfirmationDialog
          (void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4)

{
  void *this_00;
  void *local_4;
  
                    /* Shows a two-line confirmation dialog. */
  if (*(int *)((intptr_t)self + 0x268) == 0) {
    local_4 = self;
    this_00 = UI_CreateMessageBoxSubmenu((int *)&local_4);
    *(void **)((intptr_t)self + 0x268) = this_00;
    Window_GadgetNotify_Text_SetText(this_00,0x42b,arg2);
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x42c,arg3);
    Window_GadgetNotify_Text_SetMode(*(void **)((intptr_t)self + 0x268),0x42c,2);
    *(uint32_t *)((intptr_t)self + 0x274) = arg1;
    *(uint32_t *)((intptr_t)self + 0x278) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x270) = arg4;
    *(uint32_t *)((intptr_t)self + 0x27c) = 0;
    *(uint32_t *)((intptr_t)self + 0x280) = 0;
    Window_ShowWindowById(DAT_0057c5e0,(intptr_t)local_4);
    UI_AddUniquePair(*(void **)((intptr_t)self + 0x268),0x42e,0xd);
    UI_AddUniquePair(*(void **)((intptr_t)self + 0x268),0x42e,0x1b);
  }
  return;
}
