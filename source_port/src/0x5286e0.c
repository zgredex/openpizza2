// UI_ContextMenu_Delete: ported from Pizza Connection 2 at 0x5286e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5286e0
#include "pc2_port.h"

int * __thiscall UI_ContextMenu_Delete(void *self,uint8_t arg1)

{
  UI_ContextMenu_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
