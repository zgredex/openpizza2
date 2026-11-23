// Branch_GetMenuRating: ported from Pizza Connection 2 at 0x478320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x478320
#include "pc2_port.h"

int __thiscall Branch_GetMenuRating(void *self,int arg1)

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
    ptr2 = (int *)((intptr_t)self + 0x177c);
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
    value4 = *(int *)((intptr_t)self + arg1 * 4 + 0x177c);
  }
  value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
  value3 = Game_GetPlayerCity(value3);
  value4 = (((*(int *)(value3 + 0x5c) + *(int *)(value3 + 0x44)) * -3 + 100) * value4) / 100;
  if (value4 < 0) {
    return 0;
  }
  if (100 < value4) {
    value4 = 100;
  }
  return value4;
}
