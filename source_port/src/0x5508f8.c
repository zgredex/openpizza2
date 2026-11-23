// CRT_UnlockHandle: ported from Pizza Connection 2 at 0x5508f8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5508f8
#include "pc2_port.h"

void __cdecl CRT_UnlockHandle(int arg1,int arg2)

{
  if (arg1 < 0x14) {
    CS_LeaveIndexed(arg1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(arg2 + 0x20));
  return;
}
