// RecipeEdit_CloseIngredientPalette: ported from Pizza Connection 2 at 0x49d910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49d910
#include "pc2_port.h"

void RecipeEdit_CloseIngredientPalette(void)

{
  void *self;
  int value1;
  
                    /* Closes the recipe-edit ingredient palette. */
  if (DAT_0057ca2c != '\0') {
    self = *(void **)(DAT_0057c670 + 0x264);
    UI_ReleasePendingSprite(DAT_0057c5e0);
    DAT_0057ca2c = '\0';
    DAT_00568af4 = 0xffffffff;
    ContestRecipePage_FillIngredientDetails(self,-1);
    value1 = 0;
    do {
      Window_GadgetNotify_Button_SetState(self,value1 + 0x4ed,0);
      value1 = value1 + 1;
    } while (value1 < 0xc);
  }
  return;
}
