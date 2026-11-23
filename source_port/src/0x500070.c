// AI_BuyUndervaluedBuildings: ported from Pizza Connection 2 at 0x500070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x500070
#include "pc2_port.h"

void __thiscall AI_BuyUndervaluedBuildings(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  int *ptr6;
  void *pvVar7;
  int value8;
  int local_24;
  int local_1c;
  
                    /* Buys nearby undervalued buildings for an AI company. */
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value1 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x70);
  value3 = Game_GetPlayerFieldC20(value1);
  if (1 < value3) {
    value3 = *(int *)(value1 + 0x15c);
    local_1c = 0;
    if (0 < value3) {
      do {
        value4 = IDMap_Lookup((void *)(value1 + 0x148),local_1c,(int *)0x0);
        value5 = *(int *)(*(int *)(value4 + 0x16f0) + 0x74);
        if (value5 == 0) {
          local_24 = -1;
        }
        else {
          local_24 = Game_GetAdjustedValue(value5);
        }
        value5 = Branch_GetCachedBillboards(value4);
        value8 = 0;
        if (0 < value5) {
          do {
            ptr6 = (int *)IDMap_Lookup(*(void **)(value4 + 0x1a28),value8,(int *)0x0);
            pvVar7 = (void *)IDMap_Lookup((void *)(value2 + 0xfac),*ptr6,(int *)0x0);
            if (*(int *)((intptr_t)pvVar7 + 4) == 0x1b) {
              if (((double)ptr6[1] < (double)(local_24 + 0x4b) * 0.8) &&
                 (-1 < *(int *)((intptr_t)pvVar7 + 8))) {
                Branch_AddAdvertisingPlan(self,arg1,pvVar7,*(uint32_t *)(value4 + 0x3c));
              }
              if (((double)ptr6[1] < (double)(local_24 + 0x4b) * 0.9) &&
                 (*(int *)((intptr_t)pvVar7 + 8) == -1)) {
                Branch_AddAdvertisingPlan(self,arg1,pvVar7,*(uint32_t *)(value4 + 0x3c));
              }
            }
            value8 = value8 + 1;
          } while (value8 < value5);
        }
        local_1c = local_1c + 1;
      } while (local_1c < value3);
    }
  }
  return;
}
