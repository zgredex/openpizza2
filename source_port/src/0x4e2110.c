// Company_RemoveStaffMember: ported from Pizza Connection 2 at 0x4e2110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2110
#include "pc2_port.h"

void __thiscall Company_RemoveStaffMember(void *self,int arg1)

{
  int value1;
  void *this_00;
  int value2;
  int *ptr3;
  
                    /* Unlinks a person from a company's staff map and reroutes it. */
  ptr3 = (int *)0x0;
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),arg1,(int *)0x0);
  if (this_00 != (void *)0x0) {
    *(uint32_t *)((intptr_t)this_00 + 0x110) = 0xffffffff;
    Object_SetBuildingRecordForAllCompanies(this_00,0x17,0);
    Object_SetFieldA4Locked(this_00,0xffffffff);
    *(uint32_t *)((intptr_t)this_00 + 0x10c) = 0xffffffff;
    if (*(int *)((intptr_t)this_00 + 0x74) == 0) {
      Object_SetDestinationAndTarget(this_00,5,*(int *)((intptr_t)this_00 + 0xcc));
    }
    else {
      *(uint8_t *)((intptr_t)this_00 + 0x81) = 1;
    }
    value1 = *(int *)((intptr_t)self + 0x1cc);
    value2 = 0;
    if (0 < value1) {
      do {
        ptr3 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value2,(int *)0x0);
        if (*ptr3 == arg1) break;
        value2 = value2 + 1;
      } while (value2 < value1);
    }
    IDMap_RemoveByKey((void *)((intptr_t)self + 0x1b8),(intptr_t)ptr3);
  }
  return;
}
