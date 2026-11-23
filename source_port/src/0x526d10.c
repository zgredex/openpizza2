// UI_SetMenuToggle: ported from Pizza Connection 2 at 0x526d10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526d10
#include "pc2_port.h"

void __thiscall UI_SetMenuToggle(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x234) = 1;
  *(uint32_t *)((intptr_t)self + 8) = arg1;
  return;
}
