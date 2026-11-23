// Company_EnsureRequiredBranch: ported from Pizza Connection 2 at 0x4fd0a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fd0a0
#include "pc2_port.h"

void Company_EnsureRequiredBranch(int arg1,void *arg2,int arg3)

{
  int value1;
  int value2;
  void *pvVar3;
  
                    /* Ensures a company has its scenario-required branch type. */
  value1 = *(int *)(arg1 + 0x48);
  value2 = Game_GetPlayerFieldC20(arg1);
  if (value2 == 0) {
    pvVar3 = (void *)AI_FindCheapestShop(*(int *)(arg1 + 0x48),arg2,0);
    if (pvVar3 != (void *)0x0) {
      Player_BuildHeadquarters(value1,arg2,pvVar3,arg3,1);
      *(int *)((intptr_t)arg2 + value1 * 4 + 0xc20) = arg3;
    }
  }
  return;
}
