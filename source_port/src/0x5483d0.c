// Sound_StartSpeech: ported from Pizza Connection 2 at 0x5483d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5483d0
#include "pc2_port.h"

void __thiscall Sound_StartSpeech(void *self,int arg1)

{
  if (*(char *)((intptr_t)self + 0xfc) != '\0') {
    Sound_UpdateVolumeByCitySize(self,arg1);
    if (*(char *)((intptr_t)self + 0x16a) == '\0') {
      Sound_SetPosition(self,*(uint32_t *)((intptr_t)self + 0x88));
      if (*(int *)((intptr_t)self + 0x1d0) != 0) {
        (**(code **)(**(int **)((intptr_t)self + 8) + 0x58))
                  (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + 0x8c),1);
      }
      *(uint8_t *)((intptr_t)self + 0x16a) = 1;
    }
  }
  return;
}
