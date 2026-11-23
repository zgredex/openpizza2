// Stats_GetLevelFromFourCounters: ported from Pizza Connection 2 at 0x5021d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5021d0
#include "pc2_port.h"

uint8_t Stats_GetLevelFromFourCounters(void)

{
  int value1;
  
  value1 = *(int *)(DAT_0057c670 + 0x224 + *(int *)(DAT_0057c670 + 0x2f0) * 4);
  value1 = *(int *)(value1 + 0x5c) + *(int *)(value1 + 0x54) + *(int *)(value1 + 0x44) +
          *(int *)(value1 + 0x3c);
  if (4 < value1) {
    return 3;
  }
  if (value1 < 3) {
    return 0 < value1;
  }
  return 2;
}
