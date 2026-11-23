// UI_ClipChildRect: ported from Pizza Connection 2 at 0x521b30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521b30
#include "pc2_port.h"

void __fastcall UI_ClipChildRect(int arg1)

{
  UI_ClipRect(*(void **)(arg1 + 8),(int *)(arg1 + 0x28),1);
  return;
}
