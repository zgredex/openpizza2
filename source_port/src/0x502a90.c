// AI_SelectStrategyAction: ported from Pizza Connection 2 at 0x502a90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502a90
#include "pc2_port.h"

uint32_t __fastcall AI_SelectStrategyAction(int arg1)

{
  char cVar1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  
  uvalue6 = 0;
  uvalue5 = 2;
  switch(*(uint32_t *)(arg1 + 0x44)) {
  case 0:
    uvalue2 = Game_IsInputIndexUsed(0x50);
    if ((char)uvalue2 == '\0') goto switchD_00502aa4_default;
    goto LAB_00502b07;
  case 1:
    uvalue2 = Game_AnyBuildingRatingAbove(0x50);
    uvalue6 = (uint32_t)((char)uvalue2 != '\0');
    uvalue2 = Game_AnyBuildingCategoryRatingAbove(0x50);
    if ((char)uvalue2 != '\0') {
      if (uvalue6 == 1) {
        uvalue6 = 2;
      }
      else {
        uvalue6 = 0;
        uvalue5 = 0;
      }
    }
    goto switchD_00502aa4_default;
  case 2:
    uvalue2 = Game_IsObjectStatAbove(0x50);
    cVar1 = (char)uvalue2;
    break;
  case 3:
    uvalue3 = Game_AllBuildingCategoryRatingsAbove(0x50);
    cVar1 = (char)uvalue3;
    break;
  default:
    goto switchD_00502aa4_default;
  }
  if (cVar1 != '\0') {
LAB_00502b07:
    uvalue6 = 1;
  }
switchD_00502aa4_default:
  uvalue5 = Random_RangeFast(uvalue6,uvalue5);
  if (uvalue5 == 2) {
    if (*(int *)(arg1 + 0x44) == 1) {
      *(uint32_t *)(arg1 + 0x84) = 0x14;
    }
  }
  else if (uvalue5 == 1) {
    if (*(int *)(arg1 + 0x44) == 3) {
      *(uint32_t *)(arg1 + 0x84) = 0x14;
    }
    if (*(int *)(arg1 + 0x44) == 0) {
      *(uint32_t *)(arg1 + 0x84) = 5;
    }
  }
  value4 = (*(int *)(arg1 + 0x44) + uvalue5 * 4) * 4;
  *(uint32_t *)(arg1 + 0x4c) = *(uint32_t *)(&DAT_005727cc + value4);
  return *(uint32_t *)(&DAT_0057279c + value4);
}
