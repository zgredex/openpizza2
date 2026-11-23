// CRT_LseekLocked: ported from Pizza Connection 2 at 0x5503fe.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5503fe
#include "pc2_port.h"

DWORD __cdecl CRT_LseekLocked(uint32_t arg1,LONG arg2,DWORD arg3)

{
  uint8_t *bptr1;
  HANDLE hFile;
  DWORD *pDVar2;
  DWORD DVar3;
  uint32_t uvalue4;
  
  hFile = (HANDLE)CRT_GetOsHandle(arg1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar2 = CRT_GetErrnoPtr();
    *pDVar2 = 9;
  }
  else {
    DVar3 = SetFilePointer(hFile,arg2,(PLONG)0x0,arg3);
    if (DVar3 == 0xffffffff) {
      uvalue4 = GetLastError();
    }
    else {
      uvalue4 = 0;
    }
    if (uvalue4 == 0) {
      bptr1 = (uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24);
      *bptr1 = *bptr1 & 0xfd;
      return DVar3;
    }
    CRT_MapWin32Error(uvalue4);
  }
  return 0xffffffff;
}
