// Game_GetRatingPercent: ported from Pizza Connection 2 at 0x48c7b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c7b0
#include "pc2_port.h"

int __thiscall Game_GetRatingPercent(void *self,int arg1,int arg2)

{
  int value1;
  int64_t lvalue2;
  int local_20 [8];
  
  local_20[0] = 0x14;
  local_20[1] = 0x1e;
  local_20[2] = 0x28;
  local_20[3] = 0x32;
  local_20[4] = 0x5a;
  local_20[5] = 0x5f;
  local_20[6] = 0x50;
  local_20[7] = 0x46;
  if (local_20[arg1] <= arg2) {
    return 100;
  }
  IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
  lvalue2 = __ftol();
  value1 = 100 - (intptr_t)lvalue2;
  if (value1 < 0) {
    value1 = 0;
  }
  return value1;
}
