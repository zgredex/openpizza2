// Game_IsCurrentPlayer: ported from Pizza Connection 2 at 0x47fd70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47fd70
#include "pc2_port.h"

bool __fastcall Game_IsCurrentPlayer(int arg1)

{
  int value1;
  
  value1 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  return value1 == *(int *)(arg1 + 0x30);
}
