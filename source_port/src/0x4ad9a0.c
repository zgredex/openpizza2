// StatisticsBranchBalance_InitPage: ported from Pizza Connection 2 at 0x4ad9a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ad9a0
#include "pc2_port.h"


void __cdecl StatisticsBranchBalance_InitPage(void *arg1,char arg2)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  int value5;
  int *ptr6;
  uint32_t *uptr7;
  int value8;
  int local_44 [17];
  
                    /* Initializes the branch-balance statistics page. */
  value5 = 1;
  UI_SetPosition(arg1,&LAB_004ac440,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x4be,0,100,1);
  if (DAT_0057d638 != 0) {
    UI_ReleaseRefCount(DAT_0057c5e0,DAT_0057d638);
  }
  DAT_0057d638 = UI_LoadFontByName(DAT_0057c5e0,s_VERDANA10_fnt_00563e64);
  value1 = DAT_0057c670;
  value8 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value2 = *(int *)(value8 + 0x15c);
  uptr7 = &DAT_0057d5d8;
  for (value3 = 0x15; value3 != 0; value3 = value3 + -1) {
    *uptr7 = 0;
    uptr7 = uptr7 + 1;
  }
  if (value2 == 0) {
    DAT_0056951c = 0xffffffff;
    value5 = 0;
  }
  else if (-1 < (intptr_t)DAT_0056951c) {
    if (*(int *)(value1 + 0x9c) == 0) {
      DAT_0056951c = 0xffffffff;
    }
    else {
      DAT_0056951c = Map_FindIndex((void *)(value8 + 0x148),*(int *)(value1 + 0x9c));
    }
  }
  value8 = 0;
  do {
    UI_SetChildVisibleByID(arg1,*(int *)((intptr_t)&DAT_00569570 + value8),value5);
    UI_SetChildVisibleByID(arg1,*(int *)((intptr_t)&DAT_00569584 + value8),value5);
    UI_SetChildVisibleByID(arg1,*(int *)((intptr_t)&DAT_00569598 + value8),value5);
    value8 = value8 + 4;
  } while (value8 < 0x14);
  UI_SetChildVisibleByID(arg1,0x3f2,value5);
  UI_SetChildVisibleByID(arg1,0x4b2,(uint32_t)(DAT_0056951c != 0xffffffff));
  if (0 < value2) {
    if (value2 < 6) {
      UI_RemoveObjectByKey(arg1,0x3f2);
      value2 = 5 - value2;
      if (0 < value2) {
        value5 = 0;
        do {
          UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00569580 + value5));
          UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00569594 + value5));
          UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_005695a8 + value5));
          value5 = value5 + -4;
          value2 = value2 + -1;
        } while (value2 != 0);
      }
    }
    else {
      DAT_0057d630 = DAT_0056951c & ((intptr_t)DAT_0056951c < 0) - 1;
      if (value2 < (intptr_t)(DAT_0057d630 + 5)) {
        DAT_0057d630 = value2 - 5;
      }
      DAT_0057d634 = DAT_0057d630;
      Window_GadgetNotify_Slider_SetRange(arg1,0x3f2,0,(value2 * 5 + -0x19) * 0x14,0);
      Window_GadgetNotify_Slider_SetValue(arg1,0x3f2,DAT_0057d630 * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x3f2,1);
    }
  }
  if (arg2 != '\0') {
    ptr6 = &DAT_00569520;
    do {
      value5 = 0;
      do {
        ptr4 = local_44;
        value8 = value5 + -0x10 + *ptr6;
        value2 = 0x11;
        do {
          *ptr4 = value8;
          value8 = value8 + 1;
          ptr4 = ptr4 + 1;
          value2 = value2 + -1;
        } while (value2 != 0);
        UI_AddSelectionGroup(arg1,2,0x11,local_44);
        value5 = value5 + 0x11;
      } while (value5 < 0x55);
      ptr6 = ptr6 + 1;
    } while ((intptr_t)ptr6 < 0x569548);
    UI_Group_Create(arg1,0,6,0x4b3);
  }
  Window_GadgetNotify_Button_SetState(arg1,*(int *)(&DAT_00569618 + DAT_0057d62c * 4),1);
  Window_GadgetNotify_Text_SetText(arg1,0x40c,DAT_00580d3c);
  Window_GadgetNotify_Text_SetText(arg1,0x88a,DAT_00580b70);
  StatisticsBranchBalance_UpdateBranchProfits(arg1,DAT_0057d634);
  StatisticsBranchBalance_InitBranchTabs(arg1,DAT_0057d630);
  StatisticsBranchBalance_InitCategoryRows(arg1);
  StatisticsBranchBalance_InitMetricSliders(arg1);
  StatisticsBranchBalance_UpdateWeeklyRows(arg1,'\x01');
  return;
}
