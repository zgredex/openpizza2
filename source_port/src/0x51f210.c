// UI_ImageElement_Delete: ported from Pizza Connection 2 at 0x51f210.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51f210
#include "pc2_port.h"

uint32_t * __thiscall UI_ImageElement_Delete(void *self,uint8_t arg1)

{
  UI_ImageElement_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
