// City_ProcessQuarterEnd: ported from Pizza Connection 2 at 0x4da480.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da480
#include "pc2_port.h"

void __thiscall City_ProcessQuarterEnd(void *self,int arg1)

{
  int value1;
  int *ptr2;
  uint32_t uvalue3;
  int value4;
  uint32_t *uptr5;
  int value6;
  uint32_t *uptr7;
  uint32_t *uptr8;
  
                    /* Processes city quarter-end maintenance, aging, and stats. */
  City_ChargePoliceBribes(self);
  Game_ChargeQuarterlyBribes((intptr_t)self);
  Game_AdjustPlayerRankingScores((intptr_t)self);
  City_SpawnResidentWeighted(self);
  if (arg1 != 0) {
    City_GenerateRatingNews((intptr_t)self);
  }
  value6 = *(int *)((intptr_t)self + 0xfdc);
  while (value6 = value6 + -1, -1 < value6) {
    ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0xfc8),value6,(int *)0x0);
    value4 = *ptr2;
    value1 = *(int *)(value4 + 0x38);
    if ((0x3c < value1) &&
       ((uvalue3 = _rand(), (uvalue3 & 7) == 0 ||
        (uvalue3 = Random_RangeFast(0,100), (intptr_t)uvalue3 < (value1 * 5 + -300) * 4)))) {
      City_RemovePersonAndMaintainPopulation(self,value4);
      Mem_Free(ptr2);
      Person_RemoveFromStaff(value4);
    }
  }
  value6 = 5;
  uptr5 = (uint32_t *)((intptr_t)self + 0xddc);
  do {
    uptr7 = uptr5;
    uptr8 = uptr5 + 6;
    for (value4 = 6; value4 != 0; value4 = value4 + -1) {
      *uptr8 = *uptr7;
      uptr7 = uptr7 + 1;
      uptr8 = uptr8 + 1;
    }
    value6 = value6 + -1;
    uptr7 = uptr5;
    for (value4 = 6; value4 != 0; value4 = value4 + -1) {
      *uptr7 = 0;
      uptr7 = uptr7 + 1;
    }
    uptr5 = uptr5 + 0x18;
  } while (value6 != 0);
  return;
}
