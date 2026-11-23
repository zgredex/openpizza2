// Sprite_Draw: ported from Pizza Connection 2 at 0x53d570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d570
#include "pc2_port.h"

void __thiscall Sprite_Draw(void *self,int arg1,uint32_t *arg2,int arg3)

{
  uint32_t *uptr1;
  
  if (*(char *)((intptr_t)self + 0x39) == '\0') {
    Sprite_RealizeLazy(self);
  }
  uptr1 = *(uint32_t **)((intptr_t)self + 0x30);
  if (uptr1 == (uint32_t *)0x0) {
    Sprite_BlitAlphaRLEAlt
              (self,arg1,*(uint32_t **)((intptr_t)self + 0x2c),*(int *)((intptr_t)self + 0x28),arg2,arg3,
               (uint8_t *)0xffffffff,-1);
    return;
  }
  if (*(char *)((intptr_t)self + 0x37) == '\0') {
    Sprite_BlitAlphaRLEAlt
              (self,arg1,uptr1,*(int *)((intptr_t)self + 0x28),arg2,arg3,(uint8_t *)0xffffffff,-1)
    ;
    return;
  }
  Sprite_BlitAlphaRLEAlt
            (self,arg1,uptr1,*(int *)((intptr_t)self + 0x28),arg2,arg3,
             (uint8_t *)(intptr_t)*(short *)((intptr_t)self + 8),(intptr_t)*(short *)((intptr_t)self + 6));
  return;
}
