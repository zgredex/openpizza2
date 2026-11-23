// Sprite_FillTransparentColor: ported from Pizza Connection 2 at 0x53d6c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d6c0
#include "pc2_port.h"

void __thiscall Sprite_FillTransparentColor(void *self,int arg1)

{
  if (*(char *)((intptr_t)self + 0x39) == '\0') {
    Sprite_RealizeLazy(self);
  }
  if (arg1 == -1) {
    if (*(char *)((intptr_t)self + 4) == '\0') {
      arg1 = (-(uint32_t)(*(char *)(DAT_0057c5c8 + 0x18) != '\0') & 0xfffffc00) + 0x7e0;
      Sprite_SetColorKey(self,arg1);
    }
    else {
      arg1 = *(int *)((intptr_t)self + 0x1c);
    }
  }
  Mem_FillWord(*(uint32_t **)((intptr_t)self + 0x2c),(short)arg1,*(int *)((intptr_t)self + 0x18) >> 1);
  return;
}
