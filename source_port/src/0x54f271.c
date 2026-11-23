// CRT_EndThread: ported from Pizza Connection 2 at 0x54f271.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f271
#include "pc2_port.h"

void CRT_EndThread(void)

{
  DWORD *pDVar1;
  
  if (PTR_NoOp_Empty_00576720 != (uint8_t *)0x0) {
    (*(code *)PTR_NoOp_Empty_00576720)();
  }
  pDVar1 = CRT_GetThreadData();
  if (pDVar1 == (DWORD *)0x0) {
    __amsg_exit(0x10);
  }
  if ((HANDLE)pDVar1[1] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)pDVar1[1]);
  }
  CRT_FreeThreadData(pDVar1);
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}
