// Branch_RemoveConstructionOrder: ported from Pizza Connection 2 at 0x47c5b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c5b0
#include "pc2_port.h"

void __thiscall Branch_RemoveConstructionOrder(void *self,int arg1)

{
  *(uint32_t *)((intptr_t)self + 0x1718) = 0;
  IDMap_RemoveByKey((void *)((intptr_t)self + 0x16f8),arg1);
  Game_CheckObjectUpgrade(self);
  return;
}
