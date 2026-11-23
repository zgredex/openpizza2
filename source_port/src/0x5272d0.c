// UI_SetLayoutParams: ported from Pizza Connection 2 at 0x5272d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5272d0
#include "pc2_port.h"

void __thiscall UI_SetLayoutParams(void *self,uint32_t arg1,uint32_t arg2)

{
  *(uint32_t *)((intptr_t)self + 0x82e4) = arg1;
  *(uint32_t *)((intptr_t)self + 0x82e8) = arg2;
  return;
}
