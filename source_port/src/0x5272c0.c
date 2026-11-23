// UI_GetTextObject: ported from Pizza Connection 2 at 0x5272c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5272c0
#include "pc2_port.h"

void __fastcall UI_GetTextObject(int arg1)

{
  Renderer_GetTextObject(*(int *)(arg1 + 0x244));
  return;
}
