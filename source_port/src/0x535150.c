// Object_GetPair10: ported from Pizza Connection 2 at 0x535150.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535150
#include "pc2_port.h"

uint32_t __thiscall Object_GetPair10(void *self,uint32_t *arg1)

{
  *arg1 = *(uint32_t *)((intptr_t)self + 0x10);
  return *(uint32_t *)((intptr_t)self + 0x14);
}
