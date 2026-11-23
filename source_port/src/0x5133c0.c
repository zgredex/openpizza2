// Game_ComputeMarketFactors: ported from Pizza Connection 2 at 0x5133c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5133c0
#include "pc2_port.h"

void __fastcall Game_ComputeMarketFactors(int arg1)

{
  int *ptr1;
  int *ptr2;
  int value3;
  int value4;
  int *ptr5;
  int value6;
  int *ptr7;
  int value8;
  int *local_8;
  int local_4;
  
  ptr2 = (int *)(arg1 + 0x284);
  ptr7 = ptr2;
  for (value3 = 8; value3 != 0; value3 = value3 + -1) {
    *ptr7 = 0;
    ptr7 = ptr7 + 1;
  }
  value3 = *(int *)(arg1 + 0x250);
  *(int *)(arg1 + 0x2a0) = *(int *)(arg1 + 0x2a0) + value3 * 10;
  *(int *)(arg1 + 0x290) = *(int *)(arg1 + 0x290) + value3 * -10;
  value6 = *(int *)(arg1 + 0x254) * 5;
  value4 = *(int *)(arg1 + 0x254) * 10;
  *(int *)(arg1 + 0x28c) = *(int *)(arg1 + 0x28c) + value3 * 5 + value6;
  value8 = *(int *)(arg1 + 0x294) + value3 * 5 + value4;
  *(int *)(arg1 + 0x294) = value8;
  value4 = *(int *)(arg1 + 0x298) + value4 + value3 * 10;
  *(int *)(arg1 + 0x298) = value4;
  value3 = *(int *)(arg1 + 0x29c) + value6 + value3 * -10;
  *(int *)(arg1 + 0x29c) = value3;
  if (*(int *)(arg1 + 0x240) != 0) {
    *(int *)(arg1 + 0x29c) = value3 + 0x1e;
    *(int *)(arg1 + 0x294) = value8 + 0x1e;
    *(int *)(arg1 + 0x298) = value4 + 5;
    *(int *)(arg1 + 0x2a0) = *(int *)(arg1 + 0x2a0) + 0x1e;
  }
  if (200 < *(int *)(arg1 + 0x1d8)) {
    *ptr2 = *ptr2 + 10;
    *(int *)(arg1 + 0x288) = *(int *)(arg1 + 0x288) + 0x28;
    *(int *)(arg1 + 0x298) = *(int *)(arg1 + 0x298) + -0x14;
  }
  if (300 < *(int *)(arg1 + 0x1d8)) {
    *(int *)(arg1 + 0x290) = *(int *)(arg1 + 0x290) + 0x28;
    *(int *)(arg1 + 0x294) = *(int *)(arg1 + 0x294) + -0x14;
    *(int *)(arg1 + 0x29c) = *(int *)(arg1 + 0x29c) + -0x14;
    *(int *)(arg1 + 0x2a0) = *(int *)(arg1 + 0x2a0) + 0x28;
  }
  value3 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  local_8 = (int *)(value3 + 0x280);
  local_4 = 8;
  ptr7 = ptr2;
  do {
    ptr5 = (int *)(arg1 + 0x1c0);
    value3 = 6;
    ptr1 = local_8;
    do {
      value6 = *ptr5;
      ptr5 = ptr5 + 1;
      *ptr7 = *ptr7 + value6 * *ptr1;
      ptr1 = ptr1 + 8;
      value3 = value3 + -1;
    } while (value3 != 0);
    ptr7 = ptr7 + 1;
    local_8 = local_8 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  value3 = *(int *)(arg1 + 0x5c);
  if (value3 < 0x14) {
    value6 = 8;
    do {
      value6 = value6 + -1;
      *ptr2 = *ptr2 + (0x14 - value3) * -5;
      ptr2 = ptr2 + 1;
    } while (value6 != 0);
  }
  return;
}
