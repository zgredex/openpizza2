// UI_ReleasePendingSprite: ported from Pizza Connection 2 at 0x527a50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527a50
#include "pc2_port.h"

void __fastcall UI_ReleasePendingSprite(int arg1)

{
  UI_ClearChildExtent(*(uint32_t **)(arg1 + 0x8310));
  if (*(uint32_t **)(arg1 + 0x8314) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 0x8314))(1);
  }
  *(uint32_t *)(arg1 + 0x8314) = 0;
  return;
}
