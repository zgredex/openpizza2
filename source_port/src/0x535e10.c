// Palette_Free: ported from Pizza Connection 2 at 0x535e10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535e10
#include "pc2_port.h"

void __fastcall Palette_Free(uint32_t *arg1)

{
  if ((LPVOID)*arg1 != (LPVOID)0x0) {
    Mem_Free((LPVOID)*arg1);
  }
  return;
}
