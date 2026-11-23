// Branch_ComputeBuildingRating: ported from Pizza Connection 2 at 0x478be0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x478be0
#include "pc2_port.h"

int __fastcall Branch_ComputeBuildingRating(void *arg1,uint32_t arg2,int arg3)

{
  int value1;
  int value2;
  uint32_t extraout_EDX;
  int *ptr3;
  int value4;
  int value5;
  uint64_t uvalue6;
  int64_t lvalue7;
  
  if (*(int *)((intptr_t)arg1 + 0x1718) == 0) {
    Branch_RecalculateRatings();
    arg2 = extraout_EDX;
  }
  uvalue6 = Game_ComputeAverageProductQuality((intptr_t)arg1,arg2);
  lvalue7 = Stats_ComputeAverageGroupScore((intptr_t)arg1,(uint32_t)(uvalue6 >> 0x20));
  value5 = 0;
  value4 = 0;
  ptr3 = (int *)((intptr_t)arg1 + 0x17fc);
  do {
    if ((arg3 == -1) || (value4 == arg3)) {
      Game_InitStatBaselines(arg1,value4,'\0');
      value1 = (intptr_t)(((uint32_t)uvalue6 & 0xff) - (&DAT_005677f8)[value4]) >> 3;
      value2 = (intptr_t)lvalue7 - (&DAT_00567818)[value4];
      if (value2 < 0) {
        value1 = value1 + (value2 >> 1);
      }
      value2 = value1 + *ptr3;
      if (ptr3[-8] < value1 + *ptr3) {
        value2 = ptr3[-8];
      }
      value5 = value5 + (ptr3[8] + value2 * 3 >> 2) + *(int *)((intptr_t)arg1 + 0x187c) * -10;
    }
    value4 = value4 + 1;
    ptr3 = ptr3 + 1;
  } while (value4 < 8);
  if (arg3 == -1) {
    value5 = value5 >> 3;
  }
  value4 = *(int *)((intptr_t)arg1 + 0x30);
  value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if (value4 == value1) {
    value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(value1 + 0x1c8) != 0) {
      value5 = (value5 * 0x5f) / 100;
    }
    if (*(int *)(value1 + 0xe4) != 0) {
      value5 = (value5 * 0x6e) / 100;
    }
  }
  value4 = Game_GetPlayerBySlot(DAT_0057c670,value4);
  value4 = Game_GetPlayerCity(value4);
  value5 = (((*(int *)(value4 + 0x5c) + *(int *)(value4 + 0x44)) * -3 + 100) * value5) / 100;
  value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if (*(int *)((intptr_t)arg1 + 0x30) == value4) {
    value4 = 0;
    ptr3 = *(int **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac);
    do {
      ptr3 = ptr3 + 1;
      if (*ptr3 == 0xf) {
        value1 = *(int *)((intptr_t)arg1 + 0x1a04);
        if (value1 == 0) {
          return 0;
        }
        if (value1 == 4) {
          return 0;
        }
        if (value1 == 2) {
          return 0;
        }
      }
      value4 = value4 + 1;
    } while (value4 < 3);
  }
  if (value5 < 0) {
    return 0;
  }
  value4 = 100;
  if (value5 < 0x65) {
    value4 = value5;
  }
  return value4;
}
