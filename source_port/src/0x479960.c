// Map_ComputeBuildableAverage: ported from Pizza Connection 2 at 0x479960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479960
#include "pc2_port.h"

void __thiscall Map_ComputeBuildableAverage(void *self,int arg1)

{
  int value1;
  int value2;
  short *psVar3;
  int value4;
  int64_t lvalue5;
  int local_c;
  float local_8;
  
  value2 = 0;
  local_8 = 0.0;
  local_c = 0;
  psVar3 = (short *)(arg1 + 0xc);
  do {
    value4 = 0;
    do {
      if ((((psVar3[-4] == 1) && (*psVar3 == 1)) && (psVar3[0x140] == 1)) && (psVar3[0x13c] == 1)) {
        value1 = Map_CountBuildableNeighbors(value2,value4,arg1);
        local_c = local_c + 1;
        local_8 = (float)value1 + local_8;
      }
      value4 = value4 + 1;
      psVar3 = psVar3 + 4;
    } while (value4 < 0x50);
    value2 = value2 + 1;
  } while (value2 < 0x50);
  if (local_c < 1) {
    *(uint32_t *)((intptr_t)self + 0x1860) = 0;
  }
  else {
    lvalue5 = Math_RoundFloat(local_8 / (float)local_c);
    *(int *)((intptr_t)self + 0x1860) = (intptr_t)lvalue5;
  }
  if (*(int *)((intptr_t)self + 0x1860) < 0) {
    *(uint32_t *)((intptr_t)self + 0x1860) = 0;
  }
  if (8 < *(int *)((intptr_t)self + 0x1860)) {
    *(uint32_t *)((intptr_t)self + 0x1860) = 8;
  }
  return;
}
