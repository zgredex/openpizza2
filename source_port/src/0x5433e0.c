// Media_SetValue94: ported from Pizza Connection 2 at 0x5433e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5433e0
#include "pc2_port.h"

int Media_SetValue94(int arg1,uint32_t arg2)

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
  *(uint32_t *)(arg1 + 0x94) = arg2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}
