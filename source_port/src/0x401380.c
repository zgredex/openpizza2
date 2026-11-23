// CRT_RegisterListLockCleanup: ported from Pizza Connection 2 at 0x401380.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401380
#include "pc2_port.h"

void CRT_RegisterListLockCleanup(void)

{
  CRT_Atexit(0x401390);
  return;
}
