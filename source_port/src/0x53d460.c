// Sprite_GetPixelData: ported from Pizza Connection 2 at 0x53d460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d460
#include "pc2_port.h"

uint32_t __thiscall Sprite_GetPixelData(void *self,uint32_t *arg1)

{
  if (*(char *)((intptr_t)self + 0x39) == '\0') {
    Sprite_RealizeLazy(self);
  }
  *arg1 = *(uint32_t *)((intptr_t)self + 0x18);
  return *(uint32_t *)((intptr_t)self + 0x2c);
}
