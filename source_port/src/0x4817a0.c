// GameWorld_Delete: ported from Pizza Connection 2 at 0x4817a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4817a0
#include "pc2_port.h"

uint32_t * __thiscall GameWorld_Delete(void *self,uint8_t arg1)

{
                    /* Deleting destructor for the central game/world object. */
  GameState_Destruct(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
