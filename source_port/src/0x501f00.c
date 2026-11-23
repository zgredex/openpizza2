// Stats_GetCityShareRank: ported from Pizza Connection 2 at 0x501f00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501f00
#include "pc2_port.h"

uint32_t Stats_GetCityShareRank(void)

{
  int value1;
  int value2;
  int value3;
  
  value2 = 0;
  value3 = 0;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value3);
    if (value1 != 0) {
      value1 = Game_GetPlayerCity(value1);
      value2 = value2 + *(int *)(value1 + 0xa0);
    }
    value3 = value3 + 1;
  } while (value3 < 6);
  value3 = Game_GetPlayerCity(*(int *)((intptr_t)DAT_0057c670 +
                                     *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  if (0 < value2) {
    value2 = *(int *)(value3 + 0xa0) * (intptr_t)(100 / (int64_t)value2);
    if (0x3c < value2) {
      return 3;
    }
    if (0x30 < value2) {
      return 2;
    }
    if (value2 != 0) {
      return 1;
    }
  }
  return 0;
}
