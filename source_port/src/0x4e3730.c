// Game_GetLevelReward: ported from Pizza Connection 2 at 0x4e3730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3730
#include "pc2_port.h"

uint32_t __thiscall Game_GetLevelReward(void *self,int arg1)

{
  int value1;
  
  value1 = Game_GetPlayerFieldC20((intptr_t)self);
  if (value1 < 3) {
    return 0;
  }
  if (arg1 == 0x1d) {
    return *(uint32_t *)(&DAT_0056d104 + value1 * 4);
  }
  if (arg1 == 0x1e) {
    return *(uint32_t *)(&DAT_0056d114 + value1 * 4);
  }
  if (arg1 == 0x1f) {
    return *(uint32_t *)(&DAT_0056d124 + value1 * 4);
  }
  return 0;
}
