// Surface_BlitRLEEnsureFormat: ported from Pizza Connection 2 at 0x53d650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d650
#include "pc2_port.h"

void __thiscall
Surface_BlitRLEEnsureFormat(void *self,int arg1,uint32_t *arg2,uint32_t arg3,int arg4)

{
  if (*(char *)((intptr_t)self + 0x39) == '\0') {
    Sprite_RealizeLazy(self);
  }
  Surface_BlitRLESkipToRGB(self,arg1,arg2,*(uint8_t **)((intptr_t)self + 0x2c),arg3,arg4);
  return;
}
