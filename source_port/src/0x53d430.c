// Sprite_GetColorKey: ported from Pizza Connection 2 at 0x53d430.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d430
#include "pc2_port.h"

uint32_t __fastcall Sprite_GetColorKey(int arg1)

{
  if ((*(uint8_t *)(arg1 + 4) & 0x10) == 0) {
    return *(uint32_t *)(arg1 + 0x1c);
  }
  return 0;
}
