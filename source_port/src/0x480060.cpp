// Game_UpdateFreeBuildingCount: ported from Pizza Connection 2 at 0x480060.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480060
#include "pc2_port.h"

void __fastcall Game_UpdateFreeBuildingCount(int arg1)

{
  Game_CountFreeBuildingsByType(*(void **)(arg1 + 0x16f0),0x17);
  return;
}
