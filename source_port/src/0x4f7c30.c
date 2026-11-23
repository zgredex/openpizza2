// Branch_ValidateMenuAndRecalculate: ported from Pizza Connection 2 at 0x4f7c30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7c30
#include "pc2_port.h"

uint32_t __thiscall Branch_ValidateMenuAndRecalculate(void *self,void *arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
                    /* Validates a branch menu mix and recalculates its economy. */
  value1 = Game_CountObjectsByType(arg1,0xffffffff);
  value2 = Game_CountObjectsByType(arg1,0);
  value3 = Game_CountObjectsByType(arg1,3);
  value4 = Game_CountObjectsByType(arg1,2);
  if (((value2 == 0) || (value3 + value4 == 0)) && (0 < value1)) {
    Branch_RemoveAllStaff(arg1);
  }
  else if (value1 != 0) goto LAB_004f7c94;
  Branch_AssignEntranceAndCustomerSlots(self,arg1,0);
LAB_004f7c94:
  Branch_AutoTunePrice(arg1);
  return 1;
}
