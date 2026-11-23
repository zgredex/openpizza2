// Company_AddStaffMember: ported from Pizza Connection 2 at 0x4e2080.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2080
#include "pc2_port.h"

void __thiscall Company_AddStaffMember(void *self,int arg1,int arg2)

{
  void *this_00;
  int *ptr1;
  
                    /* Registers a person as a company staff member. */
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),arg1,(int *)0x0);
  if (this_00 != (void *)0x0) {
    *(uint32_t *)((intptr_t)this_00 + 0x110) = *(uint32_t *)((intptr_t)self + 0x48);
    if (arg2 != 0x1f) {
      Object_GetPlayerValue(this_00,-1);
    }
    if (*(int *)((intptr_t)this_00 + 0x74) == 0) {
      Person_SetRouteToBuilding(this_00,*(int *)((intptr_t)self + 0x1d8));
    }
    else {
      Object_SetBuildingRecordForAllCompanies(this_00,0x1c,*(int *)((intptr_t)self + 0x1d8));
    }
    ptr1 = operator_new(8);
    *ptr1 = arg1;
    ptr1[1] = arg2;
    List_Add((void *)((intptr_t)self + 0x1b8),ptr1);
  }
  return;
}
