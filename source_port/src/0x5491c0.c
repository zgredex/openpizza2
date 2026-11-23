// Sound_PlayTutorialSpeech: ported from Pizza Connection 2 at 0x5491c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5491c0
#include "pc2_port.h"

void __thiscall Sound_PlayTutorialSpeech(void *self,int arg1,char arg2,char arg3)

{
  int value1;
  uint32_t uvalue2;
  uint32_t *uptr3;
  int value4;
  uint8_t local_104 [260];
  
  if (*(char *)((intptr_t)self + 0xfc) == '\0') {
    return;
  }
  if (9 < arg1) {
    return;
  }
  value1 = (intptr_t)self + 0x178;
  CS_Enter(value1);
  if (arg3 == '\0') {
    *(uint32_t *)((intptr_t)self + 0x164) = 0xffffffff;
    CS_Leave(value1);
    return;
  }
  if (arg2 == '\0') {
    if (arg1 != *(int *)((intptr_t)self + 0x164)) {
      *(uint32_t *)((intptr_t)self + 0x16c) = 0x1e;
      value4 = arg1 * 2 + 1;
LAB_00549278:
      if (*(int *)((intptr_t)self + 0x10) != 0) {
        (**(code **)(**(int **)((intptr_t)self + 8) + 0x54))
                  (*(int **)((intptr_t)self + 8),*(int *)((intptr_t)self + 0x10));
        *(uint32_t *)((intptr_t)self + 0x10) = 0;
        *(uint32_t *)((intptr_t)self + 0x14) = 0;
      }
      String_Format(local_104,(uint8_t *)s_Speech_Tutorial__02d_wav_005761b8,value4);
      uptr3 = Sound_Play(self,local_104,3);
      *(uint32_t **)((intptr_t)self + 0x10) = uptr3;
      if (uptr3 != (uint32_t *)0x0) {
        *(uint32_t *)((intptr_t)self + 0x14) = 1;
      }
      *(int *)((intptr_t)self + 0x164) = arg1;
      CS_Leave(value1);
      return;
    }
  }
  else if ((*(int *)((intptr_t)self + 0x14) != 1) ||
          (uvalue2 = Sound_SetVolume(self,*(uint32_t *)((intptr_t)self + 0x10)), (char)uvalue2 == '\0')) {
    if (*(int *)((intptr_t)self + 0x16c) == 0) {
      *(uint32_t *)((intptr_t)self + 0x16c) = 0x1e;
      value4 = arg1 * 2 + 2;
      goto LAB_00549278;
    }
    *(int *)((intptr_t)self + 0x16c) = *(int *)((intptr_t)self + 0x16c) + -1;
  }
  CS_Leave(value1);
  return;
}
