// CompanyOverview_UpdatePanel: ported from Pizza Connection 2 at 0x4a48b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a48b0
#include "pc2_port.h"

void __cdecl CompanyOverview_UpdatePanel(void *arg1)

{
  int value1;
  int value2;
  
                    /* Fills the company-overview header and building rows. */
  CompanyOverview_UpdateCityInfo(arg1);
  BranchWindow_InitPriceRows(arg1);
  value1 = 0;
  value2 = *(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x15c);
  do {
    UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00568f90 + value1));
    UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00568fb0 + value1));
    UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00568fd0 + value1));
    UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00568ff0 + value1));
    value1 = value1 + 4;
  } while (value1 < 0x20);
  UI_ShowChildByID(arg1,0x1fa9);
  if (value2 == 0) {
    value2 = 0;
    do {
      UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568f90 + value2));
      UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568fb0 + value2));
      UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568fd0 + value2));
      UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568ff0 + value2));
      value2 = value2 + 4;
    } while (value2 < 0x20);
    UI_RemoveObjectByKey(arg1,0x1fa9);
    return;
  }
  if (value2 < 9) {
    UI_RemoveObjectByKey(arg1,0x1fa9);
    value2 = 8 - value2;
    if (0 < value2) {
      value1 = 0;
      do {
        UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568fac + value1));
        UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568fcc + value1));
        UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568fec + value1));
        UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_0056900c + value1));
        value1 = value1 + -4;
        value2 = value2 + -1;
      } while (value2 != 0);
      CompanyOverview_UpdateBuildingRows(arg1,DAT_0057d264);
      return;
    }
  }
  else {
    DAT_0057d264 = 0;
    Window_GadgetNotify_Slider_SetRange(arg1,0x1fa9,0,(value2 * 5 + -0x28) * 0x14,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x1fa9,DAT_0057d264 * 100,0);
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x1fa9,1);
  }
  CompanyOverview_UpdateBuildingRows(arg1,DAT_0057d264);
  return;
}
