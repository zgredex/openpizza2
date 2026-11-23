// Stats_ComputeOccupancyPercent: ported from Pizza Connection 2 at 0x4793b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4793b0
#include "pc2_port.h"

int __thiscall Stats_ComputeOccupancyPercent(void *self,int arg1)

{
  short svalue1;
  short *psVar2;
  int value3;
  int value4;
  int value5;
  int value6;
  int64_t lvalue7;
  
  value4 = 0;
  value3 = 0;
  psVar2 = (short *)(arg1 + 4);
  value6 = 0x50;
  do {
    value5 = 0x50;
    do {
      svalue1 = *psVar2;
      if ((svalue1 < -3) || ((-1 < svalue1 && (svalue1 != 9)))) {
        if (svalue1 == 0) {
          value3 = value3 + 1;
        }
        value4 = value4 + 1;
      }
      psVar2 = psVar2 + 4;
      value5 = value5 + -1;
    } while (value5 != 0);
    value6 = value6 + -1;
  } while (value6 != 0);
  if (value3 < 1) {
    *(uint32_t *)((intptr_t)self + 0x1858) = 100;
  }
  else {
    lvalue7 = __ftol();
    *(int *)((intptr_t)self + 0x1858) = (intptr_t)lvalue7;
  }
  Clamp_0_100((int *)((intptr_t)self + 0x1858));
  return value4;
}
