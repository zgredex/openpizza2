// Grid_GetCell: ported from Pizza Connection 2 at 0x4ef4b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ef4b0
#include "pc2_port.h"

int __thiscall Grid_GetCell(void *self,int arg1,int arg2)

{
  if ((arg2 < *(int *)((intptr_t)self + 0x20)) && (-1 < arg2)) {
    if ((arg1 < *(int *)((intptr_t)self + 0x1c)) && (-1 < arg1)) {
      return *(int *)((intptr_t)self + 0x4c) + (*(int *)((intptr_t)self + 0x1c) * arg2 + arg1) * 0xc;
    }
  }
  return 0;
}
