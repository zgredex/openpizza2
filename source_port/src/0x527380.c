// UI_RefreshChildRect: ported from Pizza Connection 2 at 0x527380.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527380
#include "pc2_port.h"

void __fastcall UI_RefreshChildRect(void *arg1)

{
  int local_10 [4];
  
  if (*(int *)((intptr_t)*(void **)((intptr_t)arg1 + 0x244) + 0x14) != 0) {
    Window_GetRect(*(void **)((intptr_t)arg1 + 0x244),local_10);
    Renderer_ReleaseTarget(*(int *)((intptr_t)arg1 + 0x244));
    Rect_Set1A4(arg1,local_10);
  }
  return;
}
