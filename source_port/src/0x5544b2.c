// CRT_SetOsfHandle: ported from Pizza Connection 2 at 0x5544b2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5544b2
#include "pc2_port.h"

uint32_t __cdecl CRT_SetOsfHandle(uint32_t arg1,HANDLE arg2)

{
  DWORD *pDVar1;
  int value2;
  DWORD nStdHandle;
  
  if (arg1 < DAT_00586d20) {
    value2 = (arg1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + value2) == -1) {
      if (DAT_00576744 == 1) {
        if (arg1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (arg1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (arg1 != 2) goto LAB_0055450b;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,arg2);
      }
LAB_0055450b:
      *(HANDLE *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + value2) = arg2;
      return 0;
    }
  }
  pDVar1 = CRT_GetErrnoPtr();
  *pDVar1 = 9;
  pDVar1 = CRT_GetDosErrnoPtr();
  *pDVar1 = 0;
  return 0xffffffff;
}
