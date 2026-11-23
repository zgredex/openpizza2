// SoundPakManager_Delete: ported from Pizza Connection 2 at 0x53fca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53fca0
#include "pc2_port.h"

uint32_t * __thiscall SoundPakManager_Delete(void *self,uint8_t arg1)

{
  SoundPakManager_Destruct(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
