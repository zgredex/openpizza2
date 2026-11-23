// Game_IsRatingBelowThreshold: ported from Pizza Connection 2 at 0x480b40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480b40
#include "pc2_port.h"

bool __thiscall Game_IsRatingBelowThreshold(void *self,int arg1)

{
  int value1;
  int local_20 [8];
  
  local_20[0] = 0xe;
  local_20[1] = 0x10;
  local_20[2] = 0x14;
  local_20[3] = 0xd;
  local_20[4] = 0x14;
  local_20[5] = 0x14;
  local_20[6] = 0x18;
  local_20[7] = 0x11;
  value1 = City_GetProductPriceLevel(self);
  return local_20[arg1] < value1;
}
