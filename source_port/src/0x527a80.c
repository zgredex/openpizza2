// UI_ApplyChildSpriteTint: ported from Pizza Connection 2 at 0x527a80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527a80
#include "pc2_port.h"

void __thiscall UI_ApplyChildSpriteTint(void *self,uint16_t *arg1,int arg2)

{
  Renderer_ApplySpriteTint(*(void **)((intptr_t)self + 0x8310),arg1,arg2);
  return;
}
