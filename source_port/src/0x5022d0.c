// Game_GetMarketRank: ported from Pizza Connection 2 at 0x5022d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5022d0
#include "pc2_port.h"

uint32_t Game_GetMarketRank(void)

{
  int value1;
  int value2;
  int value3;
  
  value3 = 0;
  value2 = 0;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value2);
    if (value1 != 0) {
      value3 = value3 + *(int *)(value1 + 0x78) + *(int *)(value1 + 0x74) + *(int *)(value1 + 0x70);
    }
    value2 = value2 + 1;
  } while (value2 < 6);
  value2 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  if (0 < value3) {
    value2 = (*(int *)(value2 + 0x78) + *(int *)(value2 + 0x74) + *(int *)(value2 + 0x70)) *
            (intptr_t)(100 / (int64_t)value3);
    if (0x50 < value2) {
      return 3;
    }
    if (0x3b < value2) {
      return 2;
    }
    if (0x27 < value2) {
      return 1;
    }
  }
  return 0;
}
