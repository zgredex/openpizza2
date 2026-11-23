// Game_SetMapRenderParams: ported from Pizza Connection 2 at 0x4808c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4808c0
#include "pc2_port.h"

void __thiscall
Game_SetMapRenderParams
          (void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4)

{
  *(uint32_t *)((intptr_t)self + 0x1a2c) = arg1;
  *(uint32_t *)((intptr_t)self + 0x1a30) = arg4;
  *(uint32_t *)((intptr_t)self + 0x1a34) = arg2;
  *(uint32_t *)((intptr_t)self + 0x1a38) = arg3;
  Game_MarkAllObjectsDirty(self,4);
  return;
}
