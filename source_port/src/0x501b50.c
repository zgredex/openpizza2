// Player_AIState_Delete: ported from Pizza Connection 2 at 0x501b50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501b50
#include "pc2_port.h"

uint32_t * __thiscall Player_AIState_Delete(void *self,uint8_t arg1)

{
  Player_AIState_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
