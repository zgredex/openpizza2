// Object_CountMatchingSlots: ported from Pizza Connection 2 at 0x50e200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e200
#include "pc2_port.h"

int __thiscall Object_CountMatchingSlots(void *self,int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  
  value1 = 0;
  ptr2 = (int *)((intptr_t)self + 0xd4);
  value3 = 8;
  do {
    if (*ptr2 == arg1) {
      value1 = value1 + 1;
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  return value1;
}
