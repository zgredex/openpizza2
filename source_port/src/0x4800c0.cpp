// Game_CountFreeBuildingsTypeD: ported from Pizza Connection 2 at 0x4800c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4800c0
#include "pc2_port.h"

void __fastcall Game_CountFreeBuildingsTypeD(int arg1)

{
  Game_CountFreeBuildingsByType(*(void **)(arg1 + 0x16f0),0xd);
  return;
}
