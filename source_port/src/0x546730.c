// SoundBuffer_Delete2: ported from Pizza Connection 2 at 0x546730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x546730
#include "pc2_port.h"

uint32_t * __thiscall SoundBuffer_Delete2(void *self,uint8_t arg1)

{
  SoundBuffer_Destructor(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
