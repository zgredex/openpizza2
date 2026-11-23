// Player_ComputeNetStatTotal: ported from Pizza Connection 2 at 0x4e3780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3780
#include "pc2_port.h"

double __fastcall Player_ComputeNetStatTotal(int arg1)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  int value4;
  double fVar5;
  double fVar6;
  float local_c;
  int local_4;
  
  uvalue3 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  local_c = 0.0;
  local_4 = 0;
  do {
    uvalue3 = uvalue3 - 1;
    if ((intptr_t)uvalue3 < 0) break;
    value4 = 0;
    value1 = *(int *)(arg1 + 0x15c);
    if (0 < value1) {
      do {
        value2 = IDMap_Lookup((void *)(arg1 + 0x148),value4,(int *)0x0);
        fVar5 = Stats_SumFilteredFloats(value2,-1,-1,uvalue3);
        fVar6 = Stats_SumFilteredFloats2(value2,-1,-1,uvalue3);
        value4 = value4 + 1;
        local_c = (float)((double)(float)(fVar5 + (double)local_c) - fVar6);
      } while (value4 < value1);
    }
    local_4 = local_4 + 1;
  } while (local_4 < 4);
  return (double)local_c;
}
