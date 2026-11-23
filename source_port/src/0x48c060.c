// Market_ComputeWeightedAveragePrice: ported from Pizza Connection 2 at 0x48c060.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c060
#include "pc2_port.h"

double __thiscall Market_ComputeWeightedAveragePrice(int arg1,int *arg2,void *arg3)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int *ptr5;
  int *ptr6;
  int value7;
  int value8;
  double fVar9;
  float local_8;
  
  value7 = 0;
  if (arg2[7] == 0) {
    *arg2 = 0;
    return (double)0.0;
  }
  if (*arg2 == 0) {
    arg2[7] = 0;
    return (double)0.0;
  }
  value8 = 0;
  local_8 = 0.0;
  value3 = Game_CountActiveCompanies((intptr_t)arg3);
  if (0 < value3) {
    do {
      value4 = Game_GetActiveCompanyById(arg3,value7);
      if (value4 == 0) {
        fVar9 = (double)local_8;
      }
      else {
        fVar9 = (double)local_8;
        ptr6 = (int *)(arg1 + 0xa8);
        ptr5 = (int *)(value4 + 100);
        value4 = 0x56;
        do {
          value1 = *ptr5;
          ptr5 = ptr5 + 1;
          value8 = value8 + value1;
          value2 = *ptr6;
          ptr6 = ptr6 + 1;
          value4 = value4 + -1;
          fVar9 = (double)*(double *)(value2 + 0xc0) * (double)value1 * (double)0.001 + fVar9;
        } while (value4 != 0);
        local_8 = (float)fVar9;
      }
      value7 = value7 + 1;
    } while (value7 < value3);
    local_8 = (float)value8;
    if (value8 != 0) goto LAB_0048c128;
  }
  fVar9 = (double)100.0;
  local_8 = 2.8026e-40;
LAB_0048c128:
  arg2[7] = 0;
  value7 = *arg2;
  *arg2 = 0;
  return (fVar9 / (double)(intptr_t)local_8) * (double)(float)arg2[4] * (double)value7;
}
