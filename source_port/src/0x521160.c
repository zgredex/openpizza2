// UI_Viewport_Delete: ported from Pizza Connection 2 at 0x521160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521160
#include "pc2_port.h"

uint32_t * __thiscall UI_Viewport_Delete(void *self,uint8_t arg1)

{
                    /* Deleting destructor for the UI viewport/custom-draw child. */
  UI_CustomControl_Destructor(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
