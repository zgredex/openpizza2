// AI_HireBranchWorker: ported from Pizza Connection 2 at 0x4ff4c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ff4c0
#include "pc2_port.h"

uint32_t AI_HireBranchWorker(void *arg1,int arg2)

{
  int *ptr1;
  void *self;
  uint32_t uvalue2;
  
                    /* Hires a free worker for a branch and sends it to a target. */
  ptr1 = Game_FindFreeStaffRecord(arg1,0x1d);
  if (ptr1 == (int *)0x0) {
    return 0;
  }
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr1,(int *)0x0);
  if (self == (void *)0x0) {
    return 0;
  }
  uvalue2 = Game_CanAffordWithCurrency(arg1,0x17,5000.0,'\x01',0xffffffff);
  if ((char)uvalue2 == '\0') {
    return 0;
  }
  Person_SendToBranchForAction(self,arg2,0x10);
  return 1;
}
