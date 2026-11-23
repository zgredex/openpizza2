// RecipeKitchen_ShowPlacedIngredient: ported from Pizza Connection 2 at 0x49f1e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49f1e0
#include "pc2_port.h"

void __cdecl RecipeKitchen_ShowPlacedIngredient(void *arg1,int arg2)

{
                    /* Shows a placed ingredient sprite in the recipe kitchen. */
  UI_ShowChildByID(arg1,arg2 + 100000);
  return;
}
