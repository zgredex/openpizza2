// Game_ComputeCategoryDominance: ported from Pizza Connection 2 at 0x479290.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479290
#include "pc2_port.h"

void __fastcall Game_ComputeCategoryDominance(int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  int64_t lvalue5;
  float local_20;
  int local_14 [5];
  
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  local_14[3] = 0;
  value3 = -1;
  local_14[4] = 0;
  value4 = 0;
  local_20 = 100.0;
  if (0 < *(int *)(arg1 + 0x170c)) {
    do {
      value1 = IDMap_Lookup((void *)(arg1 + 0x16f8),value4,(int *)0x0);
      if (value1 != 0) {
        value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(value1 + 4),(int *)0x0);
        value1 = *(int *)(value1 + 0x10);
        if (value1 != 4) {
          local_14[value1] = local_14[value1] + 1;
        }
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)(arg1 + 0x170c));
  }
  value4 = 0;
  value1 = 0;
  ptr2 = local_14;
  do {
    if (value4 < *ptr2) {
      value3 = value1;
      value4 = *ptr2;
    }
    value1 = value1 + 1;
    ptr2 = ptr2 + 1;
  } while (value1 < 5);
  if (value3 == -1) {
    *(uint32_t *)(arg1 + 0x1854) = 0;
    return;
  }
  value1 = 0;
  ptr2 = local_14;
  do {
    if (((value1 != value3) && (*ptr2 != 0)) && (0 < value4)) {
      local_20 = local_20 - ((float)*ptr2 / (float)value4) * 100.0;
    }
    value1 = value1 + 1;
    ptr2 = ptr2 + 1;
  } while (value1 < 4);
  if (value4 == 0) {
    local_20 = 0.0;
  }
  lvalue5 = Math_RoundFloat(local_20);
  *(int *)(arg1 + 0x1854) = (intptr_t)lvalue5;
  Clamp_0_100((int *)(arg1 + 0x1854));
  return;
}
