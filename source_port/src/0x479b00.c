// Grid_ScoreRuns: ported from Pizza Connection 2 at 0x479b00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479b00
#include "pc2_port.h"

int Grid_ScoreRuns(int arg1)

{
  short *psVar1;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int *ptr7;
  int local_500 [80];
  int local_3c0 [80];
  int local_280 [80];
  int local_140 [80];
  
  ptr7 = local_280;
  for (value3 = 0x50; value3 != 0; value3 = value3 + -1) {
    *ptr7 = 0;
    ptr7 = ptr7 + 1;
  }
  ptr7 = local_3c0;
  for (value3 = 0x50; value3 != 0; value3 = value3 + -1) {
    *ptr7 = 0;
    ptr7 = ptr7 + 1;
  }
  ptr7 = local_140;
  for (value3 = 0x50; value3 != 0; value3 = value3 + -1) {
    *ptr7 = 0;
    ptr7 = ptr7 + 1;
  }
  ptr7 = local_500;
  for (value3 = 0x50; value3 != 0; value3 = value3 + -1) {
    *ptr7 = 0;
    ptr7 = ptr7 + 1;
  }
  value6 = 0;
  psVar1 = (short *)(arg1 + 4);
  value3 = 0;
  do {
    value2 = 0;
    do {
      if (*psVar1 == 1) {
        value4 = *(int *)((intptr_t)local_3c0 + value3) + 1;
        *(int *)((intptr_t)local_3c0 + value3) = value4;
        value5 = *(int *)((intptr_t)local_280 + value2) + 1;
        *(int *)((intptr_t)local_280 + value2) = value5;
        if (2 < value4) {
          value6 = value6 + 4;
        }
        if (2 < value5) {
          value6 = value6 + 4;
        }
LAB_00479bd8:
        *(uint32_t *)((intptr_t)local_500 + value3) = 0;
        *(uint32_t *)((intptr_t)local_140 + value2) = 0;
      }
      else {
        if (*psVar1 != 2) {
          *(uint32_t *)((intptr_t)local_3c0 + value3) = 0;
          *(uint32_t *)((intptr_t)local_280 + value2) = 0;
          goto LAB_00479bd8;
        }
        value4 = *(int *)((intptr_t)local_500 + value3) + 1;
        *(int *)((intptr_t)local_500 + value3) = value4;
        value5 = *(int *)((intptr_t)local_140 + value2) + 1;
        *(int *)((intptr_t)local_140 + value2) = value5;
        if (4 < value4) {
          value6 = value6 + 2;
        }
        if (4 < value5) {
          value6 = value6 + 2;
        }
        *(uint32_t *)((intptr_t)local_3c0 + value3) = 0;
        *(uint32_t *)((intptr_t)local_280 + value2) = 0;
      }
      value2 = value2 + 4;
      psVar1 = psVar1 + 4;
    } while (value2 < 0x140);
    value3 = value3 + 4;
    if (0x13f < value3) {
      return value6;
    }
  } while( true );
}
