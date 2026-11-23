// Array_GetPair8: ported from Pizza Connection 2 at 0x5312f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5312f0
#include "pc2_port.h"

uint32_t __thiscall Array_GetPair8(void *self,int arg1,uint32_t *arg2)

{
  if ((arg1 < 0) || (*(int *)((intptr_t)self + 0xf0) <= arg1)) {
    return 0;
  }
  *arg2 = *(uint32_t *)(*(int *)((intptr_t)self + 0xec) + 4 + arg1 * 8);
  return *(uint32_t *)(*(int *)((intptr_t)self + 0xec) + arg1 * 8);
}
