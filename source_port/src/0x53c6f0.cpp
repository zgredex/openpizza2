// Sprite_CriticalSection_RegisterAtexit: ported from Pizza Connection 2 at 0x53c6f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53c6f0
#include "pc2_port.h"

void Sprite_CriticalSection_RegisterAtexit(void)

{
  CRT_Atexit(0x53c700);
  return;
}
