// Game_SelectPlayer: ported from Pizza Connection 2 at 0x48c160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c160
#include "pc2_port.h"

void __thiscall Game_SelectPlayer(void *self,int arg1)

{
  int value1;
  
  if (arg1 == -1) {
    arg1 = *(int *)((intptr_t)self + 0x288);
  }
  value1 = Game_GetPlayerBySlot(self,arg1);
  if ((value1 != 0) && (arg1 != *(int *)((intptr_t)self + 0x2ec))) {
    *(int *)((intptr_t)self + 0x2ec) = arg1;
    *(uint32_t *)((intptr_t)self + 0x2f0) = *(uint32_t *)(value1 + 0x4c);
    *(uint32_t *)((intptr_t)self + 700) = *(uint32_t *)((intptr_t)self + 0x29c);
    *(uint32_t *)((intptr_t)self + 0x29c) = 1;
    Game_SetViewMode(self,1,0);
  }
  return;
}
