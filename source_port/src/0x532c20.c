// Animation_ScalarDeletingDestructor: ported from Pizza Connection 2 at 0x532c20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532c20
#include "pc2_port.h"

uint32_t * __thiscall Animation_ScalarDeletingDestructor(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for a .ani animation object. */
  SpriteFile_Destruct(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
