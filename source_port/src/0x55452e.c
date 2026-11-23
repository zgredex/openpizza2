// CRT_FreeOsfHandle: ported from Pizza Connection 2 at 0x55452e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55452e
#include "pc2_port.h"

uint32_t __cdecl CRT_FreeOsfHandle(uint32_t arg1)

{
  int *ptr1;
  DWORD *pDVar2;
  int value3;
  DWORD nStdHandle;
  
  if (arg1 < DAT_00586d20) {
    value3 = (arg1 & 0x1f) * 0x24;
    ptr1 = (int *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + value3);
    if (((*(uint8_t *)(ptr1 + 1) & 1) != 0) && (*ptr1 != -1)) {
      if (DAT_00576744 == 1) {
        if (arg1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (arg1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (arg1 != 2) goto LAB_0055458a;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_0055458a:
      *(uint32_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + value3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = CRT_GetErrnoPtr();
  *pDVar2 = 9;
  pDVar2 = CRT_GetDosErrnoPtr();
  *pDVar2 = 0;
  return 0xffffffff;
}
