// UI_SetWindowVisible: ported from Pizza Connection 2 at 0x532890.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532890
#include "pc2_port.h"

void __thiscall UI_SetWindowVisible(void *self,int arg1)

{
  if (*(int *)((intptr_t)self + 0x4c) != arg1) {
    *(int *)((intptr_t)self + 0x4c) = arg1;
    Window_NotifyMouseMove(*(void **)((intptr_t)self + 0x134));
    if (*(int *)((intptr_t)self + 0x4c) != 0) {
      UI_QueueControlCommand(self,-1,0x1f,0);
      return;
    }
    UI_QueueControlCommand(self,-1,0x1e,0);
  }
  return;
}
