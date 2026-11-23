// Sound_PlaySfxByIndex: ported from Pizza Connection 2 at 0x5480c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5480c0
#include "pc2_port.h"

void __thiscall Sound_PlaySfxByIndex(void *self,int arg1,int arg2)

{
  uint8_t *uptr1;
  uint8_t local_104 [260];
  
  if (((*(char *)((intptr_t)self + 0xfc) != '\0') && (arg1 < 0x25)) &&
     (uptr1 = (&PTR_s_Sfx_City_Building_Living_wav_00575190)[arg1], uptr1 != (uint8_t *)0x0))
  {
    if (arg1 == 0xb) {
      String_Format(local_104,(uint8_t *)s_Sfx__s_s_wav_00576110,uptr1);
    }
    else {
      String_Format(local_104,(uint8_t *)s_Sfx__s_00576108,uptr1);
    }
    if (((0 < arg2) && (arg1 != 0xf)) && ((arg1 != 0x10 && (arg1 == 0x1c)))) {
      switch(arg2) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
      }
    }
    Sound_PlayChannel(self,local_104,1);
  }
  return;
}
