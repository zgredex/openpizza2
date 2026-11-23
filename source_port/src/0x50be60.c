// Thug_StartRestaurantRampage: ported from Pizza Connection 2 at 0x50be60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50be60
#include "pc2_port.h"

void __thiscall Thug_StartRestaurantRampage(void *self,int arg1,uint32_t arg2)

{
                    /* Starts a thug's restaurant rampage. */
  Object_SetDestinationAndTarget(self,1,*(int *)(arg1 + 0x16f0));
  Object_SetFieldA4Locked(self,arg2);
  return;
}
