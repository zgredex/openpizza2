// Sprite_SetColorKey: ported from Pizza Connection 2 at 0x53d440.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d440
#include "pc2_port.h"

void __thiscall Sprite_SetColorKey(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x1c) = arg1;
  *(uint8_t *)((intptr_t)self + 4) = *(uint8_t *)((intptr_t)self + 4) | 2;
  return;
}
