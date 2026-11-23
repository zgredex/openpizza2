// Game_RemoveLocalEntryRecursive: ported from Pizza Connection 2 at 0x4d2a90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2a90
#include "pc2_port.h"

void __thiscall Game_RemoveLocalEntryRecursive(void *self,int arg1)

{
  IDMap_RemoveRecursive((void *)((intptr_t)self + 0x78),arg1);
  return;
}
