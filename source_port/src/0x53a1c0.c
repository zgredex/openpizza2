// Gfx_BlendTable_RegisterAtexit: ported from Pizza Connection 2 at 0x53a1c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a1c0
#include "pc2_port.h"

void Gfx_BlendTable_RegisterAtexit(void)

{
  CRT_Atexit(0x53a1d0);
  return;
}
