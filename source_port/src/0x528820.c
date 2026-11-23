// UI_UpdateHoveredRow: ported from Pizza Connection 2 at 0x528820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528820
#include "pc2_port.h"

uint32_t __thiscall UI_UpdateHoveredRow(void *self,int *arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value1 = *(int *)((intptr_t)self + 0x3c);
  value2 = arg1[1];
  value3 = *(int *)((intptr_t)self + 0x34);
  if ((value3 + value1 <= value2) &&
     (value4 = *(int *)(*(int *)((intptr_t)self + 0x4c) + 0x9b0),
     value2 <= *(int *)((intptr_t)self + 0x40) * value4 + value3 + value1)) {
    value5 = *(int *)((intptr_t)self + 0x38) + *(int *)((intptr_t)self + 0x30);
    if ((value5 <= *arg1) && (*arg1 <= *(int *)((intptr_t)self + 0x28) + value5)) {
      value4 = ((value2 - value3) - value1) / value4;
      goto LAB_0052887f;
    }
  }
  value4 = -1;
LAB_0052887f:
  if (*(int *)((intptr_t)self + 0x40) <= value4) {
    value4 = -1;
  }
  if (value4 == *(int *)((intptr_t)self + 0x48)) {
    return 0;
  }
  *(int *)((intptr_t)self + 0x48) = value4;
  return 1;
}
