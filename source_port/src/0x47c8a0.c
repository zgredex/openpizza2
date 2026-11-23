// Game_ComputeAverageProductQuality: ported from Pizza Connection 2 at 0x47c8a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c8a0
#include "pc2_port.h"

uint64_t __fastcall Game_ComputeAverageProductQuality(int arg1,uint32_t arg2)

{
  int value1;
  int value2;
  int value3;
  int value4;
  float *fptr5;
  int *ptr6;
  uint64_t uvalue7;
  float local_30 [6];
  int local_18 [6];
  
  value3 = 0;
  fptr5 = local_30;
  for (value2 = 6; value2 != 0; value2 = value2 + -1) {
    *fptr5 = 0.0;
    fptr5 = fptr5 + 1;
  }
  ptr6 = local_18;
  for (value2 = 6; value2 != 0; value2 = value2 + -1) {
    *ptr6 = 0;
    ptr6 = ptr6 + 1;
  }
  value2 = *(int *)(arg1 + 0x170c);
  value4 = 0;
  if (0 < value2) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x16f8),value4,(int *)0x0);
      if (value2 != 0) {
        value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(value2 + 4),(int *)0x0);
        value2 = *(int *)(value1 + 8);
        if (((0 < value2) && (value2 < 5)) && ((value2 != 3 || (*(char *)(value1 + 0x14) != '\0')))) {
          local_30[value2] = (float)*(uint8_t *)(value1 + 0x14) + local_30[value2];
          value3 = value3 + 1;
          local_18[value2] = local_18[value2] + 1;
        }
      }
      value2 = *(int *)(arg1 + 0x170c);
      value4 = value4 + 1;
    } while (value4 < value2);
    arg2 = 0;
    if (0 < value3) {
      value2 = 0;
      do {
        value3 = *(int *)((intptr_t)local_18 + value2 + 4);
        if (value3 < 1) {
          *(uint32_t *)((intptr_t)local_30 + value2 + 4) = 0;
        }
        else {
          *(float *)((intptr_t)local_30 + value2 + 4) =
               *(float *)((intptr_t)local_30 + value2 + 4) / (float)value3;
        }
        value2 = value2 + 4;
      } while (value2 < 0xd);
      uvalue7 = Math_RoundFloat((local_30[4] + local_30[3] + local_30[2] + local_30[1]) * 12.5);
      return uvalue7;
    }
  }
  return CONCAT44(arg2,value2) & 0xffffffffffffff00;
}
