// Calendar_InterpolateMonthlyValue: ported from Pizza Connection 2 at 0x4dc6a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dc6a0
#include "pc2_port.h"

int __fastcall Calendar_InterpolateMonthlyValue(int arg1)

{
  uint8_t flag1;
  uint32_t uvalue2;
  int value3;
  int value4;
  
  flag1 = *(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 7);
  uvalue2 = (uint32_t)*(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 8);
  if (flag1 < 0xc) {
    value4 = *(int *)(arg1 + 0xa4 + (uvalue2 - 1 & 3) * 4) + -6;
    value3 = ((*(int *)(arg1 + 0xa4 + uvalue2 * 4) - value4) + 6) * (uint32_t)flag1;
    value3 = value3 / 6 + (value3 >> 0x1f);
    return ((value3 >> 1) - (value3 >> 0x1f)) + value4;
  }
  value4 = *(int *)(arg1 + 0xa4 + uvalue2 * 4);
  value3 = value4 + 6;
  value4 = ((value4 - value3) + -6) * (flag1 - 0xc);
  value4 = value4 / 6 + (value4 >> 0x1f);
  return ((value4 >> 1) - (value4 >> 0x1f)) + value3;
}
