// Game_ComputeCompanyRatings: ported from Pizza Connection 2 at 0x5136c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5136c0
#include "pc2_port.h"

void __thiscall Game_ComputeCompanyRatings(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  
  value3 = 0;
  value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  if (arg1 == value2) {
    value3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
    value3 = (*(int *)(value3 + 0xe8) * 2 - *(int *)(value3 + 0x1cc)) * 5;
  }
  ptr4 = (int *)((intptr_t)self + 0x2c4);
  value2 = 8;
  do {
    value1 = (((ptr4[-0x10] + ptr4[-0x18]) / 2 + ptr4[-8]) * (value3 + 100)) / 100;
    *ptr4 = value1;
    if (value1 < 0) {
      *ptr4 = 0;
    }
    if (100 < *ptr4) {
      *ptr4 = 100;
    }
    ptr4 = ptr4 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
