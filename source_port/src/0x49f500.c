// RecipeMenu_ShowSelectedRecipe: ported from Pizza Connection 2 at 0x49f500.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49f500
#include "pc2_port.h"

void __cdecl RecipeMenu_ShowSelectedRecipe(void *arg1)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  
  uptr1 = (uint32_t *)IDMap_Lookup((void *)(DAT_0057cd98 + 0x110),DAT_0057cd9c,(int *)0x0);
  RecipeMenu_SetCurrentRecipe(arg1,uptr1);
  if (uptr1 == (uint32_t *)0x0) {
    uptr2 = DAT_00581ad0;
  }
  else {
    uptr2 = uptr1 + 1;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x40f,uptr2);
  *(uint32_t **)(DAT_0057c670 + 0x98) = uptr1;
  if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x264),-0x18671,0x23,1);
  }
  return;
}
