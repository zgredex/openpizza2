// Stats_GetLevelFromTenCounters: ported from Pizza Connection 2 at 0x502360.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502360
#include "pc2_port.h"

uint8_t Stats_GetLevelFromTenCounters(void)

{
  int value1;
  int value2;
  
  value2 = 0;
  value1 = 0;
  do {
    value2 = value2 + (uint32_t)*(uint8_t *)(*(int *)(DAT_0057c670 + 0x200 +
                                            *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0xe4 + value1);
    value1 = value1 + 1;
  } while (value1 < 10);
  if (5 < value2) {
    return 3;
  }
  if (value2 < 4) {
    return 0 < value2;
  }
  return 2;
}
