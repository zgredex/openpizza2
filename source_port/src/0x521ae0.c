// UI_GetChildSize: ported from Pizza Connection 2 at 0x521ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521ae0
#include "pc2_port.h"

void __thiscall UI_GetChildSize(void *self,int *arg1,int *arg2)

{
  Sprite_GetSize(*(void **)((intptr_t)self + 0x60),arg1,arg2);
  return;
}
