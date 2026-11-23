// CRT_FreeBufferNode: ported from Pizza Connection 2 at 0x54c7e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54c7e0
#include "pc2_port.h"

void CRT_FreeBufferNode(LPVOID arg1)

{
  if (arg1 != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)((intptr_t)arg1 + 8));
    Mem_Free(*(LPVOID *)((intptr_t)arg1 + 4));
    Mem_Free(arg1);
  }
  return;
}
