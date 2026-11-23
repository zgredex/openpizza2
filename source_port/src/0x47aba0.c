// Game_GetMarketBonus: ported from Pizza Connection 2 at 0x47aba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47aba0
#include "pc2_port.h"

int __fastcall Game_GetMarketBonus(int arg1)

{
  int value1;
  int value2;
  
  if (*(int *)(arg1 + 0x14c4) == 0) {
    return 0;
  }
  value2 = *(int *)(arg1 + 0x14d0) + *(int *)(arg1 + 0x14c0) >> 2;
  if (value2 < 0) {
    value1 = Rating_GetComposite(*(int *)(arg1 + 0x14c4));
    if (0 < value1 / 0x14) {
      return value2;
    }
    value1 = Rating_GetComposite(*(int *)(arg1 + 0x14c4));
    value2 = value2 + value1 / 0x14;
  }
  return value2;
}
