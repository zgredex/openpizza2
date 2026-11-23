// Stats_SumRecordFloatsByType: ported from Pizza Connection 2 at 0x4e0920.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0920
#include "pc2_port.h"

double __thiscall Stats_SumRecordFloatsByType(int arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  float *fptr3;
  int value4;
  double fVar5;
  float local_4;
  
  fVar5 = (double)0.0;
  local_4 = (float)fVar5;
  value1 = *(int *)(arg1 + 0x178);
  value4 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x164),value4,(int *)0x0);
      if (arg3 == *(int *)(value2 + 4)) {
        if (arg2 == -1) {
          fVar5 = (double)local_4;
          fptr3 = (float *)(value2 + 0x10);
          value2 = 0x1a;
          do {
            fVar5 = fVar5 + (double)*fptr3;
            fptr3 = fptr3 + 1;
            value2 = value2 + -1;
          } while (value2 != 0);
          local_4 = (float)fVar5;
        }
        else {
          fVar5 = (double)*(float *)(value2 + 0x10 + arg2 * 4) + (double)local_4;
          local_4 = (float)fVar5;
        }
      }
      else {
        fVar5 = (double)local_4;
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  value1 = *(int *)(arg1 + 0x15c);
  value4 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x148),value4,(int *)0x0);
      fVar5 = Stats_SumFilteredFloats(value2,arg2,-1,arg3);
      value4 = value4 + 1;
      local_4 = (float)(fVar5 + (double)local_4);
    } while (value4 < value1);
    fVar5 = (double)local_4;
  }
  return fVar5;
}
