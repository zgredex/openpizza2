// Branch_StepStarRating: ported from Pizza Connection 2 at 0x47fbd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47fbd0
#include "pc2_port.h"

uint8_t __fastcall Branch_StepStarRating(void *arg1)

{
  void *pvVar1;
  uint32_t uvalue2;
  int value3;
  int value4;
  int value5;
  uint32_t extraout_EDX;
  uint32_t uvalue6;
  uint8_t local_1;
  
  uvalue2 = *(uint32_t *)((intptr_t)arg1 + 0x14b4);
  local_1 = 0;
  value3 = Stats_GetAverage8(arg1,5);
  value4 = Branch_ComputeBuildingRating(arg1,extraout_EDX,5);
  value5 = Branch_GetMenuRating(arg1,5);
  value3 = (value5 + value3 + value4) / 3;
  value4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)arg1 + 0x34),(int *)0x0);
  value4 = 0x3c - *(int *)(value4 + 0xcc8 + *(int *)((intptr_t)arg1 + 0x30) * 4);
  value4 = (intptr_t)(value4 + (value4 >> 0x1f & 7U)) >> 3;
  uvalue6 = (uint32_t)(value4 + 0x4b <= value3);
  if (value4 + 0x4e <= value3) {
    uvalue6 = uvalue6 + 1;
  }
  if (value4 + 0x51 <= value3) {
    uvalue6 = uvalue6 + 1;
  }
  if (value4 + 0x54 <= value3) {
    uvalue6 = uvalue6 + 1;
  }
  if (value4 + 0x57 <= value3) {
    uvalue6 = uvalue6 + 1;
  }
  pvVar1 = (void *)(DAT_0057c670 + 0x304);
  if (uvalue6 != uvalue2) {
    if ((intptr_t)uvalue6 < (intptr_t)uvalue2) {
      *(uint32_t *)((intptr_t)arg1 + 0x14b4) = uvalue2 - 1;
      value3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
      if (*(int *)((intptr_t)arg1 + 0x3c) == value3) {
        UI_Briefing_AddMessage
                  (pvVar1,0x14,0,4,1,*(int *)((intptr_t)arg1 + 0x16f0),DAT_005819e0,
                   (uint8_t *)DAT_005819e0,(intptr_t)arg1 + 4);
        return 0;
      }
    }
    else {
      if (uvalue2 == 5) {
        return 0;
      }
      local_1 = 1;
      *(uint32_t *)((intptr_t)arg1 + 0x14b4) = uvalue2 + 1;
      value3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
      if (*(int *)((intptr_t)arg1 + 0x3c) == value3) {
        UI_Briefing_AddMessage
                  (pvVar1,0x13,0,4,1,*(int *)((intptr_t)arg1 + 0x16f0),DAT_0058262c,
                   (uint8_t *)DAT_0058262c,(intptr_t)arg1 + 4);
      }
    }
  }
  return local_1;
}
