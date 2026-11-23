// Sprite_GetRenderSize: ported from Pizza Connection 2 at 0x53d040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d040
#include "pc2_port.h"

void __thiscall Sprite_GetRenderSize(void *self,uint32_t *arg1,uint32_t *arg2)

{
  if ((*(int *)((intptr_t)self + 0x30) == 0) || (*(char *)((intptr_t)self + 0x37) == '\0')) {
    *arg1 = (uint32_t)*(uint16_t *)((intptr_t)self + 0x12);
    *arg2 = (uint32_t)*(uint16_t *)((intptr_t)self + 0x14);
    return;
  }
  *arg1 = (uint32_t)*(uint16_t *)((intptr_t)self + 0x14);
  *arg2 = (uint32_t)*(uint16_t *)((intptr_t)self + 0x12);
  return;
}
