// Game_GetPlayerWealthBand: ported from Pizza Connection 2 at 0x501ea0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501ea0
#include "pc2_port.h"

uint32_t Game_GetPlayerWealthBand(void)

{
  double dVar1;
  
  dVar1 = *(double *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x108);
  if (1000000.0 < dVar1) {
    return 3;
  }
  if (500000.0 < dVar1) {
    return 2;
  }
  if (100000.0 < dVar1) {
    return 1;
  }
  return 0;
}
