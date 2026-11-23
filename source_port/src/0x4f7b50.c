// Branch_RemoveAllStaff: ported from Pizza Connection 2 at 0x4f7b50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7b50
#include "pc2_port.h"

void Branch_RemoveAllStaff(void *arg1)

{
  int value1;
  int *ptr2;
  
                    /* Removes every staff member from a branch. */
  value1 = Game_CountObjectsByType(arg1,0xffffffff);
  value1 = value1 + -1;
  if (-1 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),value1,(int *)0x0);
      if (*ptr2 != 0) {
        Branch_RemoveStaffMember(arg1,ptr2,0);
      }
      value1 = value1 + -1;
    } while (-1 < value1);
  }
  return;
}
