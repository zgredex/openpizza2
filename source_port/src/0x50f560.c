// Game_GetPlayerTotalValue: ported from Pizza Connection 2 at 0x50f560.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50f560
#include "pc2_port.h"

int __fastcall Game_GetPlayerTotalValue(int arg1)

{
  int value1;
  
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 8));
  return *(int *)(value1 + 0x88) + *(int *)(value1 + 0x78) + *(int *)(value1 + 0x74);
}
