// UI_RealizeSprite: ported from Pizza Connection 2 at 0x521380.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521380
#include "pc2_port.h"

void __fastcall UI_RealizeSprite(int arg1)

{
  Sprite_FillTransparentColor(*(void **)(arg1 + 0x60),-1);
  return;
}
