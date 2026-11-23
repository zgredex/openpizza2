// City_ResetPoliceDistrictSlot: ported from Pizza Connection 2 at 0x4dc330.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dc330
#include "pc2_port.h"

void __thiscall City_ResetPoliceDistrictSlot(void *self,int arg1,int arg2)

{
  int value1;
  uint32_t uvalue2;
  void *pvVar3;
  int value4;
  int *ptr5;
  int local_4;
  
  value4 = 0;
  local_4 = 999;
  *(uint32_t *)((intptr_t)self + arg2 * 0x18 + 0x10d0) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + arg2 * 0x18 + 0x10d4) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + arg2 * 0x18 + 0x10d8) = 0xffffffff;
  *(uint8_t *)((intptr_t)self + arg2 * 0x18 + 0x10e4) = 0;
  *(uint32_t *)((intptr_t)self + (arg2 * 3 + 0x21c) * 8) = 0;
  *(uint32_t *)((intptr_t)self + arg2 * 0x18 + 0x10dc) = 0;
  if (arg1 == 2) {
    ptr5 = (int *)((intptr_t)self + 0xc98);
    do {
      value1 = Game_GetPlayerBySlot(DAT_0057c670,value4);
      if ((value1 != 0) && (*ptr5 < local_4)) {
        value1 = Game_GetPlayerBySlot(DAT_0057c670,value4);
        if (0 < *(int *)(value1 + 0x15c)) {
          local_4 = *ptr5;
          arg2 = value4;
        }
      }
      value4 = value4 + 1;
      ptr5 = ptr5 + 1;
    } while (value4 < 6);
    if (value4 != 6) {
      value4 = Game_GetPlayerBySlot(DAT_0057c670,arg2);
      uvalue2 = Random_RangeFast(0,*(int *)(value4 + 0x15c) - 1);
      value4 = Game_GetPlayerBySlot(DAT_0057c670,arg2);
      pvVar3 = (void *)IDMap_Lookup((void *)(value4 + 0x148),uvalue2,(int *)0x0);
      City_SendPoliceToDistrict(self,pvVar3);
    }
  }
  return;
}
