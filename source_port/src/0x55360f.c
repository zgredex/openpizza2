// CRT_GetDosErrnoPtr: ported from Pizza Connection 2 at 0x55360f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55360f
#include "pc2_port.h"

DWORD * CRT_GetDosErrnoPtr(void)

{
  DWORD *pDVar1;
  
  pDVar1 = CRT_GetThreadData();
  return pDVar1 + 3;
}
