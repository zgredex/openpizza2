// City_ChargePoliceBribes: ported from Pizza Connection 2 at 0x4da2a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da2a0
#include "pc2_port.h"

void __fastcall City_ChargePoliceBribes(void *arg1)

{
  void *self;
  uint32_t uvalue1;
  int value2;
  int *ptr3;
  
                    /* Charges police protection money for each player. */
  value2 = 0;
  ptr3 = (int *)((intptr_t)arg1 + 0xcb0);
  do {
    self = (void *)Game_GetPlayerBySlot(DAT_0057c670,value2);
    if (self != (void *)0x0) {
      if (*ptr3 != 0) {
        uvalue1 = Game_CanAffordWithCurrency(self,0x15,(float)*ptr3,'\x01',0xffffffff);
        if ((char)uvalue1 == '\0') {
          City_SetPlayerAdvertisingBudget(arg1,value2,0);
        }
      }
    }
    value2 = value2 + 1;
    ptr3 = ptr3 + 1;
  } while (value2 < 6);
  return;
}
