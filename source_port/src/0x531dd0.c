// UI_OffsetPoint: ported from Pizza Connection 2 at 0x531dd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531dd0
#include "pc2_port.h"

void __thiscall UI_OffsetPoint(void *self,int *arg1,int *arg2)

{
  *arg1 = *arg1 + *(int *)((intptr_t)self + 0x18);
  *arg2 = *arg2 + *(int *)((intptr_t)self + 0x1c);
  return;
}
