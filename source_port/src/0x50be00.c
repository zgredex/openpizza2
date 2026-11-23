// Object_StartOrderAction9: ported from Pizza Connection 2 at 0x50be00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50be00
#include "pc2_port.h"

void __thiscall Object_StartOrderAction9(void *self,int arg1)

{
                    /* Sets the object's work animation and starts order action 9. */
  Object_SetFieldA4Locked(self,0x1d);
  UI_SetChildState(self,0x22);
  Object_SetChildField2C(self,0x10);
  Object_SetDestinationAndTarget(self,9,arg1);
  return;
}
