// Character_Destroy: ported from Pizza Connection 2 at 0x4d3f80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3f80
#include "pc2_port.h"

void __fastcall Character_Destroy(uint32_t *arg1)

{
                    /* Destructor body for a character record. */
  *arg1 = &PTR_Character_Delete_0055c4fc;
  return;
}
