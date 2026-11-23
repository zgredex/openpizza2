// Game_FindTopScoringCompany: ported from Pizza Connection 2 at 0x4ddfb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddfb0
#include "pc2_port.h"

void * __thiscall Game_FindTopScoringCompany(void *self,int arg1,int arg2)

{
  void *this_00;
  int value1;
  void *pvVar2;
  int value3;
  int value4;
  int value5;
  void *local_8;
  
  value5 = 0;
  local_8 = (void *)0x0;
  value1 = Game_CountActiveCompanies((intptr_t)self);
  value4 = 0;
  pvVar2 = (void *)0x0;
  if (0 < value1) {
    do {
      pvVar2 = (void *)Game_GetActiveCompanyById(self,value4);
      value3 = Stats_GetMaxTimelineCount(pvVar2,arg1);
      if (value5 < value3) {
        value5 = value3;
        local_8 = pvVar2;
      }
      value4 = value4 + 1;
    } while (value4 < value1);
    pvVar2 = local_8;
  }
  if (((arg2 == 0) || (this_00 = *(void **)(arg2 + 0x14dc), this_00 == (void *)0x0)) ||
     (value1 = Stats_GetMaxTimelineCount(this_00,arg1), value1 <= value5)) {
    return pvVar2;
  }
  return this_00;
}
