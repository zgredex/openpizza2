// IsoMap_Delete: ported from Pizza Connection 2 at 0x4eade0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eade0
#include "pc2_port.h"

uint32_t * __thiscall IsoMap_Delete(void *self,uint8_t arg1)

{
  IsoMap_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
