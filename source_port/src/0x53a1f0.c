// SpriteBase_Delete: ported from Pizza Connection 2 at 0x53a1f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a1f0
#include "pc2_port.h"

uint32_t * __thiscall SpriteBase_Delete(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for the sprite base class. */
  SpriteBase_Destructor(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
