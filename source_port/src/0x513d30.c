// Storage_Delete: ported from Pizza Connection 2 at 0x513d30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513d30
#include "pc2_port.h"

uint32_t * __thiscall Storage_Delete(void *self,uint8_t arg1)

{
  Storage_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
