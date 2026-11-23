// Person_SendToBranchWithCarryMode: ported from Pizza Connection 2 at 0x50b680.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b680
#include "pc2_port.h"

void __thiscall Person_SendToBranchWithCarryMode(void *self,int arg1,uint32_t arg2)

{
                    /* Sends a person to a branch with a carry/path mode. */
  Object_SetChildField2C(self,0x10);
  Object_SetDestinationAndTarget(self,1,*(int *)(arg1 + 0x16f0));
  Object_SetFieldA4Locked(self,arg2);
  if (*(int *)((intptr_t)self + 0xa4) == 0x11) {
    UI_SetChildState(self,0x22);
    return;
  }
  UI_SetChildState(self,0x15);
  return;
}
