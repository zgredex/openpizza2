// UI_QueueChildCommand: ported from Pizza Connection 2 at 0x528190.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528190
#include "pc2_port.h"

uint32_t __thiscall UI_QueueChildCommand(void *self,int arg1,int arg2)

{
  if (*(int *)((intptr_t)self + 0x8304) == 0) {
    return 0;
  }
  UI_QueueCommand(self,*(int *)((intptr_t)self + 0x8304),0,0,arg1,arg2);
  return 1;
}
