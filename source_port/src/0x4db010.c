// City_SetPlayerAdvertisingBudget: ported from Pizza Connection 2 at 0x4db010.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4db010
#include "pc2_port.h"

void __thiscall City_SetPlayerAdvertisingBudget(void *self,int arg1,uint32_t arg2)

{
                    /* Stores a player's advertising budget and rebuilds billboards. */
  *(uint32_t *)((intptr_t)self + arg1 * 4 + 0xcb0) = arg2;
  City_UpdateSecurityPatrolFrames(self,0);
  return;
}
