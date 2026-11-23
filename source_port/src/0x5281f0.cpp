// UI_SetEventCallback: ported from Pizza Connection 2 at 0x5281f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5281f0
#include "pc2_port.h"

void __thiscall UI_SetEventCallback(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x8308) = arg1;
  return;
}
