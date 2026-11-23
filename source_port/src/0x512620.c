// Recipe_RecomputeAllStats: ported from Pizza Connection 2 at 0x512620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512620
#include "pc2_port.h"

void __thiscall Recipe_RecomputeAllStats(void *self,int arg1)

{
  int value1;
  short svalue2;
  int value3;
  int value4;
  int value5;
  int extraout_EDX;
  int unaff_EDI;
  uint32_t *uptr6;
  
  uptr6 = (uint32_t *)((intptr_t)self + 0x1e0);
  for (value5 = 0x18; value5 != 0; value5 = value5 + -1) {
    *uptr6 = 0;
    uptr6 = uptr6 + 1;
  }
  value5 = 0;
  if (0 < *(int *)((intptr_t)self + 0x5c)) {
    do {
      value4 = IDMap_Lookup((void *)((intptr_t)self + 0x48),value5,(int *)0x0);
      value3 = *(int *)(DAT_0057c670 + 0xa8 + (uint32_t)*(uint8_t *)(value4 + 4) * 4);
      value1 = (uint32_t)*(uint8_t *)(value4 + 0x10) + (uint32_t)*(uint8_t *)(value4 + 6) * 8;
      svalue2 = *(short *)(value3 + 0x48 + value1 * 2);
      *(int *)(value4 + 0x14) = ((intptr_t)*(short *)(value3 + 8 + value1 * 2) >> 1) + *(int *)(value4 + 8);
      *(int *)(value4 + 0x18) = ((intptr_t)svalue2 >> 1) + *(int *)(value4 + 0xc);
      Screen_AccumulateColorHistogram(self,value4,*(int *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18));
      value5 = value5 + 1;
    } while (value5 < *(int *)((intptr_t)self + 0x5c));
  }
  AI_CheckPriceCompetitiveness(self);
  PlayerStats_Reset((intptr_t)self);
  Screen_ScoreColorHistogram((intptr_t)self);
  Recipe_RecomputeLayoutQuality(self);
  Stats_ComputeWeightedAverages(self,unaff_EDI);
  Rating_StoreClampedScores((intptr_t)self);
  Game_ComputeMarketFactors((intptr_t)self);
  Game_ComputeFoodStats(self,extraout_EDX);
  Game_ComputeCompanyRatings(self,arg1);
  return;
}
