// Branch_RemoveBuildingObject: ported from Pizza Connection 2 at 0x47f5c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f5c0
#include "pc2_port.h"

void __thiscall Branch_RemoveBuildingObject(void *self,void *arg1)

{
  Game_RemoveObjectFromList(*(void **)((intptr_t)self + 0x16f0),arg1,0);
  Game_HandleObjectDeath(DAT_0057c670,arg1);
  return;
}
