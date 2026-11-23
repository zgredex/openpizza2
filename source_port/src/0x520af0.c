// UI_Child_Delete: ported from Pizza Connection 2 at 0x520af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520af0
#include "pc2_port.h"

uint32_t * __thiscall UI_Child_Delete(void *self,uint8_t arg1)

{
  UI_Child_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
