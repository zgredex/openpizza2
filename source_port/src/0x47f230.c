// Game_ComputeCityPriceShare: ported from Pizza Connection 2 at 0x47f230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f230
#include "pc2_port.h"

double __thiscall Game_ComputeCityPriceShare(int arg1,int arg2,float *arg3)

{
  float fVar1;
  int value2;
  int value3;
  double fVar4;
  double extraout_ST0;
  int64_t lvalue5;
  
  value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0x30));
  value2 = Game_GetPlayerCity(value2);
  value3 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x74),*(int *)(arg2 + 4),(int *)0x0);
  fVar4 = Game_ComputePrice(value3,value2);
  fVar1 = (float)fVar4;
  if (arg3 != (float *)0x0) {
    *arg3 = fVar1;
  }
  value2 = *(int *)(arg2 + 0xc);
  if (value2 == 100) {
    return (double)0.0;
  }
  if (value2 < 1) {
    if (arg3 != (float *)0x0) {
      *arg3 = 0.0;
    }
    return (double)fVar1;
  }
  fVar4 = ((double)fVar1 - (double)value2 * (double)0.01 * (double)fVar1) * (double)0.25;
  if (arg3 != (float *)0x0) {
    lvalue5 = __ftol();
    *arg3 = (float)((double)(intptr_t)lvalue5 - extraout_ST0);
    fVar4 = extraout_ST0;
  }
  return fVar4;
}
