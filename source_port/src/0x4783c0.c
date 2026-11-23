// Branch_GetPriceRating: ported from Pizza Connection 2 at 0x4783c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4783c0
#include "pc2_port.h"

int __thiscall Branch_GetPriceRating(void *self,int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  
  value4 = 0;
  if (*(int *)((intptr_t)self + 0x1714) == 0) {
    Branch_RecomputeMenuPriceRatings((intptr_t)self);
  }
  if (arg1 == -1) {
    ptr2 = (int *)((intptr_t)self + 0x179c);
    value3 = 8;
    do {
      value1 = *ptr2;
      ptr2 = ptr2 + 1;
      value4 = value4 + value1;
      value3 = value3 + -1;
    } while (value3 != 0);
    value4 = (intptr_t)(value4 + (value4 >> 0x1f & 7U)) >> 3;
  }
  else {
    value4 = *(int *)((intptr_t)self + arg1 * 4 + 0x179c);
  }
  if (value4 < 0) {
    return 0;
  }
  if (100 < value4) {
    value4 = 100;
  }
  return value4;
}
