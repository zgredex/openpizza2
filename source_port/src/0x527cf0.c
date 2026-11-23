// UI_ClearScrollDrag: ported from Pizza Connection 2 at 0x527cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527cf0
#include "pc2_port.h"

void __fastcall UI_ClearScrollDrag(int arg1)

{
  *(uint32_t *)(arg1 + 0x8338) = 0;
  *(uint32_t *)(arg1 + 0x833c) = 0;
  *(uint32_t *)(arg1 + 0x8348) = 0;
  return;
}
