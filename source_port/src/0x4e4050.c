// FurnitureType_Destroy: ported from Pizza Connection 2 at 0x4e4050.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4050
#include "pc2_port.h"

void __fastcall FurnitureType_Destroy(uint32_t *arg1)

{
                    /* Destructor body for a furniture-type record. */
  *arg1 = &PTR_FurnitureType_Delete_0055c5a0;
  return;
}
