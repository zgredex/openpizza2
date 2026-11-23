// CS_LeaveIndexed: ported from Pizza Connection 2 at 0x5539be.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5539be
#include "pc2_port.h"

void __cdecl CS_LeaveIndexed(int arg1)

{
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_00576e70 + arg1 * 4));
  return;
}
