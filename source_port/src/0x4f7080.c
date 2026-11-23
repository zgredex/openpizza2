// Thread_Init: ported from Pizza Connection 2 at 0x4f7080.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7080
#include "pc2_port.h"

void __fastcall Thread_Init(int arg1)

{
  *(uint32_t *)(arg1 + 8) = 0;
                    /* WARNING: Could not recover jumptable at 0x004f7087. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetCurrentThreadId();
  return;
}
