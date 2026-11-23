// Storage_GetSlotShare: ported from Pizza Connection 2 at 0x514260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514260
#include "pc2_port.h"

int __thiscall Storage_GetSlotShare(void *self,int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  
  value1 = Array_FindPair(self,arg1);
  if (value1 == -1) {
    return 0;
  }
  value4 = 0;
  ptr2 = (int *)((intptr_t)self + 0x68);
  value3 = 0x14;
  do {
    if (ptr2[-2] != 0) {
      value4 = value4 + *ptr2;
    }
    ptr2 = ptr2 + 3;
    value3 = value3 + -1;
  } while (value3 != 0);
  if (value4 == 0) {
    return 0;
  }
  return (*(int *)((intptr_t)self + value1 * 0xc + 0x68) * 100) / value4;
}
