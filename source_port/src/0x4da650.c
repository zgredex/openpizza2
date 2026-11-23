// Game_CollectAllOwnedObjects: ported from Pizza Connection 2 at 0x4da650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da650
#include "pc2_port.h"

void Game_CollectAllOwnedObjects(void *arg1,int arg2)

{
  void *self;
  int value1;
  
  List_Node_Reset((intptr_t)arg1);
  value1 = 0;
  do {
    self = (void *)Game_GetPlayerBySlot(DAT_0057c670,value1);
    if (self != (void *)0x0) {
      Game_CollectObjectsByOwner(self,arg1,arg2);
    }
    value1 = value1 + 1;
  } while (value1 < 6);
  return;
}
