// Game_SumStatRow8: ported from Pizza Connection 2 at 0x47a820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a820
#include "pc2_port.h"

int __thiscall Game_SumStatRow8(void *self,int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  
  value1 = 0;
  value3 = 0;
  ptr2 = (int *)((intptr_t)self + 0x1364);
  do {
    if ((value3 == arg1) || (arg1 == -1)) {
      value1 = value1 + *ptr2;
    }
    value3 = value3 + 1;
    ptr2 = ptr2 + 1;
  } while (value3 < 8);
  return value1;
}
