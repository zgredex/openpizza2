// UI_ResetScrollPosition: ported from Pizza Connection 2 at 0x528160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528160
#include "pc2_port.h"

void __fastcall UI_ResetScrollPosition(int arg1)

{
  CS_Enter(arg1 + 0x1cc);
  *(uint32_t *)(arg1 + 0x82bc) = *(uint32_t *)(arg1 + 0x82c0);
  CS_Leave(arg1 + 0x1cc);
  return;
}
