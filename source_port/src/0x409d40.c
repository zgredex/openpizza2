// Object_AdvanceToQueuedTarget: ported from Pizza Connection 2 at 0x409d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x409d40
#include "pc2_port.h"

uint32_t __thiscall Object_AdvanceToQueuedTarget(void *self,void *arg1,void *arg2)

{
  int value1;
  
                    /* Advances an object to its next queued target or walks to the current one. */
  value1 = AdCampaign_GoToNextQueuedBuilding(self,(intptr_t)arg1,arg2);
  if (value1 == 0) {
    Object_SetChildField2C(arg2,0x10);
    Customer_ApproachBranchEntrance(arg1,arg2);
    return 0;
  }
  return 1;
}
