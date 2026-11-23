// Person_SendToBranchForAction: ported from Pizza Connection 2 at 0x50bed0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50bed0
#include "pc2_port.h"

void __thiscall Person_SendToBranchForAction(void *self,int arg1,uint32_t arg2)

{
                    /* Sends a person to a branch for a specific action. */
  Object_GetPlayerValue(self,-1);
  Object_SetDestinationAndTarget(self,1,*(int *)(arg1 + 0x16f0));
  Object_SetFieldA4Locked(self,arg2);
  return;
}
