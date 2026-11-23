// Sound_PlayEffectByIndex: ported from Pizza Connection 2 at 0x5482e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5482e0
#include "pc2_port.h"

void __thiscall Sound_PlayEffectByIndex(void *self,int arg1)

{
  if (*(char *)((intptr_t)self + 0xfc) != '\0') {
    Sound_SetParam(self,*(uint32_t *)((intptr_t)self + arg1 * 4 + 0x24));
  }
  return;
}
