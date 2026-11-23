// Stats_SumGroupScores: ported from Pizza Connection 2 at 0x4de4f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de4f0
#include "pc2_port.h"

double __thiscall Stats_SumGroupScores(int arg1,uint32_t arg2,int arg3,int arg4)

{
  int value1;
  int value2;
  int value3;
  double fVar4;
  float local_4;
  
  local_4 = 0.0;
  if (arg4 != 0) {
    fVar4 = Stats_GetGroupScore(arg4,arg2,arg3);
    return fVar4;
  }
  value1 = *(int *)(arg1 + 0x15c);
  value3 = 0;
  if (value1 < 1) {
    return (double)0.0;
  }
  do {
    value2 = IDMap_Lookup((void *)(arg1 + 0x148),value3,(int *)0x0);
    fVar4 = Stats_GetGroupScore(value2,arg2,arg3);
    value3 = value3 + 1;
    local_4 = (float)(fVar4 + (double)local_4);
  } while (value3 < value1);
  return (double)local_4;
}
