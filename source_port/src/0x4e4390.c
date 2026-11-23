// BuildingValue_Destroy: ported from Pizza Connection 2 at 0x4e4390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4390
#include "pc2_port.h"

void __fastcall BuildingValue_Destroy(uint32_t *arg1)

{
                    /* Destructor body for a building-value record. */
  *arg1 = &PTR_BuildingValue_Delete_0055c5a4;
  return;
}
