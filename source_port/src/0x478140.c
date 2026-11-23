// City_GetProductPriceLevel: ported from Pizza Connection 2 at 0x478140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x478140
#include "pc2_port.h"

int __fastcall City_GetProductPriceLevel(void *arg1)

{
  int value1;
  int value2;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)arg1 + 0x34),(int *)0x0);
  value1 = Calendar_InterpolateMonthlyValue(value1);
  if (0x1d < value1) {
    return 0x1e;
  }
  value2 = Game_CountRecordsByByteC(arg1,6);
  value1 = value1 + value2 * *(int *)(&DAT_005675ac + *(int *)((intptr_t)arg1 + 0x38) * 4);
  if (0x1e < value1) {
    return 0x1e;
  }
  if (value1 < 10) {
    value1 = 10;
  }
  return value1;
}
