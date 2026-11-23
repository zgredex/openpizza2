// StatisticsBranchBalance_InitCategoryRows: ported from Pizza Connection 2 at 0x4ad360.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ad360
#include "pc2_port.h"

void __cdecl StatisticsBranchBalance_InitCategoryRows(void *arg1)

{
  uint32_t uvalue1;
  int *ptr2;
  int value3;
  uint8_t local_40 [64];
  
                    /* Resets and configures branch-balance category rows. */
  ptr2 = &DAT_005695d0;
  do {
    UI_RemoveObjectByKey(arg1,*ptr2);
    ptr2 = ptr2 + 1;
  } while ((intptr_t)ptr2 < 0x5695f4);
  switch(DAT_0057d62c) {
  case 0:
  case 1:
  case 3:
  case 4:
    value3 = 0;
    do {
      String_Format(local_40,&DAT_005630d0,*(uint32_t *)((intptr_t)&DAT_005834d4 + value3));
      Window_GadgetNotify_Text_SetText(arg1,*(int *)((intptr_t)&DAT_005695ac + value3),local_40);
      UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_005695d0 + value3));
      value3 = value3 + 4;
    } while (value3 < 0x24);
    if ((DAT_0057d62c == 0) || (DAT_0057d62c == 3)) {
      uvalue1 = DAT_00582394;
      break;
    }
    uvalue1 = DAT_00581718;
    goto LAB_004ad4ab;
  case 2:
    value3 = 0;
    do {
      Window_GadgetNotify_Text_SetText
                (arg1,*(int *)((intptr_t)&DAT_005695ac + value3),
                 *(uint32_t *)((intptr_t)&DAT_00583298 + value3));
      UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_005695d0 + value3));
      value3 = value3 + 4;
    } while (value3 < 0x10);
    ptr2 = &DAT_005695bc;
    do {
      Window_GadgetNotify_Text_SetText(arg1,*ptr2,DAT_00582e4c);
      ptr2 = ptr2 + 1;
    } while ((intptr_t)ptr2 < 0x5695d0);
    uvalue1 = DAT_0058192c;
    break;
  case 5:
    value3 = 0;
    do {
      Window_GadgetNotify_Text_SetText
                (arg1,*(int *)((intptr_t)&DAT_005695ac + value3),
                 *(uint32_t *)((intptr_t)&DAT_005832b8 + value3));
      UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_005695d0 + value3));
      value3 = value3 + 4;
    } while (value3 < 0x1c);
    ptr2 = &DAT_005695c8;
    do {
      Window_GadgetNotify_Text_SetText(arg1,*ptr2,DAT_00582e4c);
      ptr2 = ptr2 + 1;
    } while ((intptr_t)ptr2 < 0x5695d0);
    uvalue1 = DAT_005828bc;
    break;
  default:
    goto switchD_004ad391_default;
  }
LAB_004ad4ab:
  Window_GadgetNotify_Text_SetText(arg1,0x862,uvalue1);
switchD_004ad391_default:
  StatisticsBranchBalance_DrawDailyChart(arg1);
  return;
}
