// GamePlan_Construct: ported from Pizza Connection 2 at 0x50f630.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50f630
#include "pc2_port.h"

void __fastcall GamePlan_Construct(uint32_t *arg1)

{
                    /* Constructs a plan/budget record with default fields. */
  *arg1 = &PTR_GamePlan_Delete_0055c688;
  arg1[1] = 0;
  arg1[2] = 2;
  arg1[4] = 0;
  arg1[5] = 0;
  arg1[6] = 0;
  arg1[7] = 0xffffffff;
  arg1[8] = 0;
  arg1[0xb] = 0xffffffff;
  arg1[3] = 0xffffffff;
  arg1[9] = 0;
  arg1[10] = 0;
  return;
}
