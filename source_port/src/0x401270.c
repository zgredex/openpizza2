// StatsPeriodReport_Destroy: ported from Pizza Connection 2 at 0x401270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401270
#include "pc2_port.h"

void __fastcall StatsPeriodReport_Destroy(uint32_t *arg1)

{
                    /* Destructor body for the period-report record. */
  *arg1 = &PTR_StatsPeriodReport_Delete_0055c2e0;
  return;
}
