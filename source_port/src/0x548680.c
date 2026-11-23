// Sound_SetMusicTrack: ported from Pizza Connection 2 at 0x548680.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548680
#include "pc2_port.h"

void __thiscall Sound_SetMusicTrack(void *self,uint32_t arg1)

{
  int value1;
  char *cptr2;
  int value3;
  uint8_t local_104 [260];
  
  if (*(char *)((intptr_t)self + 0xfc) == '\0') {
    return;
  }
  value1 = (intptr_t)self + 0x178;
  CS_Enter(value1);
  SoundBuffer_Release((intptr_t)self);
  *(uint32_t *)((intptr_t)self + 0x108) = arg1;
  switch(arg1) {
  case 1000:
    if (*(int *)((intptr_t)self + 0xc) != 0) {
      (**(code **)(**(int **)((intptr_t)self + 8) + 0x54))
                (*(int **)((intptr_t)self + 8),*(int *)((intptr_t)self + 0xc));
      *(uint32_t *)((intptr_t)self + 0xc) = 0;
      CS_Leave(value1);
      return;
    }
    goto switchD_005486c7_default;
  case 0x3e9:
    cptr2 = s_Music_Mus_City__s_0_wav_00576150;
    break;
  case 0x3ea:
    cptr2 = s_Music_Mus_City__s_1_wav_00576138;
    break;
  case 0x3eb:
    cptr2 = s_Music_Mus_City__s_2_wav_00576120;
    break;
  case 0x3ec:
    goto LAB_00548747;
  default:
    goto switchD_005486c7_default;
  }
  String_Format(local_104,(uint8_t *)cptr2,(intptr_t)self + 0x174);
LAB_00548747:
  value3 = Sound_GetChannel(self,local_104,2);
  *(int *)((intptr_t)self + 0xc) = value3;
switchD_005486c7_default:
  CS_Leave(value1);
  return;
}
