// StatisticsScreen_ChangeTab: ported from Pizza Connection 2 at 0x4ab830.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ab830
#include "pc2_port.h"

void __cdecl StatisticsScreen_ChangeTab(void *arg1,int arg2)

{
  uint16_t uvalue1;
  int value2;
  uint32_t *uptr3;
  uint32_t local_18 [4];
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Switches and refreshes the statistics screen tabs. */
  local_8 = 1;
  uptr3 = local_18;
  local_4 = (uint32_t)(*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4) != DAT_0057dfbc);
  uvalue1 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  value2 = 0;
  do {
    *uptr3 = (uint32_t)(value2 < (intptr_t)(uvalue1 + 1));
    value2 = value2 + 1;
    uptr3 = uptr3 + 1;
  } while (value2 < 4);
  if (arg2 != 0) {
    do {
      DAT_0057d5cc = DAT_0057d5cc + arg2;
      if (5 < (intptr_t)DAT_0057d5cc) {
        DAT_0057d5cc = 0;
        goto switchD_004ab8be_switchD;
      }
      if ((intptr_t)DAT_0057d5cc < 0) {
        DAT_0057d5cc = 5;
      }
    } while (local_18[DAT_0057d5cc] == 0);
  }
  if (5 < DAT_0057d5cc) {
    return;
  }
switchD_004ab8be_switchD:
  switch(DAT_0057d5cc) {
  default:
    DAT_00569354 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4);
    DAT_0057d5c8 = *(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1;
    StatisticsBalance_MovePeriod(arg1,-DAT_0057d5cc);
    return;
  case 4:
  case 5:
    break;
  }
  DAT_00569354 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4);
  if (DAT_0057d5cc == 5) {
    DAT_00569354 = DAT_00569354 - 1;
  }
  if ((intptr_t)DAT_00569354 < (intptr_t)DAT_0057dfbc) {
    DAT_00569354 = DAT_0057dfbc;
  }
  DAT_0057d5c8 = 0;
  StatisticsBalance_UpdateHeader(arg1);
  StatisticsBalance_UpdateBranchList(arg1,DAT_0057d5d4);
  StatisticsBalance_UpdateReport(arg1);
  return;
}
