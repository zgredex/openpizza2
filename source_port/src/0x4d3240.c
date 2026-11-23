// Car_Delete: ported from Pizza Connection 2 at 0x4d3240.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3240
#include "pc2_port.h"

uint32_t * __thiscall Car_Delete(void *self,uint8_t arg1)

{
  Car_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
