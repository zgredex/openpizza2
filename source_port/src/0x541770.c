// SoundStreamBuffer_DeleteObject: ported from Pizza Connection 2 at 0x541770.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541770
#include "pc2_port.h"

uint32_t * __thiscall SoundStreamBuffer_DeleteObject(void *self,uint8_t arg1)

{
  SoundStreamBuffer_Destruct(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
