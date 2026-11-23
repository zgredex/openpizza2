// Sprite_GetPalette: ported from Pizza Connection 2 at 0x53d4a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d4a0
#include "pc2_port.h"

uint32_t __fastcall Sprite_GetPalette(int arg1)

{
  return *(uint32_t *)(arg1 + 0x20);
}
