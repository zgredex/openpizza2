// ResourceManager_ScalarDeletingDestructor: ported from Pizza Connection 2 at 0x401a00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401a00
#include "pc2_port.h"

uint32_t * __thiscall ResourceManager_ScalarDeletingDestructor(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for the resource manager. */
  ResourceManager_Destruct(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
