// Stats_ComputeCategory7: ported from Pizza Connection 2 at 0x502180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502180
#include "pc2_port.h"

uint8_t Stats_ComputeCategory7(void)

{
  int value1;
  
  value1 = *(int *)(DAT_0057c670 + 0x224 + *(int *)(DAT_0057c670 + 0x2f0) * 4);
  value1 = *(int *)(value1 + 100) + *(int *)(value1 + 0x60) + *(int *)(value1 + 0x4c) +
          *(int *)(value1 + 0x48);
  if (4 < value1) {
    return 3;
  }
  if (value1 < 3) {
    return 0 < value1;
  }
  return 2;
}
