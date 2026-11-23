// UI_TickChildRepeatTimer: ported from Pizza Connection 2 at 0x5328e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5328e0
#include "pc2_port.h"

void __thiscall UI_TickChildRepeatTimer(void *self,int arg1)

{
  int value1;
  
  if ((*(int *)((intptr_t)self + 0x29c) != 0) &&
     (value1 = *(int *)((intptr_t)self + 0x2a4) - arg1, *(int *)((intptr_t)self + 0x2a4) = value1, value1 < 0)
     ) {
    UI_QueueControlCommand(self,-1,0x1d,0);
    *(int *)((intptr_t)self + 0x2a4) = *(int *)((intptr_t)self + 0x2a4) + *(int *)((intptr_t)self + 0x2a0);
  }
  return;
}
