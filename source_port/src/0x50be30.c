// Courier_StartHeadquartersBombing: ported from Pizza Connection 2 at 0x50be30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50be30
#include "pc2_port.h"

void __thiscall Courier_StartHeadquartersBombing(void *self,int arg1)

{
                    /* Starts a courier on a headquarters bombing job. */
  Object_SetFieldA4Locked(self,5);
  UI_SetChildState(self,0x22);
  Object_SetChildField2C(self,0x10);
  Object_SetDestinationAndTarget(self,0xc,arg1);
  return;
}
