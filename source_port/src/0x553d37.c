// CRT_GetWinMainCmdLine: ported from Pizza Connection 2 at 0x553d37.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553d37
#include "pc2_port.h"

uint8_t * CRT_GetWinMainCmdLine(void)

{
  uint8_t flag1;
  int value2;
  uint8_t *bptr3;
  uint8_t *bptr4;
  
                    /* Returns WinMain's command line after the program name. */
  if (DAT_00586d2c == 0) {
    FUN_00556979();
  }
  flag1 = *DAT_00586d24;
  bptr4 = DAT_00586d24;
  if (flag1 == 0x22) {
    while( true ) {
      bptr3 = bptr4;
      flag1 = bptr3[1];
      bptr4 = bptr3 + 1;
      if ((flag1 == 0x22) || (flag1 == 0)) break;
      value2 = FUN_0055655f(flag1);
      if (value2 != 0) {
        bptr4 = bptr3 + 2;
      }
    }
    if (*bptr4 == 0x22) goto LAB_00553d74;
  }
  else {
    while (0x20 < flag1) {
      flag1 = bptr4[1];
      bptr4 = bptr4 + 1;
    }
  }
  for (; (*bptr4 != 0 && (*bptr4 < 0x21)); bptr4 = bptr4 + 1) {
LAB_00553d74:
  }
  return bptr4;
}
