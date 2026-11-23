// UI_ButtonElement_Delete: ported from Pizza Connection 2 at 0x52d690.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52d690
#include "pc2_port.h"

uint32_t * __thiscall UI_ButtonElement_Delete(void *self,uint8_t arg1)

{
  UI_ButtonElement_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
