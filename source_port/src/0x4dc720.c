// Game_PlaceObjectInPlayerCity: ported from Pizza Connection 2 at 0x4dc720.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dc720
#include "pc2_port.h"

void __thiscall Game_PlaceObjectInPlayerCity(void *self,void *arg1,int arg2)

{
  MapObject_SetCityFromPlayer(arg1,*(void **)((intptr_t)self + 0xfa8),arg2);
  *(uint32_t *)(*(int *)((intptr_t)self + 0xfa8) + 0xf4) = 1;
  if (arg2 == -1) {
    *(uint32_t *)((intptr_t)arg1 + 0x38) = 0;
  }
  return;
}
