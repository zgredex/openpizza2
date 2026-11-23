// RecipeComparison_InitRecipeRows: ported from Pizza Connection 2 at 0x49d4a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49d4a0
#include "pc2_port.h"

void __cdecl RecipeComparison_InitRecipeRows(void *arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  int local_44;
  char local_40 [64];
  
                    /* Renders the competitor recipe comparison rows. */
  local_44 = *(int *)((intptr_t)DAT_0057cac8 + 0x14);
  if (local_44 < 0xd) {
    arg2 = 0;
  }
  else {
    local_44 = 0xc;
  }
  if (0 < local_44) {
    value2 = arg2 * 3;
    value3 = 0x4ed;
    do {
      Window_GadgetNotify_Button_SetState(arg1,value3,(uint32_t)(value2 == DAT_00568af4));
      if (value2 < *(int *)((intptr_t)DAT_0057cac8 + 0x14)) {
        UI_SetChildVisibleByID(arg1,value3 + 0x1c,1);
        UI_SetChildVisibleByID(arg1,value3,1);
        value1 = IDMap_Lookup(DAT_0057cac8,value2,(int *)0x0);
        String_Format(local_40,(uint8_t *)s_zmi__02d_spr_00568938,*(uint32_t *)(value1 + 0xd0));
        UI_SetButtonSpriteByName(arg1,value3 + 0x1c,local_40);
      }
      else {
        UI_SetChildVisibleByID(arg1,value3 + 0x1c,0);
        UI_SetChildVisibleByID(arg1,value3,0);
      }
      value2 = value2 + 1;
      value1 = value3 + -0x4ec;
      value3 = value3 + 1;
    } while (value1 < local_44);
  }
  return;
}
