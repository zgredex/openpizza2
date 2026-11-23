// SoundBuffer_ScalarDeletingDestructor: ported from Pizza Connection 2 at 0x541730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541730
#include "pc2_port.h"

uint32_t * __thiscall SoundBuffer_ScalarDeletingDestructor(void *self,uint8_t arg1)

{
  SoundBuffer_DestroyInterfaces(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
