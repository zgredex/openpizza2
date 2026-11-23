// CS_LeaveObject: ported from Pizza Connection 2 at 0x5508c9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5508c9
#include "pc2_port.h"

void __cdecl CS_LeaveObject(uint32_t arg1)

{
  if ((arg1 < 0x576788) || (0x5769e8 < arg1)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(arg1 + 0x20));
    return;
  }
  CS_LeaveIndexed(((intptr_t)(arg1 - 0x576788) >> 5) + 0x1c);
  return;
}
