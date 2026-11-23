// Sound_PlayBuildingSpecialSfx: ported from Pizza Connection 2 at 0x549e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x549e80
#include "pc2_port.h"

void __thiscall Sound_PlayBuildingSpecialSfx(void *self,uint32_t arg1)

{
  uint8_t *uptr1;
  uint8_t local_104 [260];
  
  if (*(char *)((intptr_t)self + 0xfc) != '\0') {
    switch(arg1) {
    case 0:
      uptr1 = &DAT_0057632c;
      break;
    case 1:
      uptr1 = &DAT_00576328;
      break;
    case 2:
      uptr1 = &DAT_00576324;
      break;
    case 3:
      uptr1 = &DAT_00576320;
      break;
    case 4:
      uptr1 = &DAT_0057631c;
      break;
    case 5:
      uptr1 = &DAT_00576318;
      break;
    case 6:
      uptr1 = &DAT_00576314;
      break;
    case 7:
      uptr1 = &DAT_00576310;
      break;
    case 8:
      uptr1 = &DAT_0057630c;
      break;
    case 9:
      uptr1 = &DAT_00576308;
      break;
    default:
      goto switchD_00549e9f_default;
    }
    String_Format(local_104,(uint8_t *)s_Sfx_Sfx_City_Building_Special__s_005762e0,uptr1);
    Sound_PlayChannel(self,local_104,1);
  }
switchD_00549e9f_default:
  return;
}
