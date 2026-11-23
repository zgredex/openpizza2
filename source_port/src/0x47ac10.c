// Game_GetRatingMultiplier: ported from Pizza Connection 2 at 0x47ac10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ac10
#include "pc2_port.h"

double __fastcall Game_GetRatingMultiplier(int arg1)

{
  int value1;
  int local_4;
  
  if (*(int *)(arg1 + 0x14c4) == 0) {
    return (double)1.0;
  }
  local_4 = *(int *)(arg1 + 0x14d4) - *(int *)(arg1 + 0x14d0) >> 1;
  if (local_4 < 0) {
    value1 = Rating_GetComposite(*(int *)(arg1 + 0x14c4));
    if (value1 / 0x14 < 1) {
      value1 = Rating_GetComposite(*(int *)(arg1 + 0x14c4));
      value1 = value1 / 0x14;
    }
    else {
      value1 = 0;
    }
    local_4 = local_4 + value1;
  }
  return ((double)local_4 + (double)100.0) * (double)0.01;
}
