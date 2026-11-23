// Game_RegisterObject: ported from Pizza Connection 2 at 0x482810.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482810
#include "pc2_port.h"

void __thiscall Game_RegisterObject(void *self,uint32_t arg1)

{
  List_Add((void *)((intptr_t)self + 0x58),arg1);
  return;
}
