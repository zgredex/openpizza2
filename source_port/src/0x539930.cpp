// Rect_ScaleAndOffset: ported from Pizza Connection 2 at 0x539930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539930
#include "pc2_port.h"

void __thiscall Rect_ScaleAndOffset(void *self,int *arg1)

{
  *arg1 = *arg1 / *(int *)((intptr_t)self + 0x58) + *(int *)((intptr_t)self + 0x5c);
  arg1[1] = arg1[1] / *(int *)((intptr_t)self + 0x58) + *(int *)((intptr_t)self + 0x60);
  arg1[2] = (arg1[2] + -1 + *(int *)((intptr_t)self + 0x58)) / *(int *)((intptr_t)self + 0x58) +
               *(int *)((intptr_t)self + 0x5c);
  arg1[3] = (arg1[3] + -1 + *(int *)((intptr_t)self + 0x58)) / *(int *)((intptr_t)self + 0x58) +
               *(int *)((intptr_t)self + 0x60);
  return;
}
