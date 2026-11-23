// Object_SetField0C: ported from Pizza Connection 2 at 0x4e4760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4760
#include "pc2_port.h"

void __thiscall Object_SetField0C(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0xc) = arg1;
  return;
}
