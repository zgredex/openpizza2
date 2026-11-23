// Game_UpdateAllPlayers: ported from Pizza Connection 2 at 0x4899d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4899d0
#include "pc2_port.h"

void __thiscall Game_UpdateAllPlayers(void *self,uint32_t arg1,void *arg2)

{
  int value1;
  int value2;
  int value3;
  int local_10;
  int local_c;
  
  if (*(int *)((intptr_t)arg2 + 0xc) != 0x10) {
    local_10 = 0;
    do {
      value1 = Game_GetPlayerBySlot(self,local_10);
      if ((value1 != 0) &&
         (value1 = Game_GetPlayerBySlot(self,local_10), *(int *)(value1 + 0x1e4) != 0)) {
        value1 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
        if (value1 == 0) {
          return;
        }
        local_c = 0;
        if (0 < *(int *)(value1 + 0xfc0)) {
          do {
            value2 = IDMap_Lookup((void *)(value1 + 0xfac),local_c,(int *)0x0);
            if ((((*(int *)(value2 + 4) == 0x1b) || (*(int *)(value2 + 4) == 0xf)) &&
                (*(int *)(value2 + 0x28) == local_10)) &&
               ((*(int *)(value2 + 0x74) != 0 &&
                (value3 = Game_GetAdjustedValue(*(int *)(value2 + 0x74)), 0 < value3)))) {
              value3 = Game_GetPlayerBySlot(self,*(int *)(value2 + 8));
              Game_FindCityIndex(value3);
              Game_GetObjectCenterY(value2);
              Game_GetObjectBottom(value2);
              Map_DrawPlayerMarkerRing(arg2);
            }
            local_c = local_c + 1;
          } while (local_c < *(int *)(value1 + 0xfc0));
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < 6);
  }
  return;
}
