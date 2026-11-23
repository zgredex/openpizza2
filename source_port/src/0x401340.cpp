// CS_Leave: ported from Pizza Connection 2 at 0x401340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401340
#include "pc2_port.h"

void __fastcall CS_Leave(int arg1)

{
  *(int *)(arg1 + 0x54) = *(int *)(arg1 + 0x54) + -1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(arg1 + 4));
  return;
}
