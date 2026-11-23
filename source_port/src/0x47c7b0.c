// Object_SetIndex171C: ported from Pizza Connection 2 at 0x47c7b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c7b0
#include "pc2_port.h"

void __thiscall Object_SetIndex171C(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x171c) = arg1;
  *(uint32_t *)((intptr_t)self + 0x1724) = 0;
  *(uint32_t *)((intptr_t)self + 0x1720) = 0;
  return;
}
