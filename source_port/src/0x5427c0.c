// SoundMixerThread_Delete: ported from Pizza Connection 2 at 0x5427c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5427c0
#include "pc2_port.h"

uint32_t * __thiscall SoundMixerThread_Delete(void *self,uint8_t arg1)

{
  SoundMixerThread_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
