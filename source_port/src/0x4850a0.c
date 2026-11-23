// Game_SetViewMode: ported from Pizza Connection 2 at 0x4850a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4850a0
#include "pc2_port.h"

void __thiscall Game_SetViewMode(void *self,int arg1,uint32_t arg2)

{
  uint32_t *uptr1;
  
  if (arg1 == 9) {
    Window_HideWindowById(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac));
    uptr1 = (uint32_t *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac),(int *)0x0);
    Window_DestroyChild(DAT_0057c5e0,uptr1);
  }
  *(int *)((intptr_t)self + 0x2dc) = arg1;
  *(uint32_t *)((intptr_t)self + 0x2e0) = arg2;
  if (((arg1 == 1) || (arg1 == 3)) || (arg1 == 2)) {
    Sound_UpdatePositionCountdown(DAT_0057ba0c);
    return;
  }
  Sound_StopAndReset((intptr_t)DAT_0057ba0c);
  return;
}
