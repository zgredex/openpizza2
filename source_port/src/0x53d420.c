// Sprite_GetFormat: ported from Pizza Connection 2 at 0x53d420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d420
#include "pc2_port.h"

uint8_t __fastcall Sprite_GetFormat(int arg1)

{
  return *(uint8_t *)(arg1 + 4);
}
