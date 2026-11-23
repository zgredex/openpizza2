// NewRecipe_CloseIngredientPalette: ported from Pizza Connection 2 at 0x499be0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x499be0
#include "pc2_port.h"

void NewRecipe_CloseIngredientPalette(void)

{
  void *self;
  int value1;
  
                    /* Closes the new-recipe ingredient palette and hides its buttons. */
  if (DAT_0057ca2c != '\0') {
    self = *(void **)(DAT_0057c670 + 0x264);
    UI_ReleasePendingSprite(DAT_0057c5e0);
    DAT_0057ca2c = '\0';
    DAT_00568914 = 0xffffffff;
    CreateRecipePage_FillIngredientDetails(self,-1);
    value1 = 0;
    do {
      Window_GadgetNotify_Button_SetState(self,value1 + 0x4ed,0);
      value1 = value1 + 1;
    } while (value1 < 0xc);
  }
  return;
}
