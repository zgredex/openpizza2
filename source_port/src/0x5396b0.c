// Surface_GetCursorRect: ported from Pizza Connection 2 at 0x5396b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5396b0
#include "pc2_port.h"

void __thiscall
Surface_GetCursorRect
          (void *self,uint32_t *arg1,uint32_t *arg2,uint32_t *arg3,
          uint32_t *arg4)

{
  *arg1 = *(uint32_t *)((intptr_t)self + 4);
  *arg2 = *(uint32_t *)((intptr_t)self + 0xc);
  *arg3 = *(uint32_t *)((intptr_t)self + 8);
  *arg4 = *(uint32_t *)((intptr_t)self + 0x10);
  return;
}
