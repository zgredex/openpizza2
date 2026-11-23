// Game_HandleQueryEndSession: ported from Pizza Connection 2 at 0x4a21a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a21a0
#include "pc2_port.h"

void Game_HandleQueryEndSession(void)

{
  void *pvVar1;
  
  if (DAT_00568d00 == -1) {
    Game_SetViewMode(DAT_0057c670,7,0);
    pvVar1 = DAT_0057c670;
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2d4) = *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2b4);
    *(uint32_t *)((intptr_t)pvVar1 + 0x2b4) = 2;
    return;
  }
  SaveGame_Write(DAT_0057c670,(char *)&DAT_0057cfd0,DAT_00568d00);
  return;
}
