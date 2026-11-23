// Company_OpenStartingBranch: ported from Pizza Connection 2 at 0x4f8a80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f8a80
#include "pc2_port.h"

uint32_t __thiscall
Company_OpenStartingBranch(void *self,int arg1,int arg2,int arg3,void *arg4)

{
  int value1;
  int value2;
  void *pvVar3;
  void *pvVar4;
  int value5;
  int unaff_ESI;
  int unaff_EDI;
  int local_8;
  int local_4;
  
                    /* Creates a scenario starting branch for a company. */
  value2 = arg1;
  value1 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x70);
  value5 = arg1 * 0x168;
  pvVar3 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
  if (pvVar3 == (void *)0x0) {
    return 0;
  }
  pvVar4 = (void *)AI_FindBestBranchSite(self,value2,pvVar3,arg3,&local_4);
  if (pvVar4 == (void *)0x0) {
    return 0;
  }
  if (arg2 == -1) {
    arg2 = 0;
  }
  Game_ComputeTradeOffers
            (pvVar3,(intptr_t)pvVar4,1,&arg1,&local_8,*(int *)((intptr_t)self + value5 + 0x40),(int *)0x0);
  value5 = Player_CreateBranch(self,*(int *)((intptr_t)pvVar3 + 0xc1c),pvVar4,value2,arg2,1);
  pvVar3 = (void *)IDMap_Lookup((void *)(value1 + 0x148),value5,(int *)0x0);
  if (arg3 == 0) {
    *(uint8_t *)((intptr_t)pvVar3 + 0x16f4) = 0;
    *(int *)((intptr_t)pvVar3 + 0x14b0) = arg1;
    DebugConsole_Printf(DAT_0057c1e0,0xff,(uint8_t *)s_Start_Filiale___s__gemietet__00571f04,
                        (intptr_t)pvVar3 + 4);
  }
  else {
    *(uint8_t *)((intptr_t)pvVar3 + 0x16f4) = 1;
    *(int *)((intptr_t)pvVar3 + 0x14b0) = arg1 >> 2;
    *(int *)((intptr_t)pvVar4 + 0x3c) = local_8;
    DebugConsole_Printf(DAT_0057c1e0,0xff,(uint8_t *)s_Start_Filiale___s__gekauft__00571f24,
                        (intptr_t)pvVar3 + 4);
  }
  Customer_VisitBranch(value2,(intptr_t)pvVar3,arg4,-1,-1,(uint32_t *)0xffffffff,unaff_EDI,unaff_ESI)
  ;
  Branch_ValidateMenuAndRecalculate(self,pvVar3);
  return 1;
}
