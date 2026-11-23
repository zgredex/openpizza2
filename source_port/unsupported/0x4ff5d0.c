// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x4ff5d0.c:18:61: error: use of undeclared identifier 'iRam00000000'
// AI_HireCourier: ported from Pizza Connection 2 at 0x4ff5d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ff5d0
#include "pc2_port.h"

uint32_t AI_HireCourier(void *arg1,int arg2)

{
  int *ptr1;
  void *self;
  uint32_t uvalue2;
  
                    /* Hires a courier and sends it to a target. */
  ptr1 = Game_FindFreeStaffRecord(arg1,0x1e);
  if (ptr1 != (int *)0x0) {
    return 0;
  }
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),iRam00000000,(int *)0x0);
  if (self == (void *)0x0) {
    return 0;
  }
  uvalue2 = Game_CanAffordWithCurrency(arg1,0x17,5000.0,'\x01',0xffffffff);
  if ((char)uvalue2 == '\0') {
    return 0;
  }
  Thug_StartRestaurantRampage(self,arg2,0xf);
  *(int *)((intptr_t)arg1 + 0x74) = *(int *)((intptr_t)arg1 + 0x74) + 1;
  return 1;
}
