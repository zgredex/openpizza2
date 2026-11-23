// CompanyOverview_AssignEmployeeToBuilding: ported from Pizza Connection 2 at 0x4a4a60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a4a60
#include "pc2_port.h"


void __cdecl CompanyOverview_AssignEmployeeToBuilding(int arg1,void *arg2)

{
  int value1;
  int value2;
  
                    /* Assigns an employee to the selected building and refreshes rows. */
  value2 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  value1 = IDMap_Lookup((void *)(value2 + 0x148),arg1,(int *)0x0);
  value2 = Company_DispatchWorkerToBranch(value2,value1);
  if (value2 == 0) {
    Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_005825a4,((uint32_t)((DAT_00580fc0) >> 32)),0);
    return;
  }
  CompanyOverview_UpdateBuildingRows(arg2,DAT_0057d264);
  return;
}
