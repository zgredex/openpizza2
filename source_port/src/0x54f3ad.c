// CRT_UnlockExit: ported from Pizza Connection 2 at 0x54f3ad.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f3ad
#include "pc2_port.h"

void CRT_UnlockExit(void)

{
  CS_LeaveIndexed(0xd);
  return;
}
