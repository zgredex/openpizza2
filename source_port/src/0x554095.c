// CRT_GetEnvStrings: ported from Pizza Connection 2 at 0x554095.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x554095
#include "pc2_port.h"

LPSTR CRT_GetEnvStrings(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  int value5;
  size_t _Size;
  LPSTR pCVar6;
  char *cptr8;
  char *cptr7;
  LPWCH lpWideCharStr;
  LPCH pCVar9;
  LPSTR local_8;
  
  local_8 = (LPSTR)0x0;
  lpWideCharStr = (LPWCH)0x0;
  pCVar9 = (LPCH)0x0;
  if (DAT_005858e8 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_005858e8 = 1;
      goto LAB_005540ec;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_005858e8 = 2;
  }
  else {
    if (DAT_005858e8 == 1) {
LAB_005540ec:
      if ((lpWideCharStr == (LPWCH)0x0) &&
         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
        return (LPSTR)0x0;
      }
      WVar2 = *lpWideCharStr;
      pWVar4 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar3 = pWVar4;
          pWVar4 = pWVar3 + 1;
        } while (*pWVar4 != L'\0');
        pWVar4 = pWVar3 + 2;
        WVar2 = *pWVar4;
      }
      value5 = ((intptr_t)pWVar4 - (intptr_t)lpWideCharStr >> 1) + 1;
      _Size = WideCharToMultiByte(0,0,lpWideCharStr,value5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      if ((_Size != 0) && (pCVar6 = _malloc(_Size), pCVar6 != (LPSTR)0x0)) {
        value5 = WideCharToMultiByte(0,0,lpWideCharStr,value5,pCVar6,_Size,(LPCSTR)0x0,(LPBOOL)0x0);
        local_8 = pCVar6;
        if (value5 == 0) {
          CRT_FreeInternal(pCVar6);
          local_8 = (LPSTR)0x0;
        }
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    if (DAT_005858e8 != 2) {
      return (LPSTR)0x0;
    }
  }
  if ((pCVar9 == (LPCH)0x0) && (pCVar9 = GetEnvironmentStrings(), pCVar9 == (LPCH)0x0)) {
    return (LPSTR)0x0;
  }
  cVar1 = *pCVar9;
  cptr7 = pCVar9;
  while (cVar1 != '\0') {
    do {
      cptr8 = cptr7;
      cptr7 = cptr8 + 1;
    } while (*cptr7 != '\0');
    cptr7 = cptr8 + 2;
    cVar1 = *cptr7;
  }
  pCVar6 = _malloc((size_t)(cptr7 + (1 - (intptr_t)pCVar9)));
  if (pCVar6 == (LPSTR)0x0) {
    pCVar6 = (LPSTR)0x0;
  }
  else {
    _memmove_2((uint32_t *)pCVar6,(uint32_t *)pCVar9,(uint32_t)(cptr7 + (1 - (intptr_t)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}
