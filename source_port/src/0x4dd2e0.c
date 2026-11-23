// GameClock_Delete: ported from Pizza Connection 2 at 0x4dd2e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd2e0
#include "pc2_port.h"

uint32_t * __thiscall GameClock_Delete(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for the game clock. */
  GameClock_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
