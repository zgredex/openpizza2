// Sound_PlayMenuSfxByIndex: ported from Pizza Connection 2 at 0x54a2a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a2a0
#include "pc2_port.h"

void __thiscall Sound_PlayMenuSfxByIndex(void *self,uint32_t arg1)

{
  if (*(char *)((intptr_t)self + 0xfc) != '\0') {
    switch(arg1) {
    case 0:
      Sound_PlaySfxByIndex(self,0,0);
      return;
    case 1:
      Sound_PlaySfxByIndex(self,1,0);
      return;
    case 2:
      Sound_PlaySfxByIndex(self,2,0);
      return;
    case 3:
      Sound_PlaySfxByIndex(self,0x12,0);
      return;
    case 4:
      Sound_PlaySfxByIndex(self,4,0);
      return;
    case 5:
      Sound_PlaySfxByIndex(self,5,0);
      return;
    case 6:
      Sound_PlaySfxByIndex(self,6,0);
      return;
    case 7:
      Sound_PlaySfxByIndex(self,7,0);
      return;
    case 8:
      Sound_PlaySfxByIndex(self,8,0);
      return;
    case 9:
      Sound_PlaySfxByIndex(self,9,0);
      return;
    case 10:
      Sound_PlaySfxByIndex(self,10,0);
      return;
    case 0xb:
      Sound_PlayChannel(self,s_Sfx_Sfx_City_Building_Manufaktur_00576330,1);
      return;
    case 0xc:
      Sound_PlaySfxByIndex(self,0xd,0);
      return;
    case 0xd:
      Sound_PlaySfxByIndex(self,0xe,0);
      return;
    case 0xe:
      Sound_PlaySfxByIndex(self,0x18,0);
      return;
    case 0xf:
      Sound_PlaySfxByIndex(self,0xb,0);
      return;
    case 0x10:
      Sound_PlaySfxByIndex(self,0x21,0);
      return;
    case 0x11:
      Sound_PlaySfxByIndex(self,0x19,0);
      return;
    case 0x12:
      Sound_PlaySfxByIndex(self,0x17,0);
      return;
    case 0x13:
      Sound_PlaySfxByIndex(self,0x13,0);
      return;
    case 0x14:
      Sound_PlaySfxByIndex(self,0x16,0);
      return;
    case 0x15:
      Sound_PlaySfxByIndex(self,0x1a,0);
      return;
    case 0x16:
      Sound_PlaySfxByIndex(self,0x23,0);
    }
  }
  return;
}
