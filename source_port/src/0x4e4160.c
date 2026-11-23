// Object_GetPair68: ported from Pizza Connection 2 at 0x4e4160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4160
#include "pc2_port.h"

void __thiscall Object_GetPair68(void *self,uint32_t *arg1,uint32_t *arg2)

{
  *arg1 = *(uint32_t *)((intptr_t)self + 0x68);
  *arg2 = *(uint32_t *)((intptr_t)self + 0x6c);
  return;
}
