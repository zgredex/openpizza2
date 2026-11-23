// Company_AssignStaffToBranch: ported from Pizza Connection 2 at 0x4fe370.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fe370
#include "pc2_port.h"

uint32_t Company_AssignStaffToBranch(void *arg1,int arg2)

{
  int value1;
  int *ptr2;
  void *self;
  
                    /* Assigns a free staff member to a branch building. */
  value1 = Game_CountObjectsForOwner(arg1,arg2,0x17);
  if (value1 == 0) {
    return 0;
  }
  ptr2 = Game_FindAssignedSubrecord(arg1,arg2,0);
  if (ptr2 == (int *)0x0) {
    ptr2 = Game_FindAssignedSubrecord(arg1,arg2,1);
    if (ptr2 == (int *)0x0) {
      return 0;
    }
  }
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr2,(int *)0x0);
  if (*(int *)((intptr_t)self + 0x74) == 0) {
    if (*(int *)((intptr_t)arg1 + 0x1d8) == 0) {
      Company_RemoveStaffMember(arg1,*ptr2);
    }
    else {
      Person_SetRouteToBuilding(self,*(int *)((intptr_t)arg1 + 0x1d8));
    }
  }
  else {
    *(uint8_t *)((intptr_t)self + 0x81) = 1;
  }
  Object_SetFieldA4Locked(self,0xffffffff);
  *(uint32_t *)((intptr_t)self + 0x10c) = 0xffffffff;
  return 1;
}
