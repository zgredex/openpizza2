// Rect_Union: ported from Pizza Connection 2 at 0x526d30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526d30
#include "pc2_port.h"

void __thiscall Rect_Union(void *self,int arg1,int arg2,int arg3,int arg4)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + 0x1a4);
  if (value1 == -999) {
    SetRect((LPRECT)((intptr_t)self + 0x1a4),arg1,arg2,arg3,arg4);
    return;
  }
  if (arg1 <= value1) {
    value1 = arg1;
  }
  ((LPRECT)((intptr_t)self + 0x1a4))->left = value1;
  value1 = *(int *)((intptr_t)self + 0x1ac);
  if (*(int *)((intptr_t)self + 0x1ac) <= arg3) {
    value1 = arg3;
  }
  *(int *)((intptr_t)self + 0x1ac) = value1;
  value1 = *(int *)((intptr_t)self + 0x1a8);
  if (arg2 <= *(int *)((intptr_t)self + 0x1a8)) {
    value1 = arg2;
  }
  *(int *)((intptr_t)self + 0x1a8) = value1;
  value1 = *(int *)((intptr_t)self + 0x1b0);
  if (*(int *)((intptr_t)self + 0x1b0) <= arg4) {
    value1 = arg4;
  }
  *(int *)((intptr_t)self + 0x1b0) = value1;
  return;
}
