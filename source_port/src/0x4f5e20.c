// Player_MissionState_Delete: ported from Pizza Connection 2 at 0x4f5e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5e20
#include "pc2_port.h"

uint32_t * __thiscall Player_MissionState_Delete(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for the player mission-state object. */
  Player_MissionState_Destructor(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
