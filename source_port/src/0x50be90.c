// Object_StartWorkOrderAndSetState: ported from Pizza Connection 2 at 0x50be90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50be90
#include "pc2_port.h"

void __thiscall
Object_StartWorkOrderAndSetState(void *self,int arg1,uint32_t arg2,uint32_t arg3)

{
                    /* Starts work order 1 toward a target and stores the work state. */
  Object_SetDestinationAndTarget(self,1,*(int *)(arg1 + 0x16f0));
  Object_SetFieldA4Locked(self,arg2);
  *(uint32_t *)((intptr_t)self + 0xac) = arg3;
  return;
}
