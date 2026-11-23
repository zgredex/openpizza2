// Array_MoveActiveSlotToRandom: ported from Pizza Connection 2 at 0x4db260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4db260
#include "pc2_port.h"

void __thiscall Array_MoveActiveSlotToRandom(void *self,int arg1)

{
  uint32_t uvalue1;
  int *ptr2;
  int *ptr3;
  int value4;
  int value5;
  
  value5 = 0;
  uvalue1 = Random_RangeFast(0,5);
  value4 = 6;
  ptr3 = (int *)((intptr_t)self + arg1 * 4 + 0x280);
  ptr2 = ptr3;
  do {
    if (*ptr2 == 1) {
      value5 = value5 + 1;
    }
    ptr2 = ptr2 + 8;
    value4 = value4 + -1;
  } while (value4 != 0);
  if (1 < value5) {
    value4 = 0;
    do {
      if (*ptr3 == 1) {
        *(uint32_t *)((intptr_t)self + (arg1 + 0xa0 + value4 * 8) * 4) = 0;
        *(uint32_t *)((intptr_t)self + (arg1 + 0xa0 + uvalue1 * 8) * 4) = 1;
        return;
      }
      value4 = value4 + 1;
      ptr3 = ptr3 + 8;
    } while (value4 < 6);
  }
  *(uint32_t *)((intptr_t)self + (arg1 + 0xa0 + uvalue1 * 8) * 4) = 1;
  return;
}
