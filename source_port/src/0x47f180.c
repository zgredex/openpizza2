// Game_GetPenaltyValues: ported from Pizza Connection 2 at 0x47f180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f180
#include "pc2_port.h"

void __fastcall Game_GetPenaltyValues(void *arg1)

{
  int value1;
  void *self;
  uint32_t uvalue2;
  int value3;
  int local_14 [5];
  
  local_14[3] = 0;
  value3 = 0;
  local_14[4] = 0;
  local_14[0] = 0xb;
  local_14[1] = 9;
  local_14[2] = 7;
  if (0 < *(int *)((intptr_t)arg1 + 0x170c)) {
    do {
      self = (void *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x16f8),value3,(int *)0x0);
      IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)((intptr_t)self + 4),(int *)0x0);
      value1 = *(int *)((intptr_t)self + 0xc);
      uvalue2 = Game_GetRecordByte14((intptr_t)self);
      uvalue2 = value1 - local_14[uvalue2];
      if ((intptr_t)uvalue2 < 0) {
        uvalue2 = 0;
        Game_UpdateObject(self,arg1);
      }
      Game_SetModeByte(self,uvalue2);
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)arg1 + 0x170c));
  }
  return;
}
