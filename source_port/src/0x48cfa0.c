// Game_ClearSelectedObject: ported from Pizza Connection 2 at 0x48cfa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48cfa0
#include "pc2_port.h"

void __thiscall Game_ClearSelectedObject(void *self,int arg1)

{
  int value1;
  void *pvVar2;
  
  value1 = *(int *)((intptr_t)self + 0x9c);
  if (value1 != 0) {
    if ((arg1 != 0) && (*(void **)((intptr_t)self + 0x264) != (void *)0x0)) {
      UI_QueueControlCommand(*(void **)((intptr_t)self + 0x264),-0x18604,0x23,0);
      UI_QueueControlCommand(*(void **)((intptr_t)self + 0x264),DAT_00568404,1,0);
    }
    pvVar2 = *(void **)(value1 + 0x14e0);
    if (pvVar2 != (void *)0x0) {
      Map_DrawSelectedObjectSprite(pvVar2);
    }
    *(uint32_t *)((intptr_t)self + 0x344) = 0xffffffff;
    if (pvVar2 != (void *)0x0) {
      *(uint32_t *)((intptr_t)pvVar2 + 0x60) = 0;
    }
    *(uint32_t *)((intptr_t)self + 0x358) = 0;
  }
  return;
}
