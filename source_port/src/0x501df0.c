// Game_GetPlayerStaffBand: ported from Pizza Connection 2 at 0x501df0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501df0
#include "pc2_port.h"

uint8_t Game_GetPlayerStaffBand(void)

{
  int value1;
  
  value1 = *(int *)(DAT_0057c670 + 0x224 + *(int *)(DAT_0057c670 + 0x2f0) * 4);
  value1 = *(int *)(value1 + 0x68) + *(int *)(value1 + 0x58) + *(int *)(value1 + 0x50) +
          *(int *)(value1 + 0x40);
  if (4 < value1) {
    return 3;
  }
  if (value1 < 3) {
    return 0 < value1;
  }
  return 2;
}
