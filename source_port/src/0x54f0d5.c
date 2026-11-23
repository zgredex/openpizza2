// CRT_Srand: ported from Pizza Connection 2 at 0x54f0d5.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f0d5
#include "pc2_port.h"

void __cdecl CRT_Srand(DWORD arg1)

{
  DWORD *pDVar1;
  
  pDVar1 = CRT_GetThreadData();
  pDVar1[5] = arg1;
  return;
}
