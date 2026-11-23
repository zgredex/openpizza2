// RecipeMenu_RefreshSelectedRecipe: ported from Pizza Connection 2 at 0x49f580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49f580
#include "pc2_port.h"

void __cdecl RecipeMenu_RefreshSelectedRecipe(void *arg1)

{
  uint32_t *uptr1;
  
  uptr1 = (uint32_t *)IDMap_Lookup((void *)(DAT_0057cd98 + 0x110),DAT_0057cd9c,(int *)0x0);
  *(uint32_t **)(DAT_0057c670 + 0x98) = uptr1;
  RecipeMenu_SetCurrentRecipe(arg1,uptr1);
  if (uptr1 == (uint32_t *)0x0) {
    Window_GadgetNotify_Text_SetText(arg1,0x40f,DAT_00581ad0);
    return;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x40f,uptr1 + 1);
  return;
}
