// Sound_PlayStatisticPageSfx: ported from Pizza Connection 2 at 0x54a490.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a490
#include "pc2_port.h"

void __thiscall Sound_PlayStatisticPageSfx(void *self,uint32_t arg1)

{
  if (*(char *)((intptr_t)self + 0xfc) != '\0') {
    switch(arg1) {
    case 0:
      Sound_PlaySfxByIndex(self,0x14,0);
      return;
    case 1:
      Sound_PlaySfxByIndex(self,0x15,0);
      return;
    case 2:
      Sound_PlaySfxByIndex(self,0x16,0);
      return;
    case 3:
      Sound_PlaySfxByIndex(self,0x1d,0);
      return;
    case 4:
      Sound_PlaySfxByIndex(self,0x1e,0);
      return;
    case 5:
      Sound_PlaySfxByIndex(self,0x1f,0);
      return;
    case 6:
      Sound_PlaySfxByIndex(self,0x1c,1);
      return;
    case 7:
      Sound_PlaySfxByIndex(self,0x1c,2);
      return;
    case 8:
      Sound_PlaySfxByIndex(self,0x1c,3);
      return;
    case 9:
      Sound_PlaySfxByIndex(self,0x1c,4);
      return;
    case 10:
      Sound_PlaySfxByIndex(self,0x1c,5);
      return;
    case 0xb:
      Sound_PlaySfxByIndex(self,0x1c,6);
      return;
    case 0xc:
      Sound_PlaySfxByIndex(self,0x11,0);
    }
  }
  return;
}
