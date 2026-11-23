// Stats_SumSixSlotValues: ported from Pizza Connection 2 at 0x4dc660.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dc660
#include "pc2_port.h"

int __thiscall Stats_SumSixSlotValues(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  
  value1 = 0;
  value3 = 0;
  value2 = 0;
  ptr4 = (int *)((intptr_t)self + arg1 * 0x18 + 0xce0);
  do {
    value1 = value1 + *ptr4;
    if (value2 == arg2) {
      value3 = *ptr4;
    }
    value2 = value2 + 1;
    ptr4 = ptr4 + 1;
  } while (value2 < 6);
  if (arg2 != -1) {
    value1 = value3;
  }
  return value1;
}
