// Memory_FreeAndClear: ported from Pizza Connection 2 at 0x54c4d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54c4d0
#include "pc2_port.h"

void __fastcall Memory_FreeAndClear(uint32_t *arg1)

{
  if ((LPVOID)*arg1 != (LPVOID)0x0) {
    Mem_Free((LPVOID)*arg1);
    *arg1 = 0;
  }
  return;
}
