// UI_SetPosition: ported from Pizza Connection 2 at 0x532310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532310
#include "pc2_port.h"

void __thiscall UI_SetPosition(void *self,uint32_t arg1,uint32_t arg2)

{
  *(uint32_t *)((intptr_t)self + 0x28c) = arg1;
  *(uint32_t *)((intptr_t)self + 0x290) = arg2;
  return;
}
