// Game_GetOwnedObjectByIndex: ported from Pizza Connection 2 at 0x4d8120.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8120
#include "pc2_port.h"

void __thiscall Game_GetOwnedObjectByIndex(void *self,int arg1,int *arg2)

{
  IDMap_Lookup((void *)((intptr_t)self + 0xfc8),arg1,arg2);
  return;
}
