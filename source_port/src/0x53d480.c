// Sprite_GetPixelBuffer: ported from Pizza Connection 2 at 0x53d480.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d480
#include "pc2_port.h"

uint32_t __fastcall Sprite_GetPixelBuffer(void *arg1)

{
  if (*(char *)((intptr_t)arg1 + 0x39) == '\0') {
    Sprite_RealizeLazy(arg1);
  }
  return *(uint32_t *)((intptr_t)arg1 + 0x2c);
}
