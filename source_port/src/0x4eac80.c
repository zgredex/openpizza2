// Game_RegisterWorldObject: ported from Pizza Connection 2 at 0x4eac80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eac80
#include "pc2_port.h"

void __thiscall Game_RegisterWorldObject(void *self,uint32_t arg1,int arg2)

{
  if (arg2 == -1) {
    List_Add((void *)((intptr_t)self + 0x2c3f8),arg1);
    return;
  }
  IDMap_InsertGrow((void *)((intptr_t)self + 0x2c3f8),arg1,arg2);
  return;
}
