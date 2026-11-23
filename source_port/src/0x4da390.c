// Game_AdjustPlayerRankingScores: ported from Pizza Connection 2 at 0x4da390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da390
#include "pc2_port.h"

void __fastcall Game_AdjustPlayerRankingScores(int arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  int value3;
  int value4;
  int value5;
  int *ptr6;
  
  value3 = Game_GetMostAdvancedCompany(arg1);
  value5 = 0;
  ptr6 = (int *)(arg1 + 0xcc8);
  do {
    value4 = Game_GetPlayerBySlot(DAT_0057c670,value5);
    if (value4 != 0) {
      if (value3 == value5) {
        value4 = *ptr6 + 8;
LAB_004da42a:
        *ptr6 = value4;
      }
      else {
        uvalue1 = ptr6[0x39];
        if (uvalue1 == 0) {
          value4 = *ptr6 + -0xc;
          goto LAB_004da42a;
        }
        uvalue2 = *(uint32_t *)(arg1 + 0xdac + value3 * 4);
        if (uvalue1 < uvalue2 >> 2) {
          value4 = *ptr6 + -8;
          goto LAB_004da42a;
        }
        if (uvalue1 < uvalue2 >> 1) {
          value4 = *ptr6 + -5;
          goto LAB_004da42a;
        }
        if (uvalue1 < (uvalue2 * 2) / 3) {
          value4 = *ptr6 + -3;
          goto LAB_004da42a;
        }
        if (uvalue2 * 3 >> 2 < uvalue1) {
          value4 = *ptr6 + 2;
          goto LAB_004da42a;
        }
      }
      value4 = Game_GetPlayerBySlot(DAT_0057c670,value5);
      value4 = Game_GetPlayerCity(value4);
      value4 = *ptr6 + *(int *)(value4 + 0x60) + *(int *)(value4 + 0x48);
      *ptr6 = value4;
      if (value4 < 0) {
        *ptr6 = 0;
      }
      if (100 < *ptr6) {
        *ptr6 = 100;
      }
    }
    value5 = value5 + 1;
    ptr6 = ptr6 + 1;
    if (5 < value5) {
      return;
    }
  } while( true );
}
