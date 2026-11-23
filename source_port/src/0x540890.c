// SoundBuffer_DeleteObject: ported from Pizza Connection 2 at 0x540890.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540890
#include "pc2_port.h"

uint32_t * __thiscall SoundBuffer_DeleteObject(void *self,uint8_t arg1)

{
  SoundBuffer_DestructDerived(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
