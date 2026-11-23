// Game_ComputeFoodStats: ported from Pizza Connection 2 at 0x513590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513590
#include "pc2_port.h"

void __fastcall Game_ComputeFoodStats(void *arg1,int arg2)

{
  uint8_t flag1;
  int *ptr2;
  int value3;
  int value4;
  int extraout_EDX;
  int *ptr5;
  int local_1c [4];
  int local_c;
  int local_8;
  int local_4;
  
  ptr2 = local_1c;
  for (value3 = 7; value3 != 0; value3 = value3 + -1) {
    *ptr2 = 0;
    ptr2 = ptr2 + 1;
  }
  if (DAT_00573264 != -1) {
    ptr2 = &DAT_00573264;
    value3 = 0;
    ptr5 = &DAT_0057326c;
    do {
      value3 = Array_AreBothCountsPositive
                        (arg1,CONCAT31((int3)((uint32_t)arg2 >> 8),(char)*ptr2),
                         CONCAT31((int3)((uint32_t)value3 >> 8),(char)ptr5[-1]));
      arg2 = extraout_EDX;
      if (value3 != 0) {
        flag1 = *(uint8_t *)(*(int *)(DAT_0057c670 + 0xa8 + ptr5[-2] * 4) + 0xa8);
        local_1c[flag1] = local_1c[flag1] + *ptr5;
        flag1 = *(uint8_t *)(*(int *)(DAT_0057c670 + 0xa8 + ptr5[-1] * 4) + 0xa8);
        arg2 = local_1c[flag1] + *ptr5;
        local_1c[flag1] = arg2;
      }
      value3 = ptr5[1];
      ptr2 = ptr5 + 1;
      ptr5 = ptr5 + 3;
    } while (value3 != -1);
  }
  value3 = local_1c[3] + local_c;
  value4 = local_1c[2] + local_4;
  ptr2 = (int *)((intptr_t)arg1 + 0x2a4);
  *ptr2 = value3 + value4 * 3;
  *(int *)((intptr_t)arg1 + 0x2a8) = value3 + value4 * 2;
  *(int *)((intptr_t)arg1 + 0x2ac) = local_8 + local_1c[1] * 2 + value4;
  *(int *)((intptr_t)arg1 + 0x2b0) = value3 * 4;
  *(int *)((intptr_t)arg1 + 0x2b4) = (local_8 + local_1c[1] * 2) * 2;
  *(int *)((intptr_t)arg1 + 0x2b8) = (local_1c[1] + local_8 * 2) * 2;
  *(int *)((intptr_t)arg1 + 700) = value3 * 3;
  *(int *)((intptr_t)arg1 + 0x2c0) = local_8 + local_1c[1] + value4 + value3;
  value3 = 8;
  do {
    if (0x14 < *ptr2) {
      *ptr2 = 0x28 - *ptr2;
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  return;
}
