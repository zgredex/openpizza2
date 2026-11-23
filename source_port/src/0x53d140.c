// Sprite_SetHotspot: ported from Pizza Connection 2 at 0x53d140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d140
#include "pc2_port.h"

void __thiscall Sprite_SetHotspot(void *self,uint16_t arg1,uint16_t arg2)

{
  if ((*(uint8_t *)((intptr_t)self + 4) & 4) != 0) {
    *(uint16_t *)((intptr_t)self + 10) = arg1;
    *(uint16_t *)((intptr_t)self + 0xc) = arg2;
  }
  return;
}
