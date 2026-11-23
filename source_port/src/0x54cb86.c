// DDRAW.DLL::DirectDrawCreate_Thunk: ported from Pizza Connection 2 at 0x54cb86.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cb86
#include "pc2_port.h"

void DirectDrawCreate_Thunk(void)

{
                    /* WARNING: Could not recover jumptable at 0x0054cb86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawCreate();
  return;
}
