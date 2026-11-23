// SoundSystem_Delete: ported from Pizza Connection 2 at 0x544ab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x544ab0
#include "pc2_port.h"

uint32_t * __thiscall SoundSystem_Delete(void *self,uint8_t arg1)

{
  SoundSystem_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free((LPVOID)((intptr_t)self + -4));
  }
  return (uint32_t *)((intptr_t)self + -4);
}
