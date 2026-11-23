// Sound_PlayMissionSpeech: ported from Pizza Connection 2 at 0x549070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x549070
#include "pc2_port.h"

void __thiscall Sound_PlayMissionSpeech(void *self,int arg1,char arg2)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  uint8_t local_104 [260];
  
  if (((*(char *)((intptr_t)self + 0xfc) == '\0') || (arg1 < 0)) || (9 < arg1)) {
    return;
  }
  value1 = (intptr_t)self + 0x178;
  CS_Enter(value1);
  if (arg2 == '\0') {
    value3 = arg1 * 2 + 1;
    if (0 < arg1) {
      value3 = arg1 * 2;
    }
  }
  else {
    if (arg1 < 1) {
      CS_Leave(value1);
      return;
    }
    value3 = arg1 * 2 + 1;
    if (value3 == *(int *)((intptr_t)self + 0x160)) {
      CS_Leave(value1);
      return;
    }
  }
  if (*(int *)((intptr_t)self + 0x10) != 0) {
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x54))
              (*(int **)((intptr_t)self + 8),*(int *)((intptr_t)self + 0x10));
    *(uint32_t *)((intptr_t)self + 0x10) = 0;
    *(uint32_t *)((intptr_t)self + 0x14) = 0;
  }
  String_Format(local_104,(uint8_t *)s_Speech_Missionen__02d_wav_0057619c,value3);
  uptr2 = Sound_Play(self,local_104,3);
  *(uint32_t **)((intptr_t)self + 0x10) = uptr2;
  if (uptr2 != (uint32_t *)0x0) {
    *(uint32_t *)((intptr_t)self + 0x14) = 3;
    *(int *)((intptr_t)self + 0x160) = value3;
  }
  CS_Leave(value1);
  return;
}
