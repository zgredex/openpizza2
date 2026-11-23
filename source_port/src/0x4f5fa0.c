// Array_SearchSet: ported from Pizza Connection 2 at 0x4f5fa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5fa0
#include "pc2_port.h"

void __thiscall Array_SearchSet(void *self,int arg1)

{
  int *ptr1;
  int *ptr2;
  int value3;
  
  value3 = 3;
  ptr2 = self;
  do {
    ptr2 = ptr2 + 1;
    if (*ptr2 == arg1) {
      ptr1 = (int *)((intptr_t)self + arg1 * 4 + 0x10);
      *ptr1 = *ptr1 + 1;
    }
    value3 = value3 + -1;
  } while (value3 != 0);
  return;
}
