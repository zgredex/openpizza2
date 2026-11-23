// Mem_Free: ported from Pizza Connection 2 at 0x54dd78.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dd78
#include "pc2_port.h"

void __cdecl Mem_Free(LPVOID arg1)

{
  CRT_FreeInternal(arg1);
  return;
}
