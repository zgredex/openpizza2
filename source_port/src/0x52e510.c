// UI_Tooltip_Delete: ported from Pizza Connection 2 at 0x52e510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e510
#include "pc2_port.h"

uint32_t * __thiscall UI_Tooltip_Delete(void *self,uint8_t arg1)

{
  UI_Tooltip_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
