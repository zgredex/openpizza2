// Person_WalkToCellOrAbort: ported from Pizza Connection 2 at 0x50e6b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e6b0
#include "pc2_port.h"

int __thiscall Person_WalkToCellOrAbort(void *self,int arg1)

{
  int value1;
  
                    /* Walks a person to a cell or aborts the order. */
  value1 = Person_AdvanceRoute(self,arg1);
  if (value1 == 0) {
    Object_SetState(self,6);
    *(uint8_t *)((intptr_t)self + 0x81) = 1;
    Person_ProcessMoveEvent(self);
    return 0;
  }
  Object_SetState(self,8);
  return value1;
}
