// UI_QueueControlCommand: ported from Pizza Connection 2 at 0x5301c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5301c0
#include "pc2_port.h"

void __thiscall UI_QueueControlCommand(void *self,int arg1,int arg2,int arg3)

{
  if (*(int *)((intptr_t)self + 0x48) != 0) {
    UI_QueueCommand(*(void **)((intptr_t)self + 0x134),*(int *)((intptr_t)self + 0x48),(intptr_t)self,arg1,
                    arg2,arg3);
  }
  return;
}
