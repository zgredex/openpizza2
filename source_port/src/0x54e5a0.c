// CRT_UnlockHelper: ported from Pizza Connection 2 at 0x54e5a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e5a0
#include "pc2_port.h"

void CRT_UnlockHelper(uint32_t arg1,uint8_t *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0054e5a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}
