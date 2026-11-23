// Company_OptimizeMenuPricing: ported from Pizza Connection 2 at 0x4fe570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fe570
#include "pc2_port.h"

uint32_t __thiscall Company_OptimizeMenuPricing(void *self,int arg1)

{
  int value1;
  int value2;
  uint32_t *uptr3;
  int value4;
  
                    /* Optimizes company menu prices and sales allocation. */
  AI_BuyUndervaluedBuildings(self,arg1);
  value1 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x70);
  value2 = Game_GetPlayerFieldC20(value1);
  if (value2 < 1) {
    return 1;
  }
  value2 = *(int *)(value1 + 0x140);
  value4 = 0;
  if (0 < value2) {
    do {
      uptr3 = (uint32_t *)IDMap_Lookup((void *)(value1 + 300),value4,(int *)0x0);
      GamePlan_Optimize(self,arg1,uptr3);
      value4 = value4 + 1;
    } while (value4 < value2);
  }
  Company_AllocateMenuSales(self,arg1);
  return 1;
}
