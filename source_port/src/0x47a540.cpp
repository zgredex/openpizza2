// Game_SumStatGrid2: ported from Pizza Connection 2 at 0x47a540.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a540
#include "pc2_port.h"

int __thiscall Game_SumStatGrid2(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  int *ptr5;
  
  value1 = 0;
  value4 = 0;
  ptr5 = (int *)((intptr_t)self + 0x44);
  do {
    if ((value4 == arg2) || (arg2 == -1)) {
      value2 = 0;
      ptr3 = ptr5;
      do {
        if ((value2 == arg1) || (arg1 == -1)) {
          value1 = value1 + *ptr3;
        }
        value2 = value2 + 1;
        ptr3 = ptr3 + 9;
      } while (value2 < 8);
    }
    value4 = value4 + 1;
    ptr5 = ptr5 + 1;
  } while (value4 < 8);
  return value1;
}
