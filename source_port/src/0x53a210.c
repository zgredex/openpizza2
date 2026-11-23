// SpriteBase_Destructor: ported from Pizza Connection 2 at 0x53a210.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a210
#include "pc2_port.h"

void __fastcall SpriteBase_Destructor(uint32_t *arg1)

{
                    /* Destroys the base sprite object. */
  *arg1 = &PTR_SpriteBase_Delete_0055c828;
  return;
}
