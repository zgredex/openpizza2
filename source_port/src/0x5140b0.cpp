// Array_FindPair: ported from Pizza Connection 2 at 0x5140b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5140b0
#include "pc2_port.h"

int __thiscall Array_FindPair(void *self,int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  ptr2 = (int *)((intptr_t)self + 100);
  while ((ptr2[-1] == 0 || (*ptr2 != arg1))) {
    value1 = value1 + 1;
    ptr2 = ptr2 + 3;
    if (0x13 < value1) {
      return -1;
    }
  }
  return value1;
}
