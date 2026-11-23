// Stats_BuildCompetitorMatrix: ported from Pizza Connection 2 at 0x4bf5c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bf5c0
#include "pc2_port.h"

void __cdecl Stats_BuildCompetitorMatrix(int *arg1)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  int *ptr5;
  int value6;
  int *ptr7;
  int local_20 [8];
  
  ptr4 = arg1;
  ptr7 = arg1;
  for (value3 = 0x40; value3 != 0; value3 = value3 + -1) {
    *ptr7 = 0;
    ptr7 = ptr7 + 1;
  }
  ptr7 = local_20;
  for (value3 = 8; value3 != 0; value3 = value3 + -1) {
    *ptr7 = 0;
    ptr7 = ptr7 + 1;
  }
  value3 = 0;
  if (0 < *(int *)(DAT_0057c670 + 0x50)) {
    do {
      value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value3,(int *)0x0);
      value6 = *(int *)(value2 + 0x30);
      if (value6 < 8) {
        ptr7 = (int *)(value2 + 0xd4);
        local_20[value6] = local_20[value6] + 1;
        value6 = 0;
        do {
          if (*(int *)(*ptr7 + 4) == *(int *)(*(int *)(DAT_0057c670 + 0x218) + 4)) {
            value1 = value6 + *(int *)(value2 + 0x30) * 8;
            arg1[value1] = arg1[value1] + 1;
          }
          value6 = value6 + 1;
          ptr7 = ptr7 + 1;
        } while (value6 < 8);
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)(DAT_0057c670 + 0x50));
  }
  ptr7 = local_20;
  arg1 = (int *)0x8;
  do {
    value3 = *ptr7;
    value6 = 8;
    ptr5 = ptr4;
    do {
      ptr4 = ptr5 + 1;
      value6 = value6 + -1;
      *ptr5 = (value3 / 2 + *ptr5 * 100) / value3;
      ptr5 = ptr4;
    } while (value6 != 0);
    ptr7 = ptr7 + 1;
    arg1 = (int *)((intptr_t)arg1 + -1);
  } while (arg1 != (int *)0x0);
  return;
}
