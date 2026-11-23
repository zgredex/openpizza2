// Sound_ProcessEventWithCooldown: ported from Pizza Connection 2 at 0x5499b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5499b0
#include "pc2_port.h"

void __thiscall Sound_ProcessEventWithCooldown(void *self,int arg1,char arg2)

{
  if ((*(char *)((intptr_t)self + 0xfc) != '\0') && (*(int *)((intptr_t)self + 0x158) < 1)) {
    *(uint32_t *)((intptr_t)self + 0x158) = 2;
    Sound_ProcessEvent(self,arg1,0,arg2);
  }
  return;
}
