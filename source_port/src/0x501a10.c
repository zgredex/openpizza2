// AwardNode_Delete: ported from Pizza Connection 2 at 0x501a10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501a10
#include "pc2_port.h"

uint32_t * __thiscall AwardNode_Delete(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for a player award node. */
  AwardNode_Destructor(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
