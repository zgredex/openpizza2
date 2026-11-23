// CRT_Lock: ported from Pizza Connection 2 at 0x55395d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55395d
#include "pc2_port.h"

void __cdecl CRT_Lock(int arg1)

{
  int *ptr1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  ptr1 = (int *)(&DAT_00576e70 + arg1 * 4);
  if (*(int *)(&DAT_00576e70 + arg1 * 4) == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    CRT_Lock(0x11);
    if (*ptr1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *ptr1 = (intptr_t)lpCriticalSection;
    }
    else {
      CRT_FreeInternal(lpCriticalSection);
    }
    CS_LeaveIndexed(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*ptr1);
  return;
}
