// Object_GetPair4: ported from Pizza Connection 2 at 0x535160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535160
#include "pc2_port.h"

void __thiscall Object_GetPair4(void *self,uint32_t *arg1,uint32_t *arg2)

{
  *arg1 = *(uint32_t *)((intptr_t)self + 4);
  *arg2 = *(uint32_t *)((intptr_t)self + 8);
  return;
}
