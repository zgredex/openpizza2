// Company_Delete: ported from Pizza Connection 2 at 0x4dd8d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd8d0
#include "pc2_port.h"

uint32_t * __thiscall Company_Delete(void *self,uint8_t arg1)

{
  Company_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
