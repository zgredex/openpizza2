// RecipeMenu_ChooseRecipe: ported from Pizza Connection 2 at 0x49f5f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49f5f0
#include "pc2_port.h"

void __cdecl RecipeMenu_ChooseRecipe(void *arg1,int arg2)

{
  *(int *)(DAT_0057c670 + 0x98) = arg2;
  RecipeMenu_RefreshPortionPreview(arg1,arg2);
  if (arg2 == 0) {
    Window_GadgetNotify_Text_SetText(arg1,0x40f,DAT_00581ad0);
    return;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x40f,arg2 + 4);
  return;
}
