// StatisticsBalance_MovePeriod: ported from Pizza Connection 2 at 0x4ab760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ab760
#include "pc2_port.h"

void __cdecl StatisticsBalance_MovePeriod(void *arg1,int arg2)

{
  int value1;
  
                    /* Moves the balance-sheet period cursor and refreshes the page. */
  DAT_0057d5c8 = DAT_0057d5c8 + arg2;
  if (DAT_0057d5c8 < 1) {
    do {
      DAT_0057d5c8 = DAT_0057d5c8 + 4;
      DAT_00569354 = DAT_00569354 - 1;
      if ((intptr_t)DAT_00569354 < (intptr_t)DAT_0057dfbc) {
        DAT_0057d5c8 = 1;
        DAT_00569354 = DAT_0057dfbc;
        break;
      }
    } while (DAT_0057d5c8 < 1);
  }
  if (DAT_00569354 == *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4)) {
    value1 = *(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1;
  }
  else {
    value1 = 4;
  }
  do {
    if (DAT_0057d5c8 <= value1) {
LAB_004ab807:
      StatisticsBalance_UpdateHeader(arg1);
      StatisticsBalance_UpdateBranchList(arg1,DAT_0057d5d4);
      StatisticsBalance_UpdateReport(arg1);
      return;
    }
    if (DAT_00569354 == *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4)) {
      DAT_0057d5c8 = value1;
      goto LAB_004ab807;
    }
    DAT_0057d5c8 = DAT_0057d5c8 + -4;
    DAT_00569354 = DAT_00569354 + 1;
  } while( true );
}
