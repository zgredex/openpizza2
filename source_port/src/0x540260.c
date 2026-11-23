// SoundStream_Close: ported from Pizza Connection 2 at 0x540260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540260
#include "pc2_port.h"

void __thiscall SoundStream_Close(void *self,int arg1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0x23c));
  if (*(int *)(arg1 + 0x1c) == 1) {
    CRT_Fclose(*(FILE **)(arg1 + 0x18));
  }
  *(uint32_t *)(arg1 + 0x14) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0x23c));
  return;
}
