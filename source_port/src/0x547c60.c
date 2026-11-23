// Sound_SetPlaybackMode: ported from Pizza Connection 2 at 0x547c60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547c60
#include "pc2_port.h"

void __thiscall Sound_SetPlaybackMode(void *self,int arg1)

{
  uint32_t *uptr1;
  int value2;
  uint32_t uvalue3;
  uint8_t local_104 [260];
  
  *(int *)((intptr_t)self + 0x104) = arg1;
  if (*(char *)((intptr_t)self + 0xfc) != '\0') {
    if (arg1 == 1) {
      uvalue3 = Sound_SetVolume(self,*(uint32_t *)((intptr_t)self + 0x10));
      if ((char)uvalue3 == '\0') {
        *(uint32_t *)((intptr_t)self + 0x20) = 0;
      }
      else {
        *(uint32_t *)((intptr_t)self + 0x20) = *(uint32_t *)((intptr_t)self + 0x10);
      }
      (**(code **)(**(int **)((intptr_t)self + 8) + 0x7c))
                (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + 0x80),
                 *(uint32_t *)((intptr_t)self + 0x1d0));
      (**(code **)(**(int **)((intptr_t)self + 8) + 0x58))
                (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + 0x80),1);
    }
    else if (arg1 != 2) {
      if (arg1 != 3) {
        return;
      }
      uvalue3 = Sound_SetVolume(self,*(uint32_t *)((intptr_t)self + 0x10));
      if ((char)uvalue3 == '\0') {
        uptr1 = (uint32_t *)((intptr_t)self + 0x20);
        (**(code **)(**(int **)((intptr_t)self + 8) + 0x34))
                  (*(int **)((intptr_t)self + 8),s_Speech_Statements_01_wav_005760ec,1,uptr1);
        (**(code **)(**(int **)((intptr_t)self + 8) + 0x80))
                  (*(int **)((intptr_t)self + 8),*uptr1,*(uint32_t *)((intptr_t)self + 0x1d8));
        (**(code **)(**(int **)((intptr_t)self + 8) + 0x60))(*(int **)((intptr_t)self + 8),*uptr1,1);
        *(uint8_t *)((intptr_t)self + 0xff) = 1;
        return;
      }
      *(uint32_t *)((intptr_t)self + 0x20) = *(uint32_t *)((intptr_t)self + 0x10);
      return;
    }
    uptr1 = (uint32_t *)((intptr_t)self + 0xc);
    if (((*(int *)((intptr_t)self + 0xc) == 0) && (value2 = *(int *)((intptr_t)self + 0x108), value2 != -1)) &&
       (value2 < 0xc)) {
      String_Format(local_104,(uint8_t *)s_Music__s_005760e0,
                    (&PTR_s_Mus_Menue_Start_wav_00575220)[value2]);
      (**(code **)(**(int **)((intptr_t)self + 8) + 0x34))(*(int **)((intptr_t)self + 8),local_104,1,uptr1);
      (**(code **)(**(int **)((intptr_t)self + 8) + 0x78))
                (*(int **)((intptr_t)self + 8),*uptr1,
                 *(uint32_t *)((intptr_t)self + *(int *)((intptr_t)self + 0x108) * 4 + 0x10c));
      (**(code **)(**(int **)((intptr_t)self + 8) + 0x80))
                (*(int **)((intptr_t)self + 8),*uptr1,*(uint32_t *)((intptr_t)self + 0x1d4));
      (**(code **)(**(int **)((intptr_t)self + 8) + 0x60))(*(int **)((intptr_t)self + 8),*uptr1,1);
    }
  }
  return;
}
