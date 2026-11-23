// SoundBuffer_GetFrequency: ported from Pizza Connection 2 at 0x544840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x544840
#include "pc2_port.h"

int SoundBuffer_GetFrequency(int arg1,int *arg2,uint32_t *arg3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int value1;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  EnterCriticalSection(lpCriticalSection);
  *arg3 = 0;
  value1 = *(int *)(arg1 + 0x98);
  if (value1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    return value1;
  }
  if (arg2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7ff8fffa;
  }
  if (*(char *)(*arg2 + 0x53) == '\0') {
    *arg3 = 0;
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  *arg3 = *(uint32_t *)(*arg2 + 0x84);
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}
