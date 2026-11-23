// City_TickBranches: ported from Pizza Connection 2 at 0x4fc630.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc630
#include "pc2_port.h"

uint32_t __thiscall City_TickBranches(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  void *pvVar3;
  int value4;
  int value5;
  int unaff_ESI;
  int unaff_EDI;
  void *local_4;
  
                    /* Runs the city's branch action tick. */
  value1 = *(int *)(*(int *)((intptr_t)self + arg1 * 0x168 + 0x70) + 0x15c);
  local_4 = self;
  City_EnsurePedestrianCoverage(self,arg1);
  value5 = 0;
  if (0 < value1) {
    do {
      pvVar3 = (void *)Game_GetPlayerSubrecord(self,arg1,value5,1);
      if (((pvVar3 != (void *)0x0) && (*(void **)((intptr_t)pvVar3 + 0x16f0) != (void *)0x0)) &&
         (value4 = Game_CountFreeBuildingsByType(*(void **)((intptr_t)pvVar3 + 0x16f0),0x1e), value4 == 0))
      {
        Game_GetBestObject(pvVar3,1,0x22,(float *)&local_4);
      }
      value5 = value5 + 1;
    } while (value5 < value1);
  }
  value5 = 0;
  if (0 < value1) {
    do {
      pvVar3 = (void *)Game_GetPlayerSubrecord(self,arg1,value5,1);
      if ((pvVar3 != (void *)0x0) && (*(int *)((intptr_t)pvVar3 + 0x2c) == 0)) {
        uvalue2 = *(uint32_t *)((intptr_t)pvVar3 + 0x28);
        if ((uvalue2 & 2) != 0) {
          Branch_ValidateMenuAndRecalculate(self,pvVar3);
          break;
        }
        if ((uvalue2 & 0x10) != 0) {
          Company_OpenBranchAtSite(self,arg1,pvVar3);
          break;
        }
        if ((uvalue2 & 0x20) != 0) {
          Branch_AutoTunePrice(pvVar3);
          break;
        }
        if ((uvalue2 & 4) != 0) {
          Customer_VisitBranch
                    (arg1,(intptr_t)pvVar3,(void *)0xffffffff,-1,-1,(uint32_t *)0xffffffff,unaff_EDI
                     ,unaff_ESI);
          break;
        }
      }
      value5 = value5 + 1;
    } while (value5 < value1);
  }
  Company_RefreshMenuSalesIfDue(self,arg1);
  return 1;
}
