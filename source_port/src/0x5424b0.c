// SoundVoice_WriteSamples: ported from Pizza Connection 2 at 0x5424b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5424b0
#include "pc2_port.h"

int __thiscall SoundVoice_WriteSamples(void *self,int arg1,uint32_t arg2)

{
  void *this_00;
  char *cptr1;
  uint32_t uvalue2;
  int value3;
  int value4;
  
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  cptr1 = (char *)SoundBuffer_LockSample(*(void **)((intptr_t)self + 0x28),arg1,arg2);
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  if (cptr1 == (char *)0x0) {
    return -0x7fffbffb;
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  if (*(char *)((intptr_t)self + 0x88) != '\0') {
    this_00 = *(void **)((intptr_t)self + 0x2c);
    uvalue2 = (uint32_t)*(uint16_t *)(*(int *)((intptr_t)self + 0x28) + 0x24) * *(int *)((intptr_t)self + 0x84);
    if (*(uint32_t *)((intptr_t)this_00 + 0x28) < uvalue2) {
      SoundBuffer_SeekSample(this_00,0);
      *(uint32_t *)((intptr_t)self + 0x84) = 0;
    }
    else {
      SoundBuffer_SeekSample(this_00,uvalue2);
    }
    *(uint8_t *)((intptr_t)self + 0x88) = 0;
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  value3 = SoundSample_ReadPCM(*(void **)((intptr_t)self + 0x2c),cptr1,arg2);
  if (-1 < value3) {
    *(int *)((intptr_t)self + 0x84) =
         *(int *)((intptr_t)self + 0x84) + arg2 / *(uint16_t *)(*(int *)((intptr_t)self + 0x28) + 0x24);
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  value4 = SoundBuffer_UnlockSample(*(int *)((intptr_t)self + 0x28));
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  if (-1 < value3) {
    value3 = value4;
  }
  return value3;
}
