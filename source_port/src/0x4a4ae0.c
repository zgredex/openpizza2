// Guard_RemoveFromRestaurant: ported from Pizza Connection 2 at 0x4a4ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a4ae0
#include "pc2_port.h"

void __cdecl Guard_RemoveFromRestaurant(int arg1,void *arg2)

{
  void *pvVar1;
  int value2;
  
                    /* Removes a guard from the selected restaurant and refreshes its rows. */
  pvVar1 = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  value2 = IDMap_Lookup((void *)((intptr_t)pvVar1 + 0x148),arg1,(int *)0x0);
  value2 = Company_AssignStaffToBranch(pvVar1,value2);
  if (value2 == 0) {
    Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_005825a4,DAT_00581224,0);
    return;
  }
  CompanyOverview_UpdateBuildingRows(arg2,DAT_0057d264);
  return;
}
