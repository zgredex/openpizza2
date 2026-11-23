// Index_Map8To5: ported from Pizza Connection 2 at 0x513980.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513980
#include "pc2_port.h"

int __thiscall Index_Map8To5(void *self,int arg1)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  
  value2 = 0;
  if (arg1 == 8) {
    arg1 = 5;
  }
  else if (arg1 == -1) {
    ptr3 = (int *)((intptr_t)self + 0x2c4);
    value4 = 8;
    do {
      value1 = *ptr3;
      ptr3 = ptr3 + 1;
      value2 = value2 + value1;
      value4 = value4 + -1;
    } while (value4 != 0);
    value2 = (intptr_t)(value2 + (value2 >> 0x1f & 7U)) >> 3;
    goto LAB_00513997;
  }
  value2 = *(int *)((intptr_t)self + arg1 * 4 + 0x2c4);
LAB_00513997:
  if (value2 < 0) {
    return 0;
  }
  if (100 < value2) {
    value2 = 100;
  }
  return value2;
}
