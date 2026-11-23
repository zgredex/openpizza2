// Stats_SumFilteredRecordFloats20: ported from Pizza Connection 2 at 0x477f50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477f50
#include "pc2_port.h"

double __thiscall Stats_SumFilteredRecordFloats20(int arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  float *fptr3;
  int value4;
  double fVar5;
  float local_8;
  
  value1 = *(int *)(arg1 + 0x14f8);
  value4 = 0;
  local_8 = 0.0;
  if (value1 < 1) {
    return (double)0.0;
  }
  do {
    value2 = IDMap_Lookup((void *)(arg1 + 0x14e4),value4,(int *)0x0);
    if (((*(int *)(value2 + 8) == arg2) || (arg2 == -1)) &&
       ((arg3 == -1 || (arg3 == *(int *)(value2 + 4))))) {
      fVar5 = (double)local_8;
      fptr3 = (float *)(value2 + 0x10);
      value2 = 0x14;
      do {
        fVar5 = fVar5 + (double)*fptr3;
        fptr3 = fptr3 + 1;
        value2 = value2 + -1;
      } while (value2 != 0);
      local_8 = (float)fVar5;
    }
    else {
      fVar5 = (double)local_8;
    }
    value4 = value4 + 1;
  } while (value4 < value1);
  return fVar5;
}
