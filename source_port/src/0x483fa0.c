// Game_MapPlayerStatusToAnimation: ported from Pizza Connection 2 at 0x483fa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483fa0
#include "pc2_port.h"

uint32_t Game_MapPlayerStatusToAnimation(int arg1)

{
  char cVar1;
  
  cVar1 = Game_GetPlayerByte8(arg1);
  if (cVar1 == '\x05') {
    return 0x20;
  }
  if (cVar1 == '\a') {
    return 0x16;
  }
  return 0xb;
}
