// CS_LeaveSlot: ported from Pizza Connection 2 at 0x55464e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55464e
#include "pc2_port.h"

void __cdecl CS_LeaveSlot(uint32_t arg1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 0xc + (arg1 & 0x1f) * 0x24));
  return;
}
