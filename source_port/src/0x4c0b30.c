// PriceMenu_Init: ported from Pizza Connection 2 at 0x4c0b30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c0b30
#include "pc2_port.h"

void __cdecl PriceMenu_Init(void *arg1)

{
                    /* Initializes the branch price submenu page. */
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x1f4f,1);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f4f,DAT_0057d70c,0);
  Window_GadgetNotify_Slider_AttachValueText(arg1,0x1f4f,0x1f51,s__d____00568834);
  MenuPage_FillRecipeDetails(arg1);
  return;
}
