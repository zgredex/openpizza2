// StatisticsBalance_ChangeTimeSelection: ported from Pizza Connection 2 at 0x4ab6a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ab6a0
#include "pc2_port.h"

void __cdecl StatisticsBalance_ChangeTimeSelection(void *arg1,int arg2)

{
  uint32_t uvalue1;
  int value2;
  
                    /* Moves the statistics day/time selection and refreshes the screen. */
  DAT_0057d5c8 = DAT_0057d5c8 + arg2;
  if (DAT_0057d5c8 < 0) {
    DAT_00569354 = DAT_00569354 - 1;
    DAT_0057d5c8 = 4;
    if ((intptr_t)DAT_00569354 < (intptr_t)DAT_0057dfbc) {
      DAT_00569354 = DAT_0057dfbc;
      DAT_0057d5c8 = 0;
    }
  }
  else {
    uvalue1 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4);
    if (DAT_00569354 == uvalue1) {
      value2 = *(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1;
    }
    else {
      value2 = 4;
    }
    if (value2 < DAT_0057d5c8) {
      if (DAT_00569354 == uvalue1) {
        DAT_0057d5c8 = value2;
      }
      else {
        DAT_00569354 = DAT_00569354 + 1;
        DAT_0057d5c8 = 0;
      }
    }
  }
  DAT_0057d5cc = 0xffffffff;
  StatisticsBalance_UpdateHeader(arg1);
  StatisticsBalance_UpdateBranchList(arg1,DAT_0057d5d4);
  StatisticsBalance_UpdateReport(arg1);
  return;
}
