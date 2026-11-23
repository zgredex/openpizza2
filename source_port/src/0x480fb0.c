// Game_ApplyDiminishingObjectBonus: ported from Pizza Connection 2 at 0x480fb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480fb0
#include "pc2_port.h"

void __fastcall Game_ApplyDiminishingObjectBonus(int arg1)

{
  if (*(int *)(arg1 + 0x187c) == 0) {
    Game_AdjustPlayerObjectPercent(*(void **)(DAT_0057c670 + 0x90),*(int *)(arg1 + 0x30),5);
    *(int *)(arg1 + 0x187c) = *(int *)(arg1 + 0x187c) + 1;
    return;
  }
  Game_AdjustPlayerObjectPercent(*(void **)(DAT_0057c670 + 0x90),*(int *)(arg1 + 0x30),1);
  *(int *)(arg1 + 0x187c) = *(int *)(arg1 + 0x187c) + 1;
  return;
}
