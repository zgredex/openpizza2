// Game_GetObjectValue: ported from Pizza Connection 2 at 0x4de570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de570
#include "pc2_port.h"

double __thiscall Game_GetObjectValue(int arg1,int arg2)

{
  uint16_t uvalue1;
  uint32_t uvalue2;
  int value3;
  int value4;
  double fVar5;
  float local_4;
  
  local_4 = 0.0;
  if (arg2 != 0) {
    fVar5 = Stats_GetMaxGroupScore(arg2);
    return fVar5;
  }
  uvalue1 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uvalue2 = (uint32_t)uvalue1;
  if (100 < uvalue1) {
    uvalue2 = 100;
  }
  value4 = 0;
  if (uvalue2 == 0) {
    return (double)0.0;
  }
  do {
    value3 = 0;
    do {
      fVar5 = Stats_SumGroupScores(arg1,value3,value4,0);
      if ((double)local_4 < fVar5) {
        local_4 = (float)fVar5;
      }
      value3 = value3 + 1;
    } while (value3 < 7);
    value4 = value4 + 1;
  } while (value4 < (intptr_t)uvalue2);
  return (double)local_4;
}
