// GamePlan_Delete: ported from Pizza Connection 2 at 0x50f670.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50f670
#include "pc2_port.h"

uint32_t * __thiscall GamePlan_Delete(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for a plan/budget record. */
  GamePlan_Destructor(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
