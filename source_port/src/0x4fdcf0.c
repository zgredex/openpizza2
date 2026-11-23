// City_MoveResidentIntoVacantHouse: ported from Pizza Connection 2 at 0x4fdcf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fdcf0
#include "pc2_port.h"

uint32_t City_MoveResidentIntoVacantHouse(void *arg1,int arg2,int arg3)

{
  void *self;
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  int local_c [3];
  
                    /* Moves a resident into a vacant house with an acceptance roll. */
  local_c[0] = 1000;
  local_c[1] = 1000;
  local_c[2] = 1000;
  if (*(char *)(arg3 + 0x1880 + arg2) != '\0') {
    return 3;
  }
  self = (void *)Game_FindIdleObjectByClass(DAT_0057c670,arg3);
  if (self == (void *)0x0) {
    return 3;
  }
  value1 = Game_GetPlayerCity((intptr_t)arg1);
  uvalue2 = Game_CanAffordWithCurrency
                    (arg1,0x17,
                     (float)((((*(int *)(value1 + 0x60) + *(int *)(value1 + 0x48)) * -3 + 100) *
                             local_c[arg3]) / 100),'\x01',0xffffffff);
  if ((char)uvalue2 == '\0') {
    return 2;
  }
  value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)(arg2 + 0x34),(int *)0x0);
  uvalue3 = Random_RangeFast(0,99);
  if ((intptr_t)uvalue3 <= *(int *)(value1 + 0xc38 + (arg3 + *(int *)((intptr_t)arg1 + 0x48) * 4) * 4)) {
    Person_AssignBranchStaffRole(self,arg2,arg3,*(int *)((intptr_t)arg1 + 0x48),'\x01');
    *(int *)((intptr_t)arg1 + 0x70) = *(int *)((intptr_t)arg1 + 0x70) + 1;
  }
  return 1;
}
