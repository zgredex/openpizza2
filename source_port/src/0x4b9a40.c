// BranchMenu_UpdatePage: ported from Pizza Connection 2 at 0x4b9a40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b9a40
#include "pc2_port.h"

void __cdecl BranchMenu_UpdatePage(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  
                    /* Refreshes the branch menu/price page. */
  self = *(void **)((intptr_t)DAT_0057c670 + 0x9c);
  DAT_0057d6cc = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
  value3 = 0;
  DAT_0057d6c8 = 0;
  Window_GadgetNotify_Text_SetText(arg1,0x502,DAT_0057d6cc + 8);
  Personnel_SetEmployeePhotoByKey(arg1,0x1f41,DAT_0057d6cc);
  value1 = Game_CountActiveCompanies(DAT_0057d6cc);
  if (*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x9c) + 0x14dc) != 0) {
    value1 = value1 + 1;
  }
  if (value1 < 10) {
    UI_RemoveObjectByKey(arg1,0x50f);
  }
  else {
    Window_GadgetNotify_Slider_SetRange(arg1,0x50f,0,(value1 * 5 + -0x2d) * 0x14,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x50f,DAT_0057d6c8 * 100,0);
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x50f,1);
  }
  CompanyBranches_InitBranchRows(arg1,DAT_0057d6c8);
  do {
    value1 = DAT_0058271c;
    value2 = Branch_GetMenuRating(self,value3);
    Rating_UpdateBarByKey(arg1,0x5ac,value3,value2,value1);
    value3 = value3 + 1;
  } while (value3 < 8);
  return;
}
