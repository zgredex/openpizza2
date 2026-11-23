// Gangster_StartProtectionCollection: ported from Pizza Connection 2 at 0x50bf00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50bf00
#include "pc2_port.h"

void __thiscall Gangster_StartProtectionCollection(void *self,int arg1)

{
                    /* Starts a gangster's protection collection. */
  Object_GetPlayerValue(self,-1);
  Object_SetDestinationAndTarget(self,1,*(int *)(arg1 + 0x16f0));
  Object_SetFieldA4Locked(self,0x1a);
  return;
}
