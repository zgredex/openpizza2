// CRT_Flush: ported from Pizza Connection 2 at 0x554670.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x554670
#include "pc2_port.h"

uint32_t __cdecl CRT_Flush(uint32_t arg1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int value4;
  uint32_t uvalue5;
  
  if (DAT_00586d20 <= arg1) {
LAB_005546f1:
    pDVar3 = CRT_GetErrnoPtr();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  value4 = (arg1 & 0x1f) * 0x24;
  if ((*(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + value4) & 1) == 0) goto LAB_005546f1;
  CRT_LockFileHandle(arg1);
  if ((*(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + value4) & 1) != 0) {
    hFile = (HANDLE)CRT_GetOsHandle(arg1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uvalue5 = 0;
    if (DVar2 == 0) goto LAB_005546e6;
    pDVar3 = CRT_GetDosErrnoPtr();
    *pDVar3 = DVar2;
  }
  pDVar3 = CRT_GetErrnoPtr();
  *pDVar3 = 9;
  uvalue5 = 0xffffffff;
LAB_005546e6:
  CS_LeaveSlot(arg1);
  return uvalue5;
}
