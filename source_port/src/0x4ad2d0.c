// Stats_SumByStorageMode: ported from Pizza Connection 2 at 0x4ad2d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ad2d0
#include "pc2_port.h"

double __cdecl Stats_SumByStorageMode(int arg1,void *arg2)

{
  void *self;
  int value1;
  double fVar2;
  
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  switch(DAT_0057d62c) {
  case 0:
    value1 = Game_SumStatGridAll(self,arg1,8,arg2);
    return (double)value1;
  case 1:
    fVar2 = Stats_SumRecordFloatMatrix((intptr_t)self,arg1,8,(intptr_t)arg2);
    return fVar2;
  case 2:
    value1 = Game_SumPlayerMatrixValues(self,arg1,8,arg2);
    return (double)value1;
  case 3:
  case 4:
  case 5:
    return (double)-3.0;
  default:
    return (double)(float)(intptr_t)(arg2);
  }
}
