// CRT_LockExit: ported from Pizza Connection 2 at 0x54f3a4.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f3a4
#include "pc2_port.h"

void CRT_LockExit(void)

{
  CRT_Lock(0xd);
  return;
}
