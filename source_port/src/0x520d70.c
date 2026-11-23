// Buffer_ReleaseField0C: ported from Pizza Connection 2 at 0x520d70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520d70
#include "pc2_port.h"

void __fastcall Buffer_ReleaseField0C(int arg1)

{
  if (*(LPVOID *)(arg1 + 0xc) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)(arg1 + 0xc));
  }
  *(uint32_t *)(arg1 + 0xc) = 0;
  return;
}
