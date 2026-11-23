// Renderer_GetTextObject: ported from Pizza Connection 2 at 0x52e8e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e8e0
#include "pc2_port.h"

uint32_t __fastcall Renderer_GetTextObject(int arg1)

{
  return *(uint32_t *)(arg1 + 0x18);
}
