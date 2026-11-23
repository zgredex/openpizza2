// Array_GetPtr: ported from Pizza Connection 2 at 0x5230b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5230b0
#include "pc2_port.h"

uint32_t __thiscall Array_GetPtr(void *self,int arg1)

{
  if ((arg1 < 0) || (*(int *)((intptr_t)self + 8) <= arg1)) {
    return 0;
  }
  return *(uint32_t *)(*(int *)((intptr_t)self + 4) + arg1 * 4);
}
