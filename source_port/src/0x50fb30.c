// GamePlan_Destructor: ported from Pizza Connection 2 at 0x50fb30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fb30
#include "pc2_port.h"

void __fastcall GamePlan_Destructor(uint32_t *arg1)

{
                    /* Destructor body for a plan/budget record. */
  *arg1 = &PTR_GamePlan_Delete_0055c688;
  return;
}
