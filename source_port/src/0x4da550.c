// City_SpawnResidentInPreferredCity: ported from Pizza Connection 2 at 0x4da550.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da550
#include "pc2_port.h"

void __fastcall City_SpawnResidentInPreferredCity(int arg1)

{
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  int value4;
  void *self;
  
                    /* Moves a resident into the preferred or random city. */
  value1 = Game_CountPlayerRecordsByField34(DAT_0057c670,arg1);
  if (value1 != 0) {
    uvalue2 = Game_GetMostAdvancedCompany(arg1);
    uvalue3 = Random_RangeFast(0,100);
    if ((0x24 < (intptr_t)uvalue3) || (uvalue2 == 0xffffffff)) {
      value1 = Game_GetPlayerCount((intptr_t)DAT_0057c670);
      uvalue2 = Random_RangeFast(0,value1 - 1);
    }
    value1 = Game_GetPlayerBySlot(DAT_0057c670,uvalue2);
    if (*(int *)(value1 + 0x15c) != 0) {
      uvalue2 = Random_RangeFast(0,*(int *)(value1 + 0x15c) - 1);
      value4 = IDMap_Lookup((void *)(value1 + 0x148),uvalue2,(int *)0x0);
      if (value4 != 0) {
        self = (void *)Game_FindFreeObjectByOwner(DAT_0057c670,0x18,'\0');
        if (((*(int *)((intptr_t)self + 0xa4) == -1) && (*(char *)((intptr_t)self + 0x104) != '\0')) &&
           (*(int *)((intptr_t)self + 0x74) != 1)) {
          Person_AssignBranchStaffRole(self,value4,0xc,0xffffffff,'\0');
          *(int *)(arg1 + 0xce0 + *(int *)(value1 + 0x48) * 4) =
               *(int *)(arg1 + 0xce0 + *(int *)(value1 + 0x48) * 4) + 1;
        }
      }
    }
  }
  return;
}
