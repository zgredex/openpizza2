// RecipeMenu_PrevRecipe: ported from Pizza Connection 2 at 0x49fa20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49fa20
#include "pc2_port.h"

void __cdecl RecipeMenu_PrevRecipe(void *arg1)

{
  if (0 < *(int *)(DAT_0057cd98 + 0x124)) {
    Window_GadgetNotify_Button_SetState(arg1,0x3fc,1);
    DAT_0057cd9c = DAT_0057cd9c + -1;
    if (DAT_0057cd9c < 0) {
      DAT_0057cd9c = *(int *)(DAT_0057cd98 + 0x124) + -1;
    }
    RecipeMenu_ShowSelectedRecipe(arg1);
  }
  return;
}
