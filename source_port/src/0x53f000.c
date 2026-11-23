// SoundBuffer_Delete: ported from Pizza Connection 2 at 0x53f000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f000
#include "pc2_port.h"

uint32_t * __thiscall SoundBuffer_Delete(void *self,uint8_t arg1)

{
  SoundBuffer_DestructBase(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
