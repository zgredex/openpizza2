// Car_Save: ported from Pizza Connection 2 at 0x4d3450.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3450
#include "pc2_port.h"

void __thiscall Car_Save(void *self,void *arg1)

{
  MapSprite_Save(arg1,*(int **)((intptr_t)self + 8));
  return;
}
