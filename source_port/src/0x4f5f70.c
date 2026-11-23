// Array_SetSlot: ported from Pizza Connection 2 at 0x4f5f70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5f70
#include "pc2_port.h"

void __thiscall Array_SetSlot(void *self,int arg1,int arg2)

{
  int *ptr1;
  int value2;
  
  value2 = 3;
  ptr1 = self;
  do {
    ptr1 = ptr1 + 1;
    if (*ptr1 == arg1) {
      *(int *)((intptr_t)self + arg1 * 4 + 0x10) = arg2;
    }
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
