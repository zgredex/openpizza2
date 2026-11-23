// Sound_TriggerSoundById: ported from Pizza Connection 2 at 0x548040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548040
#include "pc2_port.h"

void __thiscall Sound_TriggerSoundById(void *self,int arg1)

{
  if ((*(char *)((intptr_t)self + 0xfc) != '\0') && (-1 < arg1)) {
    Sound_SetPosition(self,*(uint32_t *)((intptr_t)self + arg1 * 4 + 0x24));
  }
  return;
}
