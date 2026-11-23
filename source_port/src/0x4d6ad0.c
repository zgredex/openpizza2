// Game_LookupObjectByIndex: ported from Pizza Connection 2 at 0x4d6ad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6ad0
#include "pc2_port.h"

void __thiscall Game_LookupObjectByIndex(void *self,int arg1)

{
  IDMap_Lookup((void *)((intptr_t)self + 0xfc8),arg1,(int *)0x0);
  return;
}
