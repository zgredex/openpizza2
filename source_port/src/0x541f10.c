// SoundTrack_Delete: ported from Pizza Connection 2 at 0x541f10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541f10
#include "pc2_port.h"

uint32_t * __thiscall SoundTrack_Delete(void *self,uint8_t arg1)

{
  SoundTrack_Destruct(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
