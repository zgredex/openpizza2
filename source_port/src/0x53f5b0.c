// SoundSample_Delete: ported from Pizza Connection 2 at 0x53f5b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f5b0
#include "pc2_port.h"

uint32_t * __thiscall SoundSample_Delete(void *self,uint8_t arg1)

{
  SoundSample_Destruct(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
