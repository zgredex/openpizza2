// CRT_Close: ported from Pizza Connection 2 at 0x54fe8b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fe8b
#include "pc2_port.h"

uint32_t __cdecl CRT_Close(uint32_t arg1)

{
  uint32_t uvalue1;
  DWORD *pDVar2;
  
  if ((arg1 < DAT_00586d20) &&
     ((*(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) & 1) != 0)) {
    CRT_LockFileHandle(arg1);
    uvalue1 = CRT_CloseLocked(arg1);
    CS_LeaveSlot(arg1);
    return uvalue1;
  }
  pDVar2 = CRT_GetErrnoPtr();
  *pDVar2 = 9;
  pDVar2 = CRT_GetDosErrnoPtr();
  *pDVar2 = 0;
  return 0xffffffff;
}
