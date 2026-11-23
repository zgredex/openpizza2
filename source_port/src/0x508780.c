// Person_SetRandomResidentialTarget: ported from Pizza Connection 2 at 0x508780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508780
#include "pc2_port.h"

void __fastcall Person_SetRandomResidentialTarget(void *arg1)

{
  void *self;
  int value1;
  
                    /* Sends a person to a random residential building. */
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value1 = Map_GetRandomBuildingOfType(self,0x18,0,'\0');
  Object_SetDestinationAndTarget(arg1,0xd,value1);
  return;
}
