// Array_GetPtrChecked: ported from Pizza Connection 2 at 0x535d50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535d50
#include "pc2_port.h"

uint32_t __thiscall Array_GetPtrChecked(void *self,int arg1)

{
  if ((arg1 < 0) || (*(int *)((intptr_t)self + 8) <= arg1)) {
    return 0;
  }
  return *(uint32_t *)(*(int *)self + arg1 * 4);
}
