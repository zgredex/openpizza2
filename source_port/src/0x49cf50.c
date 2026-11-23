// Game_SyncSelectedPlayerCompany: ported from Pizza Connection 2 at 0x49cf50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49cf50
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Game_SyncSelectedPlayerCompany(void)

{
  int value1;
  
  value1 = Game_GetPlayerBySlot(DAT_0057c670,DAT_0057cab4);
  _DAT_0057ca98 = *(int *)(value1 + 0x1d4);
  if (*(int *)((intptr_t)DAT_0057c670 + 0x98) != _DAT_0057ca98) {
    UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x25c),-0x18670,0x23,_DAT_0057ca98);
  }
  return;
}
