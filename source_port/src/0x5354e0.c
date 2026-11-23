// Image_FreePixelData: ported from Pizza Connection 2 at 0x5354e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5354e0
#include "pc2_port.h"

void __fastcall Image_FreePixelData(int arg1)

{
  if (*(LPVOID *)(arg1 + 0x460) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)(arg1 + 0x460));
  }
  return;
}
