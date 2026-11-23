// SoundVoice_WriteSilence: ported from Pizza Connection 2 at 0x5425b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5425b0
#include "pc2_port.h"

uint32_t __thiscall SoundVoice_WriteSilence(void *self,int arg1,uint32_t arg2)

{
  uint32_t *uptr1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  uptr1 = (uint32_t *)SoundBuffer_LockSample(*(void **)((intptr_t)self + 0x28),arg1,arg2);
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  if (uptr1 == (uint32_t *)0x0) {
    return 0x80004005;
  }
  for (uvalue3 = arg2 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *uptr1 = 0;
    uptr1 = uptr1 + 1;
  }
  for (uvalue3 = arg2 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(uint8_t *)uptr1 = 0;
    uptr1 = (uint32_t *)((intptr_t)uptr1 + 1);
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  uvalue2 = SoundBuffer_UnlockSample(*(int *)((intptr_t)self + 0x28));
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  return uvalue2;
}
