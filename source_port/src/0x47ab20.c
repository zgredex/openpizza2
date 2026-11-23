// Game_GetMarketBonusFactor: ported from Pizza Connection 2 at 0x47ab20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ab20
#include "pc2_port.h"

double __fastcall Game_GetMarketBonusFactor(int arg1)

{
  int value1;
  int value2;
  
  if (*(int *)(arg1 + 0x14c4) == 0) {
    return (double)1.0;
  }
  value2 = *(int *)(arg1 + 0x14c0) >> 1;
  if (value2 < 0) {
    value1 = Rating_GetComposite(*(int *)(arg1 + 0x14c4));
    if (value1 / 0x14 < 1) {
      value1 = Rating_GetComposite(*(int *)(arg1 + 0x14c4));
      value1 = value1 / 0x14;
    }
    else {
      value1 = 0;
    }
    value2 = value2 + value1;
  }
  return (double)(value2 + 100) * (double)0.01;
}
