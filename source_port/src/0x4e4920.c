// Ingredient_Destroy: ported from Pizza Connection 2 at 0x4e4920.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4920
#include "pc2_port.h"

void __fastcall Ingredient_Destroy(uint32_t *arg1)

{
                    /* Destructor body for an ingredient market record. */
  *arg1 = &PTR_Ingredient_Delete_0055c5b8;
  return;
}
