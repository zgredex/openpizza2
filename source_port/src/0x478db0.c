// Branch_RecalculateRatings: ported from Pizza Connection 2 at 0x478db0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x478db0
#include "pc2_port.h"

void Branch_RecalculateRatings(void)

{
  int *ptr1;
  void *self;
  int value2;
  uint32_t extraout_EDX;
  uint32_t *uptr3;
  int value4;
  uint8_t local_res0;
  
  __chkstk(local_res0);
  uptr3 = (uint32_t *)register0x00000010;
  for (value2 = 0x3200; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0x1718) = 1;
  Map_BuildObjectGrid(*(void **)((intptr_t)self + 0x14e0),(uint32_t *)&local_res0);
  Company_ComputeTypePercentages((intptr_t)self);
  Stats_ComputeBestPairShareAverage(self);
  Game_ComputeCategoryDominance((intptr_t)self);
  value2 = Stats_ComputeOccupancyPercent(self,(intptr_t)&local_res0);
  Stats_GetAverageValue(self,(intptr_t)&local_res0);
  Game_ComputeCityScore(self,value2,(intptr_t)&local_res0);
  Map_ComputeBuildableAverage(self,(intptr_t)&local_res0);
  Stats_ComputeTypeThreeShare(self);
  Game_UpdateActivePlayerCount(self);
  Game_ComputeCityConditionScore((intptr_t)self,extraout_EDX);
  NoOp_Stub();
  Stats_UpdateAverages(self,(intptr_t)&local_res0);
  Stats_ComputeWeightedTotals((intptr_t)self);
  Rating_ComputeBranchScores((intptr_t)self);
  ptr1 = (int *)((intptr_t)self + 0x17fc);
  value2 = 8;
  do {
    value4 = *ptr1 - *(int *)((intptr_t)self + 0x1878);
    *ptr1 = value4;
    if (value4 < 0) {
      *ptr1 = 0;
    }
    if (100 < *ptr1) {
      *ptr1 = 100;
    }
    ptr1 = ptr1 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
