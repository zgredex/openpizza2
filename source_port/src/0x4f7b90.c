// AI_ComputePlanScores: ported from Pizza Connection 2 at 0x4f7b90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7b90
#include "pc2_port.h"

int AI_ComputePlanScores(int arg1,int *arg2,int *arg3,int arg4)

{
  uint16_t uvalue1;
  int *ptr2;
  int value3;
  int value4;
  int value5;
  int value6;
  int *ptr7;
  int64_t lvalue8;
  int64_t lvalue9;
  
  ptr2 = arg2;
  uvalue1 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  value5 = 0;
  *arg2 = 0;
  ptr7 = arg3;
  for (value3 = arg4; value3 != 0; value3 = value3 + -1) {
    *ptr7 = 0;
    ptr7 = ptr7 + 1;
  }
  value6 = uvalue1 - 1;
  value3 = *(int *)(arg1 + 0x40);
  if (-1 < value6) {
    arg2 = arg3;
    while (value3 <= value6) {
      Stats_SumFilteredFloats(arg1,-1,-1,value6);
      lvalue8 = __ftol();
      Stats_SumFilteredFloats2(arg1,-1,-1,value6);
      lvalue9 = __ftol();
      value4 = (intptr_t)lvalue8 - (intptr_t)lvalue9;
      *arg2 = value4;
      arg2 = arg2 + 1;
      value5 = value5 + 1;
      *ptr2 = *ptr2 + value4;
      if (value5 == arg4) {
        return value5;
      }
      value6 = value6 + -1;
      if (value6 < 0) {
        return value5;
      }
    }
  }
  return value5;
}
