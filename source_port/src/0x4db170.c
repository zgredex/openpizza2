// Market_GetPriceDelta: ported from Pizza Connection 2 at 0x4db170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4db170
#include "pc2_port.h"

uint32_t __thiscall Market_GetPriceDelta(void *self,uint32_t arg1)

{
  uint8_t flag1;
  int value2;
  
  value2 = *(int *)(DAT_0057c670 + 0xa8 + (arg1 & 0xff) * 4);
  if (value2 != 0) {
    flag1 = *(uint8_t *)(value2 + 0xa8);
    if ((flag1 != 0) && (flag1 < 7)) {
      value2 = *(int *)((intptr_t)self + (uint32_t)flag1 * 4 + 200);
      if (value2 == -1) {
        return 0xffffffd8;
      }
      return -(uint32_t)(value2 != 0) & 0x28;
    }
  }
  return 0;
}
