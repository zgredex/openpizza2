// SpriteBase_Construct: ported from Pizza Connection 2 at 0x53a1e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a1e0
#include "pc2_port.h"

void __fastcall SpriteBase_Construct(uint32_t *arg1)

{
                    /* Installs the base sprite vtable. */
  *arg1 = &PTR_SpriteBase_Delete_0055c828;
  return;
}
