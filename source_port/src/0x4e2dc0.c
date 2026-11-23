// Player_ReleaseAssignmentForObject: ported from Pizza Connection 2 at 0x4e2dc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2dc0
#include "pc2_port.h"

void __thiscall Player_ReleaseAssignmentForObject(void *self,int *arg1)

{
  int *ptr1;
  int *ptr2;
  int value3;
  
                    /* Releases a player's assignment entry for a map object. */
  value3 = 0;
  if (0 < *(int *)((intptr_t)self + 0x1cc)) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value3,(int *)0x0);
      ptr2 = (int *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr1,(int *)0x0);
      if (ptr2 == arg1) break;
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x1cc));
    arg1 = ptr1;
  }
  if (value3 != *(int *)((intptr_t)self + 0x1cc)) {
    Company_RemoveStaffMember(self,*arg1);
  }
  return;
}
