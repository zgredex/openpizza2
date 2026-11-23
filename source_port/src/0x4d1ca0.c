// RecipeTopping_Destroy: ported from Pizza Connection 2 at 0x4d1ca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d1ca0
#include "pc2_port.h"

void __fastcall RecipeTopping_Destroy(uint32_t *arg1)

{
                    /* Destructor body for a recipe topping. */
  *arg1 = &PTR_RecipeTopping_Delete_0055c4e8;
  return;
}
