// MissionMap_RegisterCleanup: ported from Pizza Connection 2 at 0x4cb3a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb3a0
#include "pc2_port.h"

void MissionMap_RegisterCleanup(void)

{
  CRT_Atexit(0x4cb3b0);
  return;
}
