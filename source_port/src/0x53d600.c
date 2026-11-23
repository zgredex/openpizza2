// Sprite_BlitWithDefaultAlpha: ported from Pizza Connection 2 at 0x53d600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d600
#include "pc2_port.h"

void __thiscall
Sprite_BlitWithDefaultAlpha
          (void *self,uint32_t *arg1,void *arg2,uint32_t *arg3,int arg4,int arg5)

{
  if (*(char *)((intptr_t)self + 0x39) == '\0') {
    Sprite_RealizeLazy(self);
  }
  if (arg5 == -1) {
    arg5 = DAT_00585518;
  }
  Sprite_BlitAlphaRLE(self,arg1,arg2,*(uint16_t **)((intptr_t)self + 0x2c),*(int *)((intptr_t)self + 0x28)
                      ,arg3,arg4,(char)arg5);
  return;
}
