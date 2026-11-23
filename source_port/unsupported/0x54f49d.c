// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x54f49d.c:13:3: error: use of undeclared identifier '_WIN32_FIND_DATAA'
// CRT_FindNext: ported from Pizza Connection 2 at 0x54f49d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f49d
#include "pc2_port.h"

uint32_t __cdecl CRT_FindNext(HANDLE arg1,uint32_t *arg2)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  uint32_t uvalue4;
  _WIN32_FIND_DATAA local_144;
  
  BVar1 = FindNextFileA(arg1,&local_144);
  if (BVar1 != 0) {
    *arg2 = -(uint32_t)(local_144.dwFileAttributes != 0x80) & local_144.dwFileAttributes;
    uvalue4 = ___timet_from_ft(&local_144.ftCreationTime);
    arg2[1] = uvalue4;
    uvalue4 = ___timet_from_ft(&local_144.ftLastAccessTime);
    arg2[2] = uvalue4;
    uvalue4 = ___timet_from_ft(&local_144.ftLastWriteTime);
    arg2[3] = uvalue4;
    arg2[4] = local_144.nFileSizeLow;
    _strcpy(arg2 + 5,(uint32_t *)local_144.cFileName);
    return 0;
  }
  DVar2 = GetLastError();
  if (DVar2 < 2) {
LAB_0054f4d7:
    pDVar3 = CRT_GetErrnoPtr();
    *pDVar3 = 0x16;
  }
  else {
    if (3 < DVar2) {
      if (DVar2 == 8) {
        pDVar3 = CRT_GetErrnoPtr();
        *pDVar3 = 0xc;
        return 0xffffffff;
      }
      if (DVar2 != 0x12) goto LAB_0054f4d7;
    }
    pDVar3 = CRT_GetErrnoPtr();
    *pDVar3 = 2;
  }
  return 0xffffffff;
}
