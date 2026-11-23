// CRT_Write: ported from Pizza Connection 2 at 0x54ff6b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ff6b
#include "pc2_port.h"

int __cdecl CRT_Write(uint32_t arg1,char *arg2,DWORD arg3)

{
  int value1;
  DWORD *pDVar2;
  
  if ((arg1 < DAT_00586d20) &&
     ((*(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) & 1) != 0)) {
    CRT_LockFileHandle(arg1);
    value1 = CRT_WriteCore(arg1,arg2,arg3);
    CS_LeaveSlot(arg1);
    return value1;
  }
  pDVar2 = CRT_GetErrnoPtr();
  *pDVar2 = 9;
  pDVar2 = CRT_GetDosErrnoPtr();
  *pDVar2 = 0;
  return -1;
}
