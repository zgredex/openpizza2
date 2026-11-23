// Object_SetFrame5: ported from Pizza Connection 2 at 0x50d200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d200
#include "pc2_port.h"

void __thiscall Object_SetFrame5(void *self,int arg1)

{
  if (arg1 == -1) {
    *(uint32_t *)((intptr_t)self + 0x94) = 0xffffffff;
    return;
  }
  *(int *)((intptr_t)self + 0x94) = arg1 * 5;
  return;
}
