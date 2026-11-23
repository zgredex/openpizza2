// Game_ComputeRatingShare: ported from Pizza Connection 2 at 0x4da760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da760
#include "pc2_port.h"

int __thiscall Game_ComputeRatingShare(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  
  value2 = 0;
  value3 = 0;
  ptr4 = (int *)((intptr_t)self + 0xc98);
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value3);
    if (value1 != 0) {
      value2 = value2 + (0x65 - *ptr4);
    }
    value3 = value3 + 1;
    ptr4 = ptr4 + 1;
  } while (value3 < 6);
  return ((0x65 - *(int *)((intptr_t)self + arg1 * 4 + 0xc98)) * 100) / value2;
}
