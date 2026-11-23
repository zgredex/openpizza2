// Sprite_GetHotspot: ported from Pizza Connection 2 at 0x53d100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d100
#include "pc2_port.h"

void __thiscall Sprite_GetHotspot(void *self,int *arg1,int *arg2)

{
  if ((*(uint8_t *)((intptr_t)self + 4) & 4) == 0) {
    *arg1 = 0;
    *arg2 = 0;
    return;
  }
  *arg1 = (intptr_t)*(short *)((intptr_t)self + 10);
  *arg2 = (intptr_t)*(short *)((intptr_t)self + 0xc);
  return;
}
