// Sound_SelectCurrentTrack: ported from Pizza Connection 2 at 0x547e70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547e70
#include "pc2_port.h"

void __fastcall Sound_SelectCurrentTrack(void *arg1)

{
  int value1;
  uint8_t local_104 [260];
  
  CS_Enter((intptr_t)arg1 + 0x178);
  value1 = -1;
  if (DAT_0057c670 == 0) {
    value1 = 0;
  }
  else {
    switch(*(uint32_t *)(DAT_0057c670 + 0x290)) {
    case 4:
      if (*(int *)(DAT_0057c670 + 0x9c) == 0) {
        value1 = -1;
      }
      else {
        value1 = *(int *)(*(int *)(DAT_0057c670 + 0x9c) + 0x14d8);
        if (value1 != -1) {
          value1 = value1 + 3;
          break;
        }
      }
      SoundBuffer_Release((intptr_t)arg1);
      break;
    case 5:
      value1 = 2;
      break;
    case 6:
    case 7:
      value1 = 1;
      break;
    case 9:
    case 10:
    case 0xb:
    case 0xc:
      if (*(int *)((intptr_t)arg1 + 0x10) != 0) {
        (**(code **)(**(int **)((intptr_t)arg1 + 8) + 0x54))
                  (*(int **)((intptr_t)arg1 + 8),*(int *)((intptr_t)arg1 + 0x10));
        *(uint32_t *)((intptr_t)arg1 + 0x10) = 0;
        *(uint32_t *)((intptr_t)arg1 + 0x14) = 0;
      }
    case 0x16:
      value1 = 0;
    }
  }
  if (((*(int *)((intptr_t)arg1 + 0x108) < 1000) || (value1 != -1)) &&
     ((value1 != *(int *)((intptr_t)arg1 + 0x108) || (*(int *)((intptr_t)arg1 + 0xc) == 0)))) {
    SoundBuffer_Release((intptr_t)arg1);
    *(int *)((intptr_t)arg1 + 0x108) = value1;
    if (((value1 != -1) && (*(char *)((intptr_t)arg1 + 0xfc) != '\0')) &&
       (*(int *)((intptr_t)arg1 + 0x1d4) != 0)) {
      String_Format(local_104,(uint8_t *)s_Music__s_005760e0,
                    (&PTR_s_Mus_Menue_Start_wav_00575220)[value1]);
      value1 = Sound_GetChannel(arg1,local_104,2);
      *(int *)((intptr_t)arg1 + 0xc) = value1;
    }
  }
  CS_Leave((intptr_t)arg1 + 0x178);
  return;
}
