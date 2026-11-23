// Renderer_FlushTarget: ported from Pizza Connection 2 at 0x52e850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e850
#include "pc2_port.h"

void __thiscall Renderer_FlushTarget(void *self,int arg1)

{
  if ((*(int *)((intptr_t)self + 0x14) != 0) && (*(void **)((intptr_t)self + 0x20) != (void *)0x0)) {
    Sprite_Draw(*(void **)((intptr_t)self + 0x20),arg1,*(uint32_t **)((intptr_t)self + 0xc),
                *(int *)((intptr_t)self + 0x10));
    *(uint32_t *)((intptr_t)self + 0x3c) = 0;
  }
  return;
}
