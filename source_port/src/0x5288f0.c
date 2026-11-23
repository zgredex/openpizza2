// UI_FinishDragAndExpandDirtyRect: ported from Pizza Connection 2 at 0x5288f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5288f0
#include "pc2_port.h"

void __thiscall UI_FinishDragAndExpandDirtyRect(void *self,void *arg1)

{
  int local_10 [4];
  
  if (*(int *)((intptr_t)self + 0x48) != -1) {
    UI_QueueControlCommand(*(void **)((intptr_t)self + 0x58),*(int *)((intptr_t)self + 0x48),4,0);
  }
  UI_GetOuterRect(self,local_10);
  Rect_Set1A4(arg1,local_10);
  return;
}
