// DebugConsole_Delete: ported from Pizza Connection 2 at 0x54a610.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a610
#include "pc2_port.h"

uint32_t * __thiscall DebugConsole_Delete(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for the debug console. */
  DebugConsole_Destructor(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
