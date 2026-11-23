// Stats_GetMaxDailyFilteredSum: ported from Pizza Connection 2 at 0x4de360.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de360
#include "pc2_port.h"

double __thiscall Stats_GetMaxDailyFilteredSum(int arg1,int arg2)

{
  uint16_t uvalue1;
  int value2;
  int value3;
  int value4;
  int value5;
  double fVar6;
  float local_14;
  float local_10;
  int local_c;
  uint32_t local_8;
  
  local_14 = 0.0;
  uvalue1 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  local_8 = (uint32_t)uvalue1;
  if (100 < uvalue1) {
    local_8 = 100;
  }
  local_c = 0;
  if (local_8 == 0) {
    return (double)0.0;
  }
  do {
    if (arg2 == 0) {
      value4 = *(int *)(arg1 + 0x15c);
      value5 = 0;
      do {
        value3 = 0;
        local_10 = 0.0;
        if (0 < value4) {
          do {
            value2 = IDMap_Lookup((void *)(arg1 + 0x148),value3,(int *)0x0);
            fVar6 = Stats_SumFilteredFloats(value2,value5,-1,local_c);
            value3 = value3 + 1;
            local_10 = (float)(fVar6 + (double)local_10);
          } while (value3 < value4);
        }
        if (local_14 < local_10) {
          local_14 = local_10;
        }
        value5 = value5 + 1;
      } while (value5 < 9);
    }
    else {
      value4 = 0;
      do {
        fVar6 = Stats_SumFilteredFloats(arg2,value4,-1,local_c);
        if ((double)local_14 < fVar6) {
          local_14 = (float)fVar6;
        }
        value4 = value4 + 1;
      } while (value4 < 9);
    }
    local_c = local_c + 1;
  } while (local_c < (intptr_t)local_8);
  return (double)local_14;
}
