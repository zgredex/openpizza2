// StatisticsBalance_InitPage: ported from Pizza Connection 2 at 0x4ab970.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ab970
#include "pc2_port.h"

void __cdecl StatisticsBalance_InitPage(void *arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  uint32_t *uptr5;
  int value6;
  
                    /* Initializes the balance-sheet statistics page. */
  value4 = 1;
  if (DAT_00569354 == -9999) {
    DAT_00569354 = DAT_0057dfbc;
  }
  if (DAT_00569354 < DAT_0057dfbc) {
    DAT_00569354 = DAT_0057dfbc;
    DAT_0057d5c8 = 0;
  }
  UI_SetPosition(arg1,NoOp_Stub,0);
  value1 = DAT_0057c670;
  value6 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value2 = *(int *)(value6 + 0x15c);
  uptr5 = &DAT_0057d574;
  for (value3 = 0x15; value3 != 0; value3 = value3 + -1) {
    *uptr5 = 0;
    uptr5 = uptr5 + 1;
  }
  if (value2 == 0) {
    DAT_00569358 = 0xffffffff;
    value4 = 0;
  }
  else if (-1 < (intptr_t)DAT_00569358) {
    if (*(int *)(value1 + 0x9c) == 0) {
      DAT_00569358 = 0xffffffff;
    }
    else {
      DAT_00569358 = Map_FindIndex((void *)(value6 + 0x148),*(int *)(value1 + 0x9c));
    }
  }
  UI_SetChildVisibleByID(arg1,0x3f2,value4);
  UI_SetChildVisibleByID(arg1,0x4b2,(uint32_t)(DAT_00569358 != 0xffffffff));
  value6 = 0;
  do {
    UI_SetChildVisibleByID(arg1,*(int *)((intptr_t)&DAT_0056935c + value6),value4);
    UI_SetChildVisibleByID(arg1,*(int *)((intptr_t)&DAT_0056937c + value6),value4);
    UI_SetChildVisibleByID(arg1,*(int *)((intptr_t)&DAT_0056939c + value6),value4);
    value6 = value6 + 4;
  } while (value6 < 0x20);
  if (0 < value2) {
    if (value2 < 9) {
      UI_RemoveObjectByKey(arg1,0x3f2);
      value2 = 8 - value2;
      if (0 < value2) {
        value4 = 0x4c6;
        value6 = 0;
        do {
          UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00569378 + value6));
          UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00569398 + value6));
          UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_005693b8 + value6));
          UI_RemoveObjectByKey(arg1,value4);
          value6 = value6 + -4;
          value4 = value4 + -1;
          value2 = value2 + -1;
        } while (value2 != 0);
      }
    }
    else {
      DAT_0057d5d0 = DAT_00569358 & ((intptr_t)DAT_00569358 < 0) - 1;
      if (value2 < (intptr_t)(DAT_0057d5d0 + 8)) {
        DAT_0057d5d0 = value2 - 8;
      }
      DAT_0057d5d4 = DAT_0057d5d0;
      Window_GadgetNotify_Slider_SetRange(arg1,0x3f2,0,(value2 * 5 + -0x28) * 0x14,0);
      Window_GadgetNotify_Slider_SetValue(arg1,0x3f2,DAT_0057d5d0 * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x3f2,1);
    }
  }
  if (DAT_0057d5cc != -1) {
    StatisticsScreen_ChangeTab(arg1,0);
  }
  StatisticsBalance_UpdateBranchList(arg1,DAT_0057d5d0);
  StatisticsBalance_UpdateReport(arg1);
  StatisticsBalance_UpdateHeader(arg1);
  return;
}
