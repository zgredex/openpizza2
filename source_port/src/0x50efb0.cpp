// Object_SetField8: ported from Pizza Connection 2 at 0x50efb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50efb0
#include "pc2_port.h"

void __thiscall Object_SetField8(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 8) = arg1;
  return;
}
