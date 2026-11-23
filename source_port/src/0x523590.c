// UI_Manager_ScalarDeletingDestructor: ported from Pizza Connection 2 at 0x523590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523590
#include "pc2_port.h"

uint32_t * __thiscall UI_Manager_ScalarDeletingDestructor(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for the UI manager. */
  UI_Manager_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
