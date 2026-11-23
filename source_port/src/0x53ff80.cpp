// CS_LeavePtr: ported from Pizza Connection 2 at 0x53ff80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53ff80
#include "pc2_port.h"

void __fastcall CS_LeavePtr(uint32_t *arg1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*arg1);
  return;
}
