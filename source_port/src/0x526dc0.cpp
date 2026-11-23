// Rect_Set1A4: ported from Pizza Connection 2 at 0x526dc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526dc0
#include "pc2_port.h"

void __thiscall Rect_Set1A4(void *self,int *arg1)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + 0x1a4);
  if (value1 == -999) {
    *(int *)((intptr_t)self + 0x1a4) = *arg1;
    *(int *)((intptr_t)self + 0x1a8) = arg1[1];
    *(int *)((intptr_t)self + 0x1ac) = arg1[2];
    *(int *)((intptr_t)self + 0x1b0) = arg1[3];
    return;
  }
  if (*arg1 <= value1) {
    value1 = *arg1;
  }
  *(int *)((intptr_t)self + 0x1a4) = value1;
  value1 = *(int *)((intptr_t)self + 0x1ac);
  if (*(int *)((intptr_t)self + 0x1ac) <= arg1[2]) {
    value1 = arg1[2];
  }
  *(int *)((intptr_t)self + 0x1ac) = value1;
  value1 = *(int *)((intptr_t)self + 0x1a8);
  if (arg1[1] <= *(int *)((intptr_t)self + 0x1a8)) {
    value1 = arg1[1];
  }
  *(int *)((intptr_t)self + 0x1a8) = value1;
  value1 = *(int *)((intptr_t)self + 0x1b0);
  if (*(int *)((intptr_t)self + 0x1b0) <= arg1[3]) {
    value1 = arg1[3];
  }
  *(int *)((intptr_t)self + 0x1b0) = value1;
  return;
}
