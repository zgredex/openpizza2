// CRT_LockFile2: ported from Pizza Connection 2 at 0x5508a6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5508a6
#include "pc2_port.h"

void __cdecl CRT_LockFile2(int arg1,int arg2)

{
  if (arg1 < 0x14) {
    CRT_Lock(arg1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(arg2 + 0x20));
  return;
}
