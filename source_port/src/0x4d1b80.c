// RecipeTopping_Delete: ported from Pizza Connection 2 at 0x4d1b80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d1b80
#include "pc2_port.h"

uint32_t * __thiscall RecipeTopping_Delete(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for a recipe topping. */
  RecipeTopping_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
