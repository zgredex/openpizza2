// MapObject_SetCityFromPlayer: ported from Pizza Connection 2 at 0x4d3020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3020
#include "pc2_port.h"

void __thiscall MapObject_SetCityFromPlayer(void *self,void *arg1,int arg2)

{
  int value1;
  
  *(int *)((intptr_t)self + 8) = arg2;
  if (arg2 == -1) {
    Record_SetField2D0C(arg1,*(int *)((intptr_t)self + 0x24),0);
    return;
  }
  value1 = Game_GetPlayerBySlot(DAT_0057c670,arg2);
  value1 = Game_FindCityIndex(value1);
  Record_SetField2D0C(arg1,*(int *)((intptr_t)self + 0x24),(char)value1 + '\x01');
  return;
}
