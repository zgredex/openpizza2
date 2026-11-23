// AI_SendTroublePunks: ported from Pizza Connection 2 at 0x4fdf00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fdf00
#include "pc2_port.h"

uint32_t AI_SendTroublePunks(void *arg1,int arg2)

{
  int value1;
  int value2;
  void *self;
  uint32_t uvalue3;
  uint32_t uvalue4;
  
                    /* Sends punks to cause trouble at a target restaurant. */
  value1 = Game_UpdateFreeBuildingCount(arg2);
  uvalue4 = 1;
  if (value1 < 2) {
    if (value1 == 1) {
      uvalue4 = _rand();
      uvalue4 = uvalue4 & 3;
    }
  }
  else {
    uvalue4 = Random_RangeFast(0,10);
    if ((intptr_t)uvalue4 < DAT_0057bb24) {
      return 3;
    }
    uvalue4 = Random_RangeFast(3,6);
  }
  value1 = Game_CountFreeBuildingsByType(*(void **)(arg2 + 0x16f0),0x16);
  if (0 < value1) {
    return 3;
  }
  value2 = Game_GetPlayerCity((intptr_t)arg1);
  value1 = *(int *)(value2 + 0x58);
  value2 = *(int *)(value2 + 0x40);
  if (0 < (intptr_t)uvalue4) {
    while (self = (void *)Game_FindFreeObjectByType(DAT_0057c670,0x16), self != (void *)0x0) {
      uvalue3 = Game_CanAffordWithCurrency
                        (arg1,0x17,(float)((((10 - value1) - value2) * 50000) / 100),'\x01',
                         0xffffffff);
      if ((char)uvalue3 == '\0') {
        if (uvalue4 == 0) {
          return 2;
        }
        return 1;
      }
      Object_SetDestinationAndTarget(self,1,*(int *)(arg2 + 0x16f0));
      Object_SetFieldA4Locked(self,2);
      uvalue4 = uvalue4 - 1;
      *(uint32_t *)((intptr_t)self + 0x110) = *(uint32_t *)((intptr_t)arg1 + 0x48);
      *(int *)((intptr_t)arg1 + 0x70) = *(int *)((intptr_t)arg1 + 0x70) + 1;
      if ((intptr_t)uvalue4 < 1) {
        return 1;
      }
    }
  }
  return 1;
}
