// Sound_PlaySpeechStatement: ported from Pizza Connection 2 at 0x548e00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548e00
#include "pc2_port.h"

void __thiscall Sound_PlaySpeechStatement(void *self,int arg1)

{
  uint32_t uvalue1;
  uint32_t *uptr2;
  uint8_t auStack_104 [260];
  
  if (*(char *)((intptr_t)self + 0xfc) != '\0') {
    CS_Enter((intptr_t)self + 0x178);
    if ((*(char *)((intptr_t)self + 0x100) == '\0') && (arg1 != -1)) {
      uvalue1 = Sound_SetVolume(self,*(uint32_t *)((intptr_t)self + 0x10));
      if (((char)uvalue1 == '\0') ||
         ((*(int *)((intptr_t)self + 0x14) != 1 && (*(int *)((intptr_t)self + 0x14) != 3)))) {
        uvalue1 = Sound_SetVolume(self,*(uint32_t *)((intptr_t)self + 0x10));
        if ((char)uvalue1 == '\0') {
          (**(code **)(**(int **)((intptr_t)self + 8) + 0x54))
                    (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + 0x10));
          *(uint32_t *)((intptr_t)self + 0x10) = 0;
          *(uint32_t *)((intptr_t)self + 0x14) = 0;
          String_Format(auStack_104,(uint8_t *)s_Speech_Statements__02d_wav_00576180,arg1);
          uptr2 = Sound_Play(self,auStack_104,3);
          *(uint32_t **)((intptr_t)self + 0x10) = uptr2;
          if (uptr2 != (uint32_t *)0x0) {
            *(uint32_t *)((intptr_t)self + 0x14) = 2;
          }
        }
      }
    }
    CS_Leave((intptr_t)self + 0x178);
  }
  return;
}
