// Player_RemoveObjectReference: ported from Pizza Connection 2 at 0x4ddca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddca0
#include "pc2_port.h"

void __thiscall Player_RemoveObjectReference(void *self,int arg1)

{
  IDMap_RemoveByKey((void *)((intptr_t)self + 0x180),arg1);
  return;
}
