// Stats_GetLeadingCompanyForCategory: ported from Pizza Connection 2 at 0x4de030.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de030
#include "pc2_port.h"

int __thiscall Stats_GetLeadingCompanyForCategory(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  double fVar4;
  float local_8;
  int local_4;
  
  local_8 = 0.0;
  local_4 = 0;
  value1 = Game_CountActiveCompanies((intptr_t)self);
  value3 = 0;
  value2 = 0;
  if (0 < value1) {
    do {
      value2 = Game_GetActiveCompanyById(self,value3);
      fVar4 = Stats_GetMaxTimelineCategoryValue(value2,arg1);
      if ((double)local_8 < fVar4) {
        local_8 = (float)fVar4;
        local_4 = value2;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
    value2 = local_4;
  }
  if (((arg2 == 0) || (value1 = *(int *)(arg2 + 0x14dc), value1 == 0)) ||
     (fVar4 = Stats_GetMaxTimelineCategoryValue(value1,arg1), fVar4 <= (double)local_8)) {
    value1 = value2;
  }
  return value1;
}
