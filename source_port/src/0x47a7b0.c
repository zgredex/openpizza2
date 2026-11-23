// Stats_GetMaxGroupScore: ported from Pizza Connection 2 at 0x47a7b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a7b0
#include "pc2_port.h"

double __fastcall Stats_GetMaxGroupScore(int arg1)

{
  uint16_t uvalue1;
  uint32_t uvalue2;
  int value3;
  int value4;
  double fVar5;
  float local_4;
  
  local_4 = 0.0;
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
      fVar5 = Stats_GetGroupScore(arg1,value3,value4);
      if ((double)local_4 < fVar5) {
        local_4 = (float)fVar5;
      }
      value3 = value3 + 1;
    } while (value3 < 7);
    value4 = value4 + 1;
  } while (value4 < (intptr_t)uvalue2);
  return (double)local_4;
}
