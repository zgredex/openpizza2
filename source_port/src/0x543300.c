// SoundBuffer_SetFrequency: ported from Pizza Connection 2 at 0x543300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x543300
#include "pc2_port.h"

int SoundBuffer_SetFrequency(int arg1,uint32_t arg2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int value1;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  EnterCriticalSection(lpCriticalSection);
  value1 = *(int *)(arg1 + 0x98);
  if (value1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    return value1;
  }
  if ((arg2 == 0) || (10000 < arg2)) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7ff8ffa9;
  }
  *(uint32_t *)(arg1 + 0x84) = arg2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}
