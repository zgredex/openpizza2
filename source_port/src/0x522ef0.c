// Array_Clear: ported from Pizza Connection 2 at 0x522ef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522ef0
#include "pc2_port.h"

void __fastcall Array_Clear(int arg1)

{
  if (*(LPVOID *)(arg1 + 4) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)(arg1 + 4));
  }
  *(uint32_t *)(arg1 + 4) = 0;
  *(uint32_t *)(arg1 + 0xc) = 0;
  *(uint32_t *)(arg1 + 8) = 0;
  *(uint32_t *)(arg1 + 0x10) = 0;
  return;
}
