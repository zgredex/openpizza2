// Surface_SetBounds: ported from Pizza Connection 2 at 0x539660.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539660
#include "pc2_port.h"

void __thiscall Surface_SetBounds(void *self,int arg1,int arg2,int arg3,int arg4)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + 100);
  if (*(int *)((intptr_t)self + 100) <= arg1) {
    value1 = arg1;
  }
  *(int *)((intptr_t)self + 4) = value1;
  value1 = *(int *)((intptr_t)self + 0x68);
  if (*(int *)((intptr_t)self + 0x68) <= arg2) {
    value1 = arg2;
  }
  *(int *)((intptr_t)self + 0xc) = value1;
  value1 = *(int *)((intptr_t)self + 0x6c);
  if (arg3 <= *(int *)((intptr_t)self + 0x6c)) {
    value1 = arg3;
  }
  *(int *)((intptr_t)self + 8) = value1;
  if (*(int *)((intptr_t)self + 0x70) < arg4) {
    *(int *)((intptr_t)self + 0x10) = *(int *)((intptr_t)self + 0x70);
    return;
  }
  *(int *)((intptr_t)self + 0x10) = arg4;
  return;
}
