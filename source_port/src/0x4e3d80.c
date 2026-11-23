// Advertising_StopCampaign: ported from Pizza Connection 2 at 0x4e3d80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3d80
#include "pc2_port.h"

void __thiscall Advertising_StopCampaign(void *self,int arg1,int arg2,int arg3)

{
  uint32_t uvalue1;
  
                    /* Stops an advertising campaign in one media slot. */
  uvalue1 = (uint32_t)(arg2 == *(int *)((intptr_t)self + 0x48));
  *(uint8_t *)(arg1 + 0xac + (intptr_t)self) = 0;
  *(uint32_t *)((intptr_t)self + arg1 * 4 + 0xcc) = 0;
  *(uint32_t *)((intptr_t)self + arg1 * 4 + 0xb4) = 0;
  if (uvalue1 != 0) {
    *(uint32_t *)((intptr_t)self + arg1 * 4 + 0x94) = 0;
  }
  if (arg3 != 0) {
    Gangster_CancelJobsTargetingPlayer(arg1,uvalue1);
  }
  return;
}
