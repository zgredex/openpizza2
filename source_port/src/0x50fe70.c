// Game_GetPlayerWeightedStat: ported from Pizza Connection 2 at 0x50fe70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fe70
#include "pc2_port.h"

double __fastcall Game_GetPlayerWeightedStat(int arg1)

{
  int *ptr1;
  int *ptr2;
  int value3;
  double fVar4;
  
  fVar4 = (double)0.0;
  ptr1 = (int *)(arg1 + 100);
  value3 = 0x56;
  ptr2 = (int *)(DAT_0057c670 + 0xa8);
  do {
    if (0 < *ptr1) {
      fVar4 = (double)*(double *)(*ptr2 + 0xc0) * (double)0.001 * (double)*ptr1 + fVar4;
    }
    ptr2 = ptr2 + 1;
    ptr1 = ptr1 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  return fVar4;
}
