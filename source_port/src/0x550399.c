// CRT_Lseek: ported from Pizza Connection 2 at 0x550399.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x550399
#include "pc2_port.h"

DWORD __cdecl CRT_Lseek(uint32_t arg1,LONG arg2,DWORD arg3)

{
  DWORD DVar1;
  DWORD *pDVar2;
  
  if ((arg1 < DAT_00586d20) &&
     ((*(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) & 1) != 0)) {
    CRT_LockFileHandle(arg1);
    DVar1 = CRT_LseekLocked(arg1,arg2,arg3);
    CS_LeaveSlot(arg1);
    return DVar1;
  }
  pDVar2 = CRT_GetErrnoPtr();
  *pDVar2 = 9;
  pDVar2 = CRT_GetDosErrnoPtr();
  *pDVar2 = 0;
  return 0xffffffff;
}
