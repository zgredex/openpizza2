// CRT_LockFileHandle: ported from Pizza Connection 2 at 0x5545ef.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5545ef
#include "pc2_port.h"

void __cdecl CRT_LockFileHandle(uint32_t arg1)

{
  int value1;
  int value2;
  
  value2 = (arg1 & 0x1f) * 0x24;
  value1 = (&DAT_00586c20)[(intptr_t)arg1 >> 5] + value2;
  if (*(int *)(value1 + 8) == 0) {
    CRT_Lock(0x11);
    if (*(int *)(value1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(value1 + 0xc));
      *(int *)(value1 + 8) = *(int *)(value1 + 8) + 1;
    }
    CS_LeaveIndexed(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 0xc + value2));
  return;
}
