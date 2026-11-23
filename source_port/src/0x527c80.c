// UI_RemoveEffectObject: ported from Pizza Connection 2 at 0x527c80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527c80
#include "pc2_port.h"

void __thiscall UI_RemoveEffectObject(void *self,int arg1)

{
  Array_RemoveValueLocked((void *)((intptr_t)self + 0x8324),arg1);
  return;
}
