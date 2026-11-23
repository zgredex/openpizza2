// CRT_CallCatchBlockFinally: ported from Pizza Connection 2 at 0x5531c5.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5531c5
#include "pc2_port.h"

void CRT_CallCatchBlockFinally(void)

{
  DWORD *pDVar1;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(uint32_t *)(unaff_ESI + -4) = *(uint32_t *)(unaff_EBP + -0x28);
  pDVar1 = CRT_GetThreadData();
  pDVar1[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar1 = CRT_GetThreadData();
  pDVar1[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (*(int *)(unaff_EBP + -0x2c) != 0)))) {
    __abnormal_termination();
    CRT_InvokeExceptionHandler((intptr_t)unaff_EDI);
  }
  return;
}
