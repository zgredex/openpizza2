// Game_GetNextPlayerSlot: ported from Pizza Connection 2 at 0x486e60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486e60
#include "pc2_port.h"

int __thiscall Game_GetNextPlayerSlot(void *self,int arg1,char arg2)

{
  int value1;
  int value2;
  int value3;
  
  value3 = arg1 + 1;
  value1 = Game_GetPlayerCount((intptr_t)self);
  if (value3 < value1) {
    do {
      value1 = Game_GetPlayerBySlot(self,value3);
      if ((value1 == 0) ||
         ((arg2 == '\0' &&
          (value1 = *(int *)(value1 + 0x48), value2 = Game_GetCurrentPlayerCompanyName((intptr_t)self),
          value1 != value2)))) {
        return value3;
      }
      value3 = value3 + 1;
      value1 = Game_GetPlayerCount((intptr_t)self);
    } while (value3 < value1);
  }
  return -1;
}
