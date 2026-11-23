// UI_ShowMessageDialog: ported from Pizza Connection 2 at 0x48d420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48d420
#include "pc2_port.h"

void __thiscall UI_ShowMessageDialog(void *self,uint32_t arg1,uint32_t arg2)

{
  void *this_00;
  void *local_4;
  
                    /* Shows a modal message dialog and plays its speech. */
  if (*(int *)((intptr_t)self + 0x268) == 0) {
    local_4 = self;
    Game_SuspendSimulation(self);
    this_00 = Dialog_Loading((int *)&local_4);
    *(void **)((intptr_t)self + 0x268) = this_00;
    Window_GadgetNotify_Text_SetText(this_00,0x3e9,arg2);
    Window_GadgetNotify_Text_SetText(*(void **)((intptr_t)self + 0x268),0x3f9,arg1);
    UI_AddUniquePair(*(void **)((intptr_t)self + 0x268),0x3f8,0xd);
    Set_Field228(DAT_0057c5e0,*(uint32_t *)((intptr_t)self + 0x268));
    Window_ShowWindowById(DAT_0057c5e0,(intptr_t)local_4);
    Sound_PlaySpeechStatement(DAT_0057ba0c,0x24);
  }
  return;
}
