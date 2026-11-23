// Game_CountRecordsForSelectedPlayer: ported from Pizza Connection 2 at 0x486e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486e20
#include "pc2_port.h"

void __thiscall Game_CountRecordsForSelectedPlayer(void *self,int arg1,int arg2)

{
  void *this_00;
  
  if (arg2 == -1) {
    Game_CountRecordsByField34
              (*(void **)((intptr_t)self + *(int *)((intptr_t)self + 0x2ec) * 4 + 0x200),arg1);
    return;
  }
  this_00 = (void *)Game_GetPlayerBySlot(self,arg2);
  Game_CountRecordsByField34(this_00,arg1);
  return;
}
