// BuildingValue_ApplyUpgrade: ported from Pizza Connection 2 at 0x4d43a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d43a0
#include "pc2_port.h"

void __thiscall BuildingValue_ApplyUpgrade(void *self,uint32_t arg1)

{
  int value1;
  uint32_t uvalue2;
  void *this_00;
  int value3;
  uint16_t uvalue4;
  
  switch(arg1) {
  case 0:
    *(uint32_t *)((intptr_t)self + 0x14) = 0x14;
    break;
  case 1:
    value3 = *(int *)((intptr_t)self + 0x3c);
    value1 = Game_GetCostForType(self,1);
    Person_SetPerformance(self,value1 + value3);
    value3 = *(int *)((intptr_t)self + 0xc) + 0x14;
    if (100 < value3) {
      value3 = 100;
    }
    Person_SetMotivation(self,value3);
    break;
  case 2:
    *(uint32_t *)((intptr_t)self + 0x20) = 0x14;
    break;
  case 3:
    *(uint32_t *)((intptr_t)self + 0x18) = 0x14;
  }
  uvalue2 = State_HasFlags((intptr_t)self);
  if ((((char)uvalue2 != '\0') || (uvalue2 = State_HasPositive((intptr_t)self), (char)uvalue2 != '\0')) &&
     (this_00 = (void *)Game_GetRecordByField814((intptr_t)self), this_00 != (void *)0x0)) {
    uvalue2 = State_HasFlags((intptr_t)self);
    if ((char)uvalue2 == '\0') {
      uvalue4 = 0x27;
    }
    else {
      uvalue4 = 0x21;
    }
    UI_SetChildState(this_00,uvalue4);
    if (((*(int *)((intptr_t)this_00 + 0x74) != 0) && (value3 = *(int *)((intptr_t)this_00 + 0xf4), value3 != 0)
        ) && (value3 = Game_GetPlayerSubmapValue
                                (DAT_0057c670,*(int *)(value3 + 8),*(int *)(value3 + 0x2c)),
             value3 != 0)) {
      Game_UpdateObjectRatingScales(value3);
    }
  }
  return;
}
