// Game_ComputeCompanySharePercent: ported from Pizza Connection 2 at 0x4ddf10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddf10
#include "pc2_port.h"

double __thiscall Game_ComputeCompanySharePercent(void *arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  double fVar5;
  float local_4;
  
  uvalue4 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  local_4 = 0.0;
  value1 = Game_CountActiveCompanies((intptr_t)arg1);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = Game_GetActiveCompanyById(arg1,value3);
      fVar5 = Stats_SumValuesByCategory(value2,uvalue4,arg3);
      value3 = value3 + 1;
      local_4 = (float)(fVar5 + (double)local_4);
    } while (value3 < value1);
    if (local_4 != 0.0) {
      fVar5 = Stats_SumValuesByCategory(arg2,uvalue4,arg3);
      return (fVar5 / (double)local_4) * (double)100.0;
    }
  }
  return (double)0.0;
}
