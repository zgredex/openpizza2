// Calendar_IsSelectedDate: ported from Pizza Connection 2 at 0x4aaac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aaac0
#include "pc2_port.h"

uint32_t Calendar_IsSelectedDate(void)

{
  uint32_t uvalue1;
  
  uvalue1 = *(uint32_t *)(DAT_0057c670 + 0x94);
  if ((DAT_00569354 == *(uint16_t *)(uvalue1 + 4)) &&
     ((DAT_0057d5c8 == *(uint8_t *)(uvalue1 + 8) + 1 || (uvalue1 = DAT_0057d5c8, DAT_0057d5c8 == 0)))) {
    return CONCAT31((int3)(DAT_0057d5c8 >> 8),1);
  }
  return uvalue1 & 0xffffff00;
}
