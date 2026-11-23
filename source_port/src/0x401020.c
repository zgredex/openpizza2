// StatsPeriodReport_Delete: ported from Pizza Connection 2 at 0x401020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401020
#include "pc2_port.h"

uint32_t * __thiscall StatsPeriodReport_Delete(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for a period-report record. */
  StatsPeriodReport_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
