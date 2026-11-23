// UI_InitInputHelper: ported from Pizza Connection 2 at 0x51e9d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51e9d0
#include "pc2_port.h"

void __thiscall UI_InitInputHelper(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 4) = 0;
  *(uint32_t *)self = 0;
  *(uint32_t *)((intptr_t)self + 8) = arg1;
  *(uint32_t *)((intptr_t)self + 0xc) = 0xffffd8f1;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  *(uint32_t *)((intptr_t)self + 0x18) = 0;
  *(uint32_t *)((intptr_t)self + 0x24) = 0;
  return;
}
