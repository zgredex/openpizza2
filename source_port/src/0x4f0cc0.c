// Array_GetRecord28: ported from Pizza Connection 2 at 0x4f0cc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f0cc0
#include "pc2_port.h"

int __thiscall Array_GetRecord28(void *self,int arg1,int arg2)

{
  if (arg2 == -1) {
    return 0;
  }
  if (arg1 == 1) {
    return *(int *)((intptr_t)self + 0x9c) + arg2 * 0x28;
  }
  return *(int *)((intptr_t)self + 0xa0) + arg2 * 0x28;
}
