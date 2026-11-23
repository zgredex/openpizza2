// UI_AddEffectObject: ported from Pizza Connection 2 at 0x527c60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527c60
#include "pc2_port.h"

void __thiscall UI_AddEffectObject(void *self,uint32_t arg1)

{
  Array_InsertGrow((void *)((intptr_t)self + 0x8324),arg1);
  return;
}
