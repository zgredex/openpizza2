// CRT_LockFile: ported from Pizza Connection 2 at 0x550877.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x550877
#include "pc2_port.h"

void __cdecl CRT_LockFile(uint32_t arg1)

{
  if ((arg1 < 0x576788) || (0x5769e8 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(arg1 + 0x20));
    return;
  }
  CRT_Lock(((intptr_t)(arg1 - 0x576788) >> 5) + 0x1c);
  return;
}
