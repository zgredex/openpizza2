// SoundVoiceThread_Construct: ported from Pizza Connection 2 at 0x542720.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x542720
#include "pc2_port.h"


uint32_t * __thiscall SoundVoiceThread_Construct(void *self,int *arg1)

{
  HANDLE pvVar1;
  
  *(uint32_t *)((intptr_t)self + 4) = 0;
  *(uint32_t *)((intptr_t)self + 8) = 0;
  *(uint32_t *)((intptr_t)self + 0xc) = 0;
  *(uint32_t *)((intptr_t)self + 0x10) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0x14));
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  *(uint32_t *)((intptr_t)self + 0x30) = 0;
  *(uint8_t *)((intptr_t)self + 0x34) = 0;
  *(uint8_t ***)self = &PTR_SoundMixerThread_Delete_0055c8f0;
  if (arg1 != (int *)0x0) {
    if (*arg1 < 0) {
      return self;
    }
    *arg1 = 0;
  }
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
  *(HANDLE *)((intptr_t)self + 0x2c) = pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    if (arg1 != (int *)0x0) {
      *arg1 = -0x7fffbffb;
      return self;
    }
  }
  else {
    pvVar1 = CRT_BeginThread(0x5427b0,0,(intptr_t)self);
    *(HANDLE *)((intptr_t)self + 0x30) = pvVar1;
    if ((pvVar1 == (HANDLE)0xffffffff) && (arg1 != (int *)0x0)) {
      *arg1 = -0x7fffbffb;
    }
  }
  return self;
}
