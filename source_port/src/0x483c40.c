// Game_DestroyCachedScreens: ported from Pizza Connection 2 at 0x483c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483c40
#include "pc2_port.h"

void __thiscall Game_DestroyCachedScreens(void *self,int arg1)

{
  if (arg1 != *(int *)((intptr_t)self + 0x290)) {
    UI_DestroyWindowAt((uint32_t *)((intptr_t)self + 0x25c));
    UI_DestroyWindowAt((uint32_t *)((intptr_t)self + 0x260));
    UI_DestroyWindowAt((uint32_t *)((intptr_t)self + 0x264));
    UI_DestroyWindowAt((uint32_t *)((intptr_t)self + 0x268));
  }
  return;
}
