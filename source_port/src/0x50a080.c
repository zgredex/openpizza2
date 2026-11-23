// Person_SetRouteToBuilding: ported from Pizza Connection 2 at 0x50a080.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50a080
#include "pc2_port.h"

void __thiscall Person_SetRouteToBuilding(void *self,int arg1)

{
  int value1;
  int *ptr2;
  
  ptr2 = (int *)((intptr_t)self + 0xd4);
                    /* Sets a person's home and route slots to a building and sends it there. */
  for (value1 = 8; value1 != 0; value1 = value1 + -1) {
    *ptr2 = arg1;
    ptr2 = ptr2 + 1;
  }
  *(int *)((intptr_t)self + 0xcc) = arg1;
  Object_SetDestinationAndTarget(self,2,arg1);
  return;
}
