// Car_LoadSpriteRecord: ported from Pizza Connection 2 at 0x4d3470.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3470
#include "pc2_port.h"

void __thiscall Car_LoadSpriteRecord(void *self,void *arg1)

{
                    /* Allocates and reads a car's map-sprite render record. */
  MapSprite_InitializeRecord((intptr_t)self);
  MapActor_ReadFromStream(arg1,*(uint32_t **)((intptr_t)self + 8));
  return;
}
