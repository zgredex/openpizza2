// Buffer_ReleaseField8: ported from Pizza Connection 2 at 0x541f00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541f00
#include "pc2_port.h"

void __fastcall Buffer_ReleaseField8(int arg1)

{
  if (*(LPVOID *)(arg1 + 8) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)(arg1 + 8));
  }
  return;
}
