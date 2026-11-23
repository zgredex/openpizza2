// Player_Delete: ported from Pizza Connection 2 at 0x50e9c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e9c0
#include "pc2_port.h"

uint32_t * __thiscall Player_Delete(void *self,uint8_t arg1)

{
  Player_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
