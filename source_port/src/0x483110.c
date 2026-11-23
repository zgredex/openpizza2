// Object_SetField280: ported from Pizza Connection 2 at 0x483110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483110
#include "pc2_port.h"

void __thiscall Object_SetField280(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x280) = arg1;
  return;
}
