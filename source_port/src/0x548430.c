// Sound_StopSpeech: ported from Pizza Connection 2 at 0x548430.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548430
#include "pc2_port.h"

void __thiscall Sound_StopSpeech(void *self,int arg1)

{
  if ((*(char *)((intptr_t)self + 0xfc) != '\0') && (*(char *)((intptr_t)self + 0x16a) != '\0')) {
    if (*(int *)((intptr_t)self + 0x1d0) != 0) {
      (**(code **)(**(int **)((intptr_t)self + 8) + 0xa8))
                (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + 0xf4));
    }
    Sound_UpdateVolumeByCitySize(self,arg1);
  }
  return;
}
