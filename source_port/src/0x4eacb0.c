// Game_RemoveIDMapEntry: ported from Pizza Connection 2 at 0x4eacb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eacb0
#include "pc2_port.h"

void __thiscall Game_RemoveIDMapEntry(void *self,int arg1)

{
  Map_LookupLinear((void *)((intptr_t)self + 0x2c3f8),arg1);
  return;
}
