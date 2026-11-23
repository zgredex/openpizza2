// Array_IndexOfInt: ported from Pizza Connection 2 at 0x5230d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5230d0
#include "pc2_port.h"

int __thiscall Array_IndexOfInt(void *self,int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  if (0 < *(int *)((intptr_t)self + 8)) {
    ptr2 = *(int **)((intptr_t)self + 4);
    do {
      if (*ptr2 == arg1) {
        return value1;
      }
      value1 = value1 + 1;
      ptr2 = ptr2 + 1;
    } while (value1 < *(int *)((intptr_t)self + 8));
  }
  return -1;
}
