// Game_HasQueuedEventType: ported from Pizza Connection 2 at 0x48c000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c000
#include "pc2_port.h"

void __thiscall Game_HasQueuedEventType(void *self,int arg1)

{
  IDMap_FindByField34((void *)((intptr_t)self + 0x304),arg1);
  return;
}
