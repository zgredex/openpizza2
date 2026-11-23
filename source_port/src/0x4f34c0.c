// UI_ComputeCenteredRect: ported from Pizza Connection 2 at 0x4f34c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f34c0
#include "pc2_port.h"

void __thiscall UI_ComputeCenteredRect(void *self,int *arg1,int *arg2,int *arg3)

{
  int value1;
  int value2;
  
  value1 = *(int *)((intptr_t)self + 0x10);
  value2 = arg1[1];
  *arg2 = (*(int *)((intptr_t)self + 0xc) >> 1) + *arg1;
  *arg3 = (value1 >> 1) + value2 + value1;
  return;
}
