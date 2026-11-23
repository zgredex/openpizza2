// CS_LeaveRaw: ported from Pizza Connection 2 at 0x54d367.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d367
#include "pc2_port.h"

void __cdecl CS_LeaveRaw(LPCRITICAL_SECTION arg1)

{
  LeaveCriticalSection(arg1);
  return;
}
