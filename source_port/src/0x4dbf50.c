// Game_GetPlayerSupplyScore: ported from Pizza Connection 2 at 0x4dbf50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dbf50
#include "pc2_port.h"

int __thiscall Game_GetPlayerSupplyScore(void *self,int arg1)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  int value4;
  
  value4 = *(int *)((intptr_t)self + arg1 * 4 + 0xc98);
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,arg1);
  value1 = Game_CountActiveObjectsByType(this_00,0x1e);
  value2 = Game_CountActiveObjectsByType(this_00,0x1d);
  value3 = Game_GetPlayerCity((intptr_t)this_00);
  value4 = value4 + ((*(int *)(value3 + 0x60) + *(int *)(value3 + 0x48)) * 3 - (value1 + value2));
  if (100 < value4) {
    return 100;
  }
  if (value4 < 0) {
    return 0;
  }
  return value4;
}
