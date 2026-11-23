// Stats_GetFilteredFloatDelta: ported from Pizza Connection 2 at 0x4e0df0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0df0
#include "pc2_port.h"

double __thiscall Stats_GetFilteredFloatDelta(int arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  int value3;
  double fVar4;
  float local_c;
  float local_8;
  
  value1 = *(int *)(arg1 + 0x178);
  value3 = 0;
  local_c = 0.0;
  local_8 = 0.0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x164),value3,(int *)0x0);
      if ((((*(int *)(value2 + 4) != -2) || (arg3 == -2)) && (*(int *)(value2 + 8) == arg2)) &&
         ((arg3 == -1 || (arg3 == *(int *)(value2 + 4))))) {
        fVar4 = Record_SumFloatArray26(value2);
        local_c = (float)(fVar4 + (double)local_c);
        fVar4 = Object_SumFloat25(value2);
        local_8 = (float)(fVar4 + (double)local_8);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return (double)local_c - (double)local_8;
}
