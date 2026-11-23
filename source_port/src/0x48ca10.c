// Game_GetPlayerValueSharePercent: ported from Pizza Connection 2 at 0x48ca10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48ca10
#include "pc2_port.h"

int64_t __thiscall Game_GetPlayerValueSharePercent(void *self,int arg1)

{
  float fVar1;
  int value2;
  float *fptr3;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  uint32_t uvalue4;
  int value5;
  double fVar6;
  int64_t lvalue7;
  float local_18 [6];
  
  local_18[0] = 0.0;
  local_18[1] = 0.0;
  local_18[2] = 0.0;
  local_18[3] = 0.0;
  local_18[4] = 0.0;
  local_18[5] = 0.0;
  value5 = 0;
  fptr3 = local_18;
  do {
    value2 = Game_GetPlayerBySlot(self,value5);
    uvalue4 = extraout_EDX;
    if (value2 != 0) {
      fVar6 = Stats_SumFilteredFloats3(value2,-1,-1,-1);
      *fptr3 = (float)fVar6;
      uvalue4 = extraout_EDX_00;
    }
    value5 = value5 + 1;
    fptr3 = fptr3 + 1;
  } while (value5 < 6);
  value5 = 6;
  fptr3 = local_18;
  fVar1 = 0.0;
  do {
    fVar1 = fVar1 + *fptr3;
    fptr3 = fptr3 + 1;
    value5 = value5 + -1;
  } while (value5 != 0);
  if ((fVar1 == 0.0) || (local_18[arg1] == 0.0)) {
    return (uint64_t)uvalue4 << 0x20;
  }
  lvalue7 = __ftol();
  return lvalue7;
}
