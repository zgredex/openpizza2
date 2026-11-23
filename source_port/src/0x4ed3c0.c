// Map_ClampScrollY: ported from Pizza Connection 2 at 0x4ed3c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed3c0
#include "pc2_port.h"

bool __thiscall Map_ClampScrollY(void *self,int arg1)

{
  int value1;
  int value2;
  
  value1 = *(int *)((intptr_t)self + 0xec);
  value2 = *(int *)((intptr_t)self + 0x30) - *(int *)((intptr_t)self + 0x10174);
  *(int *)((intptr_t)self + 0xec) = arg1;
  if (arg1 < value2) {
    *(int *)((intptr_t)self + 0xec) = value2;
  }
  if (*(int *)(DAT_0057c670 + 0x2da0) == 2) {
    value2 = *(int *)((intptr_t)self + 0x10170) + -0x38 + *(int *)((intptr_t)self + 0x38);
    if (*(int *)((intptr_t)self + 0xec) <= value2) goto LAB_004ed422;
  }
  else {
    value2 = *(int *)((intptr_t)self + 0x38) + *(int *)((intptr_t)self + 0x10170);
    if (*(int *)((intptr_t)self + 0xec) <= value2) goto LAB_004ed422;
  }
  *(int *)((intptr_t)self + 0xec) = value2;
LAB_004ed422:
  return value1 != *(int *)((intptr_t)self + 0xec);
}
