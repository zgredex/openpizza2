// Object_SetFlag104: ported from Pizza Connection 2 at 0x50e710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e710
#include "pc2_port.h"

void __thiscall Object_SetFlag104(void *self,uint8_t arg1)

{
  *(uint8_t *)((intptr_t)self + 0x104) = arg1;
  return;
}
