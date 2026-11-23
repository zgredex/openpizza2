// Rect_ContainsPoint: ported from Pizza Connection 2 at 0x52ffa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52ffa0
#include "pc2_port.h"

uint32_t __thiscall Rect_ContainsPoint(void *self,int *arg1)

{
  if ((((*arg1 < *(int *)((intptr_t)self + 8)) || (*(int *)((intptr_t)self + 0x10) <= *arg1)) ||
      (arg1[1] < *(int *)((intptr_t)self + 0xc))) || (*(int *)((intptr_t)self + 0x14) <= arg1[1])) {
    return 0;
  }
  return 1;
}
