// Company_RecordDailyStatistics: ported from Pizza Connection 2 at 0x4dec10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dec10
#include "pc2_port.h"

void __fastcall Company_RecordDailyStatistics(uint32_t *arg1)

{
  int value1;
  uint32_t *uptr2;
  uint32_t *local_4;
  
  local_4 = arg1;
  local_4 = operator_new(0x1a0);
  if (*(int *)(*(int *)(DAT_0057c670 + 0x90) + 300 + arg1[0x13] * 0x168) != 0x18) {
    Stats_Report_FillCompanyOverview(arg1,(int *)&local_4);
    Company_FillStatisticsBlock(arg1,(int *)&local_4);
    Stats_FillCompanyCategoryLeaders(arg1,(int *)&local_4);
    Stats_ComputePlayerAggregateStats(arg1,(int *)&local_4);
    Game_ComputeCompanyRankStats(arg1,(int *)&local_4);
    Game_ComputeCompanyOverviewStats(arg1,(int *)&local_4);
    Game_FillCompanyRankingStats(arg1,(int *)&local_4);
    Stats_ComputeCompanyRatingStats(arg1,(int *)&local_4);
    Company_ComputeTotals((int *)&local_4);
    List_Add(arg1 + 0x67,local_4);
    return;
  }
  uptr2 = local_4;
  for (value1 = 0x68; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  List_Add(arg1 + 0x67,local_4);
  return;
}
