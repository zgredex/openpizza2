// Object_SetChildField2C: ported from Pizza Connection 2 at 0x50e4c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e4c0
#include "pc2_port.h"

void __thiscall Object_SetChildField2C(void *self,uint32_t arg1)

{
  if (*(int *)((intptr_t)self + 200) != 0) {
    *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x2c) = arg1;
  }
  return;
}
