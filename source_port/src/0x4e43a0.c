// Game_SetHQLevel: ported from Pizza Connection 2 at 0x4e43a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e43a0
#include "pc2_port.h"

void __thiscall Game_SetHQLevel(void *self,uint32_t arg1)

{
  switch(arg1) {
  case 0:
    *(uint32_t *)((intptr_t)self + 8) = 0x78;
    return;
  case 1:
    *(uint32_t *)((intptr_t)self + 8) = 0x8c;
    return;
  case 2:
    *(uint32_t *)((intptr_t)self + 8) = 0xa0;
    return;
  default:
    *(uint32_t *)((intptr_t)self + 8) = 0;
    return;
  }
}
