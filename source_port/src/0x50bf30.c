// Game_GetPlayerEconomyModifier: ported from Pizza Connection 2 at 0x50bf30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50bf30
#include "pc2_port.h"

void __fastcall Game_GetPlayerEconomyModifier(int arg1)

{
  void *self;
  
  self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0x110));
  Economy_GetModifier(self,0x1e,0);
  return;
}
