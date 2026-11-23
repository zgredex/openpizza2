// AI_SendGraffitiPunk: ported from Pizza Connection 2 at 0x4fde00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fde00
#include "pc2_port.h"

uint32_t AI_SendGraffitiPunk(void *arg1,int arg2)

{
  void *self;
  int value1;
  uint32_t uvalue2;
  
                    /* Sends a punk to spray graffiti at a target restaurant. */
  self = (void *)Game_FindFreeObjectByType(DAT_0057c670,0x16);
  if (self == (void *)0x0) {
    return 3;
  }
  value1 = Game_UpdateFreeBuildingCount(arg2);
  if (0 < value1) {
    uvalue2 = Random_RangeFast(0,10);
    if ((intptr_t)uvalue2 < DAT_0057bb24) {
      return 3;
    }
  }
  value1 = Game_CountFreeBuildingsByType(*(void **)(arg2 + 0x16f0),0x16);
  if (value1 < 1) {
    value1 = Game_GetPlayerCity((intptr_t)arg1);
    Game_CanAffordWithCurrency
              (arg1,0x17,
               (float)((((10 - *(int *)(value1 + 0x58)) - *(int *)(value1 + 0x40)) * 10000) / 100),
               '\x01',0xffffffff);
    Object_SetDestinationAndTarget(self,1,*(int *)(arg2 + 0x16f0));
    Object_SetFieldA4Locked(self,1);
    *(uint32_t *)((intptr_t)self + 0x110) = *(uint32_t *)((intptr_t)arg1 + 0x48);
    *(int *)((intptr_t)arg1 + 0x70) = *(int *)((intptr_t)arg1 + 0x70) + 1;
    return 1;
  }
  return 3;
}
