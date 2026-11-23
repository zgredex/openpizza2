// CRT_RegisterMissionListCleanup: ported from Pizza Connection 2 at 0x403d70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403d70
#include "pc2_port.h"

void CRT_RegisterMissionListCleanup(void)

{
  CRT_Atexit(0x403d80);
  return;
}
