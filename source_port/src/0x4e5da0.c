// ConstructionOrder_Delete: ported from Pizza Connection 2 at 0x4e5da0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e5da0
#include "pc2_port.h"

uint32_t * __thiscall ConstructionOrder_Delete(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for a construction order. */
  ConstructionOrder_Destructor(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
