// Sound_SetVolumePreset: ported from Pizza Connection 2 at 0x485a80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x485a80
#include "pc2_port.h"

void __thiscall Sound_SetVolumePreset(void *self,int arg1)

{
  if ((-1 < arg1) && (arg1 < 3)) {
    *(int *)((intptr_t)self + 0x2da0) = arg1;
    Sound_ApplyVolumePreset(DAT_0057ba0c,arg1);
  }
  if (*(int *)((intptr_t)self + 0x33c) == 0) {
    *(uint32_t *)((intptr_t)self + 900) = *(uint32_t *)((intptr_t)self + 0x2da0);
  }
  return;
}
