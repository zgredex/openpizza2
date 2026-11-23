// CRT_GetErrnoPtr: ported from Pizza Connection 2 at 0x553606.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553606
#include "pc2_port.h"

DWORD * CRT_GetErrnoPtr(void)

{
  DWORD *pDVar1;
  
  pDVar1 = CRT_GetThreadData();
  return pDVar1 + 2;
}
